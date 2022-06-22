/*
 * PWM.c
 *
 * Created: 2022-06-22 오후 4:24:23
 * Author : PKNU
 
 실행 결과
 – LED 가 어두워졌다 밝아짐
 */ 
#define F_CPU 7372800UL
#include <avr/io.h> // AVR 입출력에 대한 헤더 파일
#include <util/delay.h> // delay 함수사용을 위한 헤더파일

int main(void)
{
	unsigned char Light=0;
	
	DDRB = 0x10; // 포트A 를 출력포트로 설정
	
	TCCR0 = 0x76; // PC PWM 모드, 256 분주 ==> 14.4 KHz : 0, 2 8bit 1, 3 16
	//FOCn WGMn0 COMn1 COMn0 WGMn1 CSn2 CSn1 CSn0
	//(1<<WGMn1) | (1<<CSn2) | (1<<CSn1) | (1<<CSn0)
	TCNT0 = 0x00; // 타이머0 카운터를 초기화
	
	while (1)
	{
		for(Light=0;Light<255;Light++)
		{
			OCR0 = Light;
			_delay_ms(5);
		}
		for(Light=255;0<Light;Light--)
		{
			OCR0 = Light;
			_delay_ms(5);
		}
	}
}