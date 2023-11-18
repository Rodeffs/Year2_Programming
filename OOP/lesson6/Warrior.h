#pragma once

#include <string>
#include <sstream>

using std::string;

namespace game {

	class Warrior {
	public:
		explicit Warrior() = default;

		virtual string toString() const = 0;

		virtual ~Warrior() = default;
	};

	class Horseman : public Warrior {
	public:
		explicit Horseman() : Warrior() {}
	
		string toString() const override {
			std::stringstream ss{};
			ss << "Horseman";
			return ss.str();
		}
	};

	class Infantryman : public Warrior {
	public:
		explicit Infantryman() : Warrior() {}
	
		string toString() const override {
			std::stringstream ss{};
			ss << "Infantrymanman";
			return ss.str();
		}
	};


	class Archer : public Warrior {
	public:
		explicit Archer() : Warrior() {}
	
		string toString() const override {
			std::stringstream ss{};
			ss << "Archer";
			return ss.str();
		}
	};
}
