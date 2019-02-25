#include <Windows.h>
#include <iostream>
using namespace std;

class Man {
protected:
	char name[50];
	int age;
	char pol[10];
	int weight;
public:
	Man();
	void rename();
	void changeAge();
	void changeWeight();
	void show();
};

Man::Man() {
	cout << "Введите имя: "; cin >> name;
	cout << "Возраст: "; cin >> age;
	cout << "Пол: "; cin >> pol;
	cout << "Вес: "; cin >> weight;
}

void Man::show() {
	cout << "==============================" << endl;
	cout << "Имя: " << name << endl;
	cout << "Возраст: " << age << endl;
	cout << "Пол: " << pol << endl;
	cout << "Вес: " << weight << endl;
	cout << "==============================" << endl;
}

void Man::rename() {
	cout << "Введите новое имя: "; cin >> name;
}

void Man::changeAge() {
	cout << "Введите новый возраст: "; cin >> age;
}

void Man::changeWeight() {
	cout << "Введите новый вес: "; cin >> weight;
}

class Student : public Man {
private:
	int year;
public:
	Student() : Man() {
		cout << "Введите год обучения: "; cin >> year;
	}
	void changeYear();
	void show();
	Student operator++(int);
	Student operator--(int);
};

void Student::changeYear() {
	cout << "Введите новый год обучения: "; cin >> year;
}

void Student::show() {
	cout << "==============================" << endl;
	cout << "Имя: " << name << endl;
	cout << "Возраст: " << age << endl;
	cout << "Пол: " << pol << endl;
	cout << "Вес: " << weight << endl;
	cout << "Год обучения: " << year << endl;
	cout << "==============================" << endl;
}

Student Student::operator++(int) {
	year++;
	return *this;
}

Student Student::operator--(int) {
	year--;
	return *this;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	/*Man person;
	person.show();
	person.rename();
	person.changeAge();
	person.changeWeight();
	person.show();*/
	Student person;
	person.show();
	person.rename();
	person.changeAge();
	person.changeWeight();
	person.changeYear();
	person.show();
	person++;
	person.show();
	person--;
	person.show();
	system("pause");
}