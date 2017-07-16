#include "Product.h"

Product::Product(String^ name, String^ comments, 
	String^ dateShipped, String^ itemNumber, 
	String^ roomName, Double^ width, 
	Double^ height, System::Double^ depth, Double^ x,
	Double^ y, Double^ z)
	:
	name(name),
	comments(comments),
	dateShipped(dateShipped),
	itemNumber(itemNumber),
	roomName(roomName),
	width(width),
	height(height),
	depth(depth),
	x(x),
	y(y),
	z(z)
{
}

void Product::OutputData()
{
	Console::WriteLine("ItemNumber: " + itemNumber + "|Name: " + name
	+ "|Comments: " + comments + "|Date Shipped: " + dateShipped + "|Room Name: " + roomName + 
	"|Width: " + width + "|Height: " + height + "|Depth: " + depth +
	"|x: " + x + "|y: " + y + "|z: " + z);
}
