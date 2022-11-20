#include "Record.h"

Record::Record() {

}

Record::Record(int rentalNum, std::string dateFrom, std::string dateTo, int rentalDays, double totalCost, std::string customberName, std::string customerAddress, int customerNumber) :
	RentalNum(rentalNum), DateFrom(dateFrom), DateTo(dateTo), RentalDays(rentalDays), TotalCost(totalCost),
	CustomberName(customberName), CustomerAddress(customerAddress), CustomerNumber(customerNumber) 
{

}

Record::~Record() {  

}