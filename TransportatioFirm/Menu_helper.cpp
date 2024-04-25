#include "Menu_helper.h"
#include <iostream>

using namespace std;

void addInFirm(char* choice, TransportationFirm* TransMaina) {
	if (!strcmp(choice, "driver")) {
		int i = 0, numOfDrivers = 0;

		cout << "How many drivers:";
		cin >> numOfDrivers;

		while (i < numOfDrivers) {

			char nameInit[12];
			char fnameInit[12];
			int ageInit = 0;
			char categoryListInit[6];

			cout << "Enter driver number:" << i + 1 << endl;

			cout << "Enter the first name of the driver:";
			cin >> nameInit;

			cout << "Enter the last name of the driver:";
			cin >> fnameInit;

			cout << "Enter age of the driver:";
			cin >> ageInit;

			cout << "Enter the category list of the driver (comma separated):";
			cin >> categoryListInit;
			cout << endl;

			Driver* newDriverEmp = new Driver(nameInit, fnameInit, ageInit, categoryListInit, 1);
			TransMaina->addDriver(*newDriverEmp);
			i++;
			delete newDriverEmp;
		}
		cout << "Drivers added" << endl;
	} else if (!strcmp(choice, "vehicle")) {
		int i = 0, numOfVehicles = 0;

		cout << "How many vehicles?" << endl;
		cin >> numOfVehicles;

		while (i < numOfVehicles) {
			cout << "A bus or a truck:";
			char type[6];
			cin >> type;
			if (!strcmp(type, "bus")) {

				char modelInit[10];
				char regNumberInit[9];
				int prodYearInit = 0;
				char vignetteExpDateInit[12];
				char categoryInit;
				int seatsInit = 0;

				cout << "Enter vehicle number:" << i + 1 << endl;

				cout << "Enter the model of the bus:";
				cin >> modelInit;

				cout << "Enter the registration number of the bus:";
				cin >> regNumberInit;

				cout << "Enter the production year of the bus:";
				cin >> prodYearInit;

				cout << "Enter the vignette expiration date of the bus:";
				cin >> vignetteExpDateInit;

				cout << "Enter the category of the bus:";
				cin >> categoryInit;

				cout << "Enter the number of seats of the bus:";
				cin >> seatsInit;

				Vehicle* ownBus = new Bus((int)seatsInit,
					(const char*)modelInit,
					(const char*)regNumberInit,
					(int)prodYearInit,
					(const char*)vignetteExpDateInit,
					(const char)categoryInit);

				TransMaina->addVehicle(*ownBus);
				i++;
				cout << "Bus added" << endl;
				delete ownBus;
			} else if (!strcmp(type, "truck")) {

				char modelInit[10];
				char regNumberInit[9];
				int prodYearInit = 0;
				char vignetteExpDateInit[12];
				char categoryInit;
				double maxLoadInit = 0;

				cout << "Enter vehicle number:" << i + 1 << endl;

				cout << "Enter the model of the truck:";
				cin >> modelInit;

				cout << "Enter the registration number of the truck:";
				cin >> regNumberInit;

				cout << "Enter the production year of the truck:";
				cin >> prodYearInit;

				cout << "Enter the vignette expiration date of the truck:";
				cin >> vignetteExpDateInit;

				cout << "Enter the category of the truck:";
				cin >> categoryInit;

				cout << "Enter the gross weight of the truck:";
				cin >> maxLoadInit;

				Truck* ownTruck = new Truck((int)maxLoadInit,
					(const char*)modelInit,
					(const char*)regNumberInit,
					(int)prodYearInit,
					(const char*)vignetteExpDateInit,
					(const char)categoryInit);

				TransMaina->addVehicle(*ownTruck);
				i++;
				cout << "Truck added" << endl;
				delete ownTruck;
			}
		}
	}
}

void setCourseByVehicle(TransportationFirm* TransMaina) {
	char searched_v[10];

	cout << "Select a vehicle by name or registration number:" << endl;
	cin >> searched_v;

	for (int i = 0; i < TransMaina->getNumberOfVehicles(); i++) {
		if (!strcmp(TransMaina->getVehicles()[i].getModel(), searched_v) || !strcmp(TransMaina->getVehicles()[i].getRegNum(), searched_v)) {
			if (TransMaina->getVehicles()[i].getDriver() == nullptr) {
				TransMaina->setVehicleRoute(&TransMaina->getVehicles()[i]);
				cout << "Course set" << endl;
				break;
			}
		}
	}
}

void printDrivers(TransportationFirm* TransMaina) {
	for (int i = 0; i < TransMaina->getNumberOfDrivers(); i++) {
		cout << "The driver's first name is:" << TransMaina->getDrivers()[i].getFirtsName() << endl;
		cout << "The driver's last name is:" << TransMaina->getDrivers()[i].getLastName() << endl;
		cout << "The driver's age is:" << TransMaina->getDrivers()[i].getAge() << endl;
		cout << "The driver's category list is:" << TransMaina->getDrivers()[i].getCategoryList() << endl;

		if (TransMaina->getDrivers()[i].getIsDriverResting()) cout << "The driver is resting" << endl;
		else cout << "The driver is on a course" << endl<<endl;
	}
}

void printAvailableVehicles(TransportationFirm* TransMaina) {
	for (int j = 0; j < TransMaina->getNumberOfVehicles(); j++) {
		if (TransMaina->getVehicles()[j].getIsVehicleParked() && TransMaina->getVehicles()[j].getDriver() == nullptr)
			TransMaina->getVehicles()[j].print();
	}
}