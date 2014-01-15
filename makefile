OBJECTS = parser.o GenericFactory.o Tools.o DungeonLevel.o Tile.o Entity.o Item.o Armor.o Character.o Consumable.o Creature.o Equipment.o Player.o Weapon.o XMLSerializable.o

HEADERS = parser.h EntityVector.h GenericFactory.h Tools.h DungeonLevel.h Tile.h Entity.h Item.h Armor.h Character.h Consumable.h Creature.h Equipment.h Player.h Weapon.h

prog1: $(OBJECTS) xml.o
	g++ --std=c++0x $^ -o prog1

prog2: $(OBJECTS) pa2.o
	g++ --std=c++0x $^ -o prog2

prog2test: $(OBJECTS) prog2test.o
	g++ --std=c++0x $^ -o prog2test

prog3: $(OBJECTS) pa3.o
	g++ -g --std=c++0x $^ -o prog3 -lncurses

la5: $(OBJECTS) la5.o
	g++ --std=c++0x $^ -o la5

%.o: %.cpp $(HEADERS)
	g++ -g --std=c++0x -c $< -o $@

clean:
	rm -f *.o prog1
	rm -f *.h.gch prog3
