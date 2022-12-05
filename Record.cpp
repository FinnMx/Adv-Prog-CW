#include "Record.h"

Record::Record() {

}

Record::Record(int rentalNum, std::string dateFrom, std::string dateTo, int rentalDays, double totalCost, std::string customberName, std::string customerAddress, std::string number) :
	RentalNum(rentalNum), DateFrom(dateFrom), DateTo(dateTo), RentalDays(rentalDays), TotalCost(totalCost),
	CustomberName(customberName), CustomerAddress(customerAddress), CustomerNumber(number) 
{

}

Record::~Record() {  

}

