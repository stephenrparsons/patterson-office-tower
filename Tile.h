#ifndef _Tile_Included_
#define _Tile_Included_

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <map>

using namespace std;

#include "Entity.h"

class Tile {
public:
	Tile();
	~Tile();
	int getX();
	int getY();
	char getType();
	void setType(char type);
	void display();
	char getDisplayChar();
	vector<Entity*> getThings();
	void remove(Entity * thing);
	void addThing(Entity * thing);
private:
	vector<Entity*> m_things;
	char m_type;
	int m_x;
	int m_y;
};

#endif