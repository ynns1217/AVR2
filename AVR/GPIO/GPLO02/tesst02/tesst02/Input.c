/*
 * Input.c
 *
 * Created: 2022-06-17 오후 3:20:53
 *  Author: PKNU
 */ 

#define F_CPU 7432800UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRA = 0xff;  //포트 a를 출력으로 설정
	DDRB = 0x00; //포트 c를 입력으로 설정
	
	while (1)
	{
	   PORTA = PINB;		
	}
	return 0;
}