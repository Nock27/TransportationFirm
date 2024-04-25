#include <iostream>
#include "Bus.h"


Bus::Bus() {
	seats = 0;
}

Bus::Bus(int seats, const char* model, const char* registrationNumber, int productionYear, const char* vignetteExpirationDate, const char categoryNeeded) 
	:Vehicle(model, registrationNumber, productionYear, vignetteExpirationDate, categoryNeeded) {
	this->seats = seats;
}

void Bus::print() {
	std::cout << "the model of the vehicle is: " << model << std::endl;
	std::cout << "The number of seats in the vehicle is: " << seats << std::endl;
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
