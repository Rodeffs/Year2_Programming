#include "Array3D.h"
#include <iostream>
#include <vector>

using std::vector;

int main() {

	using namespace Arrays;

	Array3D<int> array(3, 3, 3);

	array.createFill(7);

	vector<int> values {98, 27, 13};

	array.setValues01(values, 2);

	auto out = array.getValues2(2);

	std::cout << out[0][0] << std::endl;

	return 0;
}
