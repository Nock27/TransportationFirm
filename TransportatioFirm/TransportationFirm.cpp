#include <iostream>
#include "TransportationFirm.h"

TransportationFirm::TransportationFirm() {
	strcpy(name, "empty");
	strcpy(address, "empty");
	numberOfVehicles = 0;
	numberOfDrivers = 0;
}

TransportationFirm::TransportationFirm(const char* name, const char* address) {
	strcpy(this->name, name);
	strcpy(this->address, address);
	this->numberOfVehicles = 0;
	this->numberOfDrivers = 0;
}

int TransportationFirm::addVehicle(Vehicle& vehicle) {
	if (numberOfVehicles >= 100) {
		return 0; //There is no more space
	}
	vehicles[numberOfVehicles] = vehicle; //Using Vehicle operator function
	numberOfVehicles++; 
	
	return 1; //Successefully added
}

int TransportationFirm::addDriver(Driver& driver) {
	if (numberOfDrivers >= 100) {
		return 0; //There is no more space
	}
	if (driver.getIsDriverEmployed()) {
		return 0;
	}
	driver.setIsDriverEmployed();
	drivers[numberOfDrivers] = driver; //Using Driver operator function
	numberOfDrivers++; 
	return 1; //Successefully added
}

void TransportationFirm::printVehicles() {
	int i;
	for (i = 0; i < numberOfVehicles; i++) {
		if (vehicles[i].getIsVehicleParked()) {
			vehicles[i].print();
		}
	}
}

int TransportationFirm::setVehicleRoute(Vehicle* vehicle) {
	if (vehicle->getIsVehicleParked()) {
		int i = 0;
		while (i < numberOfDrivers) {
			if (drivers[i].getIsDriverResting())
			{
				if (vehicle->setDriver(&drivers[i]))
				{
					drivers[i].routeSetter(vehicle);
				}
				break;
			}i++;
		}
	
	}
	return 0; //No driver is found
}

char* TransportationFirm::getName() {
	return name;
}

char* TransportationFirm::getAddress() {
	return address;
}

int TransportationFirm::getNumberOfDrivers() {
	return numberOfDrivers;
}

int TransportationFirm::getNumberOfVehicles() {
	return numberOfVehicles;
}

Vehicle* TransportationFirm::getVehicles() {
	return vehicles;
}

Driver* TransportationFirm::getDrivers() {
	return drivers;
}