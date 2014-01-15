#ifndef _Consumable_included_
#define _Consumable_included_

#include "Item.h"
#include "Character.h"
#include <string>

class Consumable : public Item
{
	public:
		Consumable();
		~Consumable();
		virtual int getQuantity();
		virtual void setQuantity(int quantity);
		virtual void use(Character & user);

		virtual void dumpObjectData();
		virtual void dumpObject();
		virtual void writeFragment(ostream & output);
		virtual void writeDataAsFragment(ostream & output);
		virtual void setElementData(std::string sElementName, std::string sValue);
		
	private:
		int m_quantity;
};

#endif