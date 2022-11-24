#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <list>
#include "Record.h"
class Vehicle
{
public:
	//constructor stuff
	Vehicle(char* Model, char* Make, char* Reg, int Age);
	~Vehicle();
	void SetValues(char* Model, char* Make, char* Reg, int Age);

	//comparison functions
	int CompareReg(const char* reg);
	const int GetAge();
	const char RegLetter();

	//op overloads
	friend std::ostream& operator<<(std::ostream& os, Vehicle& rhs);

	//display function
	void DisplayToMenu();
	void DisplayToSearchMenu();
	void DisplaySpecifics();
	void DisplayRecord(int record);

	virtual double ReturnCost() = 0;
	virtual int GetExtra1() = 0;
	virtual int GetExtra2() = 0;
	
	//record stuff
	void ReturnAllRecords();
	const std::string ReturnFilePath();
	void ResizeRecords();
	void InsertRecord(Record r);
	void SaveRecords();

protected:
	virtual std::string GetType() = 0;

private:
	//record array
	size_t RECORD_SIZE = 1;
	size_t CURRENT_RECORDS = 0;
	Record* Records = new Record[RECORD_SIZE];

	int VehicleAge;
	char VehicleModel[31], VehicleMake[31], VehicleReg[9];

};

struct CompareCost {
	bool operator()(Vehicle* lhs, Vehicle* rhs) {
		return lhs->ReturnCost() < rhs->ReturnCost();
	}
};

struct CompareReg {
	bool operator()(Vehicle* lhs, Vehicle* rhs) {
		return (lhs->RegLetter() < rhs->RegLetter());
	}
};

inline const int Vehicle::GetAge() {
	return VehicleAge;
}


