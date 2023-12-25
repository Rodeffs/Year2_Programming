#include "SampleClass.h"

void SampleClass::executeNPCListener() {
	if (NPCisActive())
		functionNPC();
}

void SampleClass::executeNPChangingListener() {
	if (NPChangingisActive() && allow)
		functionNPChanging();
}

void SampleClass::executeNCCListener() {
	if (NCCisActive())
		functionNCC();
}

void SampleClass::addNumber(int number) {
	executeNPChangingListener();
	if (allow)
		numbers.push_back(number);
}

void SampleClass::setValue(int val) {
	executeNPCListener();
	this->value = val;
}

void SampleClass::setSwitcher(bool val) {
	executeNPCListener();
	this->switcher = val;
}

void SampleClass::OnPropertyChanging(void (*f)(), bool *allowed) {
	allow = *allowed;
	functionNPChanging = f;
}

void SampleClass::OnPropertyChanged(void (*f)()) {
	functionNPC = f;
}

void SampleClass::OnCollectionChanged(void (*f)()) {
	functionNCC = f;
}
