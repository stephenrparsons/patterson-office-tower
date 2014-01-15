#include "DungeonLevel.h"

DungeonLevel::DungeonLevel()
{
	vector<Tile> tempTiles;
	for(int i = 0; i < 79; i++)
	{
		Tile tempTile;
		tempTiles.push_back(tempTile);
	}
	for(int i = 0; i < 20; i++)
	{
		m_tiles.push_back(tempTiles);
	}
}
DungeonLevel::~DungeonLevel()
{
	
}
Tile * DungeonLevel::getTile(int x, int y)
{
	return &(m_tiles[y][x]);
}
void DungeonLevel::display()
{
	for(int i = 0; i < m_tiles.size(); i++)
	{
		for(int j = 0; j < m_tiles[i].size(); j++)
		{
			m_tiles[i][j].display();
		}
		cout << endl;
	}
}
vector<string> DungeonLevel::stringFormat()
{
	vector<string> stringLevel;
	for(int i = 0; i < m_tiles.size(); i++)
	{
		string temp = "";
		for(int j = 0; j < m_tiles[i].size(); j++)
		{
			temp += m_tiles[i][j].getType();
		}
		stringLevel.push_back(temp);
	}
	return stringLevel;
}
void DungeonLevel::generateLevel()
{
	//tunnel
	for(int i = 12; i < 67; i++)
	{
		m_tiles[4][i].setType('#');
		m_tiles[15][i].setType('#');
	}
	for(int i = 4; i < 16; i++)
	{
		m_tiles[i][12].setType('#');
		m_tiles[i][66].setType('#');
		m_tiles[i][38].setType('#');
	}
	//room1(top-left)
	int x1 = this->randomNumber(10);
	int x2 = 14 + this->randomNumber(8);
	int y1 = this->randomNumber(3);
	int y2 = 7 + this->randomNumber(2);
	for(int i = y1; i <= y2; i++)
	{
		for(int j = x1; j <= x2; j++)
		{
			m_tiles[i][j].setType('.');
		}
	}
	//room2(top-center)
	x1 = 52 - this->randomNumber(10);
	x2 = 52 - 14 - this->randomNumber(8);
	y1 = this->randomNumber(3);
	y2 = 7 + this->randomNumber(2);
	for(int i = y1; i <= y2; i++)
	{
		for(int j = x1; j >= x2; j--)
		{
			m_tiles[i][j].setType('.');
		}
	}
	//room3(top-right)
	x1 = 78 - this->randomNumber(10);
	x2 = 78 - 14 - this->randomNumber(8);
	y1 = this->randomNumber(3);
	y2 = 7 + this->randomNumber(2);
	for(int i = y1; i <= y2; i++)
	{
		for(int j = x1; j >= x2; j--)
		{
			m_tiles[i][j].setType('.');
		}
	}
	//room4(bottom-left)
	x1 = this->randomNumber(10);
	x2 = 14 + this->randomNumber(8);
	y1 = 19 - this->randomNumber(3);
	y2 = 19 - 7 - this->randomNumber(2);
	for(int i = y1; i >= y2; i--)
	{
		for(int j = x1; j <= x2; j++)
		{
			m_tiles[i][j].setType('.');
		}
	}
	//room5(bottom-center)
	x1 = 52 - this->randomNumber(10);
	x2 = 52 - 14 - this->randomNumber(8);
	y1 = 19 - this->randomNumber(3);
	y2 = 19 - 7 - this->randomNumber(2);
	for(int i = y1; i >= y2; i--)
	{
		for(int j = x1; j >= x2; j--)
		{
			m_tiles[i][j].setType('.');
		}
	}
	//room6(bottom-right)
	x1 = 78 - this->randomNumber(10);
	x2 = 78 - 14 - this->randomNumber(8);
	y1 = 19 - this->randomNumber(3);
	y2 = 19 - 7 - this->randomNumber(2);
	for(int i = y1; i >= y2; i--)
	{
		for(int j = x1; j >= x2; j--)
		{
			m_tiles[i][j].setType('.');
		}
	}
	//middle room (same every time)
	for(int i = 29; i < 48; i++)
	{
		for (int j = 7; j < 13; j++)
		{
			m_tiles[j][i].setType('.');
		}
	}
	//stairs
	int x = this->randomNumber(1,78);
	int y = this->randomNumber(1,19);
	while(m_tiles[y][x].getType() != '.' || m_tiles[y+1][x].getType() != '.'
		|| m_tiles[y-1][x].getType() != '.' || m_tiles[y][x+1].getType() != '.'
		|| m_tiles[y][x-1].getType() != '.')
	{
		x = this->randomNumber(1,78);
		y = this->randomNumber(1,19);
	}
	m_tiles[y][x].setType('<');
	x = this->randomNumber(1,78);
	y = this->randomNumber(1,19);
	while(m_tiles[y][x].getType() != '.' || m_tiles[y+1][x].getType() != '.'
		|| m_tiles[y-1][x].getType() != '.' || m_tiles[y][x+1].getType() != '.'
		|| m_tiles[y][x-1].getType() != '.')
	{
		x = this->randomNumber(1,78);
		y = this->randomNumber(1,19);
	}
	m_tiles[y][x].setType('>');
	//walls
	for(int i = 0; i < 20; i++)
	{
		if(m_tiles[i][0].getType() == '.')
		{
			m_tiles[i][0].setType('+');
		}
		if(m_tiles[i][78].getType() == '.')
		{
			m_tiles[i][78].setType('+');
		}
	}
	for(int i = 0; i < 79; i++)
	{
		if(m_tiles[0][i].getType() == '.')
		{
			m_tiles[0][i].setType('+');
		}
		if(m_tiles[19][i].getType() == '.')
		{
			m_tiles[19][i].setType('+');
		}
	}
	for(int i = 1; i < 19; i++)
	{
		for(int j = 1; j < 78; j++)
		{
			if(m_tiles[i][j].getType() == '.')
			{
				if(m_tiles[i][j+1].getType() == ' ' \
					|| m_tiles[i][j-1].getType() == ' ' \
					|| m_tiles[i+1][j].getType() == ' ' \
					|| m_tiles [i-1][j].getType() == ' ')
				{
					m_tiles[i][j].setType('+');
				}
			}
		}
	}
}
int DungeonLevel::randomNumber(int iMax)
{
	static mt19937 mt(time(NULL));
	return mt() % iMax;
}
int DungeonLevel::randomNumber(int iMin, int iMax)
{
	static mt19937 mt(time(NULL));
	return mt() % (iMax - iMin) + iMin;
}

char DungeonLevel::at(int x, int y)
{
	return m_tiles[y][x].getDisplayChar();
}
void DungeonLevel::addThing(Entity * thing, int x, int y)
{
	m_tiles[y][x].addThing(thing);
}
vector<vector<Tile>> DungeonLevel::getTiles()
{
	return m_tiles;
}
void DungeonLevel::moveUp(Entity * thing, int x, int y)
{
	m_tiles[y][x].remove(thing);
	m_tiles[y-1][x].addThing(thing);
}
void DungeonLevel::moveDown(Entity * thing, int x, int y)
{
	m_tiles[y][x].remove(thing);
	m_tiles[y+1][x].addThing(thing);
}
void DungeonLevel::moveRight(Entity * thing, int x, int y)
{
	m_tiles[y][x].remove(thing);
	m_tiles[y][x+1].addThing(thing);
}
void DungeonLevel::moveLeft(Entity * thing, int x, int y)
{
	m_tiles[y][x].remove(thing);
	m_tiles[y][x-1].addThing(thing);
}
void DungeonLevel::addItem(Entity * thing)
{
	int x = this->randomNumber(1,78);
	int y = this->randomNumber(1,19);
	while(m_tiles[y][x].getDisplayChar() != '.' || m_tiles[y+1][x].getDisplayChar() != '.'
		|| m_tiles[y-1][x].getDisplayChar() != '.' || m_tiles[y][x+1].getDisplayChar() != '.'
		|| m_tiles[y][x-1].getDisplayChar() != '.')
	{
		x = this->randomNumber(1,78);
		y = this->randomNumber(1,19);
	}
	thing->setX(x);
	thing->setY(y);
	m_tiles[y][x].addThing(thing);
}
void DungeonLevel::removeThing(Entity * thing, int x, int y)
{
	m_tiles[y][x].remove(thing);
}
Tile * DungeonLevel::getTilePointer(int x, int y)
{
	return &(m_tiles[y][x]);
}