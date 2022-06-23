/*
 * tesst02.c
 *
 * Created: 2022-06-17 오후 1:59:52
 * Author : PKNU
 */ 

#define F_CPU 7432800
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	char num = 0x01 ;  // 0x 0 0 (0x F F) F = 0000 0001
	char num2 = 0x80;  // F = 1111 0000 
    DDRA = 0xff;	   // 1111 1111 모두 출력
	DDRD = 0xff;
    while (1)		   // 전원이 꺼지기 전까지 계속 실행
    {		
        for (char i =0; i<8 ; i++)  // i는 0부터 시작 i가 8번반복될때까지 i 1증가시킨다.
		{		
				PORTA = num << i ;  //a포터에 0x 0000 0001에서 -> i만큼 왼쪽으로 쉬프트시킨다.
				_delay_ms(1000);	// 1초 지연
		}
		for(char i=0; i<8 ; i++)   // i는 0부터 시작 i가 8번반복될때까지 i 1증가시킨다.
		{
			PORTA = num2 >> i;     //a포터에 0x 1000 000에서 -> i만큼 오른쪽으로 쉬프트시킨다. 
			_delay_ms(1000);       // 1초 지연
		}
		for(char i=0; i<8 ; i++)  // i는 0부터 시작 i가 8번반복될때까지 i 1증가시킨다.
		{
			PORTA = ~(num << i);  // 1111 1110 -> 0을 i 만큼 오른쪽으로 쉬프트
			_delay_ms(1000);      // 1초지연
		}
		for(char i=0; i<8 ; i++)
		{
			PORTA = ~(num2 >> i);  // 0111 1111 -> 0을 i만큼 왼쪽으로 쉬프트
			_delay_ms(1000);
		}
		
	}
		return 0;
}
	


