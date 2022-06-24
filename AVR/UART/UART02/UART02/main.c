/*
 * UART02.c
 *
 * Created: 2022-06-21 오전 10:56:34
 * Author : PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h>				//AVR 입출력에 대한 헤더 파일
#include <avr/interrupt.h>		//AVR 인터럽트에 대한 헤더 파일


volatile unsigned char TX_flag = 0;
volatile char TX_data =0;

void putch(unsigned char data)
{
	while((UCSR0A & 0x20) == 0);		//전송준비가 될때 까지 대기
	UDR0 = data;						//데이터를 URR0에 쓰면 전송
	UCSR0A |= 0x20;
}
void putch_Str(char *str)
{
	unsigned char i =0;
	while(str[i]!='\0')
	putch(str[i++]);
}
SIGNAL(INT4_vect)		// 인터럽트 서비스 루틴
{
	cli();				// 전체 인터럽트를 금지
	TX_data = '0';		 // 문자 0을 저장
	TX_flag = 1;
	sei();				// 전체 인터럽트를 허용
}
SIGNAL(INT5_vect)		// 인터럽트 서비스 루틴
{
	cli();				// 전체 인터럽트를 금지
	TX_data = '1';		// 문자 1을 저장
	TX_flag = 1;
	sei();				// 전체 인터럽트를 허용
}
SIGNAL(INT6_vect)		// 인터럽트 서비스 루틴
{
	cli();				// 전체 인터럽트를 금지
	TX_data = '2';		// 문자 2을 저장
	TX_flag = 1;
	sei();				// 전체 인터럽트를 허용
}
SIGNAL(INT7_vect)		// 인터럽트 서비스 루틴
{
	cli();				// 전체 인터럽트를 금지
	TX_data = '3';		// 문자 3을 저장
	TX_flag = 1;
	sei();				// 전체 인터럽트를 허용
}
int main(void)
{	
	DDRE = 0x02;				// Rx(입력 0), Tx(출력, 1), SW0 ~ 3 입력
	UCSR0A = 0x00;
	UCSR0B = 0x18;				// Rx, Tx enable
	UCSR0C = 0x06;				// 비동기 방식, No Parity bit, 1 Stop bit
	UBRR0H = 0x00;
	UBRR0L = 3;					//115200bps
	EICRB = 0xFF;				// 인터럽트 4, 5, 6, 7을 상승엣지에서 동작하도록 설정한다.
	EIMSK = 0xF0;				// 인터럽트 4, 5, 6, 7을 허용
	EIFR = 0xF0;				// 인터럽트 4, 5, 6, 7 플래그를 클리어
	sei();						// 전체 인터럽트를 허용
    while (1) 
    {
		if(TX_flag == 1)
		{
			putch_Str("\n\r Input Switch : ");
			putch(TX_data);
			TX_flag = 0;
		}
	}
}

