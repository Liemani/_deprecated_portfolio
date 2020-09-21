#include <stdio.h>
#include <thread>
#include <map>
#include <termio.h>    // struct termios
#include <iterator>
#include <chrono>

using std::map;
using std::thread;
using std::pair;

int pressedKey;

int getch() {
    int ch;

    struct termios buf, save;
    tcgetattr(0, &save);
    buf = save;

    buf.c_lflag &= ~(ICANON|ECHO);

    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();

    tcsetattr(0, TCSAFLUSH, &save);

    return ch;
}

void getPressedKey() {
    while(true)
        pressedKey = getch();
}

int main() {
	thread first(getPressedKey);

	map<int, int> intMap = {
		{49, 1},
		{50, 2},
		{51, 3},
		{52, 4},
		{53, 5},
	};

//	map<int, int> intMap;
/*	intMap[49] = 1;
	intMap[50] = 2;
	intMap[51] = 3;
	intMap[52] = 4;
	intMap[53] = 5;
*/
/*
	intMap.insert(pair<int, int>(49, 1));
	intMap.insert(pair<int, int>(50, 2));
	intMap.insert(pair<int, int>(51, 3));
	intMap.insert(pair<int, int>(52, 4));
	intMap.insert(pair<int, int>(53, 5));
*/


	while(true) {
		static map<int, int>::iterator intMapIterator;
//		static int pressedKey;
//		pressedKey = getch();
		if (pressedKey) {
			intMapIterator = intMap.find(pressedKey);
		
			if (intMapIterator != intMap.end()) {
				printf("pressedKey: %d \n", pressedKey);
				printf("intMapIterator->first: %d \n", intMapIterator->first);
				printf("intMapIterator->second: %d \n", intMapIterator->second);
				pressedKey = 0;
			}
		}

		if (pressedKey == 48) {
			map<int, int>::iterator itr;
			for (itr = intMap.begin(); itr != intMap.end(); ++itr) { 
				printf("(%d, %d) \n", itr->first , itr->second);
			}

			pressedKey = 0;
		}
	}

	return 0;
}
