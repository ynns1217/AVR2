/*
 * led2.c
 *
 * Created: 2022-06-17 오후 1:54:34
 *  Author: PKNU
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRA = 0xFF;
	
	while (1)
	{
		PORTA = 0x01;
		_delay_ms(1000);
		PORTA = 0x02;
		_delay_ms(1000);
		PORTA = 0x04;
		_delay_ms(1000);
		PORTA = 0x08;
		_delay_ms(1000);
	}
	return 0;
}