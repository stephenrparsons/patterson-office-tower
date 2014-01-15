#ifndef _Armor_included_
#define _Armor_included_

#include "Equipment.h"
#include <string>

using namespace std;

class Armor : public Equipment
{
	public:
		Armor();
		~Armor();
		virtual int getDefenseBonus();
		virtual void setDefenseBonus(int defenseBonus);

		virtual void dumpObjectData();
		virtual void dumpObject();
		virtual void writeFragment(ostream & output);
		virtual void writeDataAsFragment(ostream & output);
		virtual void setElementData(std::string sElementName, std::string sValue);
		
	private:
		int m_defenseBonus;
};

#endif