//В задании требуется реализовать абстрактный базовый класс, объявив 
//в нем чистые виртуальные функции.Эти функции определяются в производных 
//классах.В базовом классе должны быть объявлены чистые виртуальные 
//функции ввода / вывода, которые реализуются в производных классах.
//Вызывающая программа должна продемонстрировать все варианты вызова 
//виртуальных функций с помощью указателей на базовый класс.Написать 
//внешнюю функцию вывода, получающую параметры типа базового класса 
//по ссылке и демонстрирующую виртуальный вызов. Создать абстрактный 
//базовый класс Triad(три целых числа) с виртуальными методами 
//увеличения(уменьшения) на 1. Создать производные классы 
//Date(дата, увеличение(уменьшение) на 1 день) и Time(время, увеличение(уменьшение) на 1 секунду).
#include <iostream>
#include <time.h>
using namespace std;


class Base
{
protected:
	int a;
	int b;
	int c;
public:
	Base();
	Base(int h, int m, int s);
	Base(const Base&q);
	virtual ~Base();
	virtual void show() = 0;
	virtual void get() = 0;
	virtual void change() = 0;
};



class Triad : public Base
{
public:
	Triad() : Base() {};
	Triad(int a, int b, int c) : Base(a, b, c) {};
	void show() {
		cout << "Первое число - " << a << endl
			<< "Второе число - " << b << endl
			<< "Третье число - " << c << endl;
	}
	void get() {
		int v1, v2, v3;
		cout << "Введите первое число - "; cin >> v1;
		cout << "Введите второе число - "; cin >> v2;
		cout << "Введите третье число - "; cin >> v3;
		a = v1;
		b = v2;
		c = v3;
	}
	void change() {
		int punkt;
		cout << "Выберите пункт: " << endl
			<< "+1 - 1" << endl
			<< "-1 - 2" << endl;
		cin >> punkt;
		cout << endl;
		switch (punkt)
		{
		case 1:
			a++;
			b++;
			c++;
			break;
		case 2:
			a--;
			b--;
			c--;
			break;
		default:
			break;
		}
	}
};

class Date : public Base
{
public:
	Date() : Base() {};
	Date(int a, int b, int c) : Base(a, b, c) {};
	void show() {
		cout << a << "/" << b << "/" << c << endl;
	}
	void get() {
		int v1, v2, v3;
		cout << "Введите год - "; cin >> v1;
		cout << "Введите месяц - "; cin >> v2;
		cout << "Введите день - "; cin >> v3;
		a = v1;
		b = v2;
		c = v3;
	}
	void change() {
		int punkt;
		cout << "Выберите пункт: " << endl
			<< "+1 - 1" << endl
			<< "-1 - 2" << endl;
		cin >> punkt;
		cout << endl;
		switch (punkt)
		{
		case 1:
			c++;
			break;
		case 2:
			c--;
			break;
		default:
			break;
		}
	}
};


class Time : public Base
{
public:
	Time() : Base() {};
	Time(int a, int b, int c) : Base(a, b, c) {};
	void show() {
		cout << a << ":" << b << ":" << c << endl;
	}
	void get() {
		int v1, v2, v3;
		cout << "Введите часы - "; cin >> v1;
		cout << "Введите минуты - "; cin >> v2;
		cout << "Введите секунды - "; cin >> v3;
		a = v1;
		b = v2;
		c = v3;
	}
	void change() {
		int punkt;
		cout << "Выберите пункт: " << endl
			<< "+1 - 1" << endl
			<< "-1 - 2" << endl;
		cin >> punkt;
		cout << endl;
		switch (punkt)
		{
		case 1:
			c++;
			break;
		case 2:
			c--;
			break;
		default:
			break;
		}
	}
};

Base::Base()
{
	a = 0;
	b = 0;
	c = 0;
}

Base::Base(int v1, int v2, int v3)
{
	a = v1;
	b = v2;
	c = v3;
}

Base::~Base()
{
	a = 0;
	b = 0;
	c = 0;
}

Base::Base(const Base&q)
{
	a = q.a;
	b = q.b;
	c = q.c;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	Base *p;
	Triad numbs1;
	p = &numbs1;
	p->get();
	p->show();
	p->change();
	p->show();

	Date date1;
	p = &date1;
	p->get();
	p->show();
	p->change();
	p->show();

	Time time2;
	p = &time2;
	p->get();
	p->show();
	p->change();
	p->show();
	system("pause");
}