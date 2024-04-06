#include<stdio.h>
struct student
{
	char name[50];
	int seats;
	float price;
	
};
int main()
{
struct car myCar = {"Renault",2,500000};
struct car *myCarPtr;
myCarPtr = &myCar;

printf("%s %f %d\n%s %f %d \n %s %f %d\n");
myCar.name, myCar.price, myCar.seats,myCarPtr->name,myCarPtr->price,myCarPtr->seats,(*myCarPTR).name,(*myCarPTR).price,(*myCarPTR).seats
}

