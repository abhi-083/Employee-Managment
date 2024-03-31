#ifndef __TableController_H__
#define __TableController_H__

#include <iostream>
#include "Table.h"

namespace EmployeeDB::Controller {
	class TableController{
	public:
		static bool tableQuery(EmployeeDB::Model::Table& tab , int columnCount , int keyCount);
		static bool deleteTableQuery(std::string& tableName);
	};
}

#endif
