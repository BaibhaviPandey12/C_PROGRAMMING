#include<stdio.h>
int main()
{
	int x=10;
	char ch ='A';
	void*gp;
	gp=&x;
	printf("\n generic pointer points to the integer value = %d",*(int*)gp);
	gp=&ch;
	printf("\n generic pointer points to the integer value = %c",*(char*)gp);
	return 0;
}
