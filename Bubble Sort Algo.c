#include<stdio.h>
int main()
{
	int a[100];
	int hold,i,j,n;
	printf("\n enter value of n:");
	scanf("%d",&n);
	printf("\n enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("data items in  original order");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				hold=a[j];
				a[j]=a[j+1];
				a[j+1]=hold;
			}
		}
	}
	printf("\n data items in ascending order");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[j]);
	}
}
