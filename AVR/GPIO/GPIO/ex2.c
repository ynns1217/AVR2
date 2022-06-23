/*
 * ex2.c
 *
 * Created: 2022-06-20 오후 12:24:56
 *  Author: PKNU
 */ 

#define  F_CPU 7432800UL
#include <avr/io.h> // AVR 입출력에 대한 헤더 파일
#include <avr/interrupt.h> // AVR 인터럽트에 대한 헤더파일
#include <util/delay.h> // delay 함수사용을 위한 헤더파일
volatile unsigned char Shift_flag = 1;


SIGNAL(INT5_vect) // 인터럽트 서비스 루틴
{
	cli(); // 전체 인터럽트를 금지
	Shift_flag = 1; // Shift_flag에 1을 입력
	sei(); // 전체 인터럽트를 허용
}
SIGNAL(INT7_vect) // 인터럽트 서비스 루틴
{
	cli(); // 전체 인터럽트를 금지
	Shift_flag = 2; // Shift_flag에 2를 입력
	sei(); // 전체 인터럽트를 허용
}

int main(void) {
	unsigned char LED_Data = 0x01;
	DDRA = 0xFF; // 포트C 를 출력포트로 설정
	DDRE = 0x00; // 포트E 를 입력포트로 설정
	// 인터럽트 5를 하강에지, 7을 상승에지에서 동작하도록 설정
	EICRB = 0xC8;
	EIMSK = 0xA0; // 인터럽트 5, 7을 허용  1010 0000
	EIFR = 0xA0; // 인터럽트 5, 7 플래그를 클리어 1010 0000
	sei();
	while (1) {
		//포트C로 변수 LED_Data에 있는 데이타를 출력
		PORTA = LED_Data;
		if(Shift_flag == 1) // LED0 ~ LED7으로 이동
		{
			if(LED_Data == 0x80) LED_Data = 0x01;
			// LED_Data 값을 왼쪽으로 쉬프트
			else LED_Data <<= 1;
		}
		else if(Shift_flag == 2) // LED7 ~ LED0으로 이동
		{
			if(LED_Data == 0x01) LED_Data = 0x80; //1000 000
			else LED_Data >>= 1; // LED_Data 값을 오른쪽으로 쉬프트
		}
		_delay_ms(100);
	}
}