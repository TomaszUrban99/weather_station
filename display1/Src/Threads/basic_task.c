#include "basic_task.h"

void basic_task(){

	while(1){
	gpio_toggle();
	vTaskDelay(500);
	}
}
