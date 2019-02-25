#define TIMENEW_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
using namespace std;


class TimeL
{
protected:
	int Hour; 
	int Min; 
	int Sec; 
	virtual void printMyself(std::ostream& out) const; 
public:
	TimeL(); 
	TimeL(int h, int m, int s); 
	TimeL(const TimeL&c); 
	virtual ~TimeL();
	virtual void text(void) = 0;
	friend std::ostream& operator<< (std::ostream &, const TimeL&); 
};


class TimeFull : public TimeL
{
protected:
	virtual void printMyself(std::ostream& out) const; 
	
public:
	TimeFull() :TimeL() {};
	TimeFull(int h, int m, int s) :TimeL(h, m, s) {}; 
	void text(void) {
		cout << "ppp" << endl;
	}
};


TimeL::TimeL() 
{
	time_t currentTime; 
	struct tm *localTime; 
	time(&currentTime);                   
	localTime = localtime(&currentTime);  
	Hour = localTime->tm_hour; 
	Min = localTime->tm_min;
	Sec = localTime->tm_sec;
}

TimeL::TimeL(int h, int m, int s) 
{
	if (h > 24 || h < 0) Hour = 0; 
	else Hour = h;
	if (m > 60 || h < 0) Min = 0;
	else Min = m;
	if (m > 60 || h < 0) Sec = 0;
	else Sec = s;
}
TimeL::TimeL(const TimeL&c) 
{
	Hour = c.Hour; 
	Min = c.Min;
	Sec = c.Sec;
}
TimeL::~TimeL() 
{
	Hour = 0; 
	Min = 0;
	Sec = 0;
}

void TimeL::printMyself(std::ostream& out) const 
{
	out << Hour << ":" << Min << ":" << Sec;
};


std::ostream& operator<< (std::ostream &out, const TimeL&c)
{
	c.printMyself(out); 
	return out; 
}

void TimeFull::printMyself(std::ostream& out) const 
{
	out << Hour << ":" << Min << ":" << Sec;
	if (Hour > 5 && Hour <= 9) out << " (утро)"; 
	else if (Hour > 9 && Hour <= 17) out << " (день)";
	else if (Hour > 17 && Hour <= 22) out << " (вечер)"; 
	else if (Hour > 22 || Hour <= 5) out << " (ночь)";
};

int main()
{
	setlocale(LC_ALL, "");
	TimeFull New;
	//TimeL New2;
	//cout << "Текущее время в краткой форме: " << New2 << endl;
	cout << "Текущее время в полной форме: " << New << endl;
	int hour, min, sec;
	cout << "Введите часы: "; cin >> hour;
	cout << "Введите минуты: "; cin >> min;
	cout << "Введите секунды: "; cin >> sec;
	//TimeL New4c(hour, min, sec);
	TimeFull New3c(hour, min, sec);
	//cout << "Введённое время в краткой форме: " << New4c << endl;
	cout << "Введённое время в полной форме: " << New3c << endl;
	New3c.text();
	system("pause");
}