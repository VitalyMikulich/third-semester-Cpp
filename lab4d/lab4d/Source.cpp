#include <iostream>
using namespace std;

/*	Создать шаблон класса «Квадратная матрица» – Matrix размерности nxn (см. задачу № 4, лаб. работа № 2).
*/

/* Определить класс «Квадратная матрица» – Matrix. Класс должен содержать несколько конструкторов,
в том числе конструктор копирования. Реализовать методы для сложения, вычитания, умножения матриц;
вычисления нормы матрицы. Перегрузить операции сложения, вычитания, умножения и присваивания для данного класса.
Создать массив объектов класса Matrix и передать его в функцию, которая изменяет  i-ю матрицу путем возведения ее
в квадрат. В головной программе вывести результат.
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
	T **ptr; // указатель на матрицу
	int n;// размер матрицы
public:
	Matrix(); // конструктор по умолчанию
	Matrix(int); // конструктор с параметрами (только размер матрицы)
	Matrix(int, T **mas); // конструктор с параметрами (размер матрицы + матрица)
	Matrix(const Matrix&); // конструктор копирования
	~Matrix(); // десструктор класса Matrix

	friend std::ostream& operator<< <T> (std::ostream &, const Matrix<T>&); // перегруженный оператор вывода
	friend std::istream& operator>> <T> (std::istream &, const Matrix<T>&); // перегруженный оператор ввода
	T nornamatrix(); // вычисление нормы матрицы
	T* operator[] (int i) { return(ptr[i]); } // функция-оператор, которая достаёт член строки матрицы (перегруженная операция взятия индекса)

	Matrix<T>& operator = (Matrix<T>&); // оператор присваивания
	Matrix<T> operator + (const Matrix<T>&); // оператор сложения
	Matrix<T> operator - (const Matrix<T>&); // оператор вычитания
	Matrix<T> operator * (const Matrix<T>&); // оператор произведения
	Matrix<T>& operator += (Matrix<T>&);  // оператор дополнения
	Matrix<T>& operator *= (Matrix<T>&); // операция домножения


};


template <class T> Matrix<T>::Matrix() :n(0), ptr(nullptr) {} // конструктор по умолчанию


template <class T> Matrix<T>::Matrix(int k)
{
	n = k; // размер матрицы
	ptr = new T*[n]; // выделить место в памяти для матрицы
	for (int i = 0; i < n; i++)
		ptr[i] = new T[n];
	for (int ix = 0; ix < n; ix++) // рандомим матрицу (заполняем разными значениями)
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = rand() % 10 - 5;
}

template <class T> Matrix<T>::Matrix(int k, T **mas)
{
	n = k; // размер матрицы
	ptr = new T*[n]; // выделить место в памяти для матрицы
	for (int i = 0; i < n; i++)
		ptr[i] = new T[n];
	for (int ix = 0; ix < n; ix++) // копируем матрицу
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = mas[ix][jx];
}

template <class T> Matrix<T>::Matrix(const Matrix&c)   // конструктор копирования
{
	n = c.n;
	ptr = new int*[n];
	for (int ix = 0; ix < n; ix++)
	{
		ptr[ix] = new int[n];
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = c.ptr[ix][jx];// заполняем матрицу значениями матрицы c
	}
}

template <class T> Matrix<T>::~Matrix() // деструктор
{
	for (int i = 0; i < n; i++) delete[] ptr[i]; // уничтожаем матрицу
	delete[] ptr;
}

// перегрузка оператора <<
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
	out << std::endl; // перенос маркера на новую строку
	return out; // позволяет множественный вывод, типа cout << x << y << z << ...
}

// перегрузка оператора >>
template <class T> std::istream& operator>> (std::istream &in, const Matrix<T> &c)
{
	std::cout << "Ввод матрицы: " << std::endl;
	for (int ix = 0; ix < c.n; ix++)
	{
		std::cout << "Ввод " << ix + 1 << " Строки: " << std::endl;
		for (int jx = 0; jx < c.n; jx++)
		{
			std::cout << "Ввод " << jx + 1 << " члена: ";
			in >> c.ptr[ix][jx]; // заполняем матрицу
		}
		std::cout << std::endl;
	}
	return in;
}



// остальные функции
// вычисляем норму матрицы
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

// оператор присваивания
template <class T> Matrix<T>& Matrix<T>::operator = (Matrix<T>&c)
{
	for (int i = 0; i < n; i++) delete[] ptr[i];
	delete[] ptr;
	n = c.n;
	ptr = new T*[n]; // выделить место в памяти для матрицы
	for (int i = 0; i < n; i++)
		ptr[i] = new T[n];

	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = c.ptr[ix][jx];// заполняем матрицу значениями матрицы c
	return *this;
}

// операция домножения
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

// оператор +=
template <class T> Matrix<T>& Matrix<T>::operator += (Matrix<T>&c)
{
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			ptr[ix][jx] = ptr[ix][jx] + c.ptr[ix][jx];

	return *this;
}
// оператор сложения
template <class T> Matrix<T> Matrix<T>::operator + (const Matrix<T>&c)
{
	Matrix<T> result(n);
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			result.ptr[ix][jx] = ptr[ix][jx] + c.ptr[ix][jx];

	return result;
}

// оператор вычитания
template <class T> Matrix<T> Matrix<T>::operator - (const Matrix<T>&c)
{
	Matrix<T> result(n);
	for (int ix = 0; ix < n; ix++)
		for (int jx = 0; jx < n; jx++)
			result.ptr[ix][jx] = ptr[ix][jx] - c.ptr[ix][jx];
	return result;
}


// оператор умножения
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
	cout << "Введите размерность: "; cin >> n;
	Matrix <int> m1(n);
	cin >> m1;
	cout << "Вывод матрицы: " << endl;
	cout << m1;
	cout << "Создаём вторую матрицу " << endl;
	Matrix <int> m2(n);
	cout << "Выводим вторую матрицу: " << endl;
	cout << m2;
	cout << "Норма первой матрицы: " << m1.nornamatrix() << endl;
	cout << "Норма второй матрицы: " << m2.nornamatrix() << endl;
	cout << endl << "Складываем первую и вторую матрицу: " << endl;
	Matrix <int> m3 = m2 + m1;
	cout << m3;
	cout << "Вычитаем из первой вторую матрицу: " << endl;
	Matrix <int> m4 = m2 - m1;
	cout << m4;
	cout << "Умножаем первую матрицу на вторую: " << endl;
	Matrix <int> m5 = m1 * m2;
	cout << m5;
	cout << "Прибавляем к первой матрицу вторую: " << endl;
	m1 += m2;
	cout << m1;

	cout << "Создаём массив объектов класса, который будет состять из двух матрицу" << endl;
	Matrix<int> mas[2];
	mas[0] = m1;
	mas[1] = m2;
	cout << "Возводим обе в квадрат " << endl;
	for (int i = 0; i < 2; i++)
	{
		mas[i] *= mas[i];
	}
	cout << endl << "Выводим полученные матрицы" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "Матрица " << i + 1 << ": " << endl;
		cout << mas[i];
		cout << endl;
	}
	system("pause");
	return 0;
}