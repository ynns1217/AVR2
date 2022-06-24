/*
* keyDoReMe.c
*
* Created: 2022-06-23 오전 11:04:26
*  Author: PKNU

키보드 입력 소리출력
통신 HyperTerminal
*/

#define F_CPU 7372800UL
#include <avr/io.h> // AVR 입출력에 대한 헤더 파일
#include <avr/interrupt.h> // AVR 인터럽트에 대한 헤더파일
#include <util/delay.h> // delay 함수사용을 위한 헤더파일

//피아노 음계에 해당하는 PWM 주파수
unsigned int DoReMi[8] = {523, 587, 659, 698, 783,880, 987, 1046};
volatile unsigned char sound_flag = 1;
int Num[8]={0,1,2,3,4,5,6,7};


void putct(unsigned char data)
{
	while((UCSR0A & 0x20) == 0);			//전송대기
	UDR0 = data;							//데이터 전송
	UCSR0A |=0x20;							// UCSR0A 레지스터 중에서 5번째 비트(UDREn) 를 세트하여 UDRE0를 클리어 함. */ 0010 0000
	}
	
	unsigned char getch()
	{
	unsigned char data;
	while((UCSR0A & 0x80) == 0);				// 송신 대기
	data = UDR0;							// 송신된 데이터 저장
	UCSR0A |= 0x80;							// 7번째 비트 세트
	return data;							//데이터 반환
	}




	int main(void)
	{
	//DDRE = 0x08; // 포트E PE3를 출력 나머지는 입력포트로 설정한다.
	
	DDRE = 0xfe;			//E포트 사용, Rx(입력0), Tx(출력 1)

	UCSR0A = 0x00;
	UCSR0B = 0x18;		// Rx, Tx enable
	UCSR0C = 0x06;		// 비동기 방식, No Parity bit, 1 Stop bit
	UBRR0H = 0x00;
	UBRR0L = 3;		// 115200 bps
	
	TCCR3A = 0x00; // WGM3(1:0) = “00”
	TCCR3B = 0x19; // WGM3(3:2) = “11” , CS3(2:0) = “001” 1분주 사용
	TCCR3C = 0x00; // WGM3(3:0) = “1110”, Fast PWM, 모드 14
	
	TCNT3 = 0x0000; // 타이머3 카운터 초기화


	
	while(1)
	{
	unsigned char dat = getch();
	putct(dat);
		
	if(dat==48)
	{
	ICR3 = 7372800/DoReMi[0]/8; // 도의 음향을 연주한다
	}
	else if(dat ==49)
	{
	ICR3 = 7372800/DoReMi[1]/8; // 도의 음향을 연주한다
	}
	else if(dat ==50)
	{
	ICR3 = 7372800/DoReMi[2]/8; // 도의 음향을 연주한다
	}
	else if(dat ==51)
	{
	ICR3 = 7372800/DoReMi[3]/8; // 도의 음향을 연주한다
	}
	else if(dat ==52)
	{
	ICR3 = 7372800/DoReMi[4]/8; // 도의 음향을 연주한다
	}
	else if(dat ==53)
	{
	ICR3 = 7372800/DoReMi[5]/8; // 도의 음향을 연주한다
	}
	else if(dat ==54)
	{
	ICR3 = 7372800/DoReMi[6]/8; // 도의 음향을 연주한다
	}
	else if(dat ==55)
	{
	ICR3 = 7372800/DoReMi[7]/8; // 도의 음향을 연주한다
	}

	
	TCCR3A = 0x40; // PE4로 출력
	sound_flag = 1; // 부저 음이 발생하도록 설정
	
	if(sound_flag)
	{
	_delay_ms(200); 
	TCCR3A = 0x00; // 부저 소리를 끈다.
	sound_flag = 0;
	}
	
	
	}



