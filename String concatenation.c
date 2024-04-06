#include<stdio.h>
#include<string.h>
int main()
{
	char str1[15],str2[15];
	int n;
	printf("\n enter source string:");
	gets(str1);
	printf("\n enter destination string:");
	gets(str2);
strcat(str1,str2);
	printf("\n string after concatenation:%s",str1);


	return 0;
	
}
