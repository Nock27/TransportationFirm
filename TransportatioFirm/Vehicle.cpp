#include <iostream>
#include "Vehicle.h"
#include "Driver.h"


Vehicle::Vehicle() {
	strcpy(model, "empty");
	strcpy(registrationNumber, "empty");
	productionYear = 0;
	isVehicleParked = 1;
	strcpy(vignetteExpirationDate, "empty");
	strcpy(&categoryNeeded, "");
}

Vehicle::Vehicle(const char* model, const char* registrationNumber, int productionYear,
		const char* vignetteExpirationDate, const char categoryNeeded) {
	strcpy(this->model, model);
	strcpy(this->registrationNumber, registrationNumber);
	this->productionYear = productionYear;
	strcpy(this->vignetteExpirationDate, vignetteExpirationDate);
	//strcpy(this->categoryNeeded, categoryNeeded);
	this->categoryNeeded = categoryNeeded;
	isVehicleParked = 1;
}


void Vehicle::print() {
	std::cout << "the model of the vehicle is: " << model << std::endl;
	std::cout << "the registration number of the vehicle is: " << registrationNumber << std::endl;
	std::cout << "the production year of the vehicle is: " << productionYear << std::endl;

	if (isVehicleParked == 1) {
		std::cout << "Vehicle is parked" << std::endl;
	} else {
		std::cout << "Vehicle is travelling" << std::endl;
	}

	std::cout << "Vignette expiration date: " << vignetteExpirationDate << std::endl;
	std::cout << "The category needed is: " << categoryNeeded << std::endl << std::endl;
}

int Vehicle::setDriver(Driver* driver){
	if (driver->getIsDriverEmployed()) {
		char* categoryList = driver->getCategoryList();
		//int categoryListLength = strlen(driver->getCategoryList() - 1);
		for (int i = 0; categoryList[i] != '\0'; i++) {
			if (*(categoryList + i) == categoryNeeded && isVehicleParked && driver->getIsDriverResting()) {
				this->driver = driver;
				return 1;
				
			}
			
		}
	    return 0;
	}
}

Vehicle& Vehicle::operator=(Vehicle& vehicle) {
	strcpy(model, vehicle.model);
	strcpy(registrationNumber, vehicle.registrationNumber);
	productionYear = vehicle.productionYear;
	isVehicleParked = vehicle.isVehicleParked;
	driver = vehicle.driver;
	strcpy(vignetteExpirationDate, vehicle.vignetteExpirationDate);
	strcpy(&categoryNeeded, &vehicle.categoryNeeded);

	return vehicle;
}

int Vehicle::getIsVehicleParked() {
	return isVehicleParked;
}

void Vehicle::setVehicleNotAvailable() {
	isVehicleParked = 0;
}

char Vehicle::getCategoryNeeded() {
	return categoryNeeded;
}

Driver* Vehicle::getDriver() {
	return driver;
}

char* Vehicle::getModel()
{
	return model;
}

char* Vehicle::getRegNum()
{
	return registrationNumber;
}