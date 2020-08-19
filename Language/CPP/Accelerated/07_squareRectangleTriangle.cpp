#include <iostream>
#include <string>

int main() {
	std::string inputData;
	
	std::cout << "Please enter the width of shapes: ";
	std::cin >> inputData;
	
	const int width = std::stoi(inputData);
	
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < width; ++j) {
			std::cout << "*";
		}
		
		std::cout << std::endl;
	}
	
	std::cout << "Please enter the height of shapes: ";
	std::cin >> inputData;
	
	const int height = std::stoi(inputData);
	
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			std::cout << "*";
		}
		
		std::cout << std::endl;
	}
	
	for (int i = 0; i < height; ++i) {    // width / 2 - width * i / height / 2
		std::cout << std::string(width * (height - i) / (height * 2), ' ');
		std::cout << std::string(width * i / height, '*');
		
		std::cout << std::endl;
	}

	return 0;
}
