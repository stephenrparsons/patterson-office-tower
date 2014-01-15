#ifndef _Equipment_included_
#define _Equipment_included_

#include "Item.h"
#include <string>

class Equipment : public Item
{
	public:
		Equipment();
		~Equipment();
		virtual std::string getSlot();
		virtual void setSlot(std::string slot);

		virtual void dumpObjectData();
		virtual void dumpObject();
		virtual void writeFragment(ostream & output);
		virtual void writeDataAsFragment(ostream & output);
		virtual void setElementData(std::string sElementName, std::string sValue);
		
	private:
		std::string m_slot;
};

#endif