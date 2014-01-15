#include "Weapon.h"

using namespace std;

Weapon::Weapon()
{
	m_attackBonus = 0;
	m_weaponType = 0;
}

Weapon::~Weapon()
{
	
}

int Weapon::getAttackBonus()
{
	return m_attackBonus;
}

void Weapon::setAttackBonus(int attackBonus)
{
	m_attackBonus = attackBonus;
}

int Weapon::getWeaponType()
{
	return m_weaponType;
}

void Weapon::setWeaponType(int weaponType)
{
	m_weaponType = weaponType;
}

void Weapon::dumpObject()
{
	cout << "Weapon:" << endl;
	dumpObjectData();
}

void Weapon::dumpObjectData()
{
	Equipment::dumpObjectData();

	cout << "tackBonus : " << getAttackBonus() << endl;
	cout << "eaponType : " << getWeaponType() << endl;
}

void Weapon::writeFragment(ostream & output)
{
	output << "  <Weapon>" << endl;
	writeDataAsFragment(output);
	output << "  </Weapon>" << endl << endl;
}

void Weapon::writeDataAsFragment(ostream & output)
{
	Item::writeDataAsFragment(output);

	output
	<< "    <weaponType>"
	<< getWeaponType()
	<< "</weaponType>"
	<< endl
	<< "    <attackBonus>"
	<< getAttackBonus()
	<< "</attackBonus>"
	<< endl;
}

void Weapon::setElementData(string sElementName, string sValue)
{
	Equipment::setElementData(sElementName, sValue);
	if (sElementName == "attackBonus")
	{
		this->setAttackBonus(atoi(sValue.c_str()));
	}
	else if (sElementName == "weaponType")
	{
		this->setWeaponType(atoi(sValue.c_str()));
	}
}