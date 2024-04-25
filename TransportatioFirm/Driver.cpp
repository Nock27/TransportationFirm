#include <iostream>
#include "Driver.h"
#include "Vehicle.h"

Driver::Driver() {
	strcpy(firstName, "empty");
	strcpy(lastName, "empty");
	age = 0;
	strcpy(categoryList, "empty");
	isDriverResting = 1;
	isDriverEmployed = 0;
}

Driver::Driver(const char* firstName, const char* lastName, int age,
	const char* categoryList, int isDriverResting) {

	strcpy(this->firstName, firstName);
	strcpy(this->lastName, lastName);
	this->age = age;
	strcpy(this->categoryList, categoryList);
	this->isDriverResting = isDriverResting;
	isDriverEmployed = 0;
}

char* Driver::getCategoryList() {
	return categoryList;
}

int Driver::getIsDriverResting() {
	return isDriverResting;
}

Driver& Driver::operator=(Driver& driver) {
	strcpy(firstName, driver.firstName);
	strcpy(lastName, driver.lastName);
	age = driver.age;
	strcpy(categoryList, driver.categoryList);
	isDriverResting = driver.isDriverResting;
	isDriverEmployed = driver.isDriverEmployed;
	return driver;
}

void Driver::routeSetter(Vehicle* vehicle) {
	isDriverResting = 0;
	vehicle->setVehicleNotAvailable();
}

char* Driver::getFirtsName() {
	return firstName;
}

char* Driver::getLastName() {
	return lastName;
}

int Driver::getAge() {
	return age;
}

void Driver::setIsDriverResting() {
	isDriverResting = 0;
}
int Driver::getIsDriverEmployed() {
	return isDriverEmployed;
}
void Driver::setIsDriverEmployed() {
	isDriverEmployed = 1;
}