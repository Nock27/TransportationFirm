#pragma once
#include "Vehicle.h"

class Truck : public Vehicle {
	double maxLoad;
public:
	Truck();
	Truck(double maxLoad, const char* model, const char* registrationNumber, int productionYear,
		const char* vignetteExpirationDate, const char categoryNeeded);
	void print() override;
};
