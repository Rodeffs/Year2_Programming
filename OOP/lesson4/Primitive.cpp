#include "Primitive.h"
#include <utility>

using namespace conn;

Primitive::Primitive(std::string name, const Point2D& position) : mName{std::move(name)}, mPosition{position} {}  // благодаря move() не нужно париться с указателями

std::string Primitive::getName() const {
	return mName;	
}

void Primitive::setName(const std::string& name) {
	mName = name;
}

Point2D Primitive::getPosition() const {
	return mPosition;
}

void Primitive::setPosition(const Point2D& position) {
	mPosition = position;
}


std::ostream& operator<<(std::ostream& out, const Primitive& primitive) {
	out << primitive.getName() << "\n";	
}
