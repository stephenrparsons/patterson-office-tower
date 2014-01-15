#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <random>
#include <ctime>

using namespace std;

#include "Player.h"
#include "DungeonLevel.h"
#include "Tools.h"
#include "GenericFactory.h"

void displayTextFile(string filename)
 {
  ifstream splash;
  splash.open(filename);
  vector<string> vSplash;
  for(int i = 0; i < 30; i++)
    {
      string temp;
      getline(splash, temp);
      vSplash.push_back(temp);
    }
  splash.close();
  for(int y = 0; y < 30; y++)
    {
    for(int x = 0; x < 79; x++)
      {
        move(y,x);
        addch(vSplash[y][x]);
      }
    }
  refresh();
  getch();
 }

 void changeWorldsPlayer(Player * player, int to, int from, vector<DungeonLevel> * world)
 {
  if(from != -1)
  {
    Tile * toRemoveFrom = (*world)[from].getTile(player->getX(), player->getY());
    toRemoveFrom->remove(player);
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
  player->setX(stairsX);
  player->setY(stairsY);
  (*world)[to].addThing(player, stairsX, stairsY);
 }

void updateScreen(int currentLevel, Player * player, vector<string> * messages, \
  vector<DungeonLevel> * world, vector<string> * statuses)
{
  clear();
  for(int y = 0; y < 20; y++)
    {
    for(int x = 0; x < 79; x++)
      {
        move(y,x);
        addch((*world)[currentLevel].at(x, y));
      }
    }
  move(21,1);
  printw("+---------------------------------------------------------------------------+");
  move(29,1);
  printw("+---------------------------------------------------------------------------+");
  for(int i = 22; i < 29; i++)
  {
    move(i,1);
    addch('|');
    move(i,77);
    addch('|');
    move(i,24);
    addch('|');
    move(i,53);
    addch('|');
  }
  move(22,7);
  printw("***Stats***");
  move(23,2);
  printw("Floor: %d", currentLevel + 1);
  mvprintw(24,2,"GPA: %.2f", player->getGPA());
  mvprintw(25,2,"Smarts: %d/%d", player->getSmarts(), player->getNextSmarts());
  if(player->getLevel() < 20)
  {
    mvprintw(26,2,"Status: %s", ((*statuses)[player->getLevel()-1]).c_str());
  }
  else
  {
   mvprintw(26,2,"Status: %s", "Tenured Prof"); 
  }
  mvprintw(27,2,"Prowess: %d", player->getProwess());
  mvprintw(28,2,"Reasoning: %d", player->getReasoning());
  mvprintw(22,31,"***Inventory***");
  mvprintw(23,25,"(%d) Calculators", player->getCalculators());
  mvprintw(24,25, "   +1 prowess each");
  mvprintw(25,25,"(%d) Helpful Friends", player->getHelpfulFriends());
  mvprintw(26,25,"    +1 reasoning each");
  mvprintw(27,25,"(%d) Meet w/ Jennifer Doerge", player->getJennifers());
  mvprintw(28,25,"    restores GPA");
  mvprintw(22,54,"Patterson Office Tower");
  mvprintw(23,59," +-+  +-+");
  mvprintw(24,59," | |+-+ +-+");
  mvprintw(25,59," | || |/ /");
  mvprintw(26,59," | ||   |");
  mvprintw(27,59," \\__| |\\ \\");
  mvprintw(28,59,"    +-+ +-+");
  mvprintw(20,1,"Press 'h' for help or 'q' to quit at any time.");
  refresh();
}

void displayEndScreen(Player * player)
{
  clear();
  if(player->getGPA() <= 0)
  {
    mvprintw(0,0,"Your academic career came to a pathetic end.");
  }
  else
  {
    mvprintw(0,0,"You ended the game.");
  }
  mvprintw(2,0,"Your final score was %d.", player->getSmarts());
  mvprintw(4,0,"Thanks for playing Patterson Office Tower!");
  mvprintw(6,0,"Press 'x' to exit the game.");
  refresh();
  while(getch() != 'x') {};
}

void defend(Entity * monsterIn, Player * player)
{
  Creature * monster = static_cast<Creature*>(monsterIn);
  if(monster->getHealth()*2 > player->getReasoning())
  {
    double diff = monster->getHealth()*2 - player->getReasoning();
    double subtract = diff / 10.0;
    player->setGPA(player->getGPA() - subtract);
  }
}

void attack(Player * player, Entity * monsterIn)
{
  Creature * monster = static_cast<Creature*>(monsterIn);
  if(player->getProwess() > monster->getHealth())
  {
    double diff = player->getProwess() - monster->getHealth();
    monster->setHealth(monster->getHealth() - diff);
  }
}

int randomNumber(int iMax)
{
  static mt19937 mt(time(NULL));
  return mt();
}

void moveMonsters(vector<DungeonLevel> * world, int currentLevel, Player * player)
{
  for(int y = 0; y < 20; y++)
  {
    for(int x = 0; x < 79; x++)
    {
      if((*world)[currentLevel].at(x,y) == 't' \
        || (*world)[currentLevel].at(x,y) == 's' \
        || (*world)[currentLevel].at(x,y) == 'l' \
        || (*world)[currentLevel].at(x,y) == 'p' \
        || (*world)[currentLevel].at(x,y) == 'C' \
        || (*world)[currentLevel].at(x,y) == 'P' \
        || (*world)[currentLevel].at(x,y) == 'r')
      {
            Entity * monster = (*world)[currentLevel].getTiles()[y][x].getThings()[0];
            if(monster->getMoved() == false)
            {
              monster->setMoved(true);
              int pX = player->getX();
              int pY = player->getY();
              int xDiff = pX - x;
              int yDiff = pY - y;
              if(abs(yDiff) >= abs(xDiff))
              {
                if(abs(yDiff) == 1 && xDiff == 0)
                {
                  defend(monster, player);
                }
                else if(yDiff > 0)
                {
                  monster->moveDown(&(*world)[currentLevel]);
                }
                else
                {
                  monster->moveUp(&(*world)[currentLevel]);
                }
              }
              else
              {
                if(abs(xDiff) == 1 && yDiff == 0)
                {
                  defend(monster, player);
                }
                else if(xDiff > 0)
                {
                  monster->moveRight(&(*world)[currentLevel]);
                }
                else
                {
                  monster->moveLeft(&(*world)[currentLevel]);
                }
              }
            }
      }
    }
  }
}

int main()
{
  mt19937 mt;
  mt.seed( time(NULL) );

  initscr();
  clear();
  curs_set(0);
  noecho();

  vector<string> statuses;
  statuses.push_back("Fresh Meat");
  statuses.push_back("Quick Learner");
  statuses.push_back("Summer Intern");
  statuses.push_back("Sophomore");
  statuses.push_back("Junior");
  statuses.push_back("Dean's List");
  statuses.push_back("Researcher");
  statuses.push_back("Goldwater");
  statuses.push_back("Senior");
  statuses.push_back("Top of Class");
  statuses.push_back("Valedictorian");
  statuses.push_back("TA");
  statuses.push_back("Grad Student");
  statuses.push_back("Master");
  statuses.push_back("Doctor");
  statuses.push_back("Lecturer");
  statuses.push_back("Associate Prof");
  statuses.push_back("Professor");
  statuses.push_back("Dept Chair");
  statuses.push_back("Tenured Prof");

  displayTextFile("splash.txt");
  displayTextFile("intro.txt");
  displayTextFile("help.txt");

  Player * player = new Player;
  player->setSymbol('@');

  vector<DungeonLevel> world;
  vector<string> messages;

  for(int i = 0; i < 19; i++)
  {
    DungeonLevel level;
    level.generateLevel();
    world.push_back(level);
  }

  int currentLevel = 0;

  changeWorldsPlayer(player, 0, -1, &world);
  updateScreen(currentLevel, player, &messages, &world, &statuses);

  vector<vector<Entity*>> things;

  for( int i = 0; i < 19; i++ )
  {
    for(int j = 0; j < 5+i; j++)
    {
      Creature * pCritter = GenericFactory::instance().generateCreature((i+1)*2);
      world[i].addItem(pCritter);
    }
  }

  for(int i = 0; i < 19; i++)
  {
    for(int y = 0; y < 20; y++)
    {
      for(int x = 0; x < 79; x++)
      {
        int random = randomNumber(300);
        int random2 = random;
        if((random2 % 151) == 0)
        {
          if(world[i].getTiles()[y][x].getDisplayChar() == '.')
          {
            random2 = randomNumber(300);
            switch(abs(random2 % 3))
            {
              case 0:
                world[i].getTilePointer(x,y)->setType('c');
                break;
              case 1:
                world[i].getTilePointer(x,y)->setType('f');
                break;
              case 2:
                world[i].getTilePointer(x,y)->setType('j');
                break;
            }
          }
        }
      }
    }
  }

  updateScreen(currentLevel, player, &messages, &world, &statuses);

  bool play = true;
  while(play)
  {
    char nextMove = getch();
    char moveChar;
    char next;
    switch(nextMove)
    {
      case 'w':
        moveChar = 'w';
        next = player->nextChar(&(world[currentLevel]), 0);
        break;
      case 'a':
        moveChar = 'a';
        next = player->nextChar(&(world[currentLevel]), 3);
        break;
      case 's':
        moveChar = 's';
        next = player->nextChar(&(world[currentLevel]), 1);
        break;
      case 'd':
        moveChar = 'd';
        next = player->nextChar(&(world[currentLevel]), 2);
        break;
      case '\033':
        getch();
        switch(getch())
        {
          case 'A':
            moveChar = 'A';
            next = player->nextChar(&(world[currentLevel]), 0);
            break;
          case 'B':
            moveChar = 'B';
            next = player->nextChar(&(world[currentLevel]), 1);
            break;
          case 'C':
            moveChar = 'C';
            next = player->nextChar(&(world[currentLevel]), 2);
            break;
          case 'D':
            moveChar = 'D';
            next = player->nextChar(&(world[currentLevel]), 3);
            break;
        }
        break;
      case 'h':
        displayTextFile("help.txt");
        moveChar = ' ';
        break;
      case 'q':
        play = false;
        moveChar = ' ';
        break;
      case 'j':
        {
        if(player->getJennifers() > 0)
        {
          player->setJennifers(player->getJennifers()-1);
          player->setGPA(4.00);
        }
        }
        moveChar = ' ';
        break;
      default:
      moveChar = ' ';
        break;
    }
    player->move(currentLevel, &world, next, moveChar, play);
    moveMonsters(&world, currentLevel, player);
    for(int y = 0; y < 20; y++)
    {
      for(int x = 0; x < 79; x++)
      {
        if((world)[currentLevel].at(x,y) == 't' \
        || (world)[currentLevel].at(x,y) == 's' \
        || (world)[currentLevel].at(x,y) == 'l' \
        || (world)[currentLevel].at(x,y) == 'p' \
        || (world)[currentLevel].at(x,y) == 'C' \
        || (world)[currentLevel].at(x,y) == 'P' \
        || (world)[currentLevel].at(x,y) == 'r')
          {
            world[currentLevel].getTiles()[y][x].getThings()[0]->setMoved(false);
          }
      }
    }
    player->setSmarts(player->getSmarts()+1);
    if(player->getSmarts() >= player->getNextSmarts())
    {
      player->levelUp();
    }
    if(player->getGPA() <= 3.99)
    {
      player->setGPA(player->getGPA() + 0.01);
    }
    int raaando = randomNumber(10) % 10;
    if(raaando == 3)
    {
      Creature * pCritter = GenericFactory::instance().generateCreature((currentLevel+1)*2);
      world[currentLevel].addItem(pCritter);
    }
    updateScreen(currentLevel, player, &messages, &world, &statuses);
    if(player->getGPA() <= 0)
    {
      play = false;
    }
  }
  displayEndScreen(player);
  endwin();

  return 0;
}
