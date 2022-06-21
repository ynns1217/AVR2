/*
 * Test1.c
 *
 * Created: 2022-06-17 오전 11:46:04
 *  Author: PKNU
 */ 
#define F_CPU 7372800
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRA =0xFF;  //포트A를 출력으로 설정 0b 1111 1111로 값을 집어 넣음 
				 // 0x0F라면 0000 1111  
//DDRB =0xFF;  //포트B
// 	DDRC =0xFF;  //포트C
// 	DDRD =0xFF;  //포트D
// 	DDRE =0xFF;  //포트E
// 	DDRF =0xFF;  //포트F
// 	DDRG =0xFF;  //포트G
				
	while(1)
	{
		PORTA = 0x0F ; //포터A의 각 비트에 5V 출력을 설정한다
		_delay_ms(1000);
		PORTA = 0x00 ;
		_delay_ms(1000);
// 		PORTB = 0xFF ; //포터B
// 		PORTC = 0xFF ; //포터C
// 		PORTD = 0xFF ; //포터D
// 		PORTE = 0xFF ; //포터E
// 		PORTF = 0xFF ; //포터F
// 		PORTG = 0xFF ; //포터G
	}
	return 0;
}
