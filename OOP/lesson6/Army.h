#pragma once

#include "Heroes.h"
#include "Warrior.h"
#include <vector>

using std::vector;

namespace game {

	class Army {
	public:
		explicit Army() = default;

		void addHero(Hero* hero) {
			mHeroes.push_back(hero);
		}

		void addWarrior(Warrior* warrior) {
			mWarriors.push_back(warrior);
		}


		virtual ~Army() = default;

	protected:
		vector<Hero*> mHeroes{};
		vector<Warrior*> mWarriors{};
	};

	class ArmyFactory {
	public:
		virtual Hero* createHero() = 0;
		virtual Warrior* createWarrior() = 0;
	};

	class AmericanArmyFactory : public ArmyFactory {
	public:
		Hero* createHero() override {
			return new Superman();
		}

		Warrior* createWarrior() override {
			return new Archer();
		}
	};

	class RussianArmyFactory : public ArmyFactory {
	public:
		Hero* createHero() override {
			return new Batman();
		}

		Warrior* createWarrior() override {
			return new Horseman();
		}
	};
}
