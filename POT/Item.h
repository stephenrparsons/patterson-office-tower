#ifndef _Item_included_
#define _Item_included_

#include "Entity.h"
#include <string>

class Item : public Entity
{
	public:
		Item();
		~Item();
		virtual int getValue();
		virtual void setValue(int value);
		virtual int getWeight();
		virtual void setWeight(int weight);

		virtual void dumpObjectData();
		virtual void dumpObject();
		virtual void writeFragment(ostream & output);
		virtual void writeDataAsFragment(ostream & output);
		virtual void setElementData(std::string sElementName, std::string sValue);

	private:
		int m_value;
		int m_weight;
};

#endif