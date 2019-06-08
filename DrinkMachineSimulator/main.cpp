#include <iostream>
#include <iomanip>
#include <string>
#include "SoftDrink.h"
using namespace std;

int main() {

	SoftDrink machine;
	int menuSelection;
	double price = 0.00;

	// Call displayChoices and allow patron to pick a drink or quit the program
	cout << "Soft Drink Machine\n" << endl;
	cout << left;
	machine.displayChoices();

	do {
		cout << "Select a drink to purchase (or enter -1 to quit)" << endl;
		cin >> menuSelection;

		if (menuSelection == -1)
			cout << "Exiting menu.\n";
		else if (menuSelection >= 0 && menuSelection <= 5)
			machine.buyDrink(menuSelection);
		else
			cout << "Invalid selection.\n";

	} while (menuSelection != -1);

	system("pause");
	return 0;
}