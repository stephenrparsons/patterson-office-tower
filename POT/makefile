OBJECTS = parser.o GenericFactory.o Tools.o DungeonLevel.o Tile.o Entity.o Item.o Armor.o Character.o Consumable.o Creature.o Equipment.o Player.o Weapon.o XMLSerializable.o

HEADERS = parser.h EntityVector.h GenericFactory.h Tools.h DungeonLevel.h Tile.h Entity.h Item.h Armor.h Character.h Consumable.h Creature.h Equipment.h Player.h Weapon.h

prog3: $(OBJECTS) pa3.o
	g++ -g --std=c++0x $^ -o prog3 -lncurses

%.o: %.cpp $(HEADERS)
	g++ -g --std=c++0x -c $< -o $@

clean:
	rm -f *.o *.h.gch prog3
