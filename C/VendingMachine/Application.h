#pragma once
//********************************************
// const title = "Application"
// made by Lieman at 2020.05.28
//
// description:
//	Application structure
//********************************************





// preprocessor
#include <stdio.h>
#include <stdlib.h>
#include "VendingMachineViewController.h"





// global variable
typedef struct Application {
    VendingMachineViewController* viewController;

    void (*start)(struct Application* application);
} Application;





// function
void _Application_start(struct Application* app) {
    while (1) {
        app->viewController->mainLoop(app->viewController);
    }
}





// allocation
Application* application_alloc() {
    Application* app = (Application*)malloc(sizeof(Application));

    return app;
}

// initializer
Application* newApplication() {
    Application* app = application_alloc();

    // initialize properties
    app->viewController = newVendingMachineViewController();

    // initialize methods
    app->start = _Application_start;

    return app;
}