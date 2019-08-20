#include "sdkconfig.h"

#if CONFIG_EXAMPLE_DISPLAY_TYPE == 2
#include "drv/disp_spi.h"
#include "drv/ili9341.h"
#endif

#if CONFIG_EXAMPLE_BOARD_TYPE != 4
#include "drv/stmpe610.h"
#endif
