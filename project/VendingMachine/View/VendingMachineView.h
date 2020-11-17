#pragma once
//********************************************
// char* title = "vendingMachineView"
// made by Lieman at 2020.05.28
//
// description:
//	vendingMachineView example
//********************************************





// preprocessor
#include <stdio.h>
#include <stdlib.h>
#include "../Model/Menu.h"
#include "../Model/VendingMachine.h"

#pragma warning(disable:4996)





// global variable
typedef struct VendingMachineView {
    void (*printAskMoney)();
    void (*printMenu)(struct VendingMachine* machine);
    void (*printOrder)(struct VendingMachine* machine);
    void (*printContinue)();
    void (*printNotEnoughMoney)(struct VendingMachine* machine);
    void (*printBye)(struct VendingMachine* machine);
    void (*printInvalidInput)();
} VendingMachineView;





// function
void _VendingMachineView_printAskMoney() {
    printf("Input money: ");
}

void _VendingMachineView_printMenu(struct VendingMachine* machine) {
    Beverage** beverageArray = machine->menu->beverageArray;

    printf("Remaining amout: %d\n", machine->money);
    printf("======== MENU ========\n");
    if (machine->menu->count == 0) {
        printf("No menu exist!\n");
    }
    else {
        for (int index = 0; index < machine->menu->count; index++) {
            printf("%d. %-8s(%d)\n", index, beverageArray[index]->name, beverageArray[index]->cost);
        }
    }
    printf("======================\n");
    printf("Select: ");
}

void _VendingMachineView_printOrder(struct VendingMachine* machine) {
    printf("Here is your %s :D\n", machine->menu->beverageArray[machine->selection]->name);
    putchar('\n');
}

void _VendingMachineView_printContinue() {
    printf("Continue ? (y / n) ");
}

void _VendingMachineView_printNotEnoughMoney(struct VendingMachine* machine) {
    Beverage* selectedBeverage = machine->selectedBeverage(machine);
    printf("You don't have enough money for %s(%d)\n", selectedBeverage->name, selectedBeverage->cost);
    putchar('\n');
}

void _VendingMachineView_printBye(struct VendingMachine* machine) {
    printf("%d cents are remained.\n", machine->money);
    printf("Good bye.\n");
    putchar('\n');
}

void _VendingMachineView_invalidInput() {
    printf("Invalid input!\n");
    putchar('\n');
}




// allocation
VendingMachineView* vendingMachineView_alloc() {
    VendingMachineView* view = (VendingMachineView*)malloc(sizeof(VendingMachineView));

    // initialize methods
    view->printAskMoney = _VendingMachineView_printAskMoney;
    view->printMenu = _VendingMachineView_printMenu;
    view->printOrder = _VendingMachineView_printOrder;
    view->printContinue = _VendingMachineView_printContinue;
    view->printNotEnoughMoney = _VendingMachineView_printNotEnoughMoney;
    view->printBye = _VendingMachineView_printBye;
    view->printInvalidInput = _VendingMachineView_invalidInput;

    return view;
}


// initializer
VendingMachineView* vendingMachineView() {
    VendingMachineView* view = vendingMachineView_alloc();

    return view;
}