#include "Entity.h"
#include "DungeonLevel.h"
#include "Creature.h"
#include "Player.h"

using namespace std;

Entity::Entity()
{
	m_name = "";
	m_symbol = ' ';
	m_moved = false;
}

Entity::~Entity()
{

}

int Entity::randomNumber(int iMax)
{
	static mt19937 mt(time(NULL));
  	return mt() % iMax;
}

std::string Entity::getName()
{
	return m_name;
}

void Entity::setName(string name)
{
	m_name = name;
}

char Entity::getSymbol()
{
	return m_symbol;
}

void Entity::setSymbol(char symbol)
{
	m_symbol = symbol;
}

void Entity::dumpObject()
{
	cout << "Entity:" << endl;
	dumpObjectData();
}

void Entity::dumpObjectData()
{
	cout << "     Name : " << getName() << endl;
	cout << "   Symbol : " << getSymbol() << endl;
}

void Entity::writeFragment(ostream & output)
{
	output << "  <Entity>" << endl;
	writeDataAsFragment(output);
	output << "  </Entity>" << endl;
}

void Entity::writeDataAsFragment(ostream & output)
{
	output
	<< "    <name>"
	<< getName()
	<< "</name>"
	<< endl
	<< "    <symbol>"
	<< getSymbol()
	<< "</symbol>"
	<< endl;
}

void Entity::setElementData(string sElementName, string sValue)
{
	if (sElementName == "name")
	{
		setName(sValue);
	}
	else if (sElementName == "symbol")
	{
		setSymbol(sValue[0]);
	}
}

int Entity::getX()
{
	return m_x;
}
int Entity::getY()
{
	return m_y;
}
void Entity::setX(int x)
{
	m_x = x;
}
void Entity::setY(int y)
{
	m_y = y;
}
char Entity::updateDisplay(char current_symbol)
{
	return m_symbol;
}
void Entity::moveUp(DungeonLevel * level)
{
	if(m_y > 0)
	{
		char nextChar = (*level).getTiles()[m_y-1][m_x].getDisplayChar();
		if(nextChar == '.' \
			|| nextChar == '#')
		{
			level->moveUp(this, m_x, m_y);
			m_y--;
		}
		else if(nextChar == 's' \
			|| nextChar == 't' \
			|| nextChar == 'r' \
			|| nextChar == 'l' \
			|| nextChar == 'p' \
			|| nextChar == 'C' \
			|| nextChar == 'P')
		{
			if(this->getSymbol() == '@')
				{
					this->attack(static_cast<Player*>(this), static_cast<Creature*>((*level).getTiles()[m_y-1][m_x].getThings()[0]));
					if(static_cast<Creature*>((*level).getTiles()[m_y-1][m_x].getThings()[0])->getHealth() <= 0)
					{
						static_cast<Player*>(this)->setSmarts(static_cast<Player*>(this)->getSmarts() + 10);
						level->removeThing((*level).getTiles()[m_y-1][m_x].getThings()[0], m_x, m_y-1);
						int rando = this->randomNumber(5);
						{
							if(level->getTilePointer(m_x,m_y-1)->getType() == '.')
							{
								if(rando == 4)
								{
									int rando2 = this->randomNumber(3);
									if(rando2 == 0)
									{
										level->getTilePointer(m_x,m_y-1)->setType('c');
									}
									else if(rando2 == 1)
									{
										level->getTilePointer(m_x,m_y-1)->setType('f');
									}
									else if(rando2 == 2)
									{
										level->getTilePointer(m_x,m_y-1)->setType('j');
									}
								}
							}
						}
					}
				}
		}
		else if(this->getSymbol() == '@')
		{
			Player * player = static_cast<Player*>(this);
			if(nextChar == 'c')
			{
				level->moveUp(this, m_x, m_y);
				level->getTilePointer(m_x,m_y-1)->setType('.');
				m_y--;
				player->setCalculators(player->getCalculators()+1);
				player->setProwess(player->getProwess()+1);
			}
			else if(nextChar == 'f')
			{
				level->moveUp(this,m_x,m_y);
				level->getTilePointer(m_x,m_y-1)->setType('.');
				m_y--;
				player->setHelpfulFriends(player->getHelpfulFriends()+1);
				player->setReasoning(player->getReasoning()+1);
			}
			else if(nextChar == 'j')
			{
				level->moveUp(this,m_x,m_y);
				level->getTilePointer(m_x,m_y-1)->setType('.');
				m_y--;
				player->setJennifers(player->getJennifers()+1);
			}
		}
	}
}
void Entity::moveDown(DungeonLevel * level)
{
	if(m_y < 19)
	{
		char nextChar = (*level).getTiles()[m_y+1][m_x].getDisplayChar();
		if(nextChar == '.' \
			|| nextChar == '#')
		{
			level->moveDown(this, m_x, m_y);
			m_y++;
		}
		else if(nextChar == 's' \
			|| nextChar == 't' \
			|| nextChar == 'r' \
			|| nextChar == 'l' \
			|| nextChar == 'p' \
			|| nextChar == 'C' \
			|| nextChar == 'P')
		{
			if(this->getSymbol() == '@')
				{
					this->attack(static_cast<Player*>(this), static_cast<Creature*>((*level).getTiles()[m_y+1][m_x].getThings()[0]));
					if(static_cast<Creature*>((*level).getTiles()[m_y+1][m_x].getThings()[0])->getHealth() <= 0)
					{
						static_cast<Player*>(this)->setSmarts(static_cast<Player*>(this)->getSmarts() + 10);
						level->removeThing((*level).getTiles()[m_y+1][m_x].getThings()[0], m_x, m_y+1);
						int rando = this->randomNumber(5);
						{
							if(level->getTilePointer(m_x,m_y+1)->getType() == '.')
							{
								if(rando == 4)
								{
									int rando2 = this->randomNumber(3);
									if(rando2 == 0)
									{
										level->getTilePointer(m_x,m_y+1)->setType('c');
									}
									else if(rando2 == 1)
									{
										level->getTilePointer(m_x,m_y+1)->setType('f');
									}
									else if(rando2 == 2)
									{
										level->getTilePointer(m_x,m_y+1)->setType('j');
									}
								}
							}
						}
					}
				}
		}
		else if(this->getSymbol() == '@')
		{
			Player * player = static_cast<Player*>(this);
			if(nextChar == 'c')
			{
				level->moveDown(this, m_x, m_y);
				level->getTilePointer(m_x,m_y+1)->setType('.');
				m_y++;
				player->setCalculators(player->getCalculators()+1);
				player->setProwess(player->getProwess()+1);
			}
			else if(nextChar == 'f')
			{
				level->moveDown(this,m_x,m_y);
				level->getTilePointer(m_x,m_y+1)->setType('.');
				m_y++;
				player->setHelpfulFriends(player->getHelpfulFriends()+1);
				player->setReasoning(player->getReasoning()+1);
			}
			else if(nextChar == 'j')
			{
				level->moveDown(this,m_x,m_y);
				level->getTilePointer(m_x,m_y+1)->setType('.');
				m_y++;
				player->setJennifers(player->getJennifers()+1);
			}
		}
	}
}
void Entity::moveRight(DungeonLevel * level)
{
	if(m_x < 78)
	{
		char nextChar = (*level).getTiles()[m_y][m_x+1].getDisplayChar();
		if(nextChar == '.' \
			|| nextChar == '#')
		{
			level->moveRight(this, m_x, m_y);
			m_x++;
		}
		else if(nextChar == 's' \
			|| nextChar == 't' \
			|| nextChar == 'r' \
			|| nextChar == 'l' \
			|| nextChar == 'p' \
			|| nextChar == 'C' \
			|| nextChar == 'P')
		{
			if(this->getSymbol() == '@')
				{
					this->attack(static_cast<Player*>(this), static_cast<Creature*>((*level).getTiles()[m_y][m_x+1].getThings()[0]));
					if(static_cast<Creature*>((*level).getTiles()[m_y][m_x+1].getThings()[0])->getHealth() <= 0)
					{
						static_cast<Player*>(this)->setSmarts(static_cast<Player*>(this)->getSmarts() + 10);
						level->removeThing((*level).getTiles()[m_y][m_x+1].getThings()[0], m_x+1, m_y);
						int rando = this->randomNumber(5);
						{
							if(level->getTilePointer(m_x+1,m_y)->getType() == '.')
							{
								if(rando == 4)
								{
									int rando2 = this->randomNumber(3);
									if(rando2 == 0)
									{
										level->getTilePointer(m_x+1,m_y)->setType('c');
									}
									else if(rando2 == 1)
									{
										level->getTilePointer(m_x+1,m_y)->setType('f');
									}
									else if(rando2 == 2)
									{
										level->getTilePointer(m_x+1,m_y)->setType('j');
									}
								}
							}
						}
					}
				}
		}
		else if(this->getSymbol() == '@')
		{
			Player * player = static_cast<Player*>(this);
			if(nextChar == 'c')
			{
				level->moveRight(this, m_x, m_y);
				level->getTilePointer(m_x+1,m_y)->setType('.');
				m_x++;
				player->setCalculators(player->getCalculators()+1);
				player->setProwess(player->getProwess()+1);
			}
			else if(nextChar == 'f')
			{
				level->moveRight(this,m_x,m_y);
				level->getTilePointer(m_x+1,m_y)->setType('.');
				m_x++;
				player->setHelpfulFriends(player->getHelpfulFriends()+1);
				player->setReasoning(player->getReasoning()+1);
			}
			else if(nextChar == 'j')
			{
				level->moveRight(this,m_x,m_y);
				level->getTilePointer(m_x+1,m_y)->setType('.');
				m_x++;
				player->setJennifers(player->getJennifers()+1);
			}
		}
	}
}
void Entity::moveLeft(DungeonLevel * level)
{
	if(m_x > 0)
	{
		char nextChar = (*level).getTiles()[m_y][m_x-1].getDisplayChar();
		if(nextChar == '.' \
			|| nextChar == '#')
		{
			level->moveLeft(this, m_x, m_y);
			m_x--;
		}
		else if(nextChar == 's' \
			|| nextChar == 't' \
			|| nextChar == 'r' \
			|| nextChar == 'l' \
			|| nextChar == 'p' \
			|| nextChar == 'C' \
			|| nextChar == 'P')
		{
			if(this->getSymbol() == '@')
				{
					this->attack(static_cast<Player*>(this), static_cast<Creature*>((*level).getTiles()[m_y][m_x-1].getThings()[0]));
					if(static_cast<Creature*>((*level).getTiles()[m_y][m_x-1].getThings()[0])->getHealth() <= 0)
					{
						static_cast<Player*>(this)->setSmarts(static_cast<Player*>(this)->getSmarts() + 10);
						level->removeThing((*level).getTiles()[m_y][m_x-1].getThings()[0], m_x-1, m_y);
						int rando = this->randomNumber(5);
						{
							if(level->getTilePointer(m_x-1,m_y)->getType() == '.')
							{
								if(rando == 4)
								{
									int rando2 = this->randomNumber(3);
									if(rando2 == 0)
									{
										level->getTilePointer(m_x-1,m_y)->setType('c');
									}
									else if(rando2 == 1)
									{
										level->getTilePointer(m_x-1,m_y)->setType('f');
									}
									else if(rando2 == 2)
									{
										level->getTilePointer(m_x-1,m_y)->setType('j');
									}
								}
							}
						}
					}
				}
		}
		else if(this->getSymbol() == '@')
		{
			Player * player = static_cast<Player*>(this);
			if(nextChar == 'c')
			{
				level->moveLeft(this, m_x, m_y);
				level->getTilePointer(m_x-1,m_y)->setType('.');
				m_x--;
				player->setCalculators(player->getCalculators()+1);
				player->setProwess(player->getProwess()+1);
			}
			else if(nextChar == 'f')
			{
				level->moveLeft(this,m_x,m_y);
				level->getTilePointer(m_x-1,m_y)->setType('.');
				m_x--;
				player->setHelpfulFriends(player->getHelpfulFriends()+1);
				player->setReasoning(player->getReasoning()+1);
			}
			else if(nextChar == 'j')
			{
				level->moveLeft(this,m_x,m_y);
				level->getTilePointer(m_x-1,m_y)->setType('.');
				m_x--;
				player->setJennifers(player->getJennifers()+1);
			}
		}
	}
}
char Entity::nextChar(DungeonLevel * level, int direction)
{
	int y = this->getY();
	int x = this->getX();
	switch(direction)
	{
		case 0:
			if(y > 0)
			{
				return (*level).getTiles()[y-1][x].getDisplayChar();
			}
		case 1:
			if(y < 19)
			{
				return (*level).getTiles()[y+1][x].getDisplayChar();
			}
		case 2:
			if(x < 78)
			{
				return (*level).getTiles()[y][x+1].getDisplayChar();
			}
		case 3:
			if(x > 0)
			{
				return (*level).getTiles()[y][x-1].getDisplayChar();
			}
	}
}
void Entity::setMoved(bool moved)
{
	m_moved = moved;
}
bool Entity::getMoved()
{
	return m_moved;
}
void Entity::changeWorldsPlayer(int to, int from, vector<DungeonLevel> * world)
 {
  if(from != -1)
  {
    Tile * toRemoveFrom = (*world)[from].getTile(this->getX(), this->getY());
    toRemoveFrom->remove(this);
  }
  int stairsX = 0;
  int stairsY = 0;
  if(to > from)
  {
    for(int y = 0; y < 20; y++)
    {
      for(int x = 0; x < 79; x++)
      {
        if((*world)[to].at(x, y) == '>')
        {
          stairsY = y;
          stairsX = x;
        }
      }
    }
  }
  else if(to < from)
  {
    for(int y = 0; y < 20; y++)
    {
      for(int x = 0; x < 79; x++)
      {
        if((*world)[to].at(x, y) == '<')
        {
          stairsY = y;
          stairsX = x;
        }
      }
    }
  }
  this->setX(stairsX);
  this->setY(stairsY);
  (*world)[to].addThing(this, stairsX, stairsY);
 }

void Entity::move(int & currentLevel, vector<DungeonLevel> * world, \
	char next, char move, bool & play)
{
	
        if(next == '<')
        {
          if(currentLevel == 18)
          {
            play = false;
          }
          else
          {
            this->changeWorldsPlayer(currentLevel + 1, currentLevel, world);
            currentLevel++;
          }
        }
        else if(next == '>')
        {
          if(currentLevel == 0)
          {
            play = false;
          }
          else
          {
            this->changeWorldsPlayer(currentLevel - 1, currentLevel, world);
            currentLevel--;
          }
        }
        else
        {
        	if(move == 'w' || move == 'A')
        	{
	          this->moveUp(&(*world)[currentLevel]);
		    }
		    else if(move == 's' || move == 'B')
		    {
		    	this->moveDown(&(*world)[currentLevel]);
		    }
		    else if(move == 'd' || move == 'C')
		    {
		    	this->moveRight(&(*world)[currentLevel]);
		    }
		    else if(move == 'a' || move == 'D')
		    {
		    	this->moveLeft(&(*world)[currentLevel]);
		    }
        }
}


void Entity::attack(Player * player, Creature * monsterIn)
{
  Creature * monster = static_cast<Creature*>(monsterIn);
  if(player->getProwess() > 2*monster->getHealth())
  {
    double diff = player->getProwess() - 2*monster->getHealth();
    monster->setHealth(monster->getHealth() - diff);
  }
}