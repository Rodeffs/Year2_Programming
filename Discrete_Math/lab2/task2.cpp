#include <iostream>

float a(int n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return -7;

	return 5*a(n-1) + 6*a(n-2);
}

int main() {

	std::cout << a(100) << std::endl;

	return 0;
}
