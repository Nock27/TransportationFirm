#pragma once

class Vehicle; 
class Driver {
	char firstName[12];
	char lastName[12];
	int age;
	char categoryList[6];
	int isDriverResting;
	int isDriverEmployed;
public:
	Driver();
	Driver(const char* firstName,const char* lastName,int age,
			const char* categoryList, int isDriverResting);

	Driver& operator=(Driver& driver);

	void routeSetter(Vehicle *vehicle); 
	char* getFirtsName();
	char* getLastName();
	int getAge();
	char* getCategoryList();
	int getIsDriverResting();
	int getIsDriverEmployed();

	void setIsDriverResting();
	void setIsDriverEmployed();
};
