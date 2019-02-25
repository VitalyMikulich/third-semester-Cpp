#include "Matrix.h"
#include <iostream>
#include <math.h>
#include <cstdlib>

Matrix::Matrix() // конструктор по умолчанию
{
    n = 3; // по умолчанию размер матрицы = 3
    ptr = new int*[n]; // выделить место в памяти для матрицы
    for (int i = 0; i < n; i++)
        ptr[i] = new int[n];
    for (int ix = 0; ix < n; ix++) // рандомим матрицу (заполняем разными значениями)
        for (int jx = 0; jx < 10; jx++)
            ptr[ix][jx] = rand()%10-5;
}

Matrix::Matrix (int k)
{
    n = k; // размер матрицы
    ptr = new int*[n]; // выделить место в памяти для матрицы
    for (int i = 0; i < n; i++)
        ptr[i] = new int[n];
    for (int ix = 0; ix < n; ix++) // рандомим матрицу (заполняем разными значениями)
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = rand()%10-5;
}
Matrix::Matrix (int k, int **mas)
{
    n = k; // размер матрицы
    ptr = new int*[n]; // выделить место в памяти для матрицы
    for (int i = 0; i < n; i++)
        ptr[i] = new int[n];
    for (int ix = 0; ix < n; ix++) // копируем матрицу
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = mas[ix][jx];
}
Matrix::Matrix (const Matrix &c)   // конструктор копирования
{
    n = c.n;
    for (int ix = 0; ix < n; ix++)
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = c.ptr[ix][jx];// заполняем матрицу значениями матрицы c
}
// деструктор
Matrix::~Matrix ()
{
    for (int i = 0; i < n; i++) delete [] ptr[i]; // уничтожаем матрицу
    delete [] ptr;
}
// остальные функции
// умножаем на константу
void Matrix::umn(int num)
{
    for (int ix = 0; ix < n; ix++)
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = ptr[ix][jx] * num;
}


// Делаем из матрицы минор (немножк обманываем :)) )
Matrix Matrix::Minor(const int row, const int col) const
  {
    Matrix res(n - 1);
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


// оператор присваивания
Matrix& Matrix::operator = (Matrix &c)
{
    for (int i = 0; i < n; i++) delete [] ptr[i];
    delete [] ptr;
    n = c.n;
    ptr = new int*[n]; // выделить место в памяти для матрицы
    for (int i = 0; i < n; i++)
        ptr[i] = new int[n];

    for (int ix = 0; ix < n; ix++)
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = c.ptr[ix][jx];// заполняем матрицу значениями матрицы c
    return *this;
}

// оператор +=
Matrix& Matrix::operator += (Matrix &c)
{
    for (int ix = 0; ix < n; ix++)
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = ptr[ix][jx] + c.ptr[ix][jx];

    return *this;
}
// оператор сложения
Matrix Matrix::operator + (const Matrix &c)
{
    Matrix result(n);
    for (int ix = 0; ix < n; ix++)
        for (int jx = 0; jx < n; jx++)
            result.ptr[ix][jx] = ptr[ix][jx] + c.ptr[ix][jx];

    return result;
}

// оператор вычитания
Matrix Matrix::operator - (const Matrix &c)
{
    Matrix result(n);
    for (int ix = 0; ix < n; ix++)
        for (int jx = 0; jx < n; jx++)
            result.ptr[ix][jx] = ptr[ix][jx] - c.ptr[ix][jx];
    return result;
}


// оператор умножения
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

// перегрузка оператора <<
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
    out << std::endl; // перенос маркера на новую строку
    return out; // позволяет множественный вывод, типа cout << x << y << z << ...
}
// перегрузка оператора >>
std::istream& operator>> (std::istream &in, Matrix &c)
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
