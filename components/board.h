
/*********************
 *      BOARD DEFINES
 *********************/
#include "sdkconfig.h"

#if CONFIG_EXAMPLE_BOARD_TYPE == 0
//Olimex ESP32-EVB
#define SPI_PORT HSPI_HOST
#define DISP_SPI_MOSI 2
#define DISP_SPI_CLK  14
#define DISP_SPI_CS   17
#define ILI9341_DC   15
#define ILI9341_RST  -1
#define ILI9341_BCKL -1
#define I2C_PORT I2C_NUM_0
#define I2C_SDA	13
#define I2C_SCL	16
#elif CONFIG_EXAMPLE_BOARD_TYPE == 1
//Olimex ESP32-PoE
#define SPI_PORT HSPI_HOST
#define DISP_SPI_MOSI 2
#define DISP_SPI_CLK  14
#define DISP_SPI_CS   5
#define ILI9341_DC   15
#define ILI9341_RST  -1
#define ILI9341_BCKL -1
#define I2C_PORT I2C_NUM_0
#define I2C_SDA	13
#define I2C_SCL	16
#elif CONFIG_EXAMPLE_BOARD_TYPE == 2
//Olimex ESP32-ADF Rev.B
#define SPI_PORT HSPI_HOST
#define DISP_SPI_MOSI 2
#define DISP_SPI_CLK  14
#define DISP_SPI_CS   21
#define ILI9341_DC   15
#define ILI9341_RST  -1
#define ILI9341_BCKL -1
#define I2C_PORT I2C_NUM_0
#define I2C_SDA	18
#define I2C_SCL	23
#elif CONFIG_EXAMPLE_BOARD_TYPE == 3
//Olimex ESP32-ADF Rev.C
#define SPI_PORT HSPI_HOST
#define DISP_SPI_MOSI 13
#define DISP_SPI_CLK  14
#define DISP_SPI_CS   15
#define ILI9341_DC   12
#define ILI9341_RST  -1
#define ILI9341_BCKL -1
#define I2C_PORT I2C_NUM_0
#define I2C_SDA	18
#define I2C_SCL	23
#elif CONFIG_EXAMPLE_BOARD_TYPE == 4
//ESP-Wrover-Kit v4.1
#define SPI_PORT HSPI_HOST
#define DISP_SPI_MOSI 23
#define DISP_SPI_CLK  19
#define DISP_SPI_CS   22
#define ILI9341_DC   21
#define ILI9341_RST  18
#define ILI9341_BCKL 5
#define I2C_PORT I2C_NUM_0
#define I2C_SDA	-1
#define I2C_SCL	-1
#else
//user board
#define SPI_PORT HSPI_HOST
#define DISP_SPI_MOSI 23
#define DISP_SPI_CLK  19
#define DISP_SPI_CS   22
#define ILI9341_DC   21
#define ILI9341_RST  18
#define ILI9341_BCKL 5
#define I2C_PORT I2C_NUM_0
#define I2C_SDA	18
#define I2C_SCL	23
#endif

void board_init(void);
