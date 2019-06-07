#include <iostream>
#include <iomanip>
#include <string>
#include "SoftDrink.h"
using namespace std;

int main() {

	SoftDrink machine;
	//int menuSelection;
	//double price = 0.00;

	// Call displayChoices and allow patron to pick a drink or quit the program
	cout << "Soft Drink Machine\n" << endl;
	cout << left;
	machine.displayChoices();

	system("pause");
	return 0;
}