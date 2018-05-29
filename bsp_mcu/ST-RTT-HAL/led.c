#include <rtthread.h>
#include <led.h>

void led_thread_entry(void* parameter)
{
    rt_pin_mode(LED_RUN,PIN_MODE_OUTPUT);

    while (1)
    {
        rt_pin_write(LED_RUN,PIN_HIGH);
        rt_thread_delay( RT_TICK_PER_SECOND/5 ); /* sleep 0.5 second and switch to other thread */

        rt_pin_write(LED_RUN,PIN_LOW);
        rt_thread_delay( RT_TICK_PER_SECOND/5 );
    }
}

