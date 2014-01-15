#include "Item.h"

using namespace std;

Item::Item()
{
	m_value = 0;
	m_weight = 0;
}

Item::~Item()
{
	
}

int Item::getValue()
{
	return m_value;
}

void Item::setValue(int value)
{
	m_value = value;
}

int Item::getWeight()
{
	return m_weight;
}

void Item::setWeight(int weight)
{
	m_weight = weight;
}

void Item::dumpObject()
{
	cout << "Item:" << endl;
	dumpObjectData();
}

void Item::dumpObjectData()
{
	Entity::dumpObjectData();

	cout << "   Weight : " << getWeight() << endl;
	cout << "    Value : " << getValue() << endl;
}

void Item::writeFragment(ostream & output)
{
	output << "  <Item>" << endl;
	writeDataAsFragment(output);
	output << "  </Item>" << endl << endl;
}

void Item::writeDataAsFragment(ostream & output)
{
	Entity::writeDataAsFragment(output);

	output
	<< "    <weight>"
	<< getWeight()
	<< "</weight>"
	<< endl
	<< "    <value>"
	<< getValue()
	<< "</value>"
	<< endl;
}

void Item::setElementData(string sElementName, string sValue)
{
	Entity::setElementData(sElementName, sValue);
	if (sElementName == "value")
	{
		this->setValue(atoi(sValue.c_str()));
	}
	else if (sElementName == "weight")
	{
		this->setWeight(atoi(sValue.c_str()));
	}
}