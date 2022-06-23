/*
 * keypad.c
 *
 * Created: 2022-06-23 오후 4:03:47
 *  Author: PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h> // AVR 입출력에 대한 헤더 파일
#include <util/delay.h> // delay 함수사용을 위한 헤더파일

unsigned char keyScan();

int main()
{
	unsigned key;
	DDRA = 0xF8;	//0b 1111 1000 -> 포트A의 상위 3비트는 출력(row),
					// 하위 4비트는 입력(col)으로 설정(포트 하나에 입출력 다 사용)
	DDRC = 0xFF;
						
	while(1)
	{
		key = keyScan();
		if(key == '1') PORTC = 0x01;
	
	}
	return 0;
		
}

unsigned char keyScan()
{
		PORTA = 0xF7;								//0b 1111 0111 ->
			if(PINA == 0xF6) return '1';				//0b 1111 0110
			else if (PINA == 0xFD) return '2';			//0b 1111 1101
			else if(PINA == 0xFB) return '3';			//0b 1111 1011
			_delay_ms(10);
		
		PORTA = 0xEF;								//0b 1110 1111 ->
			if(PINA == 0xFE)	return '4';				//0b 1111 1110
			else if (PINA == 0xFD) return '5';			//0b 1111 1101
			else if(PINA == 0xFB) return '6';			//0b 1111 1011
			_delay_ms(10);
		
		PORTA = 0xDF;								//0b 1101 1111 ->
			if(PINA == 0xFE) return '7';				//0b 1111 1110
			else if (PINA == 0xFD) return '8';			//0b 1111 1101
			else if(PINA == 0xFB) return '9';			//0b 1111 1011
			_delay_ms(10);
		
		PORTA = 0xBF;								//0b 1011 1111 ->
			if(PINA == 0xFE) return '4*';				//0b 1111 1110
			else if (PINA == 0xFD) return '0';			//0b 1111 1101
			else if(PINA == 0xFB) return '#';			//0b 1111 1011
			_delay_ms(10);	
}