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
	LMTData* characterArray = File__read8Character(viewController->file);

	while (characterArray != EOF) {
		characterArray = read8Character(viewController->file);
		View__print__LMTData(characterArray);
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

	free(viewController);
}