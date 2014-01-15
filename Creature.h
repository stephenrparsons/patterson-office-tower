#ifndef _Creature_included_
#define _Creature_included_

#include "Character.h"
#include <string>

class Creature : public Character
{
	public:
		Creature();
		~Creature();
		virtual bool getHostile();
		virtual void setHostile(bool hostile);
		virtual void attack(Character & target);

		virtual void dumpObjectData();
		virtual void dumpObject();
		virtual void writeFragment(ostream & output);
		virtual void writeDataAsFragment(ostream & output);
		virtual void setElementData(std::string sElementName, std::string sValue);
		
	private:
		bool m_hostile;
};

#endif