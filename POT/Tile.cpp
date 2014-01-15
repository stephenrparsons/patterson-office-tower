#include "Tile.h"
#include "Player.h"

Tile::Tile()
{
	m_type = ' ';
}
Tile::~Tile()
{

}
int Tile::getX()
{
	return m_x;
}
int Tile::getY()
{
	return m_y;
}
char Tile::getType()
{
	return m_type;
}
void Tile::setType(char type)
{
	m_type = type;
}
void Tile::display()
{
	cout << m_type;
}
char Tile::getDisplayChar()
{
	char current_char = m_type;
	if (m_things.size() == 0)
	{
		return current_char;
	}
	for (int i = 0; i < m_things.size(); i++)
	{
		current_char = m_things[i]->updateDisplay(current_char);
	}
	return current_char;
}
vector<Entity*> Tile::getThings()
{
	vector<Entity*> things;
	things = m_things;
	return things;
}
void Tile::remove(Entity * thing)
{
	int index = 0;
	while(m_things[index] != thing)
	{
		index++;
	}
	m_things.erase(m_things.begin() + index);
}
void Tile::addThing(Entity * thing)
{
	m_things.push_back(thing);
}