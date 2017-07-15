#include "SqlInstance.h"

/*#using <System.dll>
#using <System.Data.dll>
#using <System.Data.SqlServerCe.dll>

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Data::SqlServerCe;*/

void main()
{
	SqlInstance^ in = gcnew SqlInstance("3000");
	String^ s = in->GetString("SELECT [ItemNumber] FROM Products");
	Console::WriteLine(s);



	// OPEN DATABSE: (WORKS)file://c:/notes.txt;
	/*System::String^ connString = "Data Source=C:\\Microvellum Data\\Work Orders\\3000\\MicrovellumWorkOrder.sdf; LCID=1033; Password=\"\"; Encrypt = FALSE;";
	SqlCeEngine^ engine = gcnew SqlCeEngine(connString);
	bool isGood = engine->Verify();
	Console::WriteLine(isGood);*/
	

	//EXECUTE COMMAND: (WORKS!)
	/*System::String^ query = "SELECT [CutPartLength] FROM Parts";
	SqlCeConnection^ conn = gcnew SqlCeConnection(connString);
	SqlCeCommand^ cmd = gcnew SqlCeCommand(query, conn);

	conn->Open();
	SqlCeDataReader^ rdr = cmd->ExecuteReader();*/

	
}