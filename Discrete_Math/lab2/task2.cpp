#include <iostream>

float a(int n, float vals[]) {
	if (n == 0)
		return 1.0;
	if (n == 1)
		return -7.0;

	if (!vals[n])
		vals[n] = 5*a(n-1, vals) + 6*a(n-2, vals);

	return vals[n];
}

int main() {
	
	float values[100] = {0};
	values[0] = 1.0, values[1] = -7.0;

	std::cout << "a(100) = " << a(100, values) << std::endl;

	return 0;
}
