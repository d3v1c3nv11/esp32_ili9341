#include "board.h"
#include "display.h"
#include "sdkconfig.h"

void board_init(void){
	disp_spi_init();
	ili9341_init();
#if CONFIG_EXAMPLE_BOARD_TYPE != 4	
	stmpe610_Init();
#endif
}	
