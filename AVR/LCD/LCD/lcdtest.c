/*
* lcdtest.c
*
* Created: 2022-06-20 오후 2:54:44
*  Author: PKNU
*/

#define F_CPU 7372800UL
#include <avr/io.h>
#include <avr/delay.h>
#include "Lcd.h"

int main()
{
	
	//Byte *str1 = " LCD TEST";
	//Byte *str2 = " ATmage 128";
	
	Byte str1[16];
//Byte str2[16];
//Byte str3[16];
//Byte *str4=" * ";
//Byte *str5=" = ";

//int i =2;
//int j =4;
//int b =0;
	
	DDRA = 0xFF;		//포트A를 출력포트로 지정
	DDRG = 0xFF;
	
	Lcd_Init();		//lcd 초기화
	Lcd_Clear();
	Lcd_Clear();
	
//for (int i; i<10;i++)
//{
	//
	//for(int j; j<10;j++)
	//{
		//b = i*j;
		//itoa(b,str1,10);
	//}
//}
		//b = i*j;
//itoa(i,str2,10);
//itoa(j,str3,10);
//itoa(b,str1,10);

	while(1)
	{
		//Lcd_Pos(0,0);		//lcd 위치 지정
		//Lcd_STR(str1);		//문자열 출력;
		//
		//Lcd_Pos(1,0);		//lcd 위치 지정
		//Lcd_STR(str2);		//문자열 출력;

		for (int i; i<=9;i++)
		{
			for(int j; j<=9;j++)
			{
				Lcd_Pos(0,0);
				
				sprintf(str1,"%d * %d = %d" ,i,j,i*j);
				Lcd_STR(str1);
				_delay_ms(500);
			}
		}

	}
	return 0;
}