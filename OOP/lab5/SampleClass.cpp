#include "SampleClass.h"

void SampleClass::executeNPCListener() {
	if (NPCisActive())
		functionNPC();
}

void SampleClass::executeNPChangingListener() {
	if (NPChangingisActive())
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

void SampleClass::allowChanges(bool answer) {
	this->allow = answer;
}

void SampleClass::OnPropertyChanging(void (*f)()) {
	functionNPChanging = f;
}

void SampleClass::OnPropertyChanged(void (*f)()) {
	functionNPC = f;
}

void SampleClass::OnCollectionChanged(void (*f)()) {
	functionNCC = f;
}