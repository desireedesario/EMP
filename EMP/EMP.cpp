//the game loop
#include <iostream>

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

	void display()
	{
		int x;
		int y;
		for (y = 0; y < height; y++)
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

struct GameCharacter {
	int x;
	int y;
	GameMap* theMap;

	GameCharacter(GameMap*map)
	{
		x = 0;
		y = 0;
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

	void clearFromMap()
	{
		theMap->clearTile(x, y);
	}

	void drawToMap()
	{
		theMap->tiles[x][y] = '+';
	}
};


struct Selection {

	char up = "W" || "w";
	char left = "A" || "a";
	char right = "D" || "d";
	char down = "S" || "s";

	// void function do not return values 
	char GetSelection() {
		//std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
		std::cout << "[W] Go Up" << std::endl;
		std::cout << "[A] Go Left" << std::endl;
		std::cout << "[S] Go Right" << std::endl;
		std::cout << "[D] Go Down\n" << std::endl;
		std::cout << "please select: ";

		char arrChar[15];

		arrChar[0] = '0';
		// width should only be one character
		std::cin.width(sizeof(arrChar));

		// get the input of the keystroke
		std::cin >> arrChar;

		return arrChar[0];
		
	};
};

struct Update {
	int moveX;
	int moveY;

	Update() {
		moveX = 0;
		moveY = 0;
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
		std::cout << "Update move values: " << moveX << " " << moveY << "\n";
	}

};

int main() {
	char c = 0;
	bool quitGame = false;
	Selection sel;
	Update update;
	GameMap map;
	GameCharacter character(&map);


	while (quitGame == false) {
		c = sel.GetSelection();
		update.Run(c);
		character.move(update.moveX, update.moveY);
		map.display();


		if (c == 'Q' || c == 'q') {
			quitGame = true;
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