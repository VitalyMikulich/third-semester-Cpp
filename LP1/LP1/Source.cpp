#include <conio.h>
#include <cstring>
#include <iostream>
#include <fstream> 
#include <Windows.h>
#include <iomanip> 
using namespace std;
struct date 
{
	char daymon[6];
	int year;
};

class File {
	char name[50];
	date t;
	int size;
	int NumberOfHits;
public:
	void show();
	int getSize();
	int getNumberOfHits();
	char *getName();
	void readfile(File* spis, int n);
};

void File::readfile(File* spis, int n)
{
	for (int i = 0; i < n; i++) 
	{
		
		cout << "Input name: "; cin >>spis[i].name;
		cout << "Input date of created\n";
		cout << "Day.mon: "; cin >> spis[i].t.daymon;
		cout << "Year: "; cin >> spis[i].t.year;
		cout << "Input size in MB:"; cin >> spis[i].size;
		cout << "Number of Hits:"; cin >> spis[i].NumberOfHits;
		cout << "==============================" << endl;
	}
}

int File::getSize()
{
	return size;
}

int File::getNumberOfHits() 
{
	return NumberOfHits;
}

char *File::getName()
{
	return name;
}

void File::show()
{
	
	cout << "Name: " << name << endl;
	cout << "Was created: " << t.daymon << '.' << t.year << endl;
	cout << "Size: " << size << endl;
	cout << "Number of Hits: " << NumberOfHits << endl;
	cout << "==============================" << endl;
}

void alphabetspis(File *spis, int n)
{
	
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (strcmp(spis[j].getName(), spis[j + 1].getName()) > 0) {
				File tmp = spis[j];
				spis[j] = spis[j + 1];
				spis[j + 1] = tmp;
			}
		}
	}
}

void overSize(File* spis, int n)
{
	int limitsize;
	cout << "Input limit of size in MB - "; cin >> limitsize;
	for (int i = 0; i < n; i++)
		if (spis[i].getSize() > limitsize) spis[i].show();
}

void overNumberOfHits(File* spis, int n)
{
	int limitNumberOfHits;
	cout << "Input limit of number of hits - "; cin >> limitNumberOfHits;
	for (int i = 0; i < n; i++)
		if (spis[i].getNumberOfHits() > limitNumberOfHits) spis[i].show();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	File *spis;
	int n;
	cout << "Input number of files: "; cin >> n;
	spis = new File[n];
	spis->readfile(spis, n);
	int vibor;
	while (1) {
		cout << "\n Enter number of item:\n";
		cout << "Show file list  - press 1" << endl;
		cout << "List of files alphabetically - press 2" << endl;
		cout << "Over Size - press 3" << endl;
		cout << "Over Number of hits - press 4" << endl;
		cout << "Exit - press 5" << endl;
		cin >> vibor;
		switch (vibor)
		{
		case 1:
			system("cls");
			for (int i = 0; i < n; i++) 
				spis[i].show();
			break;
		case 2:
			system("cls");
			alphabetspis(spis, n);
			for (int i = 0; i < n; i++)
				spis[i].show();
			break;
		case 3:
			system("cls");
			overSize(spis, n);
			break;
		case 4: {
			system("cls");
			overNumberOfHits(spis, n);
			break; }
		case 5:
			system("cls");
			delete[] spis;
			cout << "Good-Bye!";
			exit(1);
			break;
		}
	}
		system("pause");
	return 0;
}

