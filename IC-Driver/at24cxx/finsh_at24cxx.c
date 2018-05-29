#include "finsh_cmd.h"

#ifdef AT24CXX_USED

at24cxx_t at24c256=
{
	{0},
	{PA_0,PC_3},
	0xA2,
};

void eeprom_init(void)
{
	at24c256.eeprom=C24LC256;//C24LC256;
	at24cxx.init(at24c256);
}

void save_data(u8 pageNum , char *Commands)
{
	u8 len=strlen(Commands);
	if(	pageNum>0 && len<65	)	
	{
		at24cxx.write(at24c256,(pageNum-1)*64,Commands,len);
		printf("<save data ok>");
	}
}

void read_data(u8 pageNum)
{
	u8 read_info[64];
	u8 i;
	if(	pageNum>0 )	
	{
		at24cxx.read(at24c256 , (pageNum-1)*64, read_info, 64);
		for(i=0;i<64;i++)	
		{
			if(read_info[i]>127) { read_info[i]='\0';break;}
		}
		rt_kprintf("<%.64s>",read_info);
	}
}

INIT_APP_EXPORT(eeprom_init);

FINSH_FUNCTION_EXPORT(read_data,	read data from position 1~255) 
FINSH_FUNCTION_EXPORT(save_data,	save data to position 1~255)
//
#endif

