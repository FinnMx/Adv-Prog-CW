#pragma once
#include "Vehicle.h"
class Car : public Vehicle
{
public:
	Car(std::string Reg, std::string Make, std::string Model, int Age, int Doors, int Seats);
	~Car();

	bool CompareDoors(int doors);
	bool CompareSeats(int seats);

	friend std::ostream& operator<<(std::ostream& os, Car& rhs);

protected:
	virtual double ReturnCost()override;
	virtual std::string GetType()override;
	virtual void WriteSelfToDisk()override;

private:
	int DoorNum, SeatNum;

};

inline std::ostream& operator<<(std::ostream& os, Car& rhs) {
	return os << rhs.ReturnDataForSave() << "\n" << rhs.DoorNum << "\n" << rhs.SeatNum << "\n";
}

inline bool Car::CompareDoors(int doors) {
	return DoorNum == doors;
}

inline bool Car::CompareSeats(int seats) {
	return SeatNum == seats;
}

inline void Car::WriteSelfToDisk() {
	std::ofstream out(ReturnFilePath());
	out << *this;
}

inline std::string Car::GetType() {

	return "Car";
}
