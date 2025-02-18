/**
 * @file ili9341.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "ili9341.h"
#include "disp_spi.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/*The LCD needs a bunch of command/argument values to be initialized. They are stored in this struct. */
typedef struct {
    uint8_t cmd;
    uint8_t data[16];
    uint8_t databytes; //No of data in data; bit 7 = delay after set; 0xFF = end of cmds.
} lcd_init_cmd_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void ili9341_send_cmd(uint8_t cmd);
static void ili9341_send_data(void * data, uint16_t length);
static void ili9341_send_color(void * data, uint16_t length);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void ili9341_init(void)
{
	lcd_init_cmd_t ili_init_cmds[]={
		{0xCF, {0x00, 0x83, 0X30}, 3},
		{0xED, {0x64, 0x03, 0X12, 0X81}, 4},
		{0xE8, {0x85, 0x01, 0x79}, 3},
		{0xCB, {0x39, 0x2C, 0x00, 0x34, 0x02}, 5},
		{0xF7, {0x20}, 1},
		{0xEA, {0x00, 0x00}, 2},
		{0xC0, {0x26}, 1},			/*Power control*/
		{0xC1, {0x11}, 1},			/*Power control */
		{0xC5, {0x35, 0x3E}, 2},	/*VCOM control*/
		{0xC7, {0xBE}, 1},			/*VCOM control*/
		{0x36, {0x28}, 1},			/*Memory Access Control*/
		{0x3A, {0x55}, 1},			/*Pixel Format Set*/
		{0xB1, {0x00, 0x1B}, 2},
		{0xF2, {0x08}, 1},
		{0x26, {0x01}, 1},
		{0xE0, {0x1F, 0x1A, 0x18, 0x0A, 0x0F, 0x06, 0x45, 0X87, 0x32, 0x0A, 0x07, 0x02, 0x07, 0x05, 0x00}, 15},
		{0XE1, {0x00, 0x25, 0x27, 0x05, 0x10, 0x09, 0x3A, 0x78, 0x4D, 0x05, 0x18, 0x0D, 0x38, 0x3A, 0x1F}, 15},
		{0x2A, {0x00, 0x00, 0x00, 0xEF}, 4},
		{0x2B, {0x00, 0x00, 0x01, 0x3f}, 4},
		{0x2C, {0}, 0},
		{0xB7, {0x07}, 1},
		{0xB6, {0x0A, 0x82, 0x27, 0x00}, 4},
		{0x11, {0}, 0x80},
		{0x29, {0}, 0x80},
		{0, {0}, 0xff},
	};

	//Initialize non-SPI GPIOs
	gpio_set_direction(ILI9341_DC, GPIO_MODE_OUTPUT);
	PIN_FUNC_SELECT(GPIO_PIN_MUX_REG[ILI9341_DC], PIN_FUNC_GPIO);
#if ILI9341_RST > 0	
	gpio_set_direction(ILI9341_RST, GPIO_MODE_OUTPUT);
#endif
#if ILI9341_BCKL > 0
	gpio_set_direction(ILI9341_BCKL, GPIO_MODE_OUTPUT);
#endif	
	PIN_FUNC_SELECT(GPIO_PIN_MUX_REG[DISP_SPI_CS], PIN_FUNC_GPIO);
	gpio_set_direction(DISP_SPI_CS, GPIO_MODE_OUTPUT);
	gpio_set_level(DISP_SPI_CS, 1);
	
	//Reset the display
#if ILI9341_RST > 0 
	gpio_set_level(ILI9341_RST, 0);
	vTaskDelay(100 / portTICK_RATE_MS);
	gpio_set_level(ILI9341_RST, 1);
	vTaskDelay(100 / portTICK_RATE_MS);
#endif

	printf("ILI9341 initialization. MOSI=%d, SCK=%d, CS=%d, DC=%d, BOARD=%d\n",DISP_SPI_MOSI,DISP_SPI_CLK,DISP_SPI_CS,ILI9341_DC,CONFIG_EXAMPLE_BOARD_TYPE);


	//Send all the commands
	uint16_t cmd = 0;
	while (ili_init_cmds[cmd].databytes!=0xff) {
		ili9341_send_cmd(ili_init_cmds[cmd].cmd);
		ili9341_send_data(ili_init_cmds[cmd].data, ili_init_cmds[cmd].databytes&0x1F);
		if (ili_init_cmds[cmd].databytes & 0x80) {
			vTaskDelay(100 / portTICK_RATE_MS);
		}
		cmd++;
	}
#if ILI9341_BCKL > 0 
	///Enable backlight
	printf("Enable backlight.\n");
	gpio_set_level(ILI9341_BCKL, ILI9341_BCKL_ACTIVE_LVL);
#endif	
}


void ili9341_flush(lv_disp_drv_t * drv, const lv_area_t * area, lv_color_t * color_map)
{
	uint8_t data[4];

	/*Column addresses*/
	ili9341_send_cmd(0x2A);
	data[0] = (area->x1 >> 8) & 0xFF;
	data[1] = area->x1 & 0xFF;
	data[2] = (area->x2 >> 8) & 0xFF;
	data[3] = area->x2 & 0xFF;
	ili9341_send_data(data, 4);

	/*Page addresses*/
	ili9341_send_cmd(0x2B);
	data[0] = (area->y1 >> 8) & 0xFF;
	data[1] = area->y1 & 0xFF;
	data[2] = (area->y2 >> 8) & 0xFF;
	data[3] = area->y2 & 0xFF;
	ili9341_send_data(data, 4);

	/*Memory write*/
	ili9341_send_cmd(0x2C);


	uint32_t size = lv_area_get_width(area) * lv_area_get_height(area);

	ili9341_send_color((void*)color_map, size * 2);

}

/**********************
 *   STATIC FUNCTIONS
 **********************/


static void ili9341_send_cmd(uint8_t cmd)
{
	

	gpio_set_level(ILI9341_DC, 0);	 /*Command mode*/
    gpio_set_level(DISP_SPI_CS, 0);
	disp_spi_send_data(&cmd, 1);
	gpio_set_level(DISP_SPI_CS, 1);
}

static void ili9341_send_data(void * data, uint16_t length)
{
	
	gpio_set_level(ILI9341_DC, 1);	 /*Data mode*/
    gpio_set_level(DISP_SPI_CS, 0);
	disp_spi_send_data(data, length);
	gpio_set_level(DISP_SPI_CS, 1);
}

static void ili9341_send_color(void * data, uint16_t length)
{
    gpio_set_level(ILI9341_DC, 1);   /*Data mode*/
    gpio_set_level(DISP_SPI_CS, 0);
    disp_spi_send_colors(data, length);
    gpio_set_level(DISP_SPI_CS, 1);
}
