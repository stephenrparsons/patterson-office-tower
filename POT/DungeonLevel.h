#ifndef _DungeonLevel_Included_
#define _DungeonLevel_Included_

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <map>

class Tile;

#include "Tile.h"

class DungeonLevel {
public:
	DungeonLevel();
	~DungeonLevel();
	void display();
	vector<string> stringFormat();
	void generateLevel();
	int randomNumber(int iMax);
	int randomNumber(int iMin, int iMax);
	char at(int x, int y);
	Tile * getTile(int x, int y);
	void addThing(Entity * thing, int x, int y);
	void removeThing(Entity * thing, int x, int y);
	vector<vector<Tile>> getTiles();
	void moveUp(Entity * thing, int x, int y);
	void moveDown(Entity * thing, int x, int y);
	void moveRight(Entity * thing, int x, int y);
	void moveLeft(Entity * thing, int x, int y);
	void addItem(Entity * thing);
	Tile * getTilePointer(int x, int y);
private:
	DungeonLevel* m_upstairs;
	DungeonLevel* m_downstairs;

	vector<vector<Tile>> m_tiles;
};

#endif