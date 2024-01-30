#include <iostream>

void move(int x, int y, int *count, int maxX, int maxY) {
	if (x < maxX)
		move(x+1, y, count, maxX, maxY);

	if (y < maxY)
		move(x, y+1, count, maxX, maxY);

	if ((y == maxY)&&(x == maxX))
		(*count)++;
}

void move2(int x, int y, int *count, int maxX, int maxY, int countY) {
	if (x < maxX)
		move2(x+1, y, count, maxX, maxY, 0);

	if ((countY < 2) && (y < maxY))
		move2(x, y+1, count, maxX, maxY, countY+1);

	if ((y == maxY)&&(x == maxX))
		(*count)++;
}

int main() {
	int count1 = 0, count2 = 0, sizeX, sizeY;

	std::cout << "Введите размер по x:" << std::endl;
	std::cin >> sizeX;

	std::cout << "Введите размер по y:" << std::endl;
	std::cin >> sizeY;

	move(0, 0, &count1, sizeX, sizeY);
	move2(0, 0, &count2, sizeX, sizeY, 0);

	std::cout << "Всего " << count1 << " путей" << std::endl;
	std::cout << "Всего " << count2 << " путей, если нельзя идти дважды подряд вертикально" << std::endl;

	return 0;
}
