#pragma once
#include "Vehicle.h"
#include "Bike.h"
#include "Car.h"
#include <vector>

namespace fs = std::experimental::filesystem;

class Storage
{
public:
	Storage();
	~Storage();

	void DisplayAllVehicles();
	void DisplaySearchResults();
	void DisplayVehicleInfo();
	bool RetrieveVehicleInfo(int op);
	void DisplayRecord(int& record);

	bool DoRecordsExist();

	void InsertRecord(int days, std::string name, std::string address, std::string number);
	void SaveRecords();

	void AddVehicle(std::string& model, std::string& make, std::string& reg, int& age, int& extra1, int& extra2, int op);
	void RemoveVehicle(std::string reg);

	void SortByCost();
	void SortByReg();

	void SearchByReg(std::string reg);
	void SearchBySeats(int seats);
	void SearchByDoors(int doors);
	void SearchByEngine(int engsize);
	void SearchByWheels(int wheels);

private:
	const std::string BikeDir = "Bikes/";
	const std::string CarDir = "Cars/";

	void AddCar(std::string model, std::string make, std::string reg, int age, int extra1, int extra2);
	void AddBike(std::string model, std::string make, std::string reg, int age, int extra1, int extra2);
	void (Storage::* Choice[2])(std::string, std::string, std::string, int, int, int) = { &Storage::AddCar,&Storage::AddBike };

	void ReadFromDisk(std::string dir);
	void WriteToDisk();

	std::string ReturnDate(int offset);

	std::list<Vehicle*> vehicles;
	std::vector<Vehicle*> ReturnedFromSearch;
	Vehicle* v;

	int index = 0;

};

//----------------------------------------------------------------------------
//----------------------------RECORD MENU METHODS-----------------------------
//----------------------------------------------------------------------------

inline void Storage::DisplayRecord(int& record) {
	v->DisplaySpecifics();
	v->DisplayRecord(record);
}

//this method could be classified as pointless considering the fact that we have already returned the state of records, 
//however another menu (without a display records) would need to be implemented if we were to remove this.
//additionally were reusing another function to actually check the state so id say it that stupid of a way of doing this.
inline bool Storage::DoRecordsExist() {
	if (!(v->ReturnNextRecNum() - 1))
		return false;
	else
		return true;
}

inline void Storage::DisplayVehicleInfo() {
	v->DisplaySpecifics();
}

inline void Storage::SaveRecords() {
	v->SaveRecords();
}

inline void Storage::InsertRecord(int days, std::string name, std::string address, std::string number) {
	Record r(v->ReturnNextRecNum(), ReturnDate(0), ReturnDate(days), days, v->ReturnTotalCost(days), name, address, number);
	v->InsertRecord(r);
}

//----------------------------------------------------------------------------
//------------------------------SORTING METHODS-------------------------------
//----------------------------------------------------------------------------


inline void Storage::SortByCost() {
	vehicles.sort(CompareCost());
}

inline void Storage::SortByReg() {
	vehicles.sort(CompareReg());
}

//----------------------------------------------------------------------------
//--------------------------------INIT METHODS--------------------------------
//----------------------------------------------------------------------------

inline void Storage::DisplayAllVehicles() {
	std::list<Vehicle*>::iterator it;
	for (it = vehicles.begin(); it != vehicles.end(); it++) {
		(**it).DisplayToMenu();
	}
}
