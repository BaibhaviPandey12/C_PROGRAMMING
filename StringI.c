#include<stdio.h>
#include<string.h>
int main()
{
	char str1[20],str2[10];
	int n;
	printf("\n enter source string:");
	gets(str1);
	printf("\n enter destination string:");
	gets(str2);
	printf("\nenter no of characters you want to combine");
	scanf("%d",&n);
	strncat(str1,str2,n);
		printf("\n string after concatenation:%s",str1);
	


	return 0;
}
