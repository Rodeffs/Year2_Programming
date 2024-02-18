#include "SampleClass.h"

void SampleClass::addNumber(int number) {
	if (NCCisActive())
		functionNCC();
	numbers.push_back(number);
}

void SampleClass::setValue(int val) {
	if (NPChangingisActive()) {
		if (functionNPChanging("value", value, val))
			this->value = val;
		else
			return;
	}

	else
		this->value = val;
}

void SampleClass::setSwitcher(bool val) {
	if (NPCisActive())
		functionNPC();
	this->switcher = val;
}

void SampleClass::OnPropertyChanging(bool (*f)(const string&, int, int)) {
	functionNPChanging = f;
}

void SampleClass::OnPropertyChanged(void (*f)()) {
	functionNPC = f;
}

void SampleClass::OnCollectionChanged(void (*f)()) {
	functionNCC = f;
}
