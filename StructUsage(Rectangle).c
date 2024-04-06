#include<iostream>
using namespace std;
struct rectangle
{
	int length;
	int breadth;
};
int main()
{
	rectangle r1;
	r1.length=5;
	cout<<r1.length<<end1<<r1.breadth<<end1;
	r1.breadth=6;
	cout<<r1.length<<end1<<r1.breadth;
	return 0;
}
