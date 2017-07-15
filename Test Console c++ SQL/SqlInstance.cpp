#include "SqlInstance.h"

SqlInstance::SqlInstance(String ^ workOrderName)
	:
	connString("Data Source=" + pathToWorkOrder + workOrderName + "\\MicrovellumWorkOrder.sdf; LCID=1033; Password=\"\"; Encrypt = FALSE;"),
	conn(gcnew SqlCeConnection(connString))
{
	//throw gcnew System::NotImplementedException();
}

String ^ SqlInstance::GetString(String ^ query)
{
	//throw gcnew System::NotImplementedException();
	SqlCeCommand^ cmd = gcnew SqlCeCommand(query, conn);

	conn->Open();
	SqlCeDataReader^ rdr = cmd->ExecuteReader();
	String^ s;
	try
	{
		while (rdr->Read())
		{
			s = rdr->GetString(0);
		}
	}
	finally
	{
		rdr->Close();
		conn->Close();
	}
	return s;
}
