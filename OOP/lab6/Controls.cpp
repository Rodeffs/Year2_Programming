#include "Controls.h"

void Form::getPosition() {
	cout << "Вызван метод getPosition() у Form" << endl;
}

void Form::setPosition() {
	cout << "Вызван метод setPosition() у Form" << endl;
}

void Form::addControl() {
	cout << "Вызван метод addContol() у Form" << endl;
}


void Label::getPosition()  {
	cout << "Вызван метод getPosition() у Label" << endl;
}

void Label::setPosition()  {
	cout << "Вызван метод setPosition() у Label" << endl;
}

void Label::getText() {
	cout << "Вызван метод getText() у Label" << endl;
}

void Label::setText() {
	cout << "Вызван метод setText() у Label" << endl;
}


void TextBox::getPosition()  {
	cout << "Вызван метод getPosition() у TextBox" << endl;
}

void TextBox::setPosition()  {
	cout << "Вызван метод setPosition() у TextBox" << endl;
}

void TextBox::onValueChanged() {
	cout << "Вызван метод onValueChanged() у TextBox" << endl;
}


void ComboBox::getPosition()  {
	cout << "Вызван метод getPosition() у ComboBox" << endl;
}

void ComboBox::setPosition()  {
	cout << "Вызван метод setPosition() у ComboBox" << endl;
}

void ComboBox::getSeletecedIndex() {
	cout << "Вызван метод getSeletecedIndex() у ComboBox" << endl;
}

void ComboBox::setSelectedIndex() {
	cout << "Вызван метод setSelectedIndex() у ComboBox" << endl;
}

void ComboBox::getItems() {
	cout << "Вызван метод getItems() у ComboBox" << endl;
}

void ComboBox::setItems() {
	cout << "Вызван метод setItems() у ComboBox" << endl;
}


void Button::getPosition() {
	cout << "Вызван метод getPosition() у Button" << endl;
}

void Button::setPosition() {
	cout << "Вызван метод setPosition() у Button" << endl;
}

void Button::getText() {
	cout << "Вызван метод getText() у Button" << endl;
}

void Button::setText() {
	cout << "Вызван метод setText() у Button" << endl;
}

void Button::click() {
	cout << "Вызван метод click() у Button" << endl;
}
