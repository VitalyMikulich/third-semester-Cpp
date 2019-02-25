#ifndef MATRIX_H
#define MATRIX_H
#include <ostream>

class Matrix
{
private:
    int **ptr; // указатель на матрицу
    int n;// размер матрицы
public:
    Matrix(); // конструктор по умолчанию
    Matrix(int n); // конструктор с параметрами (только размер матрицы)
    Matrix(int n, int **mas); // конструктор с параметрами (размер матрицы + матрица)
    Matrix(const Matrix&c); // конструктор копирования
    ~Matrix(); // десструктор класса Matrix

    void umn(int num); // умножение миноров на константу
    int& operator()(const int r, const int c) { return ptr[r-1][c-1]; }
    Matrix Minor(const int row, const int col) const; // функция, которая превращает матрицу в минор
    int* operator[] (int i) { return(ptr[i]); } // функция-оператор, которая достаёт член строки матрицы (перегруженная операция взятия индекса)
    Matrix& operator = (Matrix&c); // оператор присваивания
    Matrix operator + (const Matrix&c); // оператор сложения
    Matrix operator - (const Matrix&c); // оператор вычитания
    Matrix operator * (const Matrix&c); // оператор произведения
    Matrix& operator += (Matrix&c);  // оператор дополнения
    friend std::ostream& operator<< (std::ostream &, const Matrix&); // перегруженный оператор вывода
    friend std::istream& operator>> (std::istream &, Matrix&); // перегруженный оператор ввода
};
#endif // MATRIX_H
