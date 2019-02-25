#include <iostream>
using namespace std;

/*	������� ������ ������ ����������� ������� � Matrix ����������� nxn (��. ������ � 4, ���. ������ � 2).
*/

/* ���������� ����� ����������� ������� � Matrix. ����� ������ ��������� ��������� �������������,
� ��� ����� ����������� �����������. ����������� ������ ��� ��������, ���������, ��������� ������;
���������� ����� �������. ����������� �������� ��������, ���������, ��������� � ������������ ��� ������� ������.
������� ������ �������� ������ Matrix � �������� ��� � �������, ������� ��������  i-� ������� ����� ���������� ��
� �������. � �������� ��������� ������� ���������.
*/

#include <ostream>
#include <iostream>
#include <math.h>
#include <cstdlib>

template<class T> class Matrix;
template<class T> std::ostream& operator<< (std::ostream &, const Matrix<T>&);
template<class T> std::istream& operator>> (std::istream &, const Matrix<T>&);
template<class T> class Matrix
{
private:
	T **ptr; // ��������� �� �������
	int n;// ������ �������
public:
	Matrix(); // ����������� �� ���������
	Matrix(int); // ����������� � ����������� (������ ������ �������)
	Matrix(int, T **mas); // ����������� � ����������� (������ ������� + �������)
	Matrix(const Matrix&); // ����������� �����������
	~Matrix(); // ����������� ������ Matrix

	friend std::ostream& operator<< <T> (std::ostream &, const Matrix<T>&); // ������������� �������� ������
	friend std::istream& operator>> <T> (std::istream &, const Matrix<T>&); // ������������� �������� �����
	T nornamatrix(); // ���������� ����� �������
	T* operator[] (int i) { return(ptr[i]); } // �������-��������, ������� ������ ���� ������ ������� (������������� �������� ������ �������)

	Matrix<T>& operator = (Matrix<T>&); // �������� ������������
	Matrix<T> operator + (const Matrix<T>&); // �������� ��������
	Matrix<T> operator - (const Matrix<T>&); // �������� ���������
	Matrix<T> operator * (const Matrix<T>&); // �������� ������������
	Matrix<T>& operator += (Matrix<T>&);  // �������� ����������
	Matrix<T>& operator *= (Matrix<T>&); // �������� ����������


};


template <class T> Matrix<T>::Matrix() :n(0), ptr(nullptr) {} // ����������� �� ���������


template <class T> Matrix<T>::Matrix(int k)
{
	n = k; // ������ �������
	ptr = new T*[n]; // �������� ����� � ������ ��� �������
	for (int i = 0; i < n; i++)
		ptr[i] = new T[n];
	for (int ix = 0; ix < n; ix++) // �������� ������� (��������� ������� ����������)
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = rand() % 10 - 5;
}

template <class T> Matrix<T>::Matrix(int k, T **mas)
{
	n = k; // ������ �������
	ptr = new T*[n]; // �������� ����� � ������ ��� �������
	for (int i = 0; i < n; i++)
		ptr[i] = new T[n];
	for (int ix = 0; ix < n; ix++) // �������� �������
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = mas[ix][jx];
}

template <class T> Matrix<T>::Matrix(const Matrix&c)   // ����������� �����������
{
	n = c.n;
	ptr = new int*[n];
	for (int ix = 0; ix < n; ix++)
	{
		ptr[ix] = new int[n];
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = c.ptr[ix][jx];// ��������� ������� ���������� ������� c
	}
}

template <class T> Matrix<T>::~Matrix() // ����������
{
	for (int i = 0; i < n; i++) delete[] ptr[i]; // ���������� �������
	delete[] ptr;
}

// ���������� ��������� <<
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
	out << std::endl; // ������� ������� �� ����� ������
	return out; // ��������� ������������� �����, ���� cout << x << y << z << ...
}

// ���������� ��������� >>
template <class T> std::istream& operator>> (std::istream &in, const Matrix<T> &c)
{
	std::cout << "���� �������: " << std::endl;
	for (int ix = 0; ix < c.n; ix++)
	{
		std::cout << "���� " << ix + 1 << " ������: " << std::endl;
		for (int jx = 0; jx < c.n; jx++)
		{
			std::cout << "���� " << jx + 1 << " �����: ";
			in >> c.ptr[ix][jx]; // ��������� �������
		}
		std::cout << std::endl;
	}
	return in;
}



// ��������� �������
// ��������� ����� �������
template <class T> T Matrix<T>::nornamatrix()
{
	T norm_m = 0;
	for (int i = 0; i < n; i++)
	{
		T temp = 0;
		for (int j = 0; j < n; j++)
			temp += (T)fabs(ptr[i][j]);
		if (temp > norm_m)
			norm_m = temp;
	}
	return norm_m;
}

// �������� ������������
template <class T> Matrix<T>& Matrix<T>::operator = (Matrix<T>&c)
{
	for (int i = 0; i < n; i++) delete[] ptr[i];
	delete[] ptr;
	n = c.n;
	ptr = new T*[n]; // �������� ����� � ������ ��� �������
	for (int i = 0; i < n; i++)
		ptr[i] = new T[n];

	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = c.ptr[ix][jx];// ��������� ������� ���������� ������� c
	return *this;
}

// �������� ����������
template <class T> Matrix<T>& Matrix<T>::operator *=(Matrix<T>&c)
{
	int **tmp = new T *[n];
	for (int i = 0; i < n; i++)
	{
		tmp[i] = new T[n];
		for (int j = 0; j < n; j++)
			tmp[i][j] = 0;
	};

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				tmp[i][j] += ptr[i][k] * c.ptr[k][j];
	ptr = tmp;
	n = c.n;
	return *this;
}

// �������� +=
template <class T> Matrix<T>& Matrix<T>::operator += (Matrix<T>&c)
{
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = ptr[ix][jx] + c.ptr[ix][jx];

	return *this;
}
// �������� ��������
template <class T> Matrix<T> Matrix<T>::operator + (const Matrix<T>&c)
{
	Matrix<T> result(n);
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			result.ptr[ix][jx] = ptr[ix][jx] + c.ptr[ix][jx];

	return result;
}

// �������� ���������
template <class T> Matrix<T> Matrix<T>::operator - (const Matrix<T>&c)
{
	Matrix<T> result(n);
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			result.ptr[ix][jx] = ptr[ix][jx] - c.ptr[ix][jx];
	return result;
}


// �������� ���������
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
	int n;
	cout << "������� �����������: "; cin >> n;
	Matrix <int> m1(n);
	cin >> m1;
	cout << "����� �������: " << endl;
	cout << m1;
	cout << "������ ������ ������� " << endl;
	Matrix <int> m2(n);
	cout << "������� ������ �������: " << endl;
	cout << m2;
	cout << "����� ������ �������: " << m1.nornamatrix() << endl;
	cout << "����� ������ �������: " << m2.nornamatrix() << endl;
	cout << endl << "���������� ������ � ������ �������: " << endl;
	Matrix <int> m3 = m2 + m1;
	cout << m3;
	cout << "�������� �� ������ ������ �������: " << endl;
	Matrix <int> m4 = m2 - m1;
	cout << m4;
	cout << "�������� ������ ������� �� ������: " << endl;
	Matrix <int> m5 = m1 * m2;
	cout << m5;
	cout << "���������� � ������ ������� ������: " << endl;
	m1 += m2;
	cout << m1;

	cout << "������ ������ �������� ������, ������� ����� ������� �� ���� �������" << endl;
	Matrix<int> mas[2];
	mas[0] = m1;
	mas[1] = m2;
	cout << "�������� ��� � ������� " << endl;
	for (int i = 0; i < 2; i++)
	{
		mas[i] *= mas[i];
	}
	cout << endl << "������� ���������� �������" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "������� " << i + 1 << ": " << endl;
		cout << mas[i];
		cout << endl;
	}
	system("pause");
	return 0;
}