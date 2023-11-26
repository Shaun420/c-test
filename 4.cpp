#include <iostream>
#include <string>
using namespace std;

// Base class
class Car {
	public:
		string brand = "Ford";
		void honk()
		{
			cout << "Tuut, tuut!\n" ;
		}
};

// Derived class
class Model: public Car {
	public:
		string model = "Mustang";
};

int main() {
	Model myCar;
	myCar.honk();
	cout << myCar.brand + " " + myCar.model + "\n";
	return 0;
} 