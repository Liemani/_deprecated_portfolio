//********************************************
// char* title = "ViewController.c"
// made by Lieman at 2020.07.10
//
// description:
//	ViewController implementation
//********************************************





// preprocessor
#include "ViewController.h"





// method
void ViewController__entry(ViewController* viewController) {
	SimpleString* line = read8Character(viewController->fileManager);

	while (line != EOF) {
		line = read8Character(viewController->fileManager);
		View__print__SimpleString(line);
	}
}





// ViewController factory method
ViewController* allocViewController() {
	ViewController* viewController = (ViewController*)malloc(sizeof(ViewController));

	return viewController;
}

ViewController* newViewController() {
	ViewController* viewController = allocViewController();

	viewController->fileManager = newFileManager();

	return viewController;
}

void deallocViewController(ViewController* viewController) {
	deallocFileManager(viewController->fileManager);
	deallocView(viewController->view);

	free(viewController);
}