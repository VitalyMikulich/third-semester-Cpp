#include <conio.h>
#include <cstring>
#include <iostream>
#include <fstream> 
#include <Windows.h>
#include <iomanip> 
#include <ctime> 
using namespace std;

class Matrix {
private:
	int n, m;
	int **matrix;
public:
	Matrix(int x, int y);
	Matrix(const Matrix&ob);
	//~Matrix();
	void get();
	void show();
	void getMinor(const int row, const int col);
	Matrix operator + (Matrix &ob);
	Matrix operator - (Matrix &ob);
	Matrix operator * (int p);
	Matrix& operator = (Matrix &ob);
};

Matrix::Matrix(int x, int y) {
	n = x;
	m = y;
	matrix = new int*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[m];
}

//Matrix::~Matrix() {
//	for (int i = 0; i < n; i++)
//		delete[]matrix[i];
//	delete[] matrix;
//}

Matrix Matrix::operator*(int p)
{
	Matrix res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res.matrix[i][j] = matrix[i][j] * p;
	return res;
}

void Matrix::get() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			matrix[i][j] = rand() % 9 + 1;
}

Matrix Matrix::operator +(Matrix &ob)
{
	Matrix res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res.matrix[i][j] = matrix[i][j] + ob.matrix[i][j];
	return res;
}

Matrix Matrix::operator -(Matrix &ob)
{
	Matrix res(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res.matrix[i][j] = matrix[i][j] - ob.matrix[i][j];
	return res;
}

Matrix& Matrix::operator = (Matrix &ob)
{
	for (int i = 0; i < n; i++) delete[] matrix[i];
	delete[] matrix;
	n = ob.n;
	matrix = new int*[n]; // выделить место в памяти для матрицы
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];

	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			matrix[ix][jx] = ob.matrix[ix][jx];// заполняем матрицу значениями матрицы c
	return *this;
}

//Matrix Matrix::operator =(Matrix &ob)
//{
//	for (int i = 0; i < n; i++)
//		delete[]matrix[i];
//	delete[] matrix;
//	n = ob.n;
//	m = ob.m;
//	matrix = new int*[n];
//	for (int i = 0; i < n; i++)
//		matrix[i] = new int[m];
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			matrix[i][j] = ob.matrix[i][j];
//	return *(this);
//};


void Matrix::show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout.width(4);	     cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

//void showminor(int ** matr, int sizecol, int sizerow) {
//	for (int i = 0; i < sizecol; i++) {
//		for (int j = 0; j < sizerow; j++) {
//			cout.width(4);	     cout << matr[i][j] << ' ';
//		}
//		cout << endl;
//	}
//}

Matrix::Matrix(const Matrix &ob)   // конструктор копирования
{
	n = ob.n;
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			matrix[ix][jx] = ob.matrix[ix][jx];// заполняем матрицу значениями матрицы c
}

bool proverka(int el, int * temp, int qaunt)
{
	for (int i = 0; i < qaunt; i++)
		if (el == temp[i]) return 0;
	return 1;
}

void Matrix::getMinor()
{
	Matrix res(n - 1);
	if (row > 0 && row <= n && col > 0 && col <= n)
	{
		for (int r = 1; r <= (n - (row >= n)); r++)
		{
			for (int c = 1; c <= (n - (col >= n)); c++)
			{
				res(r - (r > row), c - (c > col)) = ptr[r - 1][c - 1];
			}
		}
	}
	return res;
}
/*void Matrix::getMinor()
{
	int qauntcolumns, qauntlines;
	cout << "Введите количество вычеркиваемых столбцов - "; cin >> qauntcolumns;
	cout << "Введите количество вычеркиваемых строк - "; cin >> qauntlines;
	cout << "Введите номера вычеркиваемых столбцов - ";
	int a = n - qauntcolumns;
	int * Temp[a], k=0, Tempi, Tempj;
	for (int i = 0; i < n; i++) {
		Tempi = i;
		for (int j = 0; j < m; j++) {
			Tempj = j;
			for (i = 0; i < n; i++) {
				for (j = 0; j < m; j++)
				{
					if (i != Tempi && j != Tempj)
					{
						Temp[k] = matrix[i][j];
						k++;
					}
				}
			}
			for (k = 0; k < 4; k++)
			{
				cout << Temp[k] << " ";
			}
			cout << endl;
		}
	}
}*/

{
	Matrix res(n - 1);
	if (row > 0 && row <= n && col > 0 && col <= n)
	{
		for (int r = 1; r <= (n - (row >= n)); r++)
		{
			for (int c = 1; c <= (n - (col >= n)); c++)
			{
				res(r - (r > row), c - (c > col)) = ptr[r - 1][c - 1];
			}
		}
	}
	return res;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));
	int n, m;
	cout << "Введите количество столбцов - "; cin >> n;
	cout << "Введите количество строк - "; cin >> m;
	Matrix ob(n, m);
	Matrix ob2(n, m);
	Matrix res(n, m);
	int vibor;
	while (1) {
		cout << "\n Выберите номер элемента\n";
		cout << "Получить матрицу  - нажмите 1" << endl;
		cout << "Сложить матрицы - нажмите 2" << endl;
		cout << "Отнять матрицы - нажмите 3" << endl;
		cout << "Умножить матрицу на число - нажмите 4" << endl;
		cout << "Получить минор - нажмите 5" << endl;
		cout << "Выход - нажмите 6" << endl;
		cin >> vibor;
		switch (vibor)
		{
		case 1:
			system("cls");
			ob.get();
			ob.show();
			cout << endl;
			ob2.get();
			ob2.show();
			break;
		case 2:
			system("cls");
			ob.show();
			cout << endl << "+" << endl;;
			ob2.show();
			cout << endl << "=" << endl;;
			res = ob + ob2;
			res.show();
			break;
		case 3:
			system("cls");
			ob.show();
			cout << endl << "-" << endl;;
			ob2.show();
			cout << endl << "=" << endl;;
			res = ob - ob2;
			res.show();
			break;
		case 4: 
			system("cls");
			int p;
			cout << "Введите число - ";
			cin >> p;
			ob.show();
			cout << "*" << endl << p << endl<<"="<<endl;
			res = ob * p;
			res.show();
			break;
		case 5:
			system("cls");
			ob.show();
			ob.getMinor();
			break;
		case 6:
			system("cls");
			cout << "До свидания!" << endl;
			ob.~Matrix();
			ob2.~Matrix();
			system("pause");
			exit(1);
			break;
		default: {
			system("cls");
			break;
		}
		}
	}
	system("pause");
	return 0;
}

