#ifndef _GenericFactory_included_
#define _GenericFactory_included_

#include "Creature.h"
#include "EntityVector.h"
#include "Item.h"

#include <vector>

class GenericFactory
{
public:	
	static GenericFactory & instance();
	virtual ~GenericFactory();
	Creature * generateCreature(int iMaxHealth);
	Item * generateItem();
private:
	GenericFactory();
	EntityVector<Creature> m_vCreatures;
	EntityVector<Item> m_vItems;
};

#endif
