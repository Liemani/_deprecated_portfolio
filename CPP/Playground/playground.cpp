//********************************************
// title = "playground"
// made by Lieman at 2020.06.23
//
// description:
//   haveFun!!
//********************************************
#include <iostream>
#include <iomanip>

void helloWorld() {
	std::cout << std::setiosflags(std::ios::left);
	std::cout << std::setw(17) << "Hello World!" << std::endl;
}

void getInput() {
	int inputValue = 0;

	do {
		std::cout << "Enter a number (-1 = quit): ";

		//cout << typeid(cin >> inputValue).name();
		if (!(std::cin >> inputValue)) {
			std::cout << "You entered a non-numeric. Exiting..." << std::endl;
			break;
		}

		if (inputValue != -1) {
			std::cout << "You entered " << inputValue << std::endl;
		}
	} while (inputValue != -1);
	std::cout << "All done." << std::endl;
}

void getInput2() {
	int inputValue = 0;

	do {
		std::cout << "Enter a number (-1 = quit): ";

		if (!(std::cin >> inputValue)) {
			std::cout << "Please enter a number!" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		} else {
			std::cout << "You entered " << inputValue << std::endl;
		}
	} while (inputValue != -1);
	std::cout << "All done." << std::endl;
}


int main() {
	getInput2();

	return 0;
}