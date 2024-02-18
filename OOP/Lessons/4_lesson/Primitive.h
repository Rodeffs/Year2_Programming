#pragma once
#include "Point2D.h"
#include <string>
#include <iostream>

namespace conn {
	class Primitive {
	private:
		Point2D mPosition;
		std::string mName;

	public:
		explicit Primitive(const std::string name, const Point2D& position);

		[[nodiscard]] std::string getName() const;  // nodiscard указывает на то, что принебрегать этим нельзя
		void setName(const std::string& name);

		Point2D getPosition() const;
		void setPosition(const Point2D& position);

		friend std::ostream& operator<<(std::ostream& out, const Primitive& primitive);
	};
}
