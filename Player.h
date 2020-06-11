#pragma once
#include"Creature.h"

class Player :public Creature {
public:
	Player();
	Player(const string& name, const char symbol, int health, int damage, int gold, int level);
	Player(string& name);
	void levelUp();
	int getLevel()const;
	bool hasWon();
private:
	int p_level;
};