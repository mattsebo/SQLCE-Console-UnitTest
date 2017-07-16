#pragma once

using namespace System;

public ref class Product
{
public:
	Product(String^ name, String^ comments, String^ dateShipped,
		String^ itemNumber, String^ roomName, Double^ width, 
		Double^ height, Double^ depth, Double^ x, 
		Double^ y, Double^ z);
	void OutputData();
	String^ name;
	String^ comments;
	String^ dateShipped;
	String^ itemNumber;
	String^ roomName;
	Double^ width;
	Double^ height;
	Double^ depth;
	Double^ x;
	Double^ y;
	Double^ z;
	Int16^ qty;
	Int16^ qtyShipped;
private:

};