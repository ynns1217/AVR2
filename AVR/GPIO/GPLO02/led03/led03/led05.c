/*
 * led05.c
 *
 * Created: 2022-06-17 오후 5:26:59
 *  Author: PKNU
 */ 
#define  F_CPU 7432800UL
#include <stdio.h>
#include <util/delay.h>

// unsigned char fnd[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f};
// unsigned char fnd_pos[4] = {0x01, 0x02, 0x04, 0x08} 0111 1011 1101 1110;
int main()
{
	DDRA = 0xff;
	DDRF = 0xff;
		
	while(1)
	{
		PORTG = 0x3f;
		PORTC = 0111 1011 1101 1110;
	}
	return 0;
}