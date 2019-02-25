//� ������� ��������� ����������� ����������� ������� �����, ������� 
//� ��� ������ ����������� �������.��� ������� ������������ � ����������� 
//�������.� ������� ������ ������ ���� ��������� ������ ����������� 
//������� ����� / ������, ������� ����������� � ����������� �������.
//���������� ��������� ������ ������������������ ��� �������� ������ 
//����������� ������� � ������� ���������� �� ������� �����.�������� 
//������� ������� ������, ���������� ��������� ���� �������� ������ 
//�� ������ � ��������������� ����������� �����. ������� ����������� 
//������� ����� Triad(��� ����� �����) � ������������ �������� 
//����������(����������) �� 1. ������� ����������� ������ 
//Date(����, ����������(����������) �� 1 ����) � Time(�����, ����������(����������) �� 1 �������).
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
		cout << "������ ����� - " << a << endl
			<< "������ ����� - " << b << endl
			<< "������ ����� - " << c << endl;
	}
	void get() {
		int v1, v2, v3;
		cout << "������� ������ ����� - "; cin >> v1;
		cout << "������� ������ ����� - "; cin >> v2;
		cout << "������� ������ ����� - "; cin >> v3;
		a = v1;
		b = v2;
		c = v3;
	}
	void change() {
		int punkt;
		cout << "�������� �����: " << endl
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
		cout << "������� ��� - "; cin >> v1;
		cout << "������� ����� - "; cin >> v2;
		cout << "������� ���� - "; cin >> v3;
		a = v1;
		b = v2;
		c = v3;
	}
	void change() {
		int punkt;
		cout << "�������� �����: " << endl
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
		cout << "������� ���� - "; cin >> v1;
		cout << "������� ������ - "; cin >> v2;
		cout << "������� ������� - "; cin >> v3;
		a = v1;
		b = v2;
		c = v3;
	}
	void change() {
		int punkt;
		cout << "�������� �����: " << endl
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