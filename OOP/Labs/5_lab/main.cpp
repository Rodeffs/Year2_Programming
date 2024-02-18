/* Задание:
Создать 3 интерфейса: iNotifyPropertyChanged (уведомление при изменении поля в классе), iNotifyPropertyChanging (уведомление о том, что сейчас вызвано изменение поля в классе, то есть что СЕЙЧАС произойдёт изменение) и iNotifyCollectionChanged (уведомление об изменении состояния коллекции: Added - добавление нового элемента; Removed - удаление существующего элемента; Changed - изменение существующего элемента)
У каждого такого интерфейса должен быть метод для подключения (добавления к классу), который называется add
А также метод отключения (удаления из класса), который называется remove

Эти интерфейсы должны подключаться к классу, который необходимо слушать, через наследование (то есть этот класс наследуется от интерфейса)
Внутри класса, на который мы хотим добавить слушатель, нужно добавить строчки, которые добавят слушатели на определённые действия (к примеру, после строки, где добавляется элемент в коллекцию)
После этого класс обрастёт новыми методами в виде .onAdded(), .onChanged() и так далее (их можно назвать как-то иначе или вовсе объединить в единый метод)
Это методы (или же метод) должны вызываться извне самого класса. Вот пример псевдокода, как выглядит создание нового слушателя (с учётом, что интерфейсы уже подключены к классу)

Collection coll = new Collection()
coll.onAdded(function() {
print("Added!")
})
coll.onChanged(function() {
print("Changed!")
})
coll.addElement(123)

Результатом этого кода будет то, что в коллекцию добавится элемент 123, а после сработает слушатель и вызовется его функция (callback), которая выведет текст "Added!" в консоль
*/

#include "SampleClass.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void f() {
	std::cout << "Property has changed" << std::endl;
}

bool g(const string& name, int oldVar, int newVar) {
	cout << "Property " << name << " change attempt, old value: " << oldVar << " new value: " << newVar << endl;
	bool allow = 0;
	cout << "Allow changes?" << endl;
	cin >> allow;
	if (allow)
		cout << "Changes allowed" << endl;
	else
		cout << "Changes not allowed" << endl;
	return allow;
}

int main() {

	SampleClass sample;

	sample.setValue(12);

	sample.AddNPCListener();
	sample.AddNPChangingListener();
	sample.AddNCCListener();

	sample.OnPropertyChanged(&f);
	sample.OnPropertyChanging(&g);
	sample.OnCollectionChanged(&f);

	sample.setValue(13);

	return 0;
}
