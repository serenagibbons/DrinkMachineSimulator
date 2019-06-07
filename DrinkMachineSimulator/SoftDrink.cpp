#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class SoftDrink {
private:
	string name;
	double cost;
	int numAvailable;

	SoftDrink(string n, double c, int num) {		// Constructor
		name = n;
		cost = c;
		numAvailable = num;
	}

	SoftDrink() {									// Default constructor
		name = " ";
		cost = 0.00;
		numAvailable = 0;
	}

	double inputMoney();
	void dailyReport();

public:
	void displayChoices();
	int buyDrink();
};