﻿/*
 * PwmPiezo_Application.c
 *
 * Created: 2022-06-23 오전 10:10:55
 *  Author: PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h> // AVR 입출력에 대한 헤더 파일
#include <avr/interrupt.h> // AVR 인터럽트에 대한 헤더파일
#include <util/delay.h> // delay 함수사용을 위한 헤더파일

//피아노 음계에 해당하는 PWM 주파수
unsigned int DoReMi[8] = {523, 587, 659, 698, 783,880, 987, 1046};
volatile unsigned char sound_flag = 1;

int main(void)
{
	DDRE = 0x08; // 포트E PE3를 출력 나머지는 입력포트로 설정한다.
	// Buzzer를 PE3에 연결
	
	TCCR3A = 0x00; // WGM3(1:0) = “00”
	TCCR3B = 0x19; // WGM3(3:2) = “11” , CS3(2:0) = “001” 1분주 사용
	TCCR3C = 0x00; // WGM3(3:0) = “1110”, Fast PWM, 모드 14
	
	TCNT3 = 0x0000; // 타이머3 카운터 초기화

	EICRA = 0xFF;
	EICRB = 0xFF; // 인터럽트 4, 5, 6, 7을 상승엣지에서 동작하도록 설정한다.
	EIMSK = 0xFF; // 인터럽트 4, 5, 6, 7을 허용
	EIFR = 0xFF; // 인터럽트 4, 5, 6, 7 플래그를 클리어
	
	sei();
	while(1)
	{
		if(sound_flag)
		{
			_delay_ms(500); // 2초 지연
			TCCR3A = 0x00; // 부저 소리를 끈다.
			sound_flag = 0;
		}
	}
}
SIGNAL(INT0_vect) // 인터럽트 서비스 루틴
{
	cli(); // 전체 인터럽트를 금지
	ICR3 = 7372800/DoReMi[0]/4; // 도의 음향을 연주한다
	TCCR3A = 0x40; // PE4로 출력
	sound_flag = 1; // 부저 음이 발생하도록 설정
	sei(); // 전체 인터럽트를 허용
}
SIGNAL(INT1_vect) // 인터럽트 서비스 루틴
{
	cli(); // 전체 인터럽트를 금지
	ICR3 = 7372800/DoReMi[1]/4; // 래의 음향을 연주한다
	TCCR3A = 0x40; // PE4로 출력
	sound_flag = 1; // 부저 음이 발생하도록 설정
	sei(); // 전체 인터럽트를 허용
}
SIGNAL(INT2_vect) // 인터럽트 서비스 루틴
{
	cli(); // 전체 인터럽트를 금지
	ICR3 = 7372800/DoReMi[2]/4; // 도의 음향을 연주한다
	TCCR3A = 0x40; // PE4로 출력
	sound_flag = 1; // 부저 음이 발생하도록 설정
	sei(); // 전체 인터럽트를 허용
}
SIGNAL(INT3_vect) // 인터럽트 서비스 루틴
{
	cli(); // 전체 인터럽트를 금지
	ICR3 = 7372800/DoReMi[3]/4; // 래의 음향을 연주한다
	TCCR3A = 0x40; // PE4로 출력
	sound_flag = 1; // 부저 음이 발생하도록 설정
	sei(); // 전체 인터럽트를 허용
}


	SIGNAL(INT4_vect) // 인터럽트 서비스 루틴
	{
		cli(); // 전체 인터럽트를 금지
		ICR3 = 7372800/DoReMi[4]/4; // 도의 음향을 연주한다
		TCCR3A = 0x40; // PE4로 출력
		sound_flag = 1; // 부저 음이 발생하도록 설정
		sei(); // 전체 인터럽트를 허용
	}
	SIGNAL(INT5_vect) // 인터럽트 서비스 루틴
	{
		cli(); // 전체 인터럽트를 금지
		ICR3 = 7372800/DoReMi[5]/4; // 래의 음향을 연주한다
		TCCR3A = 0x40; // PE4로 출력
		sound_flag = 1; // 부저 음이 발생하도록 설정
		sei(); // 전체 인터럽트를 허용
	}
	SIGNAL(INT6_vect) // 인터럽트 서비스 루틴
	{
		cli(); // 전체 인터럽트를 금지
		ICR3 = 7372800/DoReMi[6]/4; // 미의 음향을 연주한다
		TCCR3A = 0x40; // PE4로 출력
		sound_flag = 1; // 부저 음이 발생하도록 설정
		sei(); // 전체 인터럽트를 허용
	}
	SIGNAL(INT7_vect) // 인터럽트 서비스 루틴
	{
		cli(); // 전체 인터럽트를 금지
		ICR3 = 7372800/DoReMi[7]/4; // 파의 음향을 연주한다
		TCCR3A = 0x40; // PE4로 출력
		sound_flag = 1; // 부저 음이 발생하도록 설정
		sei(); // 전체 인터럽트를 허용
	}
