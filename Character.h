#ifndef _Character_included_
#define _Character_included_

#include "Entity.h"
#include <string>

class Character : public Entity
{
	public:
		Character();
		~Character();
		virtual int getHealth();
		virtual void setHealth(int health);
		virtual void attack(Character & target);

		virtual void dumpObjectData();
		virtual void dumpObject();
		virtual void writeFragment(ostream & output);
		virtual void writeDataAsFragment(ostream & output);
		virtual void setElementData(std::string sElementName, std::string sValue);
		
	private:
		int m_health;
};

#endif