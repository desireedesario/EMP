#pragma once
#include <iostream>
#include <sstream>

#include "GameMap.h"
#include "GameActor.h"

struct GameCharacter : public GameActor{
	/*
	// When I don't do this I get this error:
	// Severity	Code	Description	Project	File	Line	Suppression State
	// Error	C2665	'GameCharacter::GameCharacter': no overloaded function could convert all the argument types	EMP	E:\BlizzardEntertainment\EMP\EMP\EMP.cpp	107	
	// I don't know why, shouldn't the base class constructor be called without me explicitly doing it?
	*/
	GameCharacter(GameMap* map) : GameActor(map) {
	}
	void initialize() {
		GameActor::initialize();
		name = "PlayerCharacter";
		symbol = '+';
		std::cout << "Setting player character symbol\n";
	}
};

/*
struct GameCharacter {
	int x;
	int y;
	int health;
	GameMap* theMap;

	GameCharacter(GameMap* map)
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
		// Check if x,y is within the height and width of the map
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
		if (theMap->tiles[newX][newY] != '-')
		// Logic if moving onto an object
		{
			std::cout << "Cannot move to this spot\n";
		}
		else if (newX != x || newY != y)
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

	void boostHealth()
	{
		health = health + 10;
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
*/