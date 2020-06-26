//********************************************
// title = "playground"
// made by Lieman at 2020.06.23
//
// description:
//   haveFun!!
//********************************************
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

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

void output1() {
	cout << "1\t2\t3\t4\t5\t6\t7\t8\t9" << endl << "" << endl;
	for (int c = 1; c < 10; c++) {
		cout << c << "|";
		for (int i = 1; i < 10; ++i) {
			cout << i * c << '\t';
		}
		cout << endl;
	}
}

void highLow() {
	int number;
	int guess;

	srand(time(NULL));

	number = rand() % 100 + 1;
	guess = 0;

	do {
		cout << "Guess our number (1 to 100): ";

		if (!(cin >> guess)) {
			cout << "Invalid Input!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		} else {
			if (guess > number) {
				cout << guess << " is high" << endl;
			} else if (guess < number) {
				cout << guess << " is low" << endl;
			} else {
				cout << "Congratulations!" << endl;
				break;
			}
		}
	} while (true);
}

void printGCD(int lhs, int rhs) {
	int gcd;

	int bigOne;
	int smallOne;

	int temporary;

	if (lhs > rhs) {
		bigOne = lhs;
		smallOne = rhs;
	} else {
		bigOne = rhs;
		smallOne = lhs;
	}

	if (smallOne == 0) {
		cout << bigOne;
		return;
	}

	while (smallOne != 0) {
		temporary = bigOne % smallOne;

		bigOne = smallOne;
		smallOne = temporary;
	}

	cout << "GCD of " << lhs << " and " << rhs << " is " << smallOne;
}

void test() {
	const char* token = "abcdefg";
	printf("token: 0x");
	for (int i = 0; i < strlen(token); ++i) {
		printf("%x", token[i]);
	}
}

int main() {
	printGCD(117, 81);

	return 0;
}