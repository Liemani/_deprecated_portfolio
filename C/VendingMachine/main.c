//********************************************
// const title = "main"
// made by Lieman at 2020.05.28
//
// description:
//	main function
//********************************************





// preprocessor
#include <stdio.h>
#include "Application.h"





// main function
int main(int argc, char **argv) {
    Application *app = newApplication();
    app->start(app);

	return 0;
}
