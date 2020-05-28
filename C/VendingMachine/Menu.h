#pragma once
//********************************************
// const title = "printMenu"
// made by Lieman at 2020.05.27
//
// description:
//	printMenu example
//********************************************





// preprocessor
#include <stdio.h>
#include <stdlib.h>
#include "beverage.h"

#pragma warning(disable:4996)





// global variable
typedef struct Menu {
    Beverage** beverageArray;
    int count;

    // method
    int (*cheappestCost)(struct Menu* menu);
    void (*addBeverage)(struct Menu* menu, Beverage* beverage);
    void (*_Menu_removeBeverage)(struct Menu* menu, Beverage* beverage);
} Menu;





// function
int _Menu_cheappestCost(Menu* menu) {
    if (menu->count == 0) {
        return 0;
    }

    int cheappestCost = menu->beverageArray[0]->cost;

    for (int index = 1; index < menu->count; index++) {
        int beverageCost = menu->beverageArray[index]->cost;
        if (cheappestCost > beverageCost) {
            cheappestCost = beverageCost;
        }
    }

    return cheappestCost;
}

void _Menu_addBeverage(struct Menu* menu, Beverage* beverage) {
    menu->beverageArray[menu->count] = beverage;
    menu->count++;
}

void _Menu_removeBeverage(struct Menu* menu, Beverage* beverage) {
    free(menu->beverageArray[menu->count - 1]);
    menu->count--;
}





// allocation
Menu* menu_alloc(Beverage** beverageArray, int beverageCount) {
    Menu* menu = (Menu*)malloc(sizeof(Menu));

    // initialize methods
    menu->cheappestCost = _Menu_cheappestCost;
    menu->addBeverage = _Menu_addBeverage;

    return menu;
}

// initializer
Menu* newMenu(Beverage** beverageArray, int beverageCount) {
    Menu* menu = menu_alloc(beverageArray, beverageCount);

    // initialize properties
    menu->beverageArray = beverageArray;
    menu->count = beverageCount;

    return menu;
}