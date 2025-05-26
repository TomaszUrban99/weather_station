#include <stdint.h>
#include "stm32f429xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os2.h"

#include "clock.h"
#include "gpio.h"
#include "basic_task.h"

const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

int main(void)
{
	/* Hardware initialization */
	hardware_init();

	osKernelInitialize();

	/* Threads creation */
	osThreadNew(basic_task,NULL,&defaultTask_attributes);

	osKernelStart();

    /* Loop forever */
	for(;;);
}
