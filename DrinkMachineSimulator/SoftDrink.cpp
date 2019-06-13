#include "SoftDrink.h"

drink::drink(string n, double c, int num) {		// Drink constructor
	name = n;
	cost = c;
	numAvailable = num;
}

drink::drink() {								// Drink default constructor
	name = " ";
	cost = 0.00;
	numAvailable = 0;
}

SoftDrink::~SoftDrink() {						// SoftDrink destructor
	dailyReport();
}

SoftDrink::SoftDrink() {						// SoftDrink constructor
	array[0] = drink("Cola", 1.00, 20);
	array[1] = drink("Root Beer", 1.00, 20);
	array[2] = drink("Orange Soda", 1.00, 20);
	array[3] = drink("Grape Soda", 1.00, 20);
	array[4] = drink("Bottled Water", 1.50, 20);
}

double SoftDrink::inputMoney(int sel) {	// Accept, validate, and return the amount of money input
	double remaining, change, input;

	pay = 0; // Reset pay each time inputMoney is called
	
	do {
		cout << "Input money (or enter -1 to quit): ";
		cin >> input;

		if (input == -1) {
			if (pay > 0) {
				cout << "Returning $" << pay << "...\n\n";
				pay = 0;
			}
			return pay;
		}

		pay += input;
		cout << "You entered: $" << pay << endl;

		// Calculate remaining balance due
		remaining = SoftDrink::array[sel].cost - pay;

		if (pay < array[sel].cost) {
			cout << "$" << remaining << " due.\n";
		}
	} while (pay < array[sel].cost);

	// Calculate change
	change = pay - array[sel].cost;

	if (pay > array[sel].cost) {
		pay -= change;
		cout << "\n$" << pay << " accepted. Returning $" << change << "...";
	}
	else
		cout << "\n$" << pay << " accepted. ";

	cout << endl;

	return pay;
}	

void SoftDrink::dailyReport() {
	
	cout << "Report for Today\n" << endl;
	string star;
	star.assign(38, '*');
	
	cout << setw(21) << "   Drink" << "Amount" << endl;
	cout << star << endl;

	cout << fixed << showpoint << setprecision(2);
	for (int i = 0; i < 5; i++)
		cout << i + 1 << ". " << setw(18) << array[i].name << array[i].numAvailable << endl;

	cout << endl;
	cout << "Total amount collected: $" << total << endl << endl;
}

void SoftDrink::displayChoices() {	// Display a menu of drink names and prices
	string star;
	star.assign(30, '*');

	cout << setw(21) << "   Drink" << "Price" << endl;
	cout << star << endl;

	cout << fixed << showpoint << setprecision(2);
	for (int i = 0; i < 5; i++)
		cout << i + 1 << ". " << setw(18) << array[i].name << "$" << array[i].cost << endl;

	cout << endl;
}

void SoftDrink::buyDrink(int sel) {	// Handles a sale
	sel -= 1;	// Adjust selection to match array subscript

	cout << fixed << showpoint << setprecision(2);
	cout << "Amount due: " << array[sel].cost << endl << endl;

	inputMoney(sel);

	if (pay == 0) {
		return;
	}

	// If the machine is out of the requested soda, display an appropriate sold out message and return all input money
	if (array[sel].numAvailable == 0) {
		cout << "Sorry, " << array[sel].name << " is sold out.\n";
		cout << "Returning money...\n";
	}
	// If the machine has the soda and enough money was entered, complete the sale by updating the quantity and money collected
	else {
		total += pay;
		array[sel].numAvailable--;
		cout << "Here is your beverage.\n\n";
	}

}