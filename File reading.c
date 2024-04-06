#include<stdio.h>
main()
{
	FILE*fp;
	char ch;
   fp=fopen("text","r");
   fseek(fp,241,0);
   ch=fgetc(fp);
	while(!feof(fp))
	{
	printf("%c",ch);
	printf("%d",ftell(fp));
	ch=fgetc(fp);	
		
	}
	fclose(fp);
}
