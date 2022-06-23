/*
 * LED2.c
 *
 * Created: 2022-06-17 오후 1:54:36
 *  Author: PKNU
 */ 
#define F_CPU 7432800
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRA = 0xff; //방향설정 /portA를 출력으로 설정 0b 1111 1111 123456789ABCDEF
	int led_data = 0x01; //0b 0000 0001 
	int i;
	
while(1)
{
		//PORTA = 0x01;
		//_delay_ms(1000);
		//PORTA = 0x02;
		//_delay_ms(1000);
		//PORTA = 0x04;
		//_delay_ms(1000);
		//PORTA = 0x08;
		//_delay_ms(1000);
		//
		led_data = 0x01;
		for(i=0;i<8;i++)
		{
					PORTA = led_data; //0b 1000 0000 
					led_data<<=1;	//왼쪽으로 이동
					_delay_ms(1000);
	}
	led_data =0x40;
	for(i=0;i<8;i++)
	{
			PORTA = led_data;
			led_data>>=1; //0b 0001 0000
			_delay_ms(1000);		
		}
		
		
		//for(i=0;i<8;i++)
		//{				
			//PORTA =0xff;
				//
			//PORTA = led_data+i;
			//_delay_ms(1000);
			////for(j=8;j<0;j--)
		//
		//}
			
}
	return 0;
}
