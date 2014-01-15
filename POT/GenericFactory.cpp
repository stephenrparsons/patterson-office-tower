#include "GenericFactory.h"

#include <random>
#include <ctime>

#include "parser.h"

#include "Armor.h"
#include "Weapon.h"
#include "Creature.h"
#include "Consumable.h"
#include "Item.h"
#include "Tools.h"

using namespace std;

Item * GenericFactory::generateItem()
{
	return m_vItems.generate([](Item * pItem) {return true;});
}

GenericFactory & GenericFactory::instance()
{
	static GenericFactory factory;
	return factory;
}

GenericFactory::GenericFactory()
{
	map<string, function<XMLSerializable*()>> mConstructors;
	mConstructors["Item"] = []() { return new Item; };
	mConstructors["Consumable"] = []() { return new Consumable; };
	mConstructors["Creature"] = []() { return new Creature; };
	mConstructors["Weapon"] = []() { return new Weapon; };
	mConstructors["Armor"] = []() { return new Armor; };

	vector<XMLSerializable*> vObjects;

    parseXML(mConstructors, "world.xml", vObjects);

	m_vCreatures.constructVector(vObjects);
	m_vItems.constructVector(vObjects);
}

GenericFactory::~GenericFactory()
{
}

Creature * GenericFactory::generateCreature(int iMaxHealth)
{
	return m_vCreatures.generate( [=](Creature * pCreature) { return pCreature->getHealth() < iMaxHealth; });
}
