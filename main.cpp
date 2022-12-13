#include <iostream>
#include <string>
//#include <filesystem>
#include <experimental/filesystem>
#include <fstream>
#include "Storage.h"
#include "PointOfService.h"

namespace fs = std::experimental::filesystem;

//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-- This program uses c++17 features in experimental, Therefore --
//--  Your going to have to either compile in c++17 or you can   --
//-- put the following in preprocessor definitions...            --
//--                                                             --
//-- _DEBUG;_CONSOLE;%(PreprocessorDefinitions)                  --
//-- _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING;       --
//-- _CRT_SECURE_NO_WARNINGS                                     --
//--                                                             --
//-- *these these should already be predefined                   --
//--                                                             --
//-- if you dont know how to do this do the following..          --
//-- Project -> Adv Prog... properties -> C/C++ -> PreProcessor  --
//-- -> Preprocessor Definitions...                              --
//-----------------------------------------------------------------
//-----------------------------------------------------------------

int main() {

	std::ios_base::sync_with_stdio(false);

#ifdef _DEBUG
	  //_CrtSetBreakAlloc(254);
	_onexit(_CrtDumpMemoryLeaks);
#endif


	PointOfService pos = PointOfService();
	
	return 0;
}