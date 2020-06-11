#pragma once
#include"Creature.h"
#include<array>
#include<string_view>
#include<cstdlib>
#include<ctime>

int getRandomNumber(int min, int max) {
	static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
	return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

class Monster :public Creature {
public:

	enum Type {
		DRAGON,
		ORG,
		SLIME,
		MAX_TYPES
	};

private:

	struct MonsterData {
		string_view m_name;
		char m_symbol;
		int m_health;
		int m_damage;
		int m_gold;
	};

	static constexpr array<MonsterData, Monster::MAX_TYPES>monsterData{
		{ {"dragon",'D',20,4,100}, {"orc",'o',4,2,25}, {"slime",'s',1,1,10} }
	};

public:

	Monster(Type type) :Creature{
		monsterData[type].m_name.data(),
		monsterData[type].m_symbol,
		monsterData[type].m_health,
		monsterData[type].m_damage,
		monsterData[type].m_gold,
	}
	{}

	static Monster getRandomMonster() {
		int num{ getRandomNumber(0,MAX_TYPES - 1) };
		return Monster{ static_cast<Type>(num) };
	}

};
