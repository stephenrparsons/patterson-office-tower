#include "Armor.h"

using namespace std;

Armor::Armor()
{
	m_defenseBonus = 0;
}

Armor::~Armor()
{
	
}

int Armor::getDefenseBonus()
{
	return m_defenseBonus;
}

void Armor::setDefenseBonus(int defenseBonus)
{
	m_defenseBonus = defenseBonus;
}

void Armor::dumpObject()
{
	cout << "Armor:" << endl;
	dumpObjectData();
}

void Armor::dumpObjectData()
{
	Equipment::dumpObjectData();

	cout << "enseBonus : " << getDefenseBonus() << endl;
}

void Armor::writeFragment(ostream & output)
{
	output << "  <Armor>" << endl;
	writeDataAsFragment(output);
	output << "  </Armor>" << endl << endl;
}

void Armor::writeDataAsFragment(ostream & output)
{
	Item::writeDataAsFragment(output);

	output
	<< "    <defenseBonus>"
	<< getDefenseBonus()
	<< "</defenseBonus>"
	<< endl;
}

void Armor::setElementData(string sElementName, string sValue)
{
	Item::setElementData(sElementName, sValue);
	if (sElementName == "defenseBonus")
	{
		this->setDefenseBonus(atoi(sValue.c_str()));
	}
}