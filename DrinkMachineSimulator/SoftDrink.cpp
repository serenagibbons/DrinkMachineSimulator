
#include "SoftDrink.h"

drink::drink(string n, double c, int num) {		// Constructor
	name = n;
	cost = c;
	numAvailable = num;
}

drink::drink() {								// Default constructor
	name = " ";
	cost = 0.00;
	numAvailable = 0;
}

void SoftDrink::displayChoices() {	// Display a menu of drink names and prices
	string star;
	star.assign(30, '*');

	cout << setw(18) << "   Drink" << "Price" << endl;
	cout << star << endl;

	cout << fixed << showpoint << setprecision(2);
	cout << "1. " << setw(18) << array[0].name << "$" << array[0].cost << endl;
	cout << "2. " << setw(18) << array[1].name << "$" << array[1].cost << endl;
	cout << "3. " << setw(18) << array[2].name << "$" << array[2].cost << endl;
	cout << "4. " << setw(18) << array[3].name << "$" << array[3].cost << endl;
	cout << "5. " << setw(18) << array[4].name << "$" << array[4].cost << endl << endl;
}