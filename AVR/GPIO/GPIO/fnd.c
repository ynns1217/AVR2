/*
* fnd.c
*
* Created: 2022-06-17 오후 4:21:33
*  Author: PKNU
*/

#define F_CPU 7432800UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRD = 0x00;	//포트 D 입력으로 설정
	DDRA = 0xff;	//포트 A 출력으로 설정
	
	int a[]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27}; //1-7 숫자 배열
	int button[] = {0x01, 0x02, 0x04, 0x08,0x10,0x20,0x40,0x80};		//첫 버튼값	
	int i=0;
	
	while(1)
	{		
		if(PIND ==button[i])	
		{			
			PORTA = a[i];	//포트a에 배열a의 i번째(0)(1) 인덱스 출력
				// i 1증가 (i=1)			
		}
		i++;
		
					//if(PIND ==button)	//0x02 버튼값 들어오면 (0x04)
					//{
						//PORTA = a[i];	//포트a에 배열a의 i번째(0)(1) 인덱스 출력
						//i++;	// i 1증가 (i=1)
						//button<<=1; //버튼 왼쪽으로 1 쉬프트 0x04
						//_delay_ms(300);	//3초 지연하고
						//PORTA =0x00;	//포트a가 꺼진다.
					//}

		//if(PIND ==0x02)
		//{
		//PORTA = 0x06; //0b 000 0110
		//_delay_ms(300);
		//PORTA =0x00;
		//}
		//
		//if(PIND == 0x04)
		//{
		//PORTA = 0x5b; //0b 0011 1111
		//_delay_ms(300);
		//PORTA =0x00;
		//}
		//
		//if(PIND == 0x08)
		//{
		//PORTA = 0x4f; //0b 0011 1111
		//_delay_ms(300);
		//PORTA =0x00;
		//
		//}
		//
		//if(PIND == 0x10)
		//{
		//PORTA = 0x66; //0b 0011 1111
		//_delay_ms(300);
		//PORTA =0x00;
		//
		//}if(PIND == 0x20)
		//{
		//PORTA = 0x6d; //0b 0011 1111
		//_delay_ms(300);
		//PORTA =0x00;
		//
		//}if(PIND == 0x40)
		//{
		//PORTA = 0x7d; //0b 0011 1111
		//_delay_ms(300);
		//PORTA =0x00;
		//
		//}
		//if(PIND == 0x80)
		//{
		//PORTA = 0x27; //0b 0011 1111
		//_delay_ms(300);
		//PORTA =0x00;
		//
		//}
		
		
		//PORTA = 0x3f; //0b 0011 1111
		//_delay_ms(300);
		//
		//PORTA = 0x06; //0b 000 0110
		//_delay_ms(300);
		//PORTA = 0x5B; //0b 0101 1011
		//_delay_ms(300);
		//
		//PORTA = 0x4f; //0b 0100 1111
		//_delay_ms(300);
		//
		//PORTA = 0x66; //0b 0110 0110
		//_delay_ms(300);
		//
		//PORTA = 0x6d; //0b 0110 1101
		//_delay_ms(300);
		//
		//PORTA = 0x7d; //0b 0111 1101
		//_delay_ms(300);
		//
		//PORTA = 0x27; //0b 0010 1110
		//_delay_ms(300);
		//
		//PORTA = 0x7f; //0b 0111 1111
		//_delay_ms(300);
		//
		//PORTA = 0x6f; //0b 0011 1111
		//_delay_ms(300);
		//
		
		//if(PIND==0x01)
		//{
		//PORTA = 0x3f; //0b 0011 1111
		//_delay_ms(300);
		//PORTA = 0x00;
		//}
		//if(PIND == 0x01)
		//{
		//PORTA =0x01;	//포트D 입력값이 0x01ㅣㅇ면 포트A의 0번 비트를 출력
		//_delay_ms(300);
		//PORTA = 0x00;
		//}		
	}
	return 0;
}
