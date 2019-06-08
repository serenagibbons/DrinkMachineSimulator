
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

SoftDrink::SoftDrink() {						// SoftDrink constructor
	array[0] = drink("Cola", 1.00, 20);
	array[1] = drink("Root Beer", 1.00, 20);
	array[2] = drink("Orange Soda", 1.00, 20);
	array[3] = drink("Grape Soda", 1.00, 20);
	array[4] = drink("Bottled Water", 1.50, 20);
}

SoftDrink::~SoftDrink() {						// SoftDrink destructor
	dailyReport();
}

double SoftDrink::inputMoney(int sel) {	// Accept, validate, and return the amount of money input
	double remaining, change, input;
	
	cout << "Input money: ";
	cin >> input;
	
	pay += input;
	
	cout << "You entered: $" << pay << endl;

	// Calculate remaining balance due
	remaining = SoftDrink::array[sel].cost - pay;

	while (pay < array[sel].cost) {
		cout << "$" << remaining << " due.\n";
		cout << "Input money: ";
		cin >> input;
		pay += input;
	}
	cout << "$" << pay << " accepted." << endl << endl;

	// Calculate change
	change = pay - array[sel].cost;

	if (pay > array[sel].cost)
		cout << "Returning $" << change << "...\n";

	return pay;
}	

void SoftDrink::dailyReport() {

	cout << "Report for Today" << "\n";
	string star;
	star.assign(38, '*');
	
	cout << setw(21) << "   Drink" << setw(10) << "Price" << "Amount" << endl;
	cout << star << endl;

	cout << fixed << showpoint << setprecision(2);
	for (int i = 0; i < 5; i++)
		cout << i + 1 << ". " << setw(18) << array[i].name << "$" << setw(10) << array[i].cost << array[i].numAvailable << endl;

	cout << endl;
	cout << "Total amount collected: $" << total << endl << endl;
}

void SoftDrink::displayChoices() {	// Display a menu of drink names and prices
	string star;
	star.assign(30, '*');

	cout << setw(21) << "   Drink" << "Price" << endl;
	cout << star << endl;

	cout << fixed << showpoint << setprecision(2);
	cout << "1. " << setw(18) << array[0].name << "$" << array[0].cost << endl;
	cout << "2. " << setw(18) << array[1].name << "$" << array[1].cost << endl;
	cout << "3. " << setw(18) << array[2].name << "$" << array[2].cost << endl;
	cout << "4. " << setw(18) << array[3].name << "$" << array[3].cost << endl;
	cout << "5. " << setw(18) << array[4].name << "$" << array[4].cost << endl << endl;
}

void SoftDrink::buyDrink(int sel) {	// Handles a sale
	sel -= 1;	// Adjust selection to match array subscript

	cout << fixed << showpoint << setprecision(2);
	cout << "Amount due: " << array[sel].cost << endl << endl;

	inputMoney(sel);

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
	dailyReport();

}