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

	//comparison functions
	int CompareReg(const char* reg);
	const char RegLetter();

	//op overloads
	std::string ReturnDataForSave();

	//display function
	void DisplayToMenu();
	void DisplayToSearchMenu();
	void DisplaySpecifics();
	void DisplayRecord(int& record);

	virtual double ReturnCost() = 0;
	virtual void WriteSelfToDisk() = 0;
	
	//record stuff
	void ReturnAllRecords();
	const std::string ReturnFilePath();
	void ResizeRecords();
	void InsertRecord(Record r);
	void SaveRecords();
	int ReturnNextRecNum();
	double ReturnTotalCost(int days);

protected:
	virtual std::string GetType() = 0; //can use typeid
	const int GetAge();


private:
	//private methods...
	const double ReturnTotalRentedIncome();
	const int ReturnTotalRentedDays();

	//record array (might not be the best way to do this!)
	size_t RECORD_SIZE;
	size_t CURRENT_RECORDS;
	Record* Records = new Record[RECORD_SIZE];

	int VehicleAge;
	//change so it can be dynamic
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


