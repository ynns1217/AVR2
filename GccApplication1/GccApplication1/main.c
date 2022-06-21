/*
 * GccApplication1.c
 *
 * Created: 2022-06-21 오후 3:36:16
 * Author : PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char LED_Data = 0x00;
unsigned char timer0Cnt=0;

SIGNAL(TIMER0_OVF_vect); // Timer0 Overflow0 ISP

int main(void)
{
	DDRA = 0xFF;			//PORTA를 출력으로 설정
	TCCR0 = 0x07;
	TCNT0 =183;				// 256-144=112 -> 0.01초 마다 한번씩 인터럽트 발생
	TIMSK = 0x01;			//타이머/카운터0 오버플로우 인터럽트 Enable
	TIFR |=1 << TOV0;		//타이머/카운터0 2에서 오버플로우가 발생하면 이 비트가 “1”로 세트되어 오버플로우 인터럽트가 발생
	sei();

    while (1) 
    {
	PORTA = LED_Data;		//PORTA로 변수 LED_DATA 출력
    }

}

SIGNAL(TIMER0_OVF_vect) {
	
    cli();
    TCNT0 = 183; // 256-144=112 -> 0.01초 마다 한번씩 인터럽트 발생
    timer0Cnt++; // timer0Cnt 변수를 1 증가
	
    if(timer0Cnt == 100) { // 0.01s*100=1s를 얻기 위한 카운트 횟수
        LED_Data++; // LED_Data 변수를 1 증가
        if(LED_Data>0xFF) 
			LED_Data = 0;
        timer0Cnt = 0;
    }
	
    sei();

}

