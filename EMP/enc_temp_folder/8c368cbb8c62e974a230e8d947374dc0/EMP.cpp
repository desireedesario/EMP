//the game loop
#include <iostream>
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define GAMEMAP_WIDTH 40
#define GAMEMAP_HEIGHT 16



struct GameMap {
	char tiles[GAMEMAP_WIDTH][GAMEMAP_HEIGHT];
	int width;
	int height;
	GameMap() {
		int x;
		int y;
		width = GAMEMAP_WIDTH;
		height = GAMEMAP_HEIGHT;
		for (x = 0; x < width; x++)
		{
			for (y = 0; y < height; y++)
			{
				tiles[x][y] = '-';
			}
		}
	}

	// use a mathimatical expression to use the vertical down 
	// game engine: reqad input, process input and something to draw. 
	// this is the main game loop
	// 
	void display()
	{
		int x;
		int y;
		for (y = 0; y < height; y++) // y-- will print from the top down 
		{
			for (x = 0; x < width; x++)
			{
				std::cout << tiles[x][y];
			}
			std::cout << std::endl;
		}
	}

	void clearTile(int x, int y)
	{
		if (x >= 0 && x < width && y >= 0 && y < height)
			tiles[x][y] = '-';
	}
};

struct GameEnemy {
	int health;
	int x;
	int y;
	GameMap* theMap;

	GameEnemy(GameMap* map)
	{
		theMap = map;
		health = 100;
		x = (rand() % theMap->width);
		y = (rand() % theMap->height);
		drawToMap();
	}

	bool move(int characterX, int characterY)
	{
		int newX;
		int newY;
		int attack = false;
		std::cout << "Enemy X: " << x << ", Char X: " << characterX << "\n";
		// Move enemy x 
		if (x > characterX)
		{
			newX = x - 1;
		}
		else if (x < characterX)
		{
			newX = x + 1;
		}
		else
		{
			newX = x;
		}
		if (newX >= theMap->width)
		{
			newX = theMap->width - 1;
		}

		if (y > characterY)
		{
			newY = y - 1;
		}
		else if (y < characterY)
		{
			newY = y + 1;
		}
		else 
		{
			newY = y;
		}
		if (newY >= theMap->height)
		{
			newY = theMap->height - 1;
		}
		if ((newX == characterX) && (newY == characterY))
		{
			std::cout << "ATTACK\n";
			newY = y;
			newX = x;
			attack = true;
		}
		else
		{
			std::cout << "New Enemy Position: " << newX << " " << newY << "\n";
			clearFromMap();
			x = newX;
			y = newY;
			drawToMap();
		}
		return attack;
	}

	void drawToMap()
	{
		theMap->tiles[x][y] = 'M';
	}

	void clearFromMap()
	{
		theMap->clearTile(x, y);
	}

};

struct GameCharacter {
	int x;
	int y;
	int health;
	GameMap* theMap;

	GameCharacter(GameMap*map)
	{
		x = 0;
		y = 0;
		health = 120;
		theMap = map;
		drawToMap();
	}

	bool move(int moveX, int moveY)
	{
		int newX = x + moveX;
		int newY = y + moveY;
		std::cout << "Should move character to: " << newX << " " << newY << "\n";
		std::cout << "Moving by: " << moveX << " " << moveY << "\n";
		std::cout << "Map is " << theMap->width << " " << theMap->height << "\n";
		if (newX < 0)
		{
			std::cout << newX << " < " << theMap->width << "Min width\n";
			newX = 0;
		}
		if (newX >= theMap->width)
		{
			newX = theMap->width - 1;
			std::cout << "max width\n";
		}
		if (newY < 0)
		{
			newY = 0;
			std::cout << "Min height\n";
		}
		if (newY >= theMap->height)
		{
			newY = theMap->height - 1;
			std::cout << "Max height\n";
		}
		bool moved = false;
		if (newX != x || newY != y)
		{
			moved = true;
			std::cout << "Character moved\n";
		}
		else {
			std::cout << "Character not moved\n";
		}
		if (moved)
		{
			clearFromMap();
			x = newX;
			y = newY;
			drawToMap();
		}
		return moved;
	}

	// void function do not return values 
	void clearFromMap()
	{
		theMap->clearTile(x, y);
	}

	void drawToMap()
	{
		theMap->tiles[x][y] = '+';
	}
};

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
		std::cout << "[S] Go Right" << std::endl;
		std::cout << "[D] Go Down\n" << std::endl;
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
	GameEnemy enemy(&map);

	std::ostringstream extraStatus;

	while (quitGame == false) {
		extraStatus.str("");
		c = sel.GetSelection();
		update.Run(c);
		moved = character.move(update.moveX, update.moveY);
		inAttackRange = enemy.move(character.x, character.y);
		if (inAttackRange)
		{
			if (enemy.health > 0) {
				character.health = damage(character.health);
			}

			if (update.attacking) {
				enemy.health = damage(enemy.health);
				if (enemy.health > 0) {
					extraStatus << "Enemy health: " << enemy.health << "\n";
				}else{
					extraStatus << "Enemy is dead\n";
				}
			}
		}
		map.display();
		std::cout << extraStatus.str();
		std::cout << "Health: " << character.health << "\n";
		if (character.health == 0)
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


// Notes
// endl is new line 