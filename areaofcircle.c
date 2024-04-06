#include<stdio.h>
int main()
{
	double radius,area=0.0;
	double*pradius=&radius,*parea=&area;
	printf("\n enter the radius of the circle:");
	scanf("%lf",pradius);
	*parea=3.14*(*pradius)*(*pradius);
	printf("\n the area of the circle with radius %.2lf=%.2lf",*pradius,*parea);
	return 0;
	
}
