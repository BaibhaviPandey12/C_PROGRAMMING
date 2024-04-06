#include<stdio.h>
int main()
{
	int a;
	int *aPtr;
	a=7;
	aPtr=&a;
	
printf("the address of a is %p""\n the value of aPtr is %p",&a,aPtr );
printf("\n the value of a is %d""\n the value of aPtr is %d",a,*aPtr );
printf("\n showing that * and & are complement of""each other \n&*aPtr = %p""\n*&aPtr=%p",&*aPtr,*&aPtr );
	   return 0;
}
       
