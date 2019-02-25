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
	cout << "������� ���: "; cin >> name;
	cout << "�������: "; cin >> age;
	cout << "���: "; cin >> pol;
	cout << "���: "; cin >> weight;
}

void Man::show() {
	cout << "==============================" << endl;
	cout << "���: " << name << endl;
	cout << "�������: " << age << endl;
	cout << "���: " << pol << endl;
	cout << "���: " << weight << endl;
	cout << "==============================" << endl;
}

void Man::rename() {
	cout << "������� ����� ���: "; cin >> name;
}

void Man::changeAge() {
	cout << "������� ����� �������: "; cin >> age;
}

void Man::changeWeight() {
	cout << "������� ����� ���: "; cin >> weight;
}

class Student : public Man {
private:
	int year;
public:
	Student() : Man() {
		cout << "������� ��� ��������: "; cin >> year;
	}
	void changeYear();
	void show();
	Student operator++(int);
	Student operator--(int);
};

void Student::changeYear() {
	cout << "������� ����� ��� ��������: "; cin >> year;
}

void Student::show() {
	cout << "==============================" << endl;
	cout << "���: " << name << endl;
	cout << "�������: " << age << endl;
	cout << "���: " << pol << endl;
	cout << "���: " << weight << endl;
	cout << "��� ��������: " << year << endl;
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