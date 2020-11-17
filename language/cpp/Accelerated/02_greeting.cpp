#include <iostream>
#include <string>

int main()
{
	std::string name;
	std::cout << "Please enter your first name: ";
	std::cin >> name;

	const std::string greeting = "Hello, " + name + "!";	
	
	const std::string spaces(greeting.size(), ' ');
	const std::string second = "* " + spaces + " *";
	
	const std::string first(greeting.size() + 4, '*');
	
	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " << greeting << " *" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;
	
	return 0;
}
