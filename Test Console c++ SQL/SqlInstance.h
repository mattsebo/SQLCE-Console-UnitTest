#pragma once

#using <System.dll>
#using <System.Data.dll>
#using <System.Data.SqlServerCe.dll>

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Data::SqlServerCe;

public ref class SqlInstance
{
public:
	SqlInstance(String^ workOrderName);
	String^ GetString(String^ query);
private:
	String^ connString;
	static String^ pathToWorkOrder = "C:\\Microvellum Data\\Work Orders\\";
	SqlCeConnection^ conn;
};