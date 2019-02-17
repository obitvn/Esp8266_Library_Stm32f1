#include "ObitString.h"

void obit_split_string(uint8_t *str_in, uint8_t size_str_in,uint8_t char_begin, uint8_t frequency_char_begin, uint8_t char_end, uint8_t frequency_char_end, uint8_t *str_out, uint8_t size_str_out)
{
	uint8_t done=0;
	uint8_t i=0, count_begin=0, count_end=0;
	memset((char*)str_out,'\0',size_str_out);
	for(i=0; i<size_str_in; i++)
	{
		if(str_in[i] == char_begin)
		{
			count_begin++;
			if(count_begin==frequency_char_begin)
			{
			for(int j=1; j<size_str_out+1; j++)
			 {
				
				if(str_in[i+j]==char_end)
				{
					count_end++;
					if(count_end==frequency_char_end)
					{
					done=1;
					break;
					}
					else
						str_out[j-1]=str_in[i+j];
				}
				else
				{
					str_out[j-1]=str_in[i+j];
				}
			 }
		  }
		}
		else
		{			
		 if(done==1) break;
	  }
	}
}




int obit_strcmp(uint8_t *str_expected,uint8_t size_str_expected, uint8_t *str_real, uint8_t size_str_real)
{
 int i=0;
 uint8_t next=0;
 while(i<size_str_real)
 {
	 if(str_expected[0]==str_real[i])
	 {
		 for(int j=0; j<size_str_expected; j++)
		 {
			 if(str_expected[j]!=str_real[j+i]) 
			 {
				 i++;
				 next=1;
				 break;
			 }
			 else
				 next = 0;
				 //return -1;
		 }
		 if(next==0) return 1;
	 }
	 else 
	 {
		 i++;
		 next=0;
	 }
 }
 return 0;
}