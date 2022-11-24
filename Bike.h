#pragma once
#include "Vehicle.h"
class Bike : public Vehicle
{
public:
	Bike(char* Model, char* Make, char* Reg, int Age, int Eng, int Wheels);
	~Bike();

	bool CompareWheels(int wheels);
	bool CompareEng(int engsize);

	friend std::ostream& operator<<(std::ostream& os, Bike& rhs);

protected:
	//virtual int GetExtra1()override;
	//virtual int GetExtra2()override;
	virtual double ReturnCost()override;
	virtual std::string GetType()override;
	virtual void WriteSelfToDisk()override;

private:
	int EngSize, WheelNum;


};

inline std::ostream& operator<<(std::ostream& os, Bike& rhs) {
	return os << rhs.ReturnDataForSave() << "\n" << rhs.EngSize << "\n" << rhs.WheelNum << "\n";
}

inline bool Bike::CompareWheels(int wheels) {
	return WheelNum == wheels;
}

inline bool Bike::CompareEng(int engsize) {
	return EngSize == engsize;
}

