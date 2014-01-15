#include "Creature.h"

using namespace std;

Creature::Creature()
{
	m_hostile = false;
}

Creature::~Creature()
{
	
}

bool Creature::getHostile()
{
	return m_hostile;
}

void Creature::setHostile(bool hostile)
{
	m_hostile = hostile;
}

void Creature::attack(Character & target)
{
	
}

void Creature::dumpObject()
{
	cout << "Creature:" << endl;
	dumpObjectData();
}

void Creature::dumpObjectData()
{
	Character::dumpObjectData();
	cout << "  Hostile : " << getHostile() << endl;
}

void Creature::writeFragment(ostream & output)
{
	output << "  <Creature>" << endl;
	writeDataAsFragment(output);
	output << "  </Creature>" << endl << endl;
}

void Creature::writeDataAsFragment(ostream & output)
{
	Character::writeDataAsFragment(output);

	output
	<< "    <hostile>";
	if (m_hostile == true) {output << "true";}
	else {output << "false";}
	output << "</hostile>"
	<< endl;
}

void Creature::setElementData(string sElementName, string sValue)
{
	Character::setElementData(sElementName, sValue);
	if (sElementName == "hostile")
	{
		if (sValue == "true")
		{
			setHostile(true);
		}
		else {setHostile(false);}
	}
}