/*

C++ program to overload insertion and extraction operator using friend function.

*/

#include<iostream>
using namespace std;

class A
{
	int a;
	public:
		friend void operator>>(istream &,A&);
		friend void operator<<(ostream &,A&);
};

void operator>>(istream &in,A &obj)
{
	in>>obj.a;
}

void operator<<(ostream &out,A &obj)
{
	out<<obj.a;
}

int main()
{
	A ob;
	cout<<"Enter data:";
	cin>>ob;
	cout<<"\nEntered data is:";
	cout<<ob;
	return 0;
}
