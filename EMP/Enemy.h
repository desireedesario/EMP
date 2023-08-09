#pragma once
#include <iostream>
#include <sstream>

#include "GameMap.h"

struct GameEnemy {
	int health;
	int x;
	int y;
	GameMap* theMap;

	GameEnemy(GameMap* map)
	{
		theMap = map;
		initialize();
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

	void initialize() {
		health = 100;
		x = (rand() % theMap->width);
		y = (rand() % theMap->height);
		drawToMap();
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