#include "SqlInstance.h"

SqlInstance::SqlInstance(String ^ workOrderName)
	:
	connString("Data Source=" + pathToWorkOrder + workOrderName + "\\MicrovellumWorkOrder.sdf; LCID=1033; Password=\"\"; Encrypt = FALSE;"),
	conn(gcnew SqlCeConnection(connString))
{
	InitProducts();
}

void SqlInstance::InitProducts()
{
	String^ query = "SELECT [Name],[Comments],[DateShipped],[ItemNumber],\
		[Roomname],[Width],[Height],[Depth],[X],[Y],[Z] FROM Products";
	SqlCeCommand^ cmd = gcnew SqlCeCommand(query, conn);

	conn->Open();
	SqlCeDataReader^ rdr = cmd->ExecuteReader();
	try
	{
		while (rdr->Read())
		{
			String^ name = "";
			if (!(rdr->IsDBNull(0))) { name = rdr->GetString(0); }
			String^ comments = "";
			if (!(rdr->IsDBNull(1))) { comments = rdr->GetString(1); }
			String^ dateShipped = "";
			if (!(rdr->IsDBNull(2))) { dateShipped = rdr->GetString(2); }
			String^ itemNumber = "";
			if (!(rdr->IsDBNull(3))) { itemNumber = rdr->GetString(3); }
			String^ roomname = "";
			if (!(rdr->IsDBNull(4))) { roomname = rdr->GetString(4); }
			Product^ p = gcnew Product(name, comments, dateShipped,
				itemNumber, roomname, rdr->GetDouble(5), rdr->GetDouble(6),
				rdr->GetDouble(7), rdr->GetDouble(8), rdr->GetDouble(9), rdr->GetDouble(10));
			p->OutputData(); // outputs to console for testing
			productList.Add(p);
		}
	}
	finally
	{
		rdr->Close();
		conn->Close();
	}
}

String ^ SqlInstance::GetString(String ^ query)
{
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
