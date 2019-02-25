#include <iostream>
#include <ostream>
#include <math.h>
#include <cstdlib>
using namespace std;

/* ����������� ������������� ���� ������. ��� ���������� ������� ������ �������� ��� �������� �������:
�) ������-����� ������ ������������ ����� ���������� � ������� ������������� �����������;
�) ������ ��� ������-������ ������ ���������� �����������.

��������� �������� ������, ��������������� ������������� ������� ��������� ������� n x m � ������ ������ � ���.
������ ��� ������� �������� �����������. �������� ��������� �������������, � ��� ����� ����������� �����������.
����������� ������ ��� ����������� �� ������ ��� ������� � �����, ��� � ��������� ������,
� ����� ��� ��������� ������; ��������, ���������, ��������� �������.
����������� �������� ��������, ���������, ��������� � ������������ ��� ������� ������.
������� ������ �������� ������� ������ � �������� ��� � �������, ������� �������� ��� i-� ������� �� ����� �����
��������� �� ���������.

*/

template<class T> class Matrix;
template<class T> std::ostream& operator<< (std::ostream &, const Matrix<T>&);
template<class T> std::istream& operator>> (std::istream &, const Matrix<T>&);
template<class T> class Matrix
{
private:
	T **ptr; 
	int n;
public:
	Matrix(); 
	Matrix(int); 
	Matrix(int, T **mas);
	Matrix(const Matrix&);
	~Matrix(); 

	void umn(int num); 
	T& operator()(const int r, const int c) { return ptr[r - 1][c - 1]; }
	Matrix<T> Minor(const int row, const int col) const;
	T* operator[] (int i) { return ptr[i]; } 
	Matrix<T>& operator = (Matrix<T>&); 
	Matrix<T> operator + (const Matrix<T>&); 
	Matrix<T> operator - (const Matrix<T>&); 
	Matrix<T> operator * (const Matrix<T>&); 
	Matrix<T>& operator += (Matrix<T>&); 

	friend std::ostream& operator<< <T> (std::ostream &, const Matrix<T>&); 
	friend std::istream& operator>> <T> (std::istream &, const Matrix<T>&); 
};


template <class T> Matrix<T>::Matrix() :n(0), ptr(nullptr) 
{
	
}

template <class T> Matrix<T>::Matrix(int k)
{
	n = k; 
	ptr = new T*[n]; 
	for (int i = 0; i < n; i++)
		ptr[i] = new T[n];
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = rand() % 10 - 5;
}

template <class T> Matrix<T>::Matrix(int k, T **mas)
{
	n = k;
	ptr = new T*[n];
	for (int i = 0; i < n; i++)
		ptr[i] = new T[n];
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = mas[ix][jx];
}

template <class T> Matrix<T>::Matrix(const Matrix&c)
{
	n = c.n;
	ptr = new float*[n];
	for (int ix = 0; ix < n; ix++)
	{
		ptr[ix] = new float[n];
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = c.ptr[ix][jx];
	}
}

template <class T> Matrix<T>::~Matrix()
{
	for (int i = 0; i < n; i++) delete[] ptr[i];
	delete[] ptr;
}

template <class T> std::ostream& operator<< (std::ostream &out, const Matrix<T> &c)
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

template <class T> std::istream& operator>> (std::istream &in, const Matrix<T> &c)
{
	std::cout << "���� �������" << std::endl;
	for (int ix = 0; ix < c.n; ix++)
	{
		std::cout << "���� " << ix + 1 << " ������" << std::endl;
		for (int jx = 0; jx < c.n; jx++)
		{
			std::cout << "���� " << jx + 1 << " ����� = ";
			in >> c.ptr[ix][jx]; 
		}
		std::cout << std::endl;
	}
	return in;
}


template <class T> Matrix<T> Matrix<T>::Minor(const int row, const int col) const
{
	Matrix<T> res(n - 1);
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

template <class T> void Matrix<T>::umn(int num)
{
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = ptr[ix][jx] * num;
}

template <class T> Matrix<T>& Matrix<T>::operator = (Matrix<T>&c)
{
	n = c.n;
	ptr = new T*[n];
	for (int i = 0; i < n; i++)
		ptr[i] = new T[n];

	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = c.ptr[ix][jx];
	return *this;
}

template <class T> Matrix<T>& Matrix<T>::operator += (Matrix<T>&c)
{
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = ptr[ix][jx] + c.ptr[ix][jx];

	return *this;
}

template <class T> Matrix<T> Matrix<T>::operator + (const Matrix<T>&c)
{
	Matrix<T> result(n);
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			result.ptr[ix][jx] = ptr[ix][jx] + c.ptr[ix][jx];

	return result;
}

template <class T> Matrix<T> Matrix<T>::operator - (const Matrix<T>&c)
{
	Matrix<T> result(n);
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			result.ptr[ix][jx] = ptr[ix][jx] - c.ptr[ix][jx];
	return result;
}

template <class T> Matrix<T> Matrix<T>::operator * (const Matrix<T>&c)
{
	Matrix<T> result(c.n);
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

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, num, strdel, stdel;
    cout << "������� ����������� = "; cin >> n;
    Matrix<float> NewM1(n);
    cout << "���� �������" << endl;
    cin >> NewM1;
    cout << "����� �������" << endl;
    cout << NewM1;
    cout << "������ ����� (������) �������" << endl;
    Matrix<float> NewM2;
    cout << "������� ������ �������" << endl;
    cout << NewM2;
    cout << "������������ � ������" << endl;
    NewM2=NewM1;
    cout << "������� ������������ ������ �������" << endl;
    cout << NewM2;
    cout << "������ ����� ������ �������" << endl;
    cout << "������� �������, ������� ������� ���������� - ";
    cin >> strdel;
    cout << "������� �������, ������� ������� ���������� - ";
    cin >> stdel;
    Matrix<float> m1=NewM1.Minor(strdel, stdel);
    cout << "������� ����� 1 �������" << endl;
    cout << m1;
    cout << "������ ������ �����" << endl;
    cout << "������� �������, ������� ������� ���������� - ";
    cin >> strdel;
    cout << "������� �������, ������� ������� ���������� - ";
    cin >> stdel;
    Matrix<float> m2=NewM2.Minor(strdel, stdel);
    cout << "������� ������ �����" << endl;
    cout << m2;
    cout << "���������� ������ � ������ �����" << endl;
    Matrix <float>m3 = m2+m1;
    cout << m3;
    cout << "�������� �� ������� ������ �����" << endl;
    Matrix <float>m4 = m2-m1;
    cout << m4;
    cout << "�������� ������ ����� �� ������" << endl;
    Matrix <float>m5 = m1*m2;
    cout << m5;
    cout << "���������� � ������� ������ ������" << endl;
    m1+=m2;
    cout << m1;
    cout << "������ ������ �������� ������, ������� ����� ������� �� 2 �������" << endl;
    Matrix<float> mas[1];
    mas[0]=m1;
    mas[1]=m2;
    cout << "�������� ��� �� ���������" << endl;
    cout << "������� ��������� = "; cin >> num;
    for(int i=0; i<2; i++)
    {
        mas[i].umn(num);
    }
    cout << endl << "������� ���������� ������" << endl;
    for(int i=0; i<2; i++)
    {
        cout << "����� " << i+1 << endl;
        cout << mas[i];
        cout << endl;
    }
	system("pause");
    return 0;
}
