#pragma once

namespace conn {
	class Point2D {
	private:
		int mX;
		int mY;

	public:
		explicit Point2D(int x = 0, int y = 0);

		[[nodiscard]] int getX() const;
		[[nodiscard]] int getY() const;

		void setX(int x);
		void setY(int y);
	};
}
