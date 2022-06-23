﻿/*
 * PwmPiezo_Example.c
 *
 * Created: 2022-06-23 오전 9:32:16
 *  Author: PKNU
 
 실행 결과
 – PIEZO에서 ‘도레미파솔라시도’ 소리가 출력
 */ 

#define  F_CPU 7372800UL
#include <avr/io.h> // AVR 입출력에 대한 헤더 파일
#include <util/delay.h> // delay 함수사용을 위한 헤더파일
// 피아노 음계에 해당하는 PWM 주파수
unsigned int DoReMi[8] = {523,587, 659, 698, 783,880, 987, 1046};
//{32,36,41,43,48,55,61};
	
int main(void)
{
	unsigned char piano=0;
	DDRB = 0x80; // PWM 출력, OCR1C
	TCCR1A |= 0x0A; // COM1C(1:0)=“10”, OC1C핀사용, WGM3(1:0)=“10”
	TCCR1B |= 0x19; // WGM3(3:2)=“11”, CS3(2:0)=“001” 1분주 사용
	TCCR1C = 0x00; // WGM3(3:0)=“1110”, Fast PWM, 모드 14
	TCNT1 = 0x0000; // 타이머1 카운터 초기화
	
	while(1)
	{
		ICR1 = 14745600/DoReMi[piano]; // 버튼에 맞는 음향을 연주
		OCR1C = ICR1/4; // 50% 듀티비
		piano++;		// piano 변수 1증가
		if(8 < piano) piano = 0; // piano가 9가 되면 초기화
		_delay_ms(500);
	} 
}
	