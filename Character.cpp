#include "Character.h"

using namespace std;

Character::Character()
{
	m_health = 0;
}

Character::~Character()
{

}

int Character::getHealth()
{
	return m_health;
}

void Character::setHealth(int health)
{
	m_health = health;
}

void Character::attack(Character & target)
{
	
}

void Character::dumpObject()
{
	cout << "Character:" << endl;
	dumpObjectData();
}

void Character::dumpObjectData()
{
	Entity::dumpObjectData();

	cout << "   Health : " << getHealth() << endl;
}

void Character::writeFragment(ostream & output)
{
	cout << "  <Character>" << endl;
	writeDataAsFragment(output);
	cout << "  </Character>" << endl;
}

void Character::writeDataAsFragment(ostream & output)
{
	Entity::writeDataAsFragment(output);

	output
	<< "    <health>"
	<< getHealth()
	<< "</health>"
	<< endl;
}

void Character::setElementData(string sElementName, string sValue)
{
	Entity::setElementData(sElementName, sValue);
	if (sElementName == "health")
	{
		setHealth(atoi(sValue.c_str()));
	}
}