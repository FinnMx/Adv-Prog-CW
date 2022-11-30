#include <iostream>
#include <string>
//#include <filesystem>
#include <experimental/filesystem>
#include <fstream>
#include "Storage.h"
#include "PointOfService.h"

namespace fs = std::experimental::filesystem;

int main() {
#ifdef _DEBUG
	  //_CrtSetBreakAlloc(254);
	_onexit(_CrtDumpMemoryLeaks);
#endif


	PointOfService pos = PointOfService();
	pos.DisplayMenu();
	
	return 0;
}