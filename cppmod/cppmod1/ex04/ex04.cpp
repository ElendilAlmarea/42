#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "Ptr: " << *ptr << std::endl;
	std::cout << "Ref: " << ref << std::endl;
}
