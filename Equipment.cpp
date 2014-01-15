#include "Equipment.h"

using namespace std;

Equipment::Equipment()
{
	m_slot = "";
}

Equipment::~Equipment()
{
	
}

string Equipment::getSlot()
{
	return m_slot;
}

void Equipment::setSlot(string slot)
{
	m_slot = slot;
}

void Equipment::dumpObject()
{
	cout << "Equipment:" << endl;
	dumpObjectData();
}

void Equipment::dumpObjectData()
{
	Item::dumpObjectData();

	cout << "     Slot : " << getSlot() << endl;
}

void Equipment::writeFragment(ostream & output)
{
}

void Equipment::writeDataAsFragment(ostream & output)
{
}

void Equipment::setElementData(string sElementName, string sValue)
{
	Item::setElementData(sElementName, sValue);
	if (sElementName == "slot")
	{
		this->setSlot(sValue);
	}
}