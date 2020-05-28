#pragma once
//********************************************
// char* title = "VendingMachineViewController"
// made by Lieman at 2020.05.28
//
// description:
//	vendingMachineViewController example
//********************************************





// preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Model/VendingMachineState.h"
#include "../Model/VendingMachine.h"
#include "../View/VendingMachineView.h"
#include "fileManager.h"
#include "../Resource/constant.h"

#pragma warning(disable:4996)





// global variable
typedef struct VendingMachineViewController {
    VendingMachine* machine;
    VendingMachineState state;

    void (*mainLoop)(struct VendingMachineViewController* viewController);

} VendingMachineViewController;





// function
void _VendingMachineViewController_waitingMoney(struct VendingMachineViewController* viewController) {
    VendingMachine* machine = viewController->machine;

    while (1) {
        _VendingMachineView_printAskMoney();
        scanf("%d", &machine->money);
        while (getchar() != '\n');
        putchar('\n');

        if (machine->money == -1) {
            viewController->state = _VendingMachineState_dataManageMode;
            break;
        }

        if (machine->money <= 0) {
            _VendingMachineView_printInvalidInput();
            continue;
        }

        if (_VendingMachine_isMoneyLow(machine)) {
            viewController->state = _VendingMachineState_terminating;
            break;
        }

        viewController->state = _VendingMachineState_waitingSelection;
        break;
    }
}

void _VendingMachineViewController_dataManageMode(struct VendingMachineViewController* viewController) {
    FileManager* fileManager = newFileManager();

    printf("======= data manage mode =======\n");
    printf("[q] Quit data manage mode\n");
    printf("[d] Display all beverages\n");
    printf("[c] Create a beverage\n");
    printf("[r] Remove a beverage\n");
    printf("[s] Swap the order of 2 beverage\n");
    printf("================================\n");
    printf("Input your command: ");

    char character = getchar();
    while (getchar() != '\n');
    putchar('\n');

    int beverageArrayCount = 0;
    Beverage** beverageArray;
    Beverage* beverage;

    char name[BEVERAGE_NAME_COUNT_LIMIT];
    int cost = 0;

    VendingMachine* machine = viewController->machine;

    switch (character) {
    case 'q':
        viewController->state = _VendingMachineState_waitingMoney;
        return;
    case 'd':
        beverageArray = _FileManager_readAllBeverages(fileManager, &beverageArrayCount);

        if (beverageArrayCount == 0) {
            printf("No beverage!\n");
        }
        else {
            for (int index = 0; index < beverageArrayCount; index++) {
                printf("[%d] %s(%d)\n", index, beverageArray[index]->name, beverageArray[index]->cost);
            }
        }
        putchar('\n');
        break;
    case 'c':
        while (1) {
            printf("Enter name: ");
            fgets(name, BEVERAGE_NAME_COUNT_LIMIT, stdin);
            name[strlen(name) - 1] = '\0';

            printf("Enter cost: ");
            scanf("%d", &cost);
            while (getchar() != '\n');
            putchar('\n');

            printf("%s(%d) is right? (y/n) ", name, cost);

            while (1) {
                _VendingMachine_scanSelection(machine);

                if (_VendingMachine_isSelectionY(machine)) {
                    beverage = newBeverage(name, cost);
                    _FileManager_writeBeverage(fileManager, beverage);
                    _Menu_addBeverage(machine->menu, beverage);
                    break;
                }

                if (!_VendingMachine_isSelectionN(machine)) {
                    _VendingMachineView_printInvalidInput();
                }

                break;
            }

            if (_VendingMachine_isSelectionY(machine) || _VendingMachine_isSelectionN(machine)) break;
        }
        break;
    case 'r':
        //fileManager->deleteBeverage(fileManager, beverage);
        printf("Remove a beverage goes here...\n");
        putchar('\n');
        break;
    case 's':
        printf("Swap the order of 2 beverage goes here...\n");
        putchar('\n');
        break;
    default:
        _VendingMachineView_printInvalidInput();
        break;
    }
}

void _VendingMachineViewController_waitingSelection(struct VendingMachineViewController* viewController) {
    VendingMachine* machine = viewController->machine;

    while (1) {
        _VendingMachineView_printMenu(machine);
        _VendingMachine_scanSelection(machine);

        if (!_VendingMachine_isSelectionNumber(machine)) {
            _VendingMachineView_printInvalidInput();
            continue;
        }

        if (!_VendingMachine_isMoneyEnough(machine)) {
            _VendingMachineView_printNotEnoughMoney(machine);
            viewController->state = _VendingMachineState_waitingContinue;
            break;
        }

        _VendingMachine_takeOrder(machine);
        _VendingMachineView_printOrder(machine);

        if (_VendingMachine_isMoneyLow(machine)) {
            viewController->state = _VendingMachineState_terminating;
            break;
        }

        viewController->state = _VendingMachineState_waitingContinue;
        break;
    }
}

void _VendingMachineViewController_waitingContinue(struct VendingMachineViewController* viewController) {
    VendingMachine* machine = viewController->machine;

    while (1) {
        _VendingMachineView_printContinue();
        _VendingMachine_scanSelection(machine);

        if (_VendingMachine_isSelectionY(machine)) {
            viewController->state = _VendingMachineState_waitingSelection;
            break;
        }

        if (_VendingMachine_isSelectionN(machine)) {
            viewController->state = _VendingMachineState_terminating;
            break;
        }

        _VendingMachineView_printInvalidInput();
    }
}

void _VendingMachineViewController_mainLoop(struct VendingMachineViewController* viewController) {
    switch (viewController->state) {
    case _VendingMachineState_appearing:
        viewController->state = _VendingMachineState_waitingMoney;
        break;
    case _VendingMachineState_waitingMoney:
        _VendingMachineViewController_waitingMoney(viewController);
        break;
    case _VendingMachineState_dataManageMode:
        _VendingMachineViewController_dataManageMode(viewController);
        break;
    case _VendingMachineState_waitingSelection:
        _VendingMachineViewController_waitingSelection(viewController);
        break;
    case _VendingMachineState_waitingContinue:
        _VendingMachineViewController_waitingContinue(viewController);
        break;
    case _VendingMachineState_terminating:
        _VendingMachineView_printBye(viewController->machine);
        viewController->state = _VendingMachineState_waitingMoney;
        break;
    default:
        _VendingMachineView_printInvalidInput();
        break;
    }
}





// allocation
VendingMachineViewController* vendingMachineViewController_alloc() {
    VendingMachineViewController* viewController = (VendingMachineViewController*)malloc(sizeof(VendingMachineViewController));

    return viewController;
}

// initializer
VendingMachineViewController* newVendingMachineViewController() {
    VendingMachineViewController* viewController = vendingMachineViewController_alloc();

    // initialize properties
    FileManager* fileManager = newFileManager();

    int beverageArrayCount = 0;
    Beverage** beverageArray = _FileManager_readAllBeverages(fileManager, &beverageArrayCount);

    viewController->machine = newVendingMachine(beverageArray, beverageArrayCount);
    viewController->state = _VendingMachineState_appearing;

    // initialize methods
    viewController->mainLoop = _VendingMachineViewController_mainLoop;

    return viewController;
}