#include <iostream> 
#include <string>
using namespace std;

// Раса дает бонусы для силы, ловкости и интеллекта
// Герой не может быть животным

enum Rase
{
	HUMAN,
	GOBLIN,
	ORK,
	BEAST
};

// Общая схема персонажа
// Наличие интеллекта под вопросом 

struct Npc {
	int strenght = 0;
	int agility = 0;
	int intellect = 0;
	string name;
	int health = 100;
	int max_health = 100;
	unsigned int endurance = 100;
	int max_endurance = 100;
	int mana = 0;
	int max_mana = 60;
	unsigned int XP = 0;
	unsigned int LVL = 0;
	Rase race;
};

Npc spawn(Rase rase, int lvl)
{
	Npc enemy;
	if (rase == HUMAN)
	{
		enemy.strenght = 4 + lvl / 2; enemy.agility = 3 + lvl / 2; enemy.intellect = 3 + lvl / 2;
		enemy.max_health += -20 + enemy.strenght * 5; enemy.max_endurance += -20 + enemy.agility * 10;
		enemy.health = enemy.max_health; enemy.endurance = enemy.max_endurance;
	}
	if (rase == GOBLIN)
	{
		enemy.strenght = 2 + lvl / 2; enemy.agility = 6 + lvl / 2; enemy.intellect = 2 + lvl / 2;
		enemy.max_health += -40 + enemy.strenght * 5; enemy.max_endurance += -40 + enemy.agility * 10;
		enemy.health = enemy.max_health; enemy.endurance = enemy.max_endurance;
	}
	if (rase == ORK)
	{
		enemy.strenght = 6 + lvl / 2; enemy.agility = 3 + lvl / 2; enemy.intellect = 1 + lvl / 2;
		enemy.max_health += -40 + enemy.strenght * 5; enemy.max_endurance += -40 + enemy.agility * 10;
		enemy.health = enemy.max_health; enemy.endurance = enemy.max_endurance;
	}
	if (rase == BEAST)
	{
		enemy.strenght = 2 + lvl / 2; enemy.agility = 4 + lvl / 2;
		enemy.max_health += -40 + enemy.strenght * 5; enemy.max_endurance += -40 + enemy.agility * 10;
		enemy.health = enemy.max_health; enemy.endurance = enemy.max_endurance;
	}
	return enemy;
}

void fight(Npc& player)
{
	int x;
	x = rand() % 4;
	switch (x)
	{
	case 1:
	{
		Npc rober_1 = spawn(HUMAN, player.LVL);
		Npc rober_2 = spawn(HUMAN, player.LVL);
		Npc dog = spawn(BEAST, player.LVL);
		while (player.health >= 0 && (rober_1.health >= 0 && rober_2.health >= 0 && dog.health >= 0))
		{

		}
		break;
	}
	case 2:
	{

	}
	case 3:
	{

	}
	case 4:
	{

	}
	}
}

int main()
{
	cout << "\n\n\n   Enter the number of action";
	cout << "\n  1. Start game\n  2. Exit\n  ";
	int n;
	cin >> n;
	while (n > 2 || n < 1)
	{
		cout << endl << "  Wrong number. Repeat" << endl << "  ";
		cin >> n;
	}
	if (n == 2)
	{
		cout << "   Exiting...";
		return 0;
	}
	if (n == 1)
		cout << "   Game started!\n\n\n  ";
	cout << "  Create character\n\n  Input name. Nickname should be less\n  then 20 letters and ending \".\"\n\n  ";
	Npc Player;
	cin >> Player.name;
	cout << "\n  Allocate character points\n\n  Strenght will increase your health,\n  agility will help in attack,\n  intelligence will increse your mana pool\n\n";

	int state = 20;
	do
	{
		int r = 0;
		cout << "  You have " << state << " points.\n  Input strenght\n  ";
		cin >> r;
		if (state - r < 0)
		{
			cout << endl << "  Wrong number. Repeat";
			state = 20;
			Player.intellect = 0;
			Player.agility = 0;
			Player.strenght = 0;
			Player.max_endurance = 100;
			Player.max_health = 100;
			Player.max_mana = 60;
			continue;
		}
		else
		{
			Player.strenght += r;
			Player.max_health += Player.strenght * 5;
			state -= r;
		}
		cout << endl << endl;


		cout << "  You have " << state << " points.\n  Input agility\n  ";
		cin >> r;
		if (state - r < 0)
		{
			cout << endl << "  Wrong number. Repeat";
			state = 20;
			Player.intellect = 0;
			Player.agility = 0;
			Player.strenght = 0;
			Player.max_endurance = 100;
			Player.max_health = 100;
			Player.max_mana = 60;
			continue;
		}
		else
		{
			Player.agility += r;
			Player.max_endurance += Player.agility * 10;
			state -= r;
		}
		cout << endl << endl;


		cout << "  You have " << state << " points." << endl << "  Input intelligence" << endl << "  ";
		cin >> r;
		if (state - r < 0)
		{
			cout << endl << "  Wrong number. Repeat";
			state = 20;
			Player.intellect = 0;
			Player.agility = 0;
			Player.strenght = 0;
			Player.max_endurance = 100;
			Player.max_health = 100;
			Player.max_mana = 60;
			continue;
		}
		else
		{
			Player.intellect += r;
			Player.max_mana += Player.intellect * 15;
			state -= r;
		}
		cout << endl << endl;


		if (state == 0)
		{
			int n1;
			cout << endl << "  Do you accept? Input a number\n  1. Yes\n  2. No" << endl << endl << "  ";
			cin >> n1;
			while (n1 > 2 || n1 < 1)
			{
				cout << endl << "  Wrong number. Repeat" << endl << "  ";
				cin >> n1;
			}
			if (n1 == 1)
				continue;
			if (n1 == 2)
			{
				state = 20;
				Player.intellect = 0;
				Player.agility = 0;
				Player.strenght = 0;
				Player.max_endurance = 100;
				Player.max_health = 100;
				Player.max_mana = 60;
			}
		}
	} while (state > 0);
	cout << "\n  ";
	cout << "  " << Player.name;
	cout << "  Strenght: " << Player.strenght << "\n  Agility: " << Player.agility << "\n  Intellect: " << Player.intellect << "\n\n";
	cout << "  Max health: " << Player.max_health << "\n  Max endurance: " << Player.max_endurance << "\n  Max mana: " << Player.max_mana << "\n\n\n";

	cout << "  You wake up. It was a terrible night.\n  But you need to do anything with it.\n  This is the way. \n";

	while (Player.LVL != 6)
	{
		cout << "   Choose your way";
		int way = rand() % 3;
		switch (way)
		{
		case 1:
		{
			fight(Player);
			break;
		}
		{
		case 2:
			//	location();
			break;
		}
		case 3:
		{
			//	rill();
			break;
		}
		case 4:
		{
			//	sign();
			break;
		}
		}

	}
}




/*
1
Stefan.
8
8
4
1
*/