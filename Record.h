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
	

protected:

private:
	int RentalNum, RentalDays, CustomerNumber;
	std::string CustomberName, CustomerAddress, DateFrom, DateTo;
	double TotalCost;
};

inline std::ostream& operator<<(std::ostream& os, const Record& rhs) {
	return os << "\nRental:     " << rhs.RentalNum << "\nDate From:     " << rhs.DateFrom << "\nDate To :     " << rhs.DateTo << "\nRental Days :     " << rhs.RentalDays << "\nTotal Cost :     " << rhs.TotalCost << "\nCustomer Name :     " << rhs.CustomberName << "\nCustomer Address :     " << rhs.CustomerAddress << "\nCustomer Number :     " << rhs.CustomerNumber << std::endl;
}
