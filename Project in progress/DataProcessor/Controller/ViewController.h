#pragma once
//********************************************
// char* title = "ViewController.h"
// made by Lieman at 2020.07.10
//
// description:
//	ViewController interface
//********************************************





// preprocessor
#include <stdlib.h>		// malloc()
#include "FileManager.h"
#include "../View/View.h"
#include "../Model/SimpleString.h"





// structure
typedef struct ViewController {
	FileManager* fileManager;
} ViewController;





// method
void ViewController__entry(ViewController* viewController);





// ViewController factory method
ViewController* allocViewController();

ViewController* newViewController();

void deallocViewController(ViewController* viewController);
