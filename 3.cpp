#include <iostream>
#include <string>
using namespace std;

class Classy
{
	string name; // Private
	int age; // Private
	int type; // Private
	public:
		Classy(string name, int age, int type);
		string getName()
		{
			return name;
		}
		int getAge()
		{
			return age;
		}
		int setAge(int x)
		{
			age = x;
			return 1;
		}
};

Classy::Classy(string x, int y, int z)
{
	name = x;
	age = y;
	type = z;
	cout << "Created: " << x << " " << y << " " << z << "\n";
}

int main()
{
	Classy c("c", 24, 1);
	c.setAge(25);
	cout << "Name: " << c.getName() << "\n";
	cout << "Age: " << c.getAge() << "\n";
	return 0;
}