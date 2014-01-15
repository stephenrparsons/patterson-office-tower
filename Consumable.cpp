#include "Consumable.h"

using namespace std;

Consumable::Consumable()
{
	m_quantity = 0;
}

Consumable::~Consumable()
{
	
}

int Consumable::getQuantity()
{
	return m_quantity;
}

void Consumable::setQuantity(int quantity)
{
	m_quantity = quantity;
}

void Consumable::use(Character & user)
{
	
}

void Consumable::dumpObject()
{
	cout << "Consumable:" << endl;
	dumpObjectData();
}

void Consumable::dumpObjectData()
{
	Item::dumpObjectData();

	cout << " Quantity : " << getQuantity() << endl;
}

void Consumable::writeFragment(ostream & output)
{
}

void Consumable::writeDataAsFragment(ostream & output)
{
}

void Consumable::setElementData(string sElementName, string sValue)
{
	Item::setElementData(sElementName, sValue);
	if (sElementName == "quantity")
	{
		this->setQuantity(atoi(sValue.c_str()));
	}
}