#pragma once
#include <iostream>
#include <sstream>
#include <string>

#include "GameMap.h"
#include "RunPrefs.h"
#include "mymath.h"

template <typename T>
struct ActorStat {
	T minV;
	T maxV;
	T value;
	std::string name;

	ActorStat()
	{
		minV = 0;
		maxV = 100;
		value = 100;
		name = "Generic Stat";
	}

	void initialize(const char * i_name, T i_minV, T i_maxV, T i_value)
	{
		minV = i_minV;
		maxV = i_maxV;
		setValue(i_value);
		name = i_name;
	}
	T setValue(T newValue) {
		value = clamp(newValue, minV, maxV);
		return value;
	}
	T offset(T amount) {
		value = clamp(value - amount, minV, maxV);
		return value;
	}
	bool atMin() {
		return value == minV;
	}
	bool atMax() {
		return value == maxV;
	}
};

struct GameActor {
	int x;
	int y;
	GameMap* theMap;
	std::string name;
	char symbol;
	ActorStat <int> health;

	GameActor(GameMap* map)
	{
		theMap = map;
		health.initialize("health", 0, 100, 100);
		initialize();
		drawToMap();
	}

	virtual void initialize()
	{
		x = 0;
		y = 0;
		name = "GameActorBaseClass";
		symbol = 'A';
	}

	bool move(int moveX, int moveY)
	{
		int newX = x + moveX;
		int newY = y + moveY;
		theMap->clampPosition(newX, newY);

		bool moved = (newX != x || newY != y) && theMap->tileIsEmpty(newX, newY);

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
		theMap->drawTile(x, y, symbol);
	}
};