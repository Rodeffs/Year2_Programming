#include "Heroes.h"
#include "Army.h"
#include "Game.h"
#include <iostream>

int main() {
	return 0;
}

void doGame() {
	using namespace game;
	Game game{};
	AmericanArmyFactory armyFactory1{};
	RussianArmyFactory armyFactory2{};

	Army* army1 = game.createArmy(armyFactory1, 100);
	Army* army2 = game.createArmy(armyFactory2, 100);

	game.Fight(army1, army2);
}
