#include "Player.h"
#include "DungeonLevel.h"

using namespace std;

Player::Player()
{
	m_smarts = 0;
	m_level = 1;
	m_GPA = 4.0;
	m_nextSmarts = 10;
	m_prowess = 1;
	m_reasoning = 1;
	m_calculators = 0;
	m_helpfulFriends = 0;
	m_jennifers = 0;
}

Player::~Player()
{
	
}

int Player::getSmarts()
{
	return m_smarts;
}

void Player::setSmarts(int smarts)
{
	m_smarts = smarts;
}

int Player::getLevel()
{
	return m_level;
}

void Player::setLevel(int level)
{
	m_level = level;
}

void Player::attack(Character & target)
{

}

void Player::dumpObject()
{
}

void Player::dumpObjectData()
{
}

void Player::writeFragment(ostream & output)
{
}

void Player::writeDataAsFragment(ostream & output)
{
}

void Player::setElementData(string sElementName, string sValue)
{
}
char Player::updateDisplay(char current_symbol)
{
	return this->getSymbol();
}
double Player::getGPA()
{
	return m_GPA;
}
void Player::setGPA(double gpa)
{
	m_GPA = gpa;
}
int Player::getNextSmarts()
{
	return m_nextSmarts;
}
void Player::setNextSmarts(int nextSmarts)
{
	m_nextSmarts = nextSmarts;
}
void Player::playerMoveUp(DungeonLevel * level)
{
	int y = this->getY();
	int x = this->getX();
	char nextChar = (*level).getTiles()[y-1][x].getDisplayChar();

	if(y > 0)
	{
		if(nextChar == '.' || nextChar == '#')
		{
			this->Entity::moveUp(level);
		}
		else if(nextChar = '<')
		{
			
		}
		else if(nextChar == '>')
		{
			
		}
	}
}
int Player::getReasoning()
{
	return m_reasoning;
}
void Player::setReasoning(int reasoning)
{
	m_reasoning = reasoning;
}
int Player::getProwess()
{
	return m_prowess;
}
void Player::setProwess(int prowess)
{
	m_prowess = prowess;
}
void Player::levelUp()
{
   	m_level++;
   	m_nextSmarts = m_nextSmarts + 20*m_level;
   	m_prowess++;
   	m_reasoning++;
}
void Player::setCalculators(int calculators)
{
	m_calculators = calculators;
}
int Player::getCalculators()
{
	return m_calculators;
}
void Player::setHelpfulFriends(int helpfulFriends)
{
	m_helpfulFriends = helpfulFriends;
}
int Player::getHelpfulFriends()
{
	return m_helpfulFriends;
}
void Player::setJennifers(int jennifers)
{
	m_jennifers = jennifers;
}
int Player::getJennifers()
{
	return m_jennifers;
}