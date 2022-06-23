/*
* int.c
*
* Created: 2022-06-20 오전 10:39:49
*  Author: PKNU
*/

#include <avr/io.h>
#include <avr/interrupt.h> // 인터럽트 관련 시스템 헤더 파일
#define F_CPU 7432800UL
#include <util/delay.h>

volatile unsigned char exchange = 0;

//INT4
SIGNAL(INT4_vect)
{
	exchange = ~exchange;		//2의 나머지로 구해도된다
}

int main(void)
{
	DDRE = 0x00; // 인터럽트 입력으로 E 포트를 사용 (INT4이므로)
	DDRA= 0xff;
	EICRB =(1 <<ISC41);	//0011	//EICRA = 0x03; //ob 0000 0011
	EIMSK = (1<<INT4);	//0001	  //1을 int0만큼 좌측으로 이동시켜라			//EIMSK = 0x01; // external interrupt 0 을 활성화


	sei();		//전체 인턻 활성화
	
	while(1)
	{
		if(exchange) PORTA = 0XFF;		//exchange가 0이면 불키고
		else PORTA =0x00;				//exchange 1이면 불을 꺼라
	}
	
}
