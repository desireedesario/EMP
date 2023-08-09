//the game loop
#include <iostream>
#include <sstream>
#include <stdlib.h> // srand, rand 
#include <time.h>   // time 
#include <conio.h> // For _getch()

#include "Player.h"
#include "GameMap.h"
#include "Enemy.h"


char readOneCharacter()
{
	char arrChar[15];

	arrChar[0] = '0';
	// width should only be one character
	std::cin.width(sizeof(arrChar));

	// get the input of the keystroke
	std::cin >> arrChar;

	return arrChar[0];
}

struct Selection {
	char GetSelection() {
		// Get Selection for attacking
		std::cout << "[W] Go Up" << std::endl;
		std::cout << "[A] Go Left" << std::endl;
		std::cout << "[S] Go Down" << std::endl;
		std::cout << "[D] Go Right\n" << std::endl;
		std::cout << "[X] Attack" << std::endl;
		std::cout << "please select: ";
		return readOneCharacter();
	};
};

struct Update {
	int moveX;
	int moveY;
	bool attacking;

	Update() {
		moveX = 0;
		moveY = 0;
		attacking = false;
	}

	void Run(char c) {
		//state machine
		// add "next to treasure"?
		moveX = 0;
		moveY = 0;
		if (c == 'W' || c == 'w') {
			std::cout << "Up" << std::endl;
			moveX = 0;
			moveY = -1;
		};
		if (c == 'A' || c == 'a') {
			std::cout << "Left" << std::endl;
			moveX = -1;
			moveY = 0;
		};
		if (c == 'D' || c == 'd') {
			std::cout << "Right" << std::endl;
			moveX = 1;
			moveY = 0;
		};
		if (c == 'S' || c == 's') {
			std::cout << "Down" << std::endl;
			moveX = 0;
			moveY = 1;
		};
		attacking = (c == 'x' || c == 'X');
		// std::cout << "Update move values: " << moveX << " " << moveY << "\n";
	}

};

int damage(int startHealth) {
	int newHealth;
	int damage = (rand() % 20);
	newHealth = startHealth - damage;
	if (newHealth < 0) {
		newHealth = 0;
	}
	return newHealth;
}

void death() {
	std::cout << "You are dead. :(\n Hit any key to accept your fate\n";
	readOneCharacter();
}

int main() {
	/* initialize random seed: */
	srand(time(NULL));
	char c = 0;
	bool quitGame = false;
	bool moved = false;
	bool inAttackRange = false;
	Selection sel;
	Update update;
	GameMap map;
	GameCharacter character(&map);
	// If I don't call this explicitly then the function defined on GameCharacter isn't called
	// and only the base class function is called.
	character.initialize();
	GameEnemy enemy(&map);

	std::ostringstream extraStatus;

	std::cout << character.name << std::endl;

	while (quitGame == false) {
		extraStatus.str("");
		c = sel.GetSelection();
		update.Run(c);
		moved = character.move(update.moveX, update.moveY);
		inAttackRange = enemy.move(character.x, character.y);
		if (inAttackRange)
		{
			if (enemy.health > 0) {
				character.health.setValue(damage(character.health.value));
			}

			if (update.attacking) {
				enemy.health = damage(enemy.health);
				if (enemy.health > 0) {
					extraStatus << "Enemy health: " << enemy.health << "\n";
				}
				else {
					enemy.clearFromMap();
					extraStatus << "Enemy is dead\n";
					character.health.offset(10);
					enemy.initialize();
				}
			}
		}
		map.display();
		std::cout << extraStatus.str();
		std::cout << "Health: " << character.health.value << "\n";
		if (character.health.atMin())
		{
			death();
			break;
		}
	}
};


int gameInputExample() {
	char arrChar[10];
	bool quitGame = false;

	arrChar[0] = '0';


	while (quitGame == false) {
		std::cout << "say something : ";

		// the width of the array should be the same length of the array
		std::cin.width(sizeof(arrChar));

		// get the input of user and place in array
		std::cin >> arrChar;

		// repeat the data 
		std::cout << "you said: " << arrChar << std::endl;

		// ignore the input if a user puts in 10,000 characters
		//std::cin.ignore(10000, '\n');

		// max is the biggest number that your machine can possibly have 
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');

		if (arrChar[0] == 'q') {
			quitGame = true;
		}

		// process and output the input of the user
		std::cout << std::endl;

	};
	return 0;
};

