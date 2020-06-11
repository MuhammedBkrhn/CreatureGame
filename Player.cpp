#include "Player.h"

Player::Player():Creature(),p_level{1}
{
}

Player::Player(const string& name, const char symbol='@', int health=10, int damage=1, int gold=0, int level=1)
    :Creature(name,symbol,health,damage,gold)
{
    p_level = level;
}

Player::Player(string& name):Creature(name,'@',10,1,0)
{
    p_level = 1;
}

void Player::levelUp()
{
    p_level += 1;
    c_damage += 1;
}

int Player::getLevel() const
{
    return p_level;
}

bool Player::hasWon()
{
    return (p_level >= 20);
}
