#pragma once
#include<iostream>
#include<string>
using namespace std;

class Creature {
public:
	Creature();
	Creature(const string& name, const char symbol, int health, int damage, int gold);
	Creature(const Creature& c);

	string getName() const;
	char getSymbol()const;
	int getHealth()const;
	int getDamage()const;
	int getGold()const;

	void reduceHealth(int o_damage);
	bool isDead();
	void addGold(int gold);

protected:
	string c_name;
	char c_symbol;
	int c_health;
	int c_damage;
	int c_gold;
};