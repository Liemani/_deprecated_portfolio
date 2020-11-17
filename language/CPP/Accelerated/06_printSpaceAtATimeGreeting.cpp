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
	
	std::string inputData;
	
	std::cout << "Please enter vertical padding: ";
	std::cin >> inputData;
	const int verticalPadding = std::stoi(inputData);
	
	std::cout << "Please enter horizontal padding: ";
	std::cin >> inputData;
	const int horizontalPadding = std::stoi(inputData);
	
	const int row = verticalPadding * 2 + 3;
	const string::size_type column = greeting.size() + horizontalPadding * 2 + 2;
	
	std::cout << std::endl;
	
	for (int r = 0; r != row; ++r) {
		string::size_type c = 0;
		
		while (c != column) {
			if (r == verticalPadding + 1 && c == horizontalPadding + 1) {
				std::cout << greeting;
				
				c += greeting.size();
			} else {
				if (r == 0 || r == row - 1 || c == 0 || c == column - 1) {
					std::cout << '*';
					
					++c;
				} else if (r != verticalPadding + 1) {
					std::cout << string(column - 2, ' ');
					
					c += column - 2;
				} else {
					std::cout << string(horizontalPadding, ' ');
					
					c += horizontalPadding;
				}
			}
		}
		
		std::cout << std::endl;
	}
	
	return 0;
}
