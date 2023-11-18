#pragma once

#include <string>
#include <sstream>

using std::string;

namespace game {

	enum class HeroType {Superman, Hulk, Batman};

	class Hero {
	public:
		explicit Hero() = default;

		virtual string toString() const = 0;

		virtual ~Hero() = default;
	};

	class Superman : public Hero {
	public:
		explicit Superman() : Hero() {}

		string toString() const override {
			std::stringstream ss{};
			ss << "Superman";
			return ss.str();
		}
	};

	class Hulk : public Hero {
	public:
		explicit Hulk() : Hero() {}

		string toString() const override {
			std::stringstream ss{};
			ss << "Hulk";
			return ss.str();
		}
	};

	class Batman : public Hero {
	public:
		explicit Batman() : Hero() {}

		string toString() const override {
			std::stringstream ss{};
			ss << "Batman";
			return ss.str();
		}
	};

	class HeroFactory {
	public:
		explicit HeroFactory() = default;
		virtual Hero* createHero(HeroType hero);
		virtual ~HeroFactory() = default;	
	};

	class OneHeroFactory {

	};

}
