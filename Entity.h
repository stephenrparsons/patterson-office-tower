#ifndef _Entity_included_
#define _Entity_included_

using namespace std;

#include <string>
#include <map>
#include <functional>
#include "XMLSerializable.h"
#include <vector>
#include <random>

class DungeonLevel;
class Creature;
class Player;

class Entity : public XMLSerializable
{
	public:
		Entity();
		~Entity();
		virtual std::string getName();
		virtual void setName(std::string name);
		virtual char getSymbol();
		virtual void setSymbol(char symbol);
		virtual char updateDisplay(char current_symbol);

		virtual void dumpObjectData();
		virtual void dumpObject();
		virtual void writeFragment(ostream & output);
		virtual void writeDataAsFragment(ostream & output);
		virtual void setElementData(std::string sElementName, std::string sValue);

		virtual int getX();
		virtual int getY();
		virtual void setX(int x);
		virtual void setY(int y);

		virtual void moveUp(DungeonLevel * level);
		virtual void moveDown(DungeonLevel * level);
		virtual void moveRight(DungeonLevel * level);
		virtual void moveLeft(DungeonLevel * level);

		virtual char nextChar(DungeonLevel * level, int direction);
		virtual void setMoved(bool moved);
		virtual bool getMoved();

		virtual void move(int & currentLevel, vector<DungeonLevel> * world, \
			char next, char move, bool & play);

		virtual void changeWorldsPlayer(int to, int from, vector<DungeonLevel> * world);
		virtual void attack(Player * player, Creature * monsterIn);

		virtual int randomNumber(int iMax);
	private:
		std::string m_name;
		char m_symbol;
		int m_x;
		int m_y;
		bool m_moved;
};

#endif