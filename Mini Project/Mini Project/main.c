/*
* Mini Project.c
*
* Created: 2022-06-24 오전 9:34:22
* Author : PKNU
*/

#define  F_CPU 7372800UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Lcd.h"
#include <util/delay.h>

unsigned char piano=0;
unsigned int DoReMi[8] = {523,587, 659};
volatile unsigned char TX_flag = 0;
unsigned char bimilNum[5] ="1111";		//내 비밀번호
unsigned char key[5];						//눌러서 저장되는 비밀번호
unsigned char Num_TX =0;					//비밀번호 배열 번호 txt

void init_keypad()
{
	DDRC = 0xF8; //0b 1111 1000
	PORTC = 0x07; //0b 0000 0111
}

unsigned char keyscan()
{
	PORTC = 0x08; //0b 0000 1000
	_delay_ms(1);
	if((PINC & 0x07) == 0x01) return '1';
	else if((PINC & 0x07) == 0x02) return '2';
	else if((PINC & 0x07) == 0x04) return '3';
	_delay_ms(10);
	
	PORTC = 0x10;		// 0x10
	_delay_ms(1);
	if((PINC & 0x07) == 0x01) return '4';
	else if((PINC & 0x07) == 0x02) return '5';
	else if((PINC & 0x07) == 0x04) return '6';
	_delay_ms(10);
	
	PORTC = 0x20;		// 0x20
	_delay_ms(1);
	if((PINC & 0x07) == 0x01) return '7';
	else if((PINC & 0x07) == 0x02) return '8';
	else if((PINC & 0x07) == 0x04) return '9';
	_delay_ms(10);
	
	PORTC = 0x40;		// 0x40
	_delay_ms(1);
	if((PINC & 0x07) == 0x01) return '*';
	else if((PINC & 0x07) == 0x02) return '0';
	else if((PINC & 0x07) == 0x04) return '#';
	_delay_ms(10);
	
	return 0;
}

// 입력받은 키 배열 하나씩 반환
unsigned char insert_keypad()
{
	init_keypad();
	unsigned char tmp;
	unsigned char a;
	a=keyscan();
	tmp = a;
	
	return tmp;

}


//출력 함수
void putch(unsigned char data)
{
	while((UCSR0A & 0x20) == 0);		// 전송준비가 될때까지 대기
	UDR0 = data;						// 데이터를 UDR0에 쓰면 전송된다
	UCSR0A |= 0x20;
}

//putch()함수 문자열을 읽어 출력하는 함수
void putstr(char * str )
{
	
	unsigned char i = 0;
	while(str[i]!='\0')
	putch(str[i++]);
}

//입력함수
unsigned char getch(void)
{
	
	unsigned char data;
	while((UCSR0A & 0X80)==0);
	data = UDR0;
	UCSR0A |= 0x80;
	return data;
}

//통신
void tongsin()
{
	unsigned char txt[] = "Password >>>  \r\n";
	unsigned char dat[4];
	unsigned char i =0;
	
	DDRE = 0xfe; // Rx(입력 0), Tx(출력, 1)
	
	UCSR0A = 0x00;
	UCSR0B = 0x18; // Rx, Tx enable
	UCSR0C = 0x06; // 비동기 방식, No Parity bit, 1 Stop bit
	UBRR0H = 0x00;
	UBRR0L = 3; // 115200 bps
	
	//PW 출력
	while(txt[i]!='\0') // 문자열 데이터가 '\0'인 경우, 문자열 끝임
	{
		putch(txt[i++]); // 저장된 문자열 출력
	}
	
	i = 0;
	for(i=0;i<=4;i++)
	{
		dat[i] = getch();
		putch(dat[i]);
	}
	
	unsigned char *str = &dat;
	putstr(str); // 저장된 문자열 출력
}



//lcd
void lcd1()
{
	unsigned char *str1 = "Doorlock system";
	unsigned char *str2 = "Insert PW:";
	//unsigned char *str3;

	
	Lcd_Init(); //LCD 초기화
	Lcd_Clear();
	
	Lcd_Pos(0, 0); //커서 위치를 나타냄
	Lcd_STR(str1);
	
	Lcd_Pos(1, 0); //커서 위치를 나타냄
	Lcd_STR(str2);
	
	unsigned char a = insert_keypad();
	if(a != 0)
	{
		
		key[Num_TX] = a;
		Lcd_Pos(1,10); //커서 위치를 나타냄
		Lcd_STR(key);
		_delay_ms(1000);
		Num_TX++;
	}
}

void open_lcd()
{
	unsigned char *str = "open";
	
	Lcd_Init(); //LCD 초기화
	Lcd_Clear();
	
	Lcd_Pos(0, 0); //커서 위치를 나타냄
	Lcd_STR(str);
	_delay_ms(1000);
}
void error_lcd()
{
	unsigned char *str = "Error number";
	
	Lcd_Init(); //LCD 초기화
	Lcd_Clear();
	
	Lcd_Pos(0, 0); //커서 위치를 나타냄
	Lcd_STR(str);
	_delay_ms(1000);
}

//모터
void motor()
{
	
	while (1) {
		PORTD = 0x10;			// 1 step
		_delay_ms(100);
		PORTD = 0x20;			// 2 step
		_delay_ms(100);
		PORTD = 0x40;			// 3 step
		_delay_ms(100);
		PORTD = 0x80;			// 4 step
		_delay_ms(100);
	}
}


//소리
void sound1()
{

	while(1)
	{
		ICR3 = 7372800/DoReMi[piano]/4; // 버튼에 맞는 음향을 연주
		OCR3C = ICR3/4; // 50% 듀티비
		piano++;		// piano 변수 1증가
		if(3 < piano)	piano = 0;
		_delay_ms(200);
	}
	
}

void sound2()
{
	while(1)
	{
		ICR3 = 7372800/DoReMi[piano]/4; // 버튼에 맞는 음향을 연주
		OCR3C = ICR3/4; // 50% 듀티비
		piano++;		// piano 변수 1증가
		if(3 < piano)	piano = 0;
		_delay_ms(200);
	}
	
}


int main(void)
{
	DDRD = 0xF0;				// STEP 0~STEP 3을 출력 포트로 설정
	DDRA = 0xFF;
	DDRG = 0x0F;
	DDRE = 0x08; // e출력
	
	TCCR3A = 0x40;
	TCCR3B = 0x19;
	TCCR3C = 0x00; // WGM3(3:0) = “1110”, Fast PWM, 모드 14	
	TCNT3 = 0x0000; // 타이머3 카운터 초기화
	
	while(1)
	{

					lcd1();
		if (Num_TX == 4)
		{

			if(strcmp(key,bimilNum) == 0)
			{
				motor();
				sound1();
				open_lcd();
				break;
			}
			
			else
			{
				error_lcd();
				sound2();
				break;
			}
			Num_TX =0;
		}		
	}
	
	//tongsin();
	
	return 0;
}

