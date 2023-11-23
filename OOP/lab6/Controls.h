#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Control {
public:
	explicit Control() = default;

	virtual void getPosition() = 0;

	virtual void setPosition() = 0;

	virtual ~Control() = default;
};


class Form : public Control {
public:
	explicit Form() : Control() {}

	void getPosition() override;

	void setPosition() override;

	void addControl();
};


class Label : public Control {
public:	
	explicit Label() : Control() {}

	void getPosition() override;

	void setPosition() override;

	void getText();

	void setText();
};


class TextBox : public Control {
public:
	explicit TextBox() : Control() {}

	void getPosition() override;

	void setPosition() override;

	void onValueChanged();
};


class ComboBox : public Control {
public:
	explicit ComboBox() : Control() {}

	void getPosition() override;

	void setPosition() override;

	void getSeletecedIndex();

	void setSelectedIndex();

	void getItems();

	void setItems();	
};


class Button : public Control {
public:
	explicit Button() : Control() {}

	void getPosition() override;

	void setPosition() override;

	void getText();

	void setText();

	void click();
};
