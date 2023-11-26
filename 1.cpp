#include <iostream>
#include <string>
using namespace std;

class Car
{
	public:
		string name;
		int year;
		int myMethod(int x);
};

int Car::myMethod(int x)
{
	return x * 10;
}

int main()
{
	Car c;
	c.name = "BMW";
	c.year = 2016;
	cout << "Car: " << c.name << "\n";
	cout << "Year: " << c.year << "\n";
	cout << c.myMethod(4) << "\n";
	return 0;
}