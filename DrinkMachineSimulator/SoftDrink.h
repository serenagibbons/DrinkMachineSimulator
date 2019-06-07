#ifndef SOFTDRINK_H
#define SOFTDRINK_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int TYPES = 5;		// Types of soft drinks in machine

struct drink {
	string name;
	double cost;
	int numAvailable;

	drink(string n, double c, int num);
	drink();
};

class SoftDrink {
private:

	drink array[TYPES] = {
		drink("Cola", 1.00, 20),
		drink("Root Beer", 1.00, 20),
		drink("Orange Soda", 1.00, 20),
		drink("Grape Soda", 1.00, 20),
		drink("Bottled Water", 1.50, 20) };

	double inputMoney();
	void dailyReport();

public:

	void displayChoices();
	int buyDrink();
};

#endif // !SOFTDRINK_H