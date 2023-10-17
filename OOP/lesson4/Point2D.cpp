#include "Point2D.h"

using namespace conn;

int Point2D::getX() const {
	return mX;
}

int Point2D::getY() const {
	return mY;
}

void Point2D::setX(int x) {
	mX = x;
}

void Point2D::setY(int y) {
	mY = y;
}

Point2D::Point2D(int x, int y) : mX{x}, mY{y} {}
