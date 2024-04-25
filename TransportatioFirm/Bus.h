#pragma once
#include "Vehicle.h"

class Bus : public Vehicle {
	int seats;
public:
	Bus();
	Bus(int seats, const char* model, const char* registrationNumber, int productionYear, const char* vignetteExpirationDate, const char categoryNeeded);

	void print() override;
	
	
};