#include<stdio.h>
struct Employee
{
	char ename[20];
	int ssn;
	float salary;
	struct dob
	{
		int date;
		int month;
		int year;
	}db1;
}emp ={"aniket",1000,1000.50,{22,6,1990}};
 int main()
 {
 	printf("\n Employee name :%s",emp.ename);
 	printf("\n Employee ssn :%d",emp.ssn);
 	printf("\n Employee salary :%.2f",emp.salary);
 	printf("\n Employee dob :%d / %d / %d",emp.db1.date,emp.db1.month,emp.db1.year);
 	return 0;
 }
	

