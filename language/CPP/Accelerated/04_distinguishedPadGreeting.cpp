#include <iostream>
#include <string>

using std::string;

int main()
{
	std::string name;
	std::cout << "Please enter your first name: ";
	std::cin >> name;

	const string greeting = "Hello, " + name + "!";	
	
	const string spaces(greeting.size(), ' ');
	const string second = "* " + spaces + " *";
	
	const int verticalPad = 1;
	const int horizontalPad = 2;
	
	const int row = verticalPad * 2 + 3;
	const string::size_type column = greeting.size() + horizontalPad * 2 + 2;
	
	std::cout << std::endl;
	
	for (int r = 0; r != row; ++r) {
		string::size_type c = 0;
		
		while (c != column) {
			if (r == verticalPad + 1 && c == horizontalPad + 1) {
				std::cout << greeting;
				
				c += greeting.size();
			} else {
				if (r == 0 || r == row - 1 || c == 0 || c == column - 1) {
					std::cout << '*';
				} else {
					std::cout << ' ';
				}
				
				++c;
			}
		}
	
		std::cout << std::endl;
	}
	
	return 0;
}
