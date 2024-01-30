#include <iostream>

float a(int n) {
	if (n == 0)
		return 1.0;
	if (n == 1)
		return -7.0;

	float answer = 5*a(n-1) + 6*a(n-2);

	std::cout << "a " << n << " = " << answer << std::endl;

	return answer;
}

int main() {

	std::cout << "a(100) = " << a(100) << std::endl;

	return 0;
}
