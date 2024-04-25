#pragma once
#include"Driver.h"
#include "Vehicle.h"

class TransportationFirm {
	char name[20];
	char address[30];
	
	Vehicle vehicles[100]; //Limit of the vehicles of the firm
	int numberOfVehicles;
	
	Driver drivers[100]; //Limit of the drivers of the firm
	int numberOfDrivers;
public:
	TransportationFirm();
	TransportationFirm(const char* name, const char* address);

	int addVehicle(Vehicle& vehicle); 
	int addDriver(Driver& driver);
	void printVehicles();
	int setVehicleRoute(Vehicle* vehicle);
	// kato parametyr zadavame vehicle
	// proverqvame dali vehicle e svoboden
	// ako ne e swoboden return 0
	// ako e svoboden obhovdame masiva sys shofiori i proverqvame za kategoriq i dali e svoboden
	
	char* getName();
	char* getAddress();
	int getNumberOfVehicles();
	int getNumberOfDrivers();
	Vehicle* getVehicles();
	Driver* getDrivers();

	
};