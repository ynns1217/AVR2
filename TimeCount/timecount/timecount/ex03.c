/*
* ex03.c
*
* Created: 2022-06-22 오후 3:22:18
*  Author: PKNU

실행 결과
– 1초마다 FND의 숫자가 증가(‘0’ ~ ’_’ 까지)

*/
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 7372800UL


unsigned char FND_DATA_TBL[] = {0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7C,
								0X07,0X7F,0X67,0X77,0X7C,0X39,0X5E,
								0X79,0X71,0X08,0X80};

volatile unsigned char time_s = 0;		//초를 세는 변수

int main(void)
{
	
	DDRA = 0xFF;			// 포트A를 출력포트로 설정
	
	TCCR1A =0x00;
	TCCR1B = 0x05;			//프리스케일러 분주 1024 //101
	
	OCR1A = 7200;		//1초 마다 한번씩 인터럽트 발생
	
	// 비교출력 인터럽트 enable
	TIMSK = (1 << OCIE1A);
	TIFR |= (1 << OCF1A);
	
	sei();
	while(1)
	{
		
		PORTA = FND_DATA_TBL[time_s];		//포트A에 FND Table 값을 출력
	}
	return 0;
}
SIGNAL (TIMER1_COMPA_vect)
{
	cli();
	
	OCR1A += 7200;			//1초 후에 인터럽트 발생
	if(time_s>=17)
	time_s =0;				//time_s 변수는 17까지만 증가
	else
	time_s++;				//17되면 0으로 초기화
	
	sei();
	
}