#pragma once

#include "iNotifyPropertyChanged.hpp"
#include "iNotifyPropertyChanging.hpp"
#include "iNotifyCollectionChanged.hpp"
#include <vector>

using std::vector;

class SampleClass : public iNotifyPropertyChanged, public iNotifyPropertyChanging, public iNotifyCollectionChanged {
private:
	vector<int> numbers;
	int value;
	bool switcher;
	bool allow;

	void executeNPCListener();

	void executeNPChangingListener();

	void executeNCCListener();

public:
	explicit SampleClass() : iNotifyPropertyChanged(false, nullptr), iNotifyPropertyChanging(false, true, nullptr), iNotifyCollectionChanged(false, nullptr) {}

	void addNumber(int number);

	void setValue(int val);

	void setSwitcher(bool val);

	void OnPropertyChanged(void (*f)()) override;

	void allowChanges(bool answer) override;

	void OnPropertyChanging(void (*f)()) override;

	void OnCollectionChanged(void (*f)()) override;
};
