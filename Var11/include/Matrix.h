#ifndef MATRIX_H
#define MATRIX_H
#include <ostream>

class Matrix
{
private:
    int **ptr; // ��������� �� �������
    int n;// ������ �������
public:
    Matrix(); // ����������� �� ���������
    Matrix(int n); // ����������� � ����������� (������ ������ �������)
    Matrix(int n, int **mas); // ����������� � ����������� (������ ������� + �������)
    Matrix(const Matrix&c); // ����������� �����������
    ~Matrix(); // ����������� ������ Matrix

    void umn(int num); // ��������� ������� �� ���������
    int& operator()(const int r, const int c) { return ptr[r-1][c-1]; }
    Matrix Minor(const int row, const int col) const; // �������, ������� ���������� ������� � �����
    int* operator[] (int i) { return(ptr[i]); } // �������-��������, ������� ������ ���� ������ ������� (������������� �������� ������ �������)
    Matrix& operator = (Matrix&c); // �������� ������������
    Matrix operator + (const Matrix&c); // �������� ��������
    Matrix operator - (const Matrix&c); // �������� ���������
    Matrix operator * (const Matrix&c); // �������� ������������
    Matrix& operator += (Matrix&c);  // �������� ����������
    friend std::ostream& operator<< (std::ostream &, const Matrix&); // ������������� �������� ������
    friend std::istream& operator>> (std::istream &, Matrix&); // ������������� �������� �����
};
#endif // MATRIX_H
