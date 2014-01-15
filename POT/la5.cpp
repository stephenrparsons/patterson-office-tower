#include <iostream>
#include <map>
#include <string>
#include <functional>

#include "Armor.h"
#include "Weapon.h"
#include "Item.h"
#include "Creature.h"

using namespace std;

XMLSerializable * constructItem()
{
	return new Item;
}

int main()
{
	map<string, function<XMLSerializable*()>> mapConstructor;

	mapConstructor["Item"] = constructItem;
	mapConstructor["Creature"] = []() { return new Creature; };
	mapConstructor["Armor"] = []() { return new Armor; };
	mapConstructor["Weapon"] = []() { return new Weapon; };

	string sLookup;
	cout << "Please enter a string to look up: ";
	cin >> sLookup;

	function<XMLSerializable*()> pFunc = mapConstructor[sLookup];

	if(pFunc == NULL)
	{
		cout << "There is no such thing, man." << endl;
	}
	else
	{
		if(pFunc() != NULL)
		{
			cout << "Nice." << endl;
		}
		else
		{
			cout << "For some reason that did not work, but that makes no sense." << endl;
		}
	}

	return 0;
}
