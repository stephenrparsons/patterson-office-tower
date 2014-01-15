#include <ncurses.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void displaySplash()
 {
  ifstream splash;
  splash.open("splash.txt");
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