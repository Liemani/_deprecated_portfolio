#pragma once
//********************************************
// char* title = "vendingMachine"
// made by Lieman at 2020.05.27
//
// description:
//	vendingMachine example
//********************************************





// preprocessor
#include <stdio.h>
#include <stdlib.h>
#include "Beverage.h"
#include "menu.h"
#include "../Foundation/Bool.h"
#include "selection.h"

#pragma warning(disable:4996)





// global variable
typedef struct VendingMachine {
    Menu* menu;
    Selection selection;
    int money;

    // method
    void (*takeOrder)(struct VendingMachine* machine);
    Beverage* (*selectedBeverage)(struct VendingMachine* machine);
    int (*isMoneyLow)(struct VendingMachine* machine);
    int (*isMoneyEnough)(struct VendingMachine* machine);
    void (*scanSelection)(struct VendingMachine* machine);
    int (*isSelectionNumber)(struct VendingMachine* machine);
    int (*isSelectionY)(struct VendingMachine* machine);
    int (*isSelectionN)(struct VendingMachine* machine);
} VendingMachine;





// function
void _VendingMachine_takeOrder(struct VendingMachine* machine) {
    machine->money -= machine->menu->beverageArray[machine->selection]->cost;
}

Beverage* _VendingMachine_selectedBeverage(struct VendingMachine* machine) {
    if (machine->selection >= machine->menu->count) {
        printf("Invalid beverage selection.\n");
        return NULL;
    }

    return machine->menu->beverageArray[machine->selection];
}

int _VendingMachine_isMoneylow(struct VendingMachine* machine) {
    return machine->money < machine->menu->cheappestCost(machine->menu);
}

int _VendingMachine_isMoneyEnough(struct VendingMachine* machine) {
    return machine->money >= machine->selectedBeverage(machine)->cost;
}

void _VendingMachine_scanSelection(struct VendingMachine* machine) {
    char character = getchar();
    while (getchar() != '\n');
    putchar('\n');

    if (character >= '0' && character < machine->menu->count + '0') {
        machine->selection = character - '0';
    }
    else if (character == 'Y' || character == 'y') {
        machine->selection = Yes;
    }
    else if (character == 'N' || character == 'n') {
        machine->selection = No;
    }
    else {
        machine->selection = Invalid;
    }
}

int _VendingMachine_isSelectionNumber(struct VendingMachine* machine) {
    return machine->selection >= 0 && machine->selection <= 9;
}

int _VendingMachine_isSelectionY(struct VendingMachine* machine) {
    return machine->selection == 10;
}

int _VendingMachine_isSelectionN(struct VendingMachine* machine) {
    return machine->selection == 11;
}





// allocation
VendingMachine* vendingMachine_alloc(Beverage** beverageArray, int arrayCount) {
    VendingMachine* machine = (VendingMachine*)malloc(sizeof(VendingMachine));

    // initialize methods
    machine->takeOrder = _VendingMachine_takeOrder;
    machine->selectedBeverage = _VendingMachine_selectedBeverage;
    machine->isMoneyLow = _VendingMachine_isMoneylow;
    machine->isMoneyEnough = _VendingMachine_isMoneyEnough;
    machine->scanSelection = _VendingMachine_scanSelection;
    machine->isSelectionNumber = _VendingMachine_isSelectionNumber;
    machine->isSelectionY = _VendingMachine_isSelectionY;
    machine->isSelectionN = _VendingMachine_isSelectionN;

    return machine;
}

// initializer
VendingMachine* newVendingMachine(Beverage** beverageArray, int arrayCount) {
    VendingMachine* machine = vendingMachine_alloc(beverageArray, arrayCount);

    // initialize properties
    machine->menu = newMenu(beverageArray, arrayCount);
    machine->selection = Invalid;
    machine->money = 0;

    return machine;
}