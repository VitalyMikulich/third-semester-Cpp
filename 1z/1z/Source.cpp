#include <iostream>
using namespace std;

class Array
{
protected:
	int size;
	char* arr;
	
public: 
	Array(int);
	~Array();
	//Array operator+ (const Array&);
	Array operator[] (int);
	Array operator= (char*);
	virtual Array sum(Array&, Array&);
	virtual void show();
};

class Octal : public Array
{
public:
	Octal(int size) : Array(size) {};
	virtual Array sum(Octal&, Octal&);
	virtual void show();
};

class BitString : public Array
{
public:
	BitString(int size) : Array(size) {};
	virtual Array sum(BitString&, BitString&);
	virtual void show();
};

Array::Array(int k)
{
	size = k;
	arr = new char[size];
}

Array::~Array()
{
	delete[] arr;
	size = 0;
}

Array Array::operator=(char * b)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = b[i];
	}
	return arr;
}

//Array Array::operator+(const Array &c)
//{
//	Array result(size);
//	for (int i = 0; i < size; i++) {
//		result.arr[i] = arr[i] + c.arr[i];
//	}
//	return result;
//}

Array Array::operator[](int i)
{
	if(i<size && i>=0) return arr[i];
	//else cout << "Неверный индекс" << endl;
}

Array Array::sum(Array &a, Array &b)
{
	Array result(size);
	for (int i = 0; i < size; i++) {
		result.arr[i] = a.arr[i] + b.arr[i];
	}
	return result;
}

Array Octal::sum(Octal &a, Octal &b)
{
	Octal result(size);
	for (int i = 0; i < size; i++) {
		result.arr[i] = a.arr[i] + b.arr[i];
	}
	return result;
}

Array BitString::sum(BitString&a, BitString&b)
{
	BitString result(size);
	for (int i = 0; i < size; i++) {
		result.arr[i] = a.arr[i] + b.arr[i];
	}
	return result;
}

void Array::show()
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " " << endl;
	}
}

void Octal::show()
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " " << endl;
	}
}

void BitString::show()
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " " << endl;
	}
}

void get(Array a, int size) {
	char *b = new char[size];
	cout << "Введите строку: ";
	for (int i = 0; i < size; i++) {
		
		cin >> b[i];
	}
	for (int i = 0; i < size; i++) {

		cout << b[i];
	}
	for (int i = 0; i < size; i++)
	{
		a[i] = b[i];
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	cout << "Введите размер: ";
	cin >> size;
	cout << endl;
	Octal arr1(size), arr2(size), res(size);
	get(arr1, size);
	arr1.show();
	get(arr2, size);
	arr2.show();
	res.sum(arr1, arr2);
	res.show();
}


