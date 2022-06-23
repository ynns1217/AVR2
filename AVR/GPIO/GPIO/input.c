/*
 * input.c
 *
 * Created: 2022-06-17 오후 3:20:12
 *  Author: PKNU
 */ 

#define F_CPU 7432800UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRD = 0x00;	//포트 D 입력으로 설정
	DDRA = 0xff;	//포트 A 출력으로 설정
	
	int led_data = 0x01; //0b 0000 0001
	int i;
	
	while(1)
	{
		for(i=0;i<8;i++)
		{
					if(PIND == led_data)
					{
						PORTA =led_data;	//포트D 입력값이 0x01이면 포트A의 0번 비트를 출력
						led_data<<=1;	//왼쪽으로 이동
						_delay_ms(300);
						PORTA = 0x00;
					}
					
		}
		

		//if(PIND == 0x01) 
		//{
			//PORTA =0x01;	//포트D 입력값이 0x01ㅣㅇ면 포트A의 0번 비트를 출력	
			//_delay_ms(300);
			//PORTA = 0x00;		
		//}
		//if(PIND == 0x02)
		//{
			//PORTA =0x02;	//포트D 입력값이 0x01ㅣㅇ면 포트A의 0번 비트를 출력
			//_delay_ms(300);
			//PORTA = 0x00;
		//}
		//if(PIND == 0x04)
		//{
			//PORTA =0x04;	//포트D 입력값이 0x01ㅣㅇ면 포트A의 0번 비트를 출력
			//_delay_ms(300);
			//PORTA = 0x00;
		//}
		//if(PIND == 0x08)
		//{
			//PORTA =0x08;	//포트D 입력값이 0x01ㅣㅇ면 포트A의 0번 비트를 출력
			//_delay_ms(300);
			//PORTA = 0x00;
		//}
		//if(PIND == 0x10) 
		//{
			//PORTA =0x10;	//포트D 입력값이 0x01ㅣㅇ면 포트A의 0번 비트를 출력	
			//_delay_ms(300);
			//PORTA = 0x00;		
		//}
		//if(PIND == 0x20)
		//{
			//PORTA =0x20;	//포트D 입력값이 0x01ㅣㅇ면 포트A의 0번 비트를 출력
			//_delay_ms(300);
			//PORTA = 0x00;
		//}
		//if(PIND == 0x40)
		//{
			//PORTA =0x40;	//포트D 입력값이 0x01ㅣㅇ면 포트A의 0번 비트를 출력
			//_delay_ms(300);
			//PORTA = 0x00;
		//}
		//if(PIND == 0x80)
		//{
			//PORTA =0x80;	//포트D 입력값이 0x01ㅣㅇ면 포트A의 0번 비트를 출력
			//_delay_ms(300);
			//PORTA = 0x00;
		//}
		
	}
	return 0;
}