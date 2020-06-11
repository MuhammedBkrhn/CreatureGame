#include"Creature.h"
#include"Monster.h"
#include"Player.h"

void attackMonster(Player& p, Monster& m) {
	if (p.isDead())
		return;

	cout << " You hit the " << m.getName() << " for " << p.getDamage() << " damage " << endl;

	m.reduceHealth(p.getHealth());

	if (m.isDead())
	{
		cout << " You killed the" << m.getName() << endl;
		p.levelUp();
		cout << " You are now level " << p.getLevel() << endl;
		cout << " You found " << m.getGold() << " gold " << endl;
		p.addGold(m.getGold());
	}
}

void attackPlayer(Monster& m, Player& p) {
	if (m.isDead())
		return;

	p.reduceHealth(m.getDamage());
	cout << " The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
}

void fightMonster(Player& p) {
	
	Monster m{ Monster::getRandomMonster()};
	cout << " You have a encountred a " << m.getName() << "(" << m.getSymbol() << ")" << endl;

	while (!m.isDead() && !p.isDead()) {
		cout << " (R)un or (F)ight: ";
		char input;
		cin >> input;

		if (input == 'R' || input == 'r')
		{
			
			if (getRandomNumber(1, 2) == 1)
			{
				cout << " You successfully fled. "<<endl;
				return; 
			}
			else
			{
				cout << " You failed to flee. "<<endl;
				attackPlayer(m, p);
				continue;
			}
		}
		if (input == 'F' || input == 'f')
		{
			attackMonster(p, m);
			attackPlayer(m, p);
		}
	}
}

int main() {

	srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	rand(); // get rid of first result

	cout << " Enter your name: ";
	string playerName;
	cin >> playerName;

	Player p{playerName};
	std::cout << " Welcome, " << p.getName() <<endl;

	// If the player isn't dead and hasn't won yet, the game continues
	while (!p.isDead() && !p.hasWon())
		fightMonster(p);

	// At this point, the player is either dead or has won
	if (p.isDead())
	{
		cout << " You died at level " << p.getLevel() << " and with " << p.getGold() << " gold."<<endl;
		cout << " Too bad you can't take it with you! "<<endl;
	}
	else
	{
		cout << " You won the game with " << p.getGold() << " gold! " << endl;
	}

	return 0;
}