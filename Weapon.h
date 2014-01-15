#ifndef _Weapon_included_
#define _Weapon_included_

#include "Equipment.h"

class Weapon : public Equipment
{
	public:
		Weapon();
		~Weapon();
		virtual int getAttackBonus();
		virtual void setAttackBonus(int attackBonus);
		virtual int getWeaponType();
		virtual void setWeaponType(int weaponType);

		virtual void dumpObjectData();
		virtual void dumpObject();
		virtual void writeFragment(ostream & output);
		virtual void writeDataAsFragment(ostream & output);
		virtual void setElementData(std::string sElementName, std::string sValue);
		
	private:
		int m_attackBonus;
		int m_weaponType;
};

#endif