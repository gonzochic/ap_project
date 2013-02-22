//
// Copyright (C) 2013
// Axis Flight Training Systems GmbH
//
// Date:       2013/02/14
//

#ifndef AP_PROJECT_DATAHOLDER
#define AP_PROJECT_DATAHOLDER

#include <string>

class DataHolder 
{
public:
	
	DataHolder& instance()
	{
		static DataHolder dataHolder;
		return dataHolder;
	};
	
	void writeToConsole(std::string text);

private:

	DataHolder() { };

};

#endif // AP_PROJECT_DATAHOLDER
