#ifndef __LED_H
#define __LED_H

#include <sys.h>
#include <drivers/pin.h>

#define LED_RUN	PB_2

void led_thread_entry(void* parameter);

#endif

