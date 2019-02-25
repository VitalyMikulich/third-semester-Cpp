#include "Matrix.h"
#include <iostream>
#include <math.h>
#include <cstdlib>

Matrix::Matrix() // ����������� �� ���������
{
    n = 3; // �� ��������� ������ ������� = 3
    ptr = new int*[n]; // �������� ����� � ������ ��� �������
    for (int i = 0; i < n; i++)
        ptr[i] = new int[n];
    for (int ix = 0; ix < n; ix++) // �������� ������� (��������� ������� ����������)
        for (int jx = 0; jx < 10; jx++)
            ptr[ix][jx] = rand()%10-5;
}

Matrix::Matrix (int k)
{
    n = k; // ������ �������
    ptr = new int*[n]; // �������� ����� � ������ ��� �������
    for (int i = 0; i < n; i++)
        ptr[i] = new int[n];
    for (int ix = 0; ix < n; ix++) // �������� ������� (��������� ������� ����������)
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = rand()%10-5;
}
Matrix::Matrix (int k, int **mas)
{
    n = k; // ������ �������
    ptr = new int*[n]; // �������� ����� � ������ ��� �������
    for (int i = 0; i < n; i++)
        ptr[i] = new int[n];
    for (int ix = 0; ix < n; ix++) // �������� �������
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = mas[ix][jx];
}
Matrix::Matrix (const Matrix &c)   // ����������� �����������
{
    n = c.n;
    for (int ix = 0; ix < n; ix++)
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = c.ptr[ix][jx];// ��������� ������� ���������� ������� c
}
// ����������
Matrix::~Matrix ()
{
    for (int i = 0; i < n; i++) delete [] ptr[i]; // ���������� �������
    delete [] ptr;
}
// ��������� �������
// �������� �� ���������
void Matrix::umn(int num)
{
    for (int ix = 0; ix < n; ix++)
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = ptr[ix][jx] * num;
}


// ������ �� ������� ����� (������� ���������� :)) )
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


// �������� ������������
Matrix& Matrix::operator = (Matrix &c)
{
    for (int i = 0; i < n; i++) delete [] ptr[i];
    delete [] ptr;
    n = c.n;
    ptr = new int*[n]; // �������� ����� � ������ ��� �������
    for (int i = 0; i < n; i++)
        ptr[i] = new int[n];

    for (int ix = 0; ix < n; ix++)
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = c.ptr[ix][jx];// ��������� ������� ���������� ������� c
    return *this;
}

// �������� +=
Matrix& Matrix::operator += (Matrix &c)
{
    for (int ix = 0; ix < n; ix++)
        for (int jx = 0; jx < n; jx++)
            ptr[ix][jx] = ptr[ix][jx] + c.ptr[ix][jx];

    return *this;
}
// �������� ��������
Matrix Matrix::operator + (const Matrix &c)
{
    Matrix result(n);
    for (int ix = 0; ix < n; ix++)
        for (int jx = 0; jx < n; jx++)
            result.ptr[ix][jx] = ptr[ix][jx] + c.ptr[ix][jx];

    return result;
}

// �������� ���������
Matrix Matrix::operator - (const Matrix &c)
{
    Matrix result(n);
    for (int ix = 0; ix < n; ix++)
        for (int jx = 0; jx < n; jx++)
            result.ptr[ix][jx] = ptr[ix][jx] - c.ptr[ix][jx];
    return result;
}


// �������� ���������
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

// ���������� ��������� <<
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
    out << std::endl; // ������� ������� �� ����� ������
    return out; // ��������� ������������� �����, ���� cout << x << y << z << ...
}
// ���������� ��������� >>
std::istream& operator>> (std::istream &in, Matrix &c)
{
    std::cout << "���� �������" << std::endl;
    for (int ix = 0; ix < c.n; ix++)
    {
        std::cout << "���� "<< ix+1 << " ������" << std::endl;
        for (int jx = 0; jx < c.n; jx++)
        {
            std::cout << "���� "<< jx+1 << " ����� = ";
            in >> c.ptr[ix][jx]; // ��������� �������
        }
        std::cout << std::endl;
    }
    return in;
}
