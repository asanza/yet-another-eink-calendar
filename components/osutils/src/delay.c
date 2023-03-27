#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <os/delay.h>

void os_sleep(uint32_t ms)
{
    vTaskDelay(pdMS_TO_TICKS(ms));
}