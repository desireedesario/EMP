#pragma once
#include <iostream>
#include <sstream>

#include "mymath.h"

#define GAMEMAP_WIDTH 40
#define GAMEMAP_HEIGHT 16


struct GameMap {
	char tiles[GAMEMAP_WIDTH][GAMEMAP_HEIGHT];
	int width;
	int height;
	char emptyTile;
	GameMap() {
		int x;
		int y;
		emptyTile = '-';
		width = GAMEMAP_WIDTH;
		height = GAMEMAP_HEIGHT;
		for (x = 0; x < width; x++)
		{
			for (y = 0; y < height; y++)
			{
				tiles[x][y] = emptyTile;
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

	bool positionInRange(int x, int y)
	{
		return x >= 0 && x < width && y >= 0 && y < height;
	}

	bool clearTile(int x, int y)
	{
		return drawTile(x, y, emptyTile);
	}

	bool drawTile(int x, int y, char c)
	{
		if (positionInRange(x, y))
		{
			tiles[x][y] = c;
			return true;
		}
		return false;
	}

	void clampPosition(int& x, int& y)
	{
		x = clamp(x, 0, width - 1);
		y = clamp(y, 0, height - 1);
	}
	
	bool tileIsEmpty(int x, int y)
	{
		clampPosition(x, y);
		return tiles[x][y] == emptyTile;
	}
};