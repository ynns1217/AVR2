/*
 * Interupt.c
 *
 * Created: 2022-06-20 오전 9:57:29
 *  Author: PKNU
 */ 


#include <avr/io.h>
#include <avr/interrupt.h> // 인터럽트 관련 시스템 헤더 파일
#define F_CPU 7432800UL
#include <util/delay.h>

volatile unsigned char count = 0;

SIGNAL(INT0_vect)
{
	count++;
	PORTA = count;		//포트A 를 출력으로
}

int main(void)
{
	DDRD = 0x00; // 인터럽트 입력으로 D 포트를 사용
	DDRA= 0xff;	
	EICRA =(1 <<ISC01) | (1<<ISC00);	//0011	//EICRA = 0x03; //ob 0000 0011
	EIMSK = (1<<INT0);	//0001	  //1을 int0만큼 좌측으로 이동시켜라			//EIMSK = 0x01; // external interrupt 0 을 활성화
	sei();		//전체 인턻 활성화
	
	while(1)
	{}
	
}
//LED =1;
//LED <<1;
