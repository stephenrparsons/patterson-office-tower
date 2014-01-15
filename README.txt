make with 'make prog3' and run with './prog3'

************************************** Intro **************************************

Welcome to Patterson Office Tower, a game by Stephen Parsons.

You are a student at the University of Kentucky trying to survive in a competitive academic environment.

You start on the first floor and your goal is to make it as far up as you can. Don't forget that there is an intermezzo floor, so the 18th floor is deceptively actually the 19th! Along the way you will encounter professors and TAs who wish to fail you. Defeat them by turning in great assignments! If your smarts (experience) aren't good enough, you will have a hard time. Start with some easy professors in order to gain smarts and level up.

Your GPA (health) starts at 4.0. Luckily for you, the university allows you to be a student as long as you keep your GPA above 0.0. If you go below this, you will fail. Keep it high by defeating professors and TAs, but be careful that they don't keep failing you or you will lose the game. You're generally a good student, so your GPA will increase slowly as long as you are not challenging professors constantly.

Good luck!

************************************** Help **************************************

Command            | Function             Item       (symbol) | Use
---------------------------------------   ------------------------------------
wasd/arrow keys    | move                 Calculator      (c) | Prowess +1
h                  | help                 Helpful Friend  (f) | Reasoning +1
q                  | quit                 Meet w/ Jennifer(j) | Restore GPA
j                  | meet with Jennifer
move to creature   | attack
move to item       | pick up


Adversary          | Symbol | Level       Stat      | Description
---------------------------------------   ------------------------------------
Student            | s      | 1           Floor     | Current floor of POT
Teaching Assistant | t      | 3           GPA       | "health"
Researcher         | r      | 5           Smarts    | "experience"
Lecturer           | l      | 7           Status    | "level"
Professor          | p      | 11          Prowess   | "attack"
Department Chair   | C      | 17          Reasoning | "defense"
President          | P      | 30

You are marked with '@'. Press any key to return to game.

*********************************** Positioning **********************************

I chose to implement positioning in both the Entity class as member variables and in vectors of Entities
in the tiles. It was more difficult to write the basic movement functionality this way, but after getting
that done it made writing the rest of the program much easier. This is because each thing knows where it
is without having to ask the level above it, but the levels also know where things are without having
to ask them individually so it is easy to search through a level looking for something.

******************************* Extra Credit Things ******************************

-walls
-beautiful splash screen featuring image of Patterson Office Tower
-Patterson Office Tower theme (19 levels for 19 floors)
-ability to meet with Jennifer Doerge to restore your GPA
-rather than leveling up you advance through statuses beginning with 'Fresh Meat' and ending with 'Tenured Prof'
-ncurses integrated from the beginning, ability to use wasd or arrow keys
-UK logo in bottom corner of game