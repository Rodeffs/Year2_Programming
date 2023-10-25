#include "Array3D.h"
#include <iostream>
#include "MultiArray.h"

int main() {
	

	Arrays::Array3D<int> array(3, 3, 3);

	array.createFill(7);

	int values[] = {98, 27, 13};

	array.setValues01(values, 2);


	auto output = array.getValues02(1, 2);

	std::cout << output << std::endl;

	delete[] output;

	return 0;
}
