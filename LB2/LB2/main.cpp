#include <iostream>
#include "Matrix.h"
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

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, num, strdel, stdel;
    cout << "������� ����������� = "; cin >> n;
    Matrix NewM1(n);
    cout << "���� �������" << endl;
    cin >> NewM1;
    cout << "����� �������" << endl;
    cout << NewM1;
    cout << "������ ����� (������) �������" << endl;
    Matrix NewM2;
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
    Matrix m1=NewM1.Minor(strdel,stdel);
    cout << "������� ����� 1 �������" << endl;
    cout << m1;
    cout << "������ ������ �����" << endl;
    cout << "������� �������, ������� ������� ���������� - ";
    cin >> strdel;
    cout << "������� �������, ������� ������� ���������� - ";
    cin >> stdel;
    Matrix m2=NewM2.Minor(strdel,stdel);
    cout << "������� ������ �����" << endl;
    cout << m2;
    cout << "���������� ������ � ������ �����" << endl;
    Matrix m3 = m2+m1;
    cout << m3;
    cout << "�������� �� ������� ������ �����" << endl;
    Matrix m4 = m2-m1;
    cout << m4;
    cout << "�������� ������ ����� �� ������" << endl;
    Matrix m5 = m1*m2;
    cout << m5;
    cout << "���������� � ������� ������ ������" << endl;
    m1+=m2;
    cout << m1;
    cout << "������ ������ �������� ������, ������� ����� ������� �� 2 �������" << endl;
    Matrix mas[1];
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
    return 0;
}
