#include "Menu_helper.h"
#include <iostream>
using namespace std;

int main() {
	char name[20];
	char address[30];
	char choice[8];
	char loop[4];

	cout << "Welcome to the transportation firm maker! Please give a name to your firm:";
	std::cin.getline(name, 20);

	cout << "Now please give us an address:";
	std::cin.getline(address, 30);

	TransportationFirm* TransMaina = new TransportationFirm(name, address);

	cout << "The proccess of making a firm has been successful!" << endl;
	cout << "Name:" << TransMaina->getName() << endl;
	cout << "Address:" << TransMaina->getAddress() << endl;

	cout << "Choose what would you add - a driver or a vehicle:";
	cin >> choice;



	addInFirm(choice, TransMaina);
	choice[0] = 0;
	cout << "Would you like to add something else? (yes/no):";
	cin >> loop;


	do {
		choice[0] = 0;
		cout << "Choose what would you add - a driver or a vehicle:";
		cin >> choice;
		addInFirm(choice, TransMaina);
		cout << "Would you like to add something else? (yes/no):";
		loop[0]=0;
		cin >> loop;
	} while (!strcmp(loop, "yes"));

	cout << "Here's a list of all vehicles in the firm:" << endl;
	TransMaina->printVehicles();

	cout << "Would you like to make a course for a vehicle of your choice? (yes/no):";

	choice[0] = 0;
	cin >> choice;

	if (!strcmp(choice, "no")) { 
		cout << "Thank you" << endl;
	} else if (!strcmp(choice, "yes")) {
		setCourseByVehicle(TransMaina);
	}

	cout << "Would you like to make another course? (yes/no):";
	choice[0] = 0;
	cin >> choice;

	if (!strcmp(choice, "no")) { 
		cout << "Thank you" << endl;
	} else if (!strcmp(choice, "yes")){
		setCourseByVehicle(TransMaina);
	}
	cout << "Here's a list of information about all drivers:" << endl;
	printDrivers(TransMaina);
	cout << "Here's a list of information about all available vehicles:" << endl;
	printAvailableVehicles(TransMaina);
	delete TransMaina;

	return 0;
}