/*
 * ex3.c
 *
 * Created: 2022-06-20 오후 1:52:57
 *  Author: PKNU
 */ 

#define  F_CPU 7432800UL
#include <avr/io.h> // AVR 입출력에 대한 헤더 파일
#include <avr/interrupt.h> // AVR 인터럽트에 대한 헤더파일
#include <util/delay.h> // delay 함수사용을 위한 헤더파일
volatile unsigned char Time_STOP = 0;

SIGNAL(INT5_vect) // 인터럽트 서비스 루틴
{
	cli(); // 전체 인터럽트를 금지
	if(Time_STOP == 0) // Time_Stop이 0인 경우
	{
		Time_STOP = 1; // Time_Stop에 1을 입력
	}
	else // Time_Stop이 1인 경우
	{
		Time_STOP = 0; // Time_Stop에 0을 입력
	}
	sei(); // 전체 인터럽트를 허용
}

int main(void) {
	// 7-Segment에 표시할 글자의 입력 데이터를 저장
	
	unsigned char FND_DATA_TBL []={0x3F,0X06,0X5B,0X4F,0X66,0X6D,
		0X7C,0X07,0X7F,0X67,0X77,0X7C,
	0X39,0X5E,0X79,0X71,0X08};
	
	unsigned char cnt=0; // FND Table 카운터 변수
	
	DDRA = 0xFF; // 포트A 를 출력포트로 설정
	DDRE = 0x00; // 포트E 를 입력포트로 설정
	
	EICRB = 0x0C; // 인터럽트 5를 상승엣지에서 동작하도록 설정
	EIMSK = 0x20; // 인터럽트 5를 허용
	EIFR = 0x20; // 인터럽트 5 플래그를 클리어
	sei(); // 전체 인터럽트를 허용
	
	while (1) {
		PORTA = FND_DATA_TBL[cnt]; // 포트A에 FND Table 값을 출력
		if(Time_STOP == 0) // Time_Stop이 0인 경우
		{
			cnt++; // FND Table 카운터 변수를 증가
			if(cnt>16) cnt=0; // 테이블 크기를 초과하는 경우 방지
		}
		_delay_ms(200);
	}
}