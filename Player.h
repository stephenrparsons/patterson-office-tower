#ifndef _Player_included_
#define _Player_included_

#include "Character.h"

class Player : public Character
{
	public:
		Player();
		~Player();
		virtual int getSmarts();
		virtual void setSmarts(int smarts);
		virtual int getLevel();
		virtual void setLevel(int level);
		virtual void attack(Character & target);
		virtual char updateDisplay(char current_symbol);
		virtual double getGPA();
		virtual void setGPA(double gpa);
		virtual int getNextSmarts();
		virtual void setNextSmarts(int nextSmarts);

		virtual void dumpObjectData();
		virtual void dumpObject();
		virtual void writeFragment(ostream & output);
		virtual void writeDataAsFragment(ostream & output);
		virtual void setElementData(std::string sElementName, std::string sValue);
		
		virtual void playerMoveUp(DungeonLevel * level);
		virtual int getReasoning();
		virtual void setReasoning(int reasoning);
		virtual int getProwess();
		virtual void setProwess(int prowess);
		virtual void levelUp();

		virtual void setCalculators(int calculators);
		virtual int getCalculators();
		virtual void setHelpfulFriends(int helpfulFriends);
		virtual int getHelpfulFriends();
		virtual void setJennifers(int jennifers);
		virtual int getJennifers();
	private:
		int m_smarts;
		int m_level;
		double m_GPA;
		int m_nextSmarts;
		int m_prowess;
		int m_reasoning;
		int m_calculators;
		int m_helpfulFriends;
		int m_jennifers;
};

#endif