#include "Creature.h"

Creature::Creature()
    :c_name{"creature"},c_symbol{'c'},c_health{10},c_damage{1},c_gold{0}
{
}

Creature::Creature(const string& name, const char symbol, int health=0, int damage=0, int gold=0)
{
    if (health < 0 || damage < 0 || gold < 0 || name == "" || symbol == '\0') {
        Creature();
    }

    else{
        c_name = name;
        c_symbol = symbol;
        c_health = health;
        c_damage = damage;
        c_gold = gold;
    }   
}

Creature::Creature(const Creature& c)
{
    c_name = c.c_name;
    c_symbol = c.c_symbol;
    c_health = c.c_health;
    c_damage = c.c_health;
    c_gold = c.c_gold;
}

string Creature::getName() const
{
    return c_name;
}

char Creature::getSymbol() const
{
    return c_symbol;
}

int Creature::getHealth() const
{
    return c_health;
}

int Creature::getDamage() const
{
    return c_damage;
}

int Creature::getGold() const
{
    return c_gold;
}

void Creature::reduceHealth(int o_damage)
{
    c_health -= o_damage;
}

bool Creature::isDead()
{
    return (c_health <= 0);
}

void Creature::addGold(int gold)
{
    c_gold += gold;
}
