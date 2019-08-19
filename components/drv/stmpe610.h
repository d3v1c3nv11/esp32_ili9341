/*
    STMPE610 Touch controller constants
*/

#ifndef _STMPE610_H
#define _STMPE610_H

#include <stdint.h>
#include "lvgl/lvgl.h"

#define TP_CALX_STMPE610	21368532
#define TP_CALY_STMPE610	11800144

// === Screen orientation constants ===
#define PORTRAIT	0
#define LANDSCAPE	1
#define PORTRAIT_FLIP	2
#define LANDSCAPE_FLIP	3
#define DEFAULT_TFT_DISPLAY_WIDTH   240
#define DEFAULT_TFT_DISPLAY_HEIGHT  320

// ==== Display dimensions in pixels ============================
extern int _width;
extern int _height;

#define STMPE610_ADDR 0x9a

#define STMPE610_SPI_MODE              0

// Identification registers
#define STMPE610_REG_CHP_ID         0x00 // 16-bit
#define STMPE610_REG_ID_VER         0x02

// System registers
#define STMPE610_REG_SYS_CTRL1      0x03
#define STMPE610_REG_SYS_CTRL2      0x04
#define STMPE610_REG_SPI_CFG        0x08

// Interrupt control registers
#define STMPE610_REG_INT_CTRL       0x09
#define STMPE610_REG_INT_EN         0x0A
#define STMPE610_REG_INT_STA        0x0B
#define STMPE610_REG_GPIO_INT_EN    0x0C
#define STMPE610_REG_GPIO_INT_STA   0x0D
#define STMPE610_REG_ADC_INT_EN     0x0E
#define STMPE610_REG_ADC_INT_STA    0x0F

// GPIO registers
#define STMPE610_REG_GPIO_SET_PIN   0x10
#define STMPE610_REG_GPIO_CLR_PIN   0x11
#define STMPE610_REG_GPIO_MP_STA    0x12
#define STMPE610_REG_GPIO_DIR       0x13
#define STMPE610_REG_GPIO_ED        0x14
#define STMPE610_REG_GPIO_RE        0x15
#define STMPE610_REG_GPIO_FE        0x16
#define STMPE610_REG_GPIO_AF        0x17

// ADC registers
#define STMPE610_REG_ADC_CTRL1      0x20
#define STMPE610_REG_ADC_CTRL2      0x21
#define STMPE610_REG_ADC_CAPT       0x22
#define STMPE610_REG_ADC_DATA_CH0   0x30 // 16-bit
#define STMPE610_REG_ADC_DATA_CH1   0x32 // 16-bit
#define STMPE610_REG_ADC_DATA_CH4   0x38 // 16-bit
#define STMPE610_REG_ADC_DATA_CH5   0x3A // 16-bit
#define STMPE610_REG_ADC_DATA_CH6   0x3C // 16-bit
#define STMPE610_REG_ADC_DATA_CH7   0x3E // 16-bit

// Touchscreen registers
#define STMPE610_REG_TSC_CTRL       0x40
#define STMPE610_REG_TSC_CFG        0x41
#define STMPE610_REG_WDW_TR_X       0x42 // 16-bit
#define STMPE610_REG_WDW_TR_Y       0x44 // 16-bit
#define STMPE610_REG_WDW_BL_X       0x46 // 16-bit
#define STMPE610_REG_WDW_BL_Y       0x48 // 16-bit
#define STMPE610_REG_FIFO_TH        0x4A
#define STMPE610_REG_FIFO_STA       0x4B
#define STMPE610_REG_FIFO_SIZE      0x4C
#define STMPE610_REG_TSC_DATA_X     0x4D // 16-bit
#define STMPE610_REG_TSC_DATA_Y     0x4F // 16-bit
#define STMPE610_REG_TSC_DATA_Z     0x51
#define STMPE610_REG_TSC_DATA_XYZ   0x52 // 32-bit
#define STMPE610_REG_TSC_FRACT_XYZ  0x56
#define STMPE610_REG_TSC_DATA       0x57
#define STMPE610_REG_TSC_I_DRIVE    0x58
#define STMPE610_REG_TSC_SHIELD     0x59


#define STMPE_SYS_CTRL1 0x03
#define STMPE_SYS_CTRL1_RESET 0x02
#define STMPE_SYS_CTRL2 0x04

#define STMPE_TSC_CTRL 0x40
#define STMPE_TSC_CTRL_EN 0x01
#define STMPE_TSC_CTRL_XYZ 0x00
#define STMPE_TSC_CTRL_XY 0x02

#define STMPE_INT_CTRL 0x09
#define STMPE_INT_CTRL_POL_HIGH 0x04
#define STMPE_INT_CTRL_POL_LOW 0x00
#define STMPE_INT_CTRL_EDGE 0x02
#define STMPE_INT_CTRL_LEVEL 0x00
#define STMPE_INT_CTRL_ENABLE 0x01
#define STMPE_INT_CTRL_DISABLE 0x00



#define STMPE_INT_EN 0x0A
#define STMPE_INT_EN_TOUCHDET 0x01
#define STMPE_INT_EN_FIFOTH 0x02
#define STMPE_INT_EN_FIFOOF 0x04
#define STMPE_INT_EN_FIFOFULL 0x08
#define STMPE_INT_EN_FIFOEMPTY 0x10
#define STMPE_INT_EN_ADC 0x40
#define STMPE_INT_EN_GPIO 0x80

#define STMPE_INT_STA 0x0B
#define STMPE_INT_STA_TOUCHDET 0x01

#define STMPE_ADC_CTRL1 0x20
#define STMPE_ADC_CTRL1_12BIT 0x08
#define STMPE_ADC_CTRL1_10BIT 0x00

#define STMPE_ADC_CTRL2 0x21
#define STMPE_ADC_CTRL2_1_625MHZ 0x00
#define STMPE_ADC_CTRL2_3_25MHZ 0x01
#define STMPE_ADC_CTRL2_6_5MHZ 0x02

#define STMPE_TSC_CFG 0x41
#define STMPE_TSC_CFG_1SAMPLE 0x00
#define STMPE_TSC_CFG_2SAMPLE 0x40
#define STMPE_TSC_CFG_4SAMPLE 0x80
#define STMPE_TSC_CFG_8SAMPLE 0xC0
#define STMPE_TSC_CFG_DELAY_10US 0x00
#define STMPE_TSC_CFG_DELAY_50US 0x08
#define STMPE_TSC_CFG_DELAY_100US 0x10
#define STMPE_TSC_CFG_DELAY_500US 0x18
#define STMPE_TSC_CFG_DELAY_1MS 0x20
#define STMPE_TSC_CFG_DELAY_5MS 0x28
#define STMPE_TSC_CFG_DELAY_10MS 0x30
#define STMPE_TSC_CFG_DELAY_50MS 0x38
#define STMPE_TSC_CFG_SETTLE_10US 0x00
#define STMPE_TSC_CFG_SETTLE_100US 0x01
#define STMPE_TSC_CFG_SETTLE_500US 0x02
#define STMPE_TSC_CFG_SETTLE_1MS 0x03
#define STMPE_TSC_CFG_SETTLE_5MS 0x04
#define STMPE_TSC_CFG_SETTLE_10MS 0x05
#define STMPE_TSC_CFG_SETTLE_50MS 0x06
#define STMPE_TSC_CFG_SETTLE_100MS 0x07

#define STMPE_FIFO_TH 0x4A

#define STMPE_FIFO_SIZE 0x4C

#define STMPE_FIFO_STA 0x4B
#define STMPE_FIFO_STA_RESET 0x01
#define STMPE_FIFO_STA_OFLOW 0x80
#define STMPE_FIFO_STA_FULL 0x40
#define STMPE_FIFO_STA_EMPTY 0x20
#define STMPE_FIFO_STA_THTRIG 0x10

#define STMPE_TSC_I_DRIVE 0x58
#define STMPE_TSC_I_DRIVE_20MA 0x00
#define STMPE_TSC_I_DRIVE_50MA 0x01

#define STMPE_TSC_DATA_X 0x4D
#define STMPE_TSC_DATA_Y 0x4F
#define STMPE_TSC_FRACTION_Z 0x56

#define STMPE_GPIO_SET_PIN 0x10
#define STMPE_GPIO_CLR_PIN 0x11
#define STMPE_GPIO_DIR 0x13
#define STMPE_GPIO_ALT_FUNCT 0x17

//int stmpe610_read_touch(int *x, int* y, uint8_t raw);
bool TP_read(lv_indev_drv_t * drv, lv_indev_data_t * data);
//static void IRAM_ATTR stmpe610_write_reg(uint8_t reg, uint8_t val) ;
//static int i2c_init();
//static uint8_t IRAM_ATTR stmpe610_read_byte(uint8_t reg);
//static uint16_t IRAM_ATTR stmpe610_read_word(uint8_t reg);
uint32_t stmpe610_getID();
void stmpe610_Init();
//int stmpe610_get_touch(uint16_t *x, uint16_t *y, uint16_t *z);



#endif /* _STMPE610_H */
