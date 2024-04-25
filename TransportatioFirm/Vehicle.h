#pragma once
class Driver;
class Vehicle {
protected:
	char model[10];
	char registrationNumber[9];
	int productionYear;
	int isVehicleParked;
	Driver* driver; 
	char vignetteExpirationDate[12];
	char categoryNeeded;
public:
	Vehicle();
	Vehicle(const char* model, const char* registrationNumber, int productionYear,
		 const char* vignetteExpirationDate, const char categoryNeeded);

	Driver* getDriver();
	Vehicle& operator=(Vehicle& vehicle);

	virtual void print();

	char* getModel();
	char* getRegNum();
	int getIsVehicleParked();
	char getCategoryNeeded();

	int setDriver(Driver* driver);
	void setVehicleNotAvailable(); 
};