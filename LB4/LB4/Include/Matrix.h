#ifndef MATRIX_H
#define MATRIX_H
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

    void umn(int num); // умножение миноров на константу
    T& operator()(const int r, const int c) { return ptr[r-1][c-1]; }
    Matrix<T> Minor(const int row, const int col) const;
    T* operator[] (int i) { return ptr[i]; } // функция-оператор, которая достаёт член строки матрицы (перегруженная операция взятия индекса)
    Matrix<T>& operator = (Matrix<T>&); // оператор присваивания
    Matrix<T> operator + (const Matrix<T>&); // оператор сложения
    Matrix<T> operator - (const Matrix<T>&); // оператор вычитания
    Matrix<T> operator * (const Matrix<T>&); // оператор произведения
    Matrix<T>& operator += (Matrix<T>&);  // оператор дополнения

    friend std::ostream& operator<< <T> (std::ostream &, const Matrix<T>&); // перегруженный оператор вывода
    friend std::istream& operator>> <T> (std::istream &, const Matrix<T>&); // перегруженный оператор ввода
};


template <class T> Matrix<T>::Matrix() // конструктор по умолчанию
{
    n = 3; // по умолчанию размер матрицы = 3
    ptr = new T*[n]; // выделить место в памяти для матрицы
    for (int i = 0; i < n; i++)
        ptr[i] = new T[n];
    for (int ix = 0; ix < n; ix++) // рандомим матрицу (заполняем разными значениями)
        for (int jx = 0; jx < 10; jx++)
            ptr[ix][jx] = rand()%10-5;
}

template <class T> Matrix<T>::Matrix (int k)
{
    n = k; // размер матрицы
    ptr = new T*[n]; // выделить место в памяти для матрицы
    for (int i = 0; i < n; i++)
        ptr[i] = new T[n];
    for (int ix = 0; ix < n; ix++) // рандомим матрицу (заполняем разными значениями)
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = rand()%10-5;
}

template <class T> Matrix<T>::Matrix (int k, T **mas)
{
    n = k; // размер матрицы
    ptr = new T*[n]; // выделить место в памяти для матрицы
    for (int i = 0; i < n; i++)
        ptr[i] = new T[n];
    for (int ix = 0; ix < n; ix++) // копируем матрицу
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = mas[ix][jx];
}

template <class T> Matrix<T>::Matrix (const Matrix&c)   // конструктор копирования
{
    n = c.n;
    for (int ix = 0; ix < n; ix++)
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = c.ptr[ix][jx];// заполняем матрицу значениями матрицы c
}

template <class T> Matrix<T>::~Matrix () // деструктор
{
    for (int i = 0; i < n; i++) delete [] ptr[i]; // уничтожаем матрицу
    delete [] ptr;
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
    std::cout << "ВВОД МАТРИЦЫ" << std::endl;
    for (int ix = 0; ix < c.n; ix++)
    {
        std::cout << "ВВОД "<< ix+1 << " СТРОКИ" << std::endl;
        for (int jx = 0; jx < c.n; jx++)
        {
            std::cout << "Ввод "<< jx+1 << " члена = ";
            in >> c.ptr[ix][jx]; // заполняем матрицу
        }
        std::cout << std::endl;
    }
    return in;
}


// остальные функции
// Делаем из матрицы минор
template <class T> Matrix<T> Matrix<T>::Minor(const int row, const int col) const
  {
    Matrix<T> res(n - 1);
    if (row > 0 && row <= n && col > 0 && col <= n)
    {
      for (int r = 1; r <= (n - (row >= n)); r++)
      {
        for (int c = 1; c <= (n - (col >= n)); c++)
        {
          res(r - (r > row), c - (c > col)) = ptr[r-1][c-1];
        }
      }
    }
    return res;
  }

// умножаем на константу
template <class T> void Matrix<T>::umn(int num)
{
    for (int ix = 0; ix < n; ix++)
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = ptr[ix][jx] * num;
}

// оператор присваивания
template <class T> Matrix<T>& Matrix<T>::operator = (Matrix<T>&c)
{
    for (int i = 0; i < n; i++) delete [] ptr[i];
        delete [] ptr;
        n = c.n;
        ptr = new T*[n]; // выделить место в памяти для матрицы
        for (int i = 0; i < n; i++)
        ptr[i] = new T[n];

    for (int ix = 0; ix < n; ix++)
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = c.ptr[ix][jx];// заполняем матрицу значениями матрицы c
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

#endif // MATRIX_H
