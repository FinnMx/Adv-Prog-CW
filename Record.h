#pragma once
#include <string>
#include <iostream>
class Record
{
public:
	Record();
	Record(int rentalNum, std::string dateFrom, std::string dateTo, int rentalDays, double totalCost, std::string customberName, std::string customerAddress, int customerNumber);
	~Record();

	friend std::ostream& operator<<(std::ostream& os, const Record& rhs);
	void DisplayToMenu();

	const double ReturnCost();
	const int ReturnDays();

protected:

private:
	int RentalNum, RentalDays, CustomerNumber;
	std::string CustomberName, CustomerAddress, DateFrom, DateTo;
	double TotalCost;
};

inline std::ostream& operator<<(std::ostream& os, const Record& rhs) {
	return os << rhs.RentalNum << "\n" << rhs.DateFrom << "\n" << rhs.DateTo << "\n" << rhs.RentalDays << "\n" << rhs.TotalCost << "\n" << rhs.CustomberName << "\n" << rhs.CustomerAddress << "\n" << rhs.CustomerNumber << "\n/\n";
}
