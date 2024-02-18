#pragma once

#include "iNotifyPropertyChanged.hpp"
#include "iNotifyPropertyChanging.hpp"
#include "iNotifyCollectionChanged.hpp"
#include <vector>

using std::vector;

class SampleClass : virtual public iNotifyPropertyChanged, virtual public iNotifyPropertyChanging, virtual public iNotifyCollectionChanged {
private:
	vector<int> numbers;
	int value;
	bool switcher;

public:
	explicit SampleClass() : iNotifyPropertyChanged(false, nullptr), iNotifyPropertyChanging(false, nullptr), iNotifyCollectionChanged(false, nullptr) {}

	void addNumber(int number);

	void setValue(int val);

	void setSwitcher(bool val);

	void OnPropertyChanged(void (*f)()) override;

	void OnPropertyChanging(bool (*f)(const string&, int, int)) override;

	void OnCollectionChanged(void (*f)()) override;
};
