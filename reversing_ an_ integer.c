#include<stdio.h>
int main()
{
	int n,reversedNumber=0,remainder;
	int*pn,*prn,*pr;
	pn=&n;
	prn=&reversedNumber;
	pr=&remainder;
	printf("enter an integer:");
	scanf("%d",pn);
	while(*pn!=0)
	{
		*pr=*pn%10;
		*prn=*prn*10+*pr;
		*pn=*pn/10;
	}
	printf("Reversed number=%d",*prn);
	return 0;
}
