#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Creature.h"

#include "XMLSerializable.h"

using namespace std;



void parseElement(istream & input, string sPrefix, XMLSerializable * pObject, vector<XMLSerializable*>& world, 
	map<string, function<XMLSerializable*()>>& mapConstructor)
{
	string sElementName;
	getline(input, sElementName, '>');

	if( sElementName.back() == '/' )
	{
		cout << sPrefix << "Empty element: " << sElementName << endl;
		return;
	}
	else
	{
		// cout << sPrefix << " Element - " << sElementName << endl;
		// cout << "Try to construct " << sElementName << " here." << endl;
		if (mapConstructor.count(sElementName) == 1)
		{
			// if (pObject == NULL)
			{
				pObject = mapConstructor[sElementName]();
				// cout << sElementName << endl;
				world.push_back(pObject);
				// cout << pObject << endl;
			}
		}
	}

	string sContent = "";

	while( true )
	{

		char c = input.get();

		while( c != '<' )
		{
			if( c != '\n' )
				sContent.push_back(c);

			c = input.get();
		}

		if( input.peek() == '/' )
		{
			input.get();
			string sEndElement;
			getline(input, sEndElement, '>');

			if( sEndElement != sElementName )
				cout << "Bad XML found" << endl;


			// cout << sPrefix << " : " << sElementName << " : "  << sContent << endl;
			if (pObject != NULL && mapConstructor.count(sElementName) == 0)
			{
				// cout << "set" + sElementName + "to" + sContent << endl;
				pObject->setElementData(sElementName, sContent);
				// cout << pObject << endl;
			}

			return;
		}
		else
		{
			parseElement(input, sPrefix + " > " + sElementName, pObject, world, mapConstructor);
		}
	}

}

void parseXML(string sFilename, vector<XMLSerializable*>& world, 
	map<string, function<XMLSerializable*()>>& mapConstructor)
{
	ifstream input;
	input.open(sFilename);

	while( input.get() != '?' );
	while( input.get() != '?' );
	
	if( input.get() != '>' )
	{
		cout << "Bad XML detected" << endl;
		return;
	}

	while( input.get() != '<' );

	parseElement(input, "> ", NULL, world, mapConstructor);

	input.close();
}

void dumpObjects(vector<XMLSerializable*>& objects)
{
	for (auto entity : objects)
	{
		entity->dumpObject();
	}
	cout << endl;
}

void createMapConstructor(map<string, function<XMLSerializable*()>>& mapIn)
{
	mapIn["Item"] = []() { return new Item; };
	mapIn["Creature"] = []() { return new Creature; };
	mapIn["Armor"] = []() { return new Armor; };
	mapIn["Weapon"] = []() { return new Weapon; };
}

void writeObjects(vector<XMLSerializable*>& objects)
{
	cout << "What file should we write to? ";
	string wFileName;
	cin >> wFileName;

	ofstream output;
	output.open(wFileName);

	output << "-" << endl
	<< "+<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;

	output << "<World>" << endl;

	for (auto entity : objects)
	{
		entity->writeFragment(output);
	}

	output << "</World>" << endl;

	output.close();
}

void parseObjects(map<string, function<XMLSerializable*()>>& mapIn, vector<XMLSerializable*>& objects)
{
	cout << "What file should we parse? ";
	string sFilename;
	cin >> sFilename;
	cout << endl;

	parseXML(sFilename, objects, mapIn);
}

int main(int argc, char * argv[])
{
	map<string, function<XMLSerializable*()>> mapConstructor;
	createMapConstructor(mapConstructor);
	vector<XMLSerializable*> world;

	parseObjects(mapConstructor, world);

	dumpObjects(world);

	writeObjects(world);

	return 0;
}