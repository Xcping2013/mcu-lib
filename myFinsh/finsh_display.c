#include "finsh_cmd.h"

#ifdef TM1638_USED

static uint8_t tm1638_Inited = 0; 
//100个字节为基准
void led_show(char *num)
{
	if(tm1638_Inited==0)
	{
		tm1638.init(tm1638_8bit);
		tm1638_Inited=1;
	}	
	tm1638.show(tm1638_8bit,num);
	
}

void key_get(void)
{
	if(tm1638_Inited==0)
	{
		tm1638.init(tm1638_8bit);
		tm1638_Inited=1;
	}	
	rt_kprintf( "key=%d",tm1638.readkey(tm1638_8bit));
}

FINSH_FUNCTION_EXPORT(led_show,  .)
FINSH_FUNCTION_EXPORT(key_get,  .)

static void led_dis(void)
{
	tm1638.init(tm1638_8bit);
	tm1638.show(tm1638_8bit,"6666");
	
}
INIT_APP_EXPORT(led_dis);
#endif

