#include <iostream>
#include <string>
using namespace std;

class Classy
{
	public:
		string name;
		int age;
		int type;
        Classy(string name, int age, int type);
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
	cout << "Name: " << c.name << "\n";
	cout << "Age: " << c.age << "\n";
	return 0;
}