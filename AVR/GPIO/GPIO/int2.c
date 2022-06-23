/*
* int2.c
*
* Created: 2022-06-20 오전 11:23:05
*  Author: PKNU
*/

#include <avr/io.h>
#include <avr/interrupt.h> // 인터럽트 관련 시스템 헤더 파일
#define F_CPU 7432800UL
#include <util/delay.h>

volatile unsigned char count = 0;

//INT4
SIGNAL(INT4_vect)
{
	count++;
}

int main(void)
{
	DDRE = 0x00; // 인터럽트 입력으로 E 포트를 사용 (INT4이므로)
	DDRA= 0xff;	//출력포트로 사용
	EICRB =(1 <<ISC41);	//0010	//EICRA = 0x03; //ob 0000 0011
	EIMSK = (1<<INT4);	//0001	  //1을 int4만큼 좌측으로 이동시켜라			//EIMSK = 0x01; // external interrupt 0 을 활성화
	// 인터럽트 4를 허용

	sei();		//전체 인턻 활성화
	
	while(1)
	{
			PORTA =count;
			
		if(!EIMSK)
		{
			PORTA =0x00;
		}
		else
		{
			
			PORTA =count;
		}
	}
	
	return 0;
}
