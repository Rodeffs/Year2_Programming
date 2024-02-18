#include "Controls.h"

class OSFactory {
public:
	explicit OSFactory() = default;

	virtual Form* createForm() = 0;  // нужно каждому методу дать либо пустую реализацию, либо сделать чисто виртуальными, иначе не скомпилируется

	virtual Label* createLabel() = 0;

	virtual TextBox* createTextBox() = 0;

	virtual ComboBox* createComboBox() = 0;

	virtual Button* createButton() = 0;

	virtual ~OSFactory() = default;
};


class LinuxFactory : public OSFactory {
public:
	explicit LinuxFactory() : OSFactory() {}

	Form* createForm() override {
		return new Form();
	}

	Label* createLabel() override {
		return new Label();
	}

	TextBox* createTextBox() override {
		return new TextBox();
	}

	ComboBox* createComboBox() override {
		return new ComboBox();
	}

	Button* createButton() override {
		return new Button();
	}
};


class WindowsFactory : public OSFactory {
public:
	explicit WindowsFactory() : OSFactory() {}

	Form* createForm() override {
		return new Form();
	}

	Label* createLabel() override {
		return new Label();
	}

	TextBox* createTextBox() override {
		return new TextBox();
	}

	ComboBox* createComboBox() override {
		return new ComboBox();
	}

	Button* createButton() override {
		return new Button();
	}
};


class MacFactory : public OSFactory {
public:
	explicit MacFactory() : OSFactory() {}

	Form* createForm() override {
		return new Form();
	}

	Label* createLabel() override {
		return new Label();
	}

	TextBox* createTextBox() override {
		return new TextBox();
	}

	ComboBox* createComboBox() override {
		return new ComboBox();
	}

	Button* createButton() override {
		return new Button();
	}
};
