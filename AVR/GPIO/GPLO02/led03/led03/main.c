/*
 * led03.c
 *
 * Created: 2022-06-17 오후 4:17:54
 * Author : PKNU
 */ 

#define F_CPU 7432800UL
#include <avr/io.h>
#include <util/delay.h>
 
int main(void)
{
	char num[] ={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f, 0x77, 0x7C,
	0x39, 0x5e, 0x79, 0x71};
	unsigned char count =0;
	
	
	DDRA = 0xFF;
	DDRB = 0x00;
	
		
	while(1)
	{
		if(PINB == 1)
		{
			PORTA = num[0]; 
		}
		if(PINB == 0x04)
		{
			PORTA = num[2];
		}
		if(PINB == 0x08)
		{
			PORTA = num[3];
		}
		if(PINB == 0x10)
		{
			PORTA = num[4];
		}
		if(PINB == 0x11)
		{
			PORTA = num[5];
		}
		if(PINB == 0x14)
		{
			PORTA = num[4];
		}

	}
    
	return 0;
}

