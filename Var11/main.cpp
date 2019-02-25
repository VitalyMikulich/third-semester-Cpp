#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <ostream>
#include <fstream> 
using namespace std;

class Matrix
{
private:
	int **ptr;
	int n;
public:
	Matrix(); 
	Matrix(int n); 
	Matrix(int n, int **mas); 
	Matrix(const Matrix&c); 
	~Matrix(); 

	void umn(int num); 
	int& operator()(const int r, const int c) { return ptr[r - 1][c - 1]; }
	Matrix Minor(const int row, const int col) const; 
	int* operator[] (int i) { return(ptr[i]); } 
	Matrix& operator = (Matrix&c); 
	Matrix operator + (const Matrix&c); 
	Matrix operator - (const Matrix&c); 
	Matrix operator * (const Matrix&c); 
	Matrix& operator += (Matrix&c); 
	friend std::ostream& operator<< (std::ostream &, const Matrix&); 
	friend std::istream& operator>> (std::istream &, Matrix&); 
};

Matrix::Matrix() 
{
	n = 3; 
	ptr = new int*[n]; 
	for (int i = 0; i < n; i++)
		ptr[i] = new int[n];
	for (int ix = 0; ix < n; ix++) 
		for (int jx = 0; jx < 10; jx++)
			ptr[ix][jx] = rand() % 10 - 5;
}

Matrix::Matrix(int k)
{
	n = k; 
	ptr = new int*[n]; 
	for (int i = 0; i < n; i++)
		ptr[i] = new int[n];
	for (int ix = 0; ix < n; ix++) 
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = rand() % 10 - 5;
}
Matrix::Matrix(int k, int **mas)
{
	n = k; 
	ptr = new int*[n]; 
	for (int i = 0; i < n; i++)
		ptr[i] = new int[n];
	for (int ix = 0; ix < n; ix++) 
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = mas[ix][jx];
}
Matrix::Matrix(const Matrix &c)  
{
	n = c.n;
	ptr = new int*[n];
	for (int i = 0; i < n; i++)
		ptr[i] = new int[n];
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = c.ptr[ix][jx];
}

Matrix::~Matrix()
{
	for (int i = 0; i < n; i++) delete[] ptr[i];
	delete[] ptr;
}

void Matrix::umn(int num)
{
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = ptr[ix][jx] * num;
}



Matrix Matrix::Minor(const int row, const int col) const
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



Matrix& Matrix::operator = (Matrix &c)
{
	/*for (int i = 0; i < n; i++) delete[] ptr[i];
	delete[] ptr;*/
	n = c.n;
	ptr = new int*[n]; 
	for (int i = 0; i < n; i++)
		ptr[i] = new int[n];

	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = c.ptr[ix][jx];
	return *this;
}


Matrix& Matrix::operator += (Matrix &c)
{
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = ptr[ix][jx] + c.ptr[ix][jx];

	return *this;
}

Matrix Matrix::operator + (const Matrix &c)
{
	Matrix result(n);
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			result.ptr[ix][jx] = ptr[ix][jx] + c.ptr[ix][jx];

	return result;
}


Matrix Matrix::operator - (const Matrix &c)
{
	Matrix result(n);
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			result.ptr[ix][jx] = ptr[ix][jx] - c.ptr[ix][jx];
	return result;
}



Matrix Matrix::operator * (const Matrix &c)
{
	Matrix result(c.n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < c.n; j++)
		{
			result[i][j] = 0;
			for (int v = 0; v < c.n; v++)
			{
				result[i][j] += ptr[i][v] * c.ptr[v][j];
			}
		}
	}
	return result;
}


std::ostream& operator<< (std::ostream &out, const Matrix &c)
{
	for (int ix = 0; ix < c.n; ix++)
	{
		for (int jx = 0; jx < c.n; jx++)
		{
			out << c.ptr[ix][jx] << "\t";
		}
		std::cout << std::endl;
	}
	out << std::endl; 
	return out; 
}

std::istream& operator>> (std::istream &in, Matrix &c)
{
	std::cout << "ВВОД МАТРИЦЫ" << std::endl;
	for (int ix = 0; ix < c.n; ix++)
	{
		std::cout << "ВВОД " << ix + 1 << " СТРОКИ" << std::endl;
		for (int jx = 0; jx < c.n; jx++)
		{
			std::cout << "Ввод " << jx + 1 << " члена = ";
			in >> c.ptr[ix][jx]; 
		}
		std::cout << std::endl;
	}
	return in;
}


int main()
{
    setlocale(LC_ALL, "Russian");
	srand(time(0));
    int n, num, strdel, stdel;
    cout << "Введите размерность = "; cin >> n;
    Matrix NewM1(n);
    cout << "Ввод матрицы" << endl;
    cin >> NewM1;
    cout << "Вывод матрицы" << endl;
    cout << NewM1;
    cout << "Создаём новую (вторую) матрицу" << endl;
    Matrix NewM2;
    cout << "Выводим вторую матрицу" << endl;
    cout << NewM2;
    cout << "Приравниваем к первой" << endl;
    NewM2=NewM1;
    cout << "Выводим приравненную вторую матрицу" << endl;
    cout << NewM2;
    cout << "Делаем минор первой матрицы" << endl;
    cout << "Укажите строчку, которую следует вычеркнуть - ";
    cin >> strdel;
    cout << "Укажите столбик, который следует вычеркнуть - ";
    cin >> stdel;
    Matrix m1=NewM1.Minor(strdel,stdel);
    cout << "Выводим минор 1 матрицы" << endl;
    cout << m1;
    cout << "Делаем второй минор" << endl;
    cout << "Укажите строчку, которую следует вычеркнуть - ";
    cin >> strdel;
    cout << "Укажите столбик, который следует вычеркнуть - ";
    cin >> stdel;
    Matrix m2=NewM2.Minor(strdel,stdel);
    cout << "Выводим второй минор" << endl;
    cout << m2;
    cout << "Складываем первый и второй минор" << endl;
    Matrix m3 = m2+m1;
    cout << m3;
    cout << "Вычитаем из первого второй минор" << endl;
    Matrix m4 = m2-m1;
    cout << m4;
    cout << "Умножаем первый минор на второй" << endl;
    Matrix m5 = m1*m2;
    cout << m5;
    cout << "Прибавляем к первому минору второй" << endl;
    m1+=m2;
    cout << m1;
    cout << "Создаём массив объектов класса, который будет состять из 2 миноров" << endl;
    Matrix mas[1];
    mas[0]=m1;
    mas[1]=m2;
    cout << "Умножаем оба на константу" << endl;
    cout << "Введите константу = "; cin >> num;
    for(int i=0; i<2; i++)
    {
        mas[i].umn(num);
    }
    cout << endl << "Выводим полученные миноры" << endl;
    for(int i=0; i<2; i++)
    {
        cout << "Минор " << i+1 << endl;
        cout << mas[i];
        cout << endl;
    }
	system("pause");
    return 0;
	
}
