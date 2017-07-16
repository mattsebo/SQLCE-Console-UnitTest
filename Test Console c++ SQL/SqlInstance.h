#pragma once
#using <System.dll>
#using <System.Data.dll>
#using <System.Data.SqlServerCe.dll>
#include "Product.h"

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Data::SqlServerCe;
using namespace System::Collections::Generic;

public ref class SqlInstance
{
public:
	SqlInstance(String^ workOrderName);
	void InitProducts(); // get all item numbers from work order
private:
	String^ GetString(String^ query);
	String^ connString;
	static String^ pathToWorkOrder = "C:\\Microvellum Data\\Work Orders\\";
	SqlCeConnection^ conn;
	List<Product^> productList;
};