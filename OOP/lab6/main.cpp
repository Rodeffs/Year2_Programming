/*
Создать симуляцию крокссплатформенного приложения пр помощи паттерна «абстрактная фабрика». Фабрика должна генерировать набор контроллов для различных операционных систем (Windows, Linux, MacOS).
Все контроллы наследуются от базового класса 
Contol (setPosition, getPosition).
Примеры реализующихся контроллов и их возможных методов
	Form (addContol)
	Label (setText, getText)
	TextBox (setText, getText, OnValueChanged)
	ComboBox (getSeletecedIndex, setSelectedIndex, setItems, getItems)
	Button (setText, getText, Click)
Приложение должно в зависимости от выбранной операционной системы создавать свой набор контроллов, размещать их на форме, делать с ними манипуляции (вызывать их методы(.
Графический интерфейс создавать не требуется! Контроллы в реальности на все методы просто пишут информацию о вызове метода в консоль по типу:«Вызван метод _____  у контролла ___»
*/

#include "Factories.h"

int main() {
	LinuxFactory gnu_linux;
	WindowsFactory windows;
	MacFactory mac;

	cout << "Linux:" << endl;

	auto gnu_linuxCombo = gnu_linux.createComboBox();
	gnu_linuxCombo->getSeletecedIndex();
	auto gnu_linuxLabel = gnu_linux.createLabel();
	gnu_linuxLabel->setText();

	cout << endl << "Windows:" << endl;

	auto windowsText = windows.createTextBox();
	windowsText->onValueChanged();
	auto windowsButton = windows.createButton();
	windowsButton->click();

	cout << endl << "MacOS:" << endl;

	auto macForm = mac.createForm();
       	macForm->addControl();
	auto macLabel = mac.createLabel();
	macLabel->getPosition();	

	return 0;
}
