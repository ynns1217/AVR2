/*
* count.c
*
* Created: 2022-06-17 오후 6:18:36
*  Author: PKNU
*/
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 7432800UL
#define  COUNT 100

int main()
{
	DDRA = 0xff;	//포트 A 출력으로 설정
	DDRC = 0xff;	//포트 A 출력으로 설정
	int count = COUNT;
	int a[]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f}; //1-9 숫자 배열
	while(1)
	{
		//PORTC =0x03;		//20	1101
		//PORTA=a[1];
		//PORTA=0x00;
		//
		//PORTC =0x0b;		//1011 11
		//PORTA=a[0];
		//PORTA=0x00;
		//
		//PORTC =0x07;		//1
		//PORTA=a[0];
		//PORTA=0x00;
		
		  int hun;
		  int ten;
		  int il ;


		  if (count == 100)
		  {
			  
			  hun = a[1];
			  ten = a[0];
			  il = a[0];
			PORTC =0x03;		//20	1101
			  PORTA = hun;
		PORTA=0x00;
		
			  PORTA = ten;
			  PORTA=  il;
		  }
		  count--;

		  ten = count / 10;
		  il = count % 10;

		  cout << a[ten];
		  //delay(1000);
		  //멈춤

		  cout << a[il];
		  //delay(1000);
		  //멈춤
		  il--;
		  
		  if (il == 0)
		  {
			  ten--;
			  //hun = 0x00;
			  //delay(1000);
			  //멈춤
			  cout << a[ten];
			  //delay(1000);
			  //멈춤

			  cout << a[il];
			  //delay(1000);
			  //멈춤
		  }

	  }


		
		//int bac= Num/100;
		//int sib =Num/10;
		//int il = Num%10;
		//Num--;
		//
		//
		//PORTC =0x03;		//1의자리 1110
		//PORTA=a[count];
		//count--;
		//_delay_ms(2000);
		//PORTA=0x00;
		//
		//if(PORTA=a[0])
		//{
		//
		//PORTC =0x0b;		//1의자리 1110
		//PORTA=a[count];
		//count--;
		//_delay_ms(2000);
		//PORTA=0x00;
		//}
		//
		
		
		
		
		//PORTC=0x5b;		//0b 0101 1011			//위치
		//PORTA=0x6f;
		//PORTC =0x07;	0111	//1의자리
		
	}
	
	//DDRD = 0x00;	//포트 D 입력으로 설정
	//DDRA = 0xff;	//포트 A 출력으로 설정
	//
	//int a[]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x27}; //1-7 숫자 배열
	//int button[] = {0x01, 0x02, 0x04, 0x08,0x10,0x20,0x40,0x80};		//첫 버튼값
	//int i=0;
	//
	//while(1)
	//{
	//if(PIND ==button[i])
	//{
	//PORTA = a[i];	//포트a에 배열a의 i번째(0)(1) 인덱스 출력
	//// i 1증가 (i=1)
	//}
	//i++;
	//}
	return 0;
}