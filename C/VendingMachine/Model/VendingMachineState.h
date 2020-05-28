#pragma once
//********************************************
// const title = "vendingMachineState"
// made by Lieman at 2020.05.25
//
// description:
//	vendingMachineState example
//********************************************





// preprocessor
#include <stdio.h>

#pragma warning(disable:4996)





// global variable
typedef enum VendingMachineState { _VendingMachineState_appearing, _VendingMachineState_waitingMoney, _VendingMachineState_dataManageMode, _VendingMachineState_waitingSelection, _VendingMachineState_waitingContinue, _VendingMachineState_terminating } VendingMachineState;