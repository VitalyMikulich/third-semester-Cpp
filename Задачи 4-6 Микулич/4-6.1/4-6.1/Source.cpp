#include <iostream>
#include <Windows.h>
using namespace std;

class Complex {
protected:
	double real;
	double imaginary;
public:
	Complex();
	Complex(double real, double imaginary);
	Complex(const Complex&object);

	void setComplex(const double real, const double imaginary);
	double getReal()const;
	double getImaginary()const;

	Complex operator+(const Complex& temp);
	Complex operator*(const Complex& temp);

	friend ostream& operator<<(ostream& stream, const Complex& comp);
	friend istream& operator>>(istream& stream, Complex& comp);
};

Complex::Complex() {
	real = 0;
	imaginary = 0;
}

Complex::Complex(double real, double imaginary) {
	setComplex(real, imaginary);
}

Complex::Complex(const Complex& object) {
	setComplex(object.getReal(), object.getImaginary());
}

void Complex::setComplex(const double newReal, const double newImaginary) {
	real = newReal;
	imaginary = newImaginary;
}


double Complex::getReal()const {
	return real;
}

double Complex::getImaginary()const {
	return imaginary;
}

Complex Complex::operator+(const Complex& temp) {
	double newReal, newImaginary;
	newReal = real + temp.getReal();
	newImaginary = imaginary + temp.getImaginary();
	return Complex(newReal, newImaginary);
}

Complex Complex::operator*(const Complex& temp) {
	double newReal, newImaginary;
	newReal = real * temp.getReal() - imaginary * temp.getImaginary();
	newImaginary = real * temp.getImaginary() + imaginary * temp.getReal();
	return Complex(newReal, newImaginary);
}

std::ostream& operator<<(std::ostream& stream, const Complex& comp) {
	stream << comp.real << " + " << comp.imaginary<<"i";
	return stream;
}

istream& operator>>(istream& stream, Complex& comp) {
	int temp1, temp2;
	const int N = 50;
	char* buffer = new char[N];
	for (;;) {
		cout << "\n¬ведите вещественную часть: ";
		stream >> temp1;
		if (!stream) {
			cout << "\nInvalid type; Enter number!";
			stream.clear();
			stream.get(buffer, N - 1, '\n');
		}
		else break;
	}
	for (;;) {
		cout << "¬ведите мнимую часть: ";
		stream >> temp2;
		if (!stream) {
			cout << "\nInvalid type; Enter number!";
			stream.clear();
			stream.get(buffer, N - 1, '\n');
		}
		else break;
	}

	comp.setComplex(temp1, temp2);
	delete[] buffer;
	return stream;
}

class CompVect : public Complex
{
private:
	int n;
	Complex *numb;
public:
	CompVect(int n);
	/*CompVect();*/
	Complex getComplex(int i)const;
	CompVect(const CompVect&object);
	CompVect operator+(const CompVect& temp);
	friend ostream& operator<<(ostream& stream, const CompVect& comp);
	friend istream& operator>>(istream& stream, CompVect& comp);
};

CompVect::CompVect(int x) 
{
	n = x;
	numb = new Complex[n];
}

Complex CompVect::getComplex(int i)const {
	return numb[i];
}

CompVect::CompVect(const CompVect& object) {
	n = object.n;
	numb = new Complex;
	for (int i = 0; i < n; i++) {
		numb[i]=object.numb[i];
	}
}

CompVect CompVect::operator+(const CompVect& temp) {
	CompVect vect(n);
	for (int i = 0; i < n; i++) {
		vect.numb[i] = numb[i] + temp.numb[i];
	}
	return vect;
}

ostream& operator<<(ostream& stream, const CompVect& comp) {
	int n = comp.n;
	cout<<"(";
	for (int i = 0; i < n; i++) {
		stream << comp.numb[i];
		if (i+1 != n)
			cout << ", ";
	}
	cout << ")" << endl;
	return stream;
}

istream& operator>>(istream& stream, CompVect& comp) {
	int n = comp.n;
	for (int i = 0; i < n; i++) {
		stream >> comp.numb[i];
	}
	return stream;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Complex numb1(5, 12);
	Complex numb2;
	cout << numb1 << endl;
	cin >> numb2;
	cout << numb2 << endl;
	cout << "numb1 + numb2 = " << numb1 + numb2 << endl;
	cout << "numb1 * numb2 = " << numb1 * numb2 << endl;
	int n;
	cout << "¬ведите количество координат: "; cin >> n;
	CompVect vect1(n);
	/*vect1.get();*/
	cin >> vect1;
	CompVect vect2(n);
	cin >> vect2;
	cout << vect1;
	cout << vect2;
	cout << "vect1 + vect2 = " << vect1 + vect2;
	system("pause");
}