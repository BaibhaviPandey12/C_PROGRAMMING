//DYNAMIC MEMORY ALLOCATION FOR INTEGER ARRAY
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p,n,i;
	printf("enter the number of integers to be entered");
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	if(p==NULL)
	{
		printf("memory not available\n");
		exit(1);	
	}
	else
	{
		printf("memory allocation was successful\n");
		printf("enter integers value\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",p+i);
		}
		for(i=0;i<n;i++)
		printf("%d\n",*(p+i));
		
	}
	
	}
	//DYNAMIC MEMORY ALLOCATION FOR INTEGER BLOCK
#include<stdlib.h>
int main()
{
	int *p,n,i;
	printf("enter the number of block we want to reserve");
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	if(p==NULL)
	{
		printf("memory not available\n");
		exit(1);	
	}
	else
	{
		printf("memory allocation was successful\n");
		printf("enter integers value\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",p+i);
		}
		printf("entered values are");
		for(i=0;i<n;i++)
		printf("%d\n",*(p+i));
		
		return 0;
	}
	
	}
