#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>

#define MIN_AGE 1
#define MAX_AGE 8		//years
#define MIN_WEIGHT 0.1 //kg
#define MAX_WEIGHT 100	//kg
#define NAME_LENGTH 15
#define KIND_LENGTH 20

using namespace std;

class Kangaroo
{
private:
	int age;
	double weight;
	char* kind;
	char* name;

public:
	Kangaroo();
	Kangaroo(const Kangaroo& copyKangaroo);
	Kangaroo(const int age, const double weight, const char* kind, const char* name);

	int getAge()const;
	double getWeight()const;
	char* getKind()const;
	char* getName()const;
	double getCoef()const;  //weight to age

	bool setAge(const int age);
	bool setWeight(const double weight);
	bool setKind(const char* kind);
	bool setName(const char* name);

	Kangaroo& operator+(const Kangaroo& kangaroo)const;
	Kangaroo& operator-(const Kangaroo& kangaroo)const;
	Kangaroo& operator=(const Kangaroo& kangaroo);

	bool operator>(const Kangaroo& kangaroo)const;
	bool operator<(const Kangaroo& kangaroo)const;
	bool operator==(const Kangaroo& kangaroo)const;
	bool operator>=(const Kangaroo& kangaroo)const;
	bool operator<=(const Kangaroo& kangaroo)const;

	friend ostream& operator<<(ostream& stream, const Kangaroo& kangaroo);

	~Kangaroo();
};


Kangaroo::Kangaroo()
{
	age = MIN_AGE;
	weight = MIN_WEIGHT;
	kind = new char[KIND_LENGTH];
	strcpy(kind, "Unset");
	name = new char[NAME_LENGTH];
	strcpy(name, "Unset");

}

Kangaroo::Kangaroo(const int age, const double weight, const char* kind, const char* name) {
	this->kind = new char[KIND_LENGTH];
	this->name = new char[NAME_LENGTH];
	if (!this->setAge(age)) {
		this->age = MIN_AGE;
	}
	if (!this->setWeight(weight)) {
		this->weight = MIN_WEIGHT;
	}
	if (!this->setKind(kind)) {
		strcpy(this->kind, "Unset");
	}
	if (!this->setName(name)) {
		strcpy(this->name, "Unset");
	}
}

Kangaroo::Kangaroo(const Kangaroo& copyKangaroo) {
	this->kind = new char[KIND_LENGTH];
	this->name = new char[NAME_LENGTH];
	if (!this->setAge(copyKangaroo.getAge())) {
		this->age = MIN_AGE;
	}
	if (!this->setWeight(copyKangaroo.getWeight())) {
		this->weight = MIN_WEIGHT;
	}
	if (!this->setKind(copyKangaroo.getKind())) {
		strcpy(this->kind, "Unset");
	}
	if (!this->setName(copyKangaroo.getName())) {
		strcpy(this->name, "Unset");
	}
}

Kangaroo::~Kangaroo()
{
	delete[] kind;
	delete[] name;
}

double Kangaroo::getCoef()const {
	return (weight / age);
}

bool Kangaroo::setAge(const int age) {
	if (age >= MIN_AGE && age <= MAX_AGE) {
		this->age = age;
		return true;
	}
	else {
		cout << "\n*Invalid age!*\n";
		return false;
	}
}

bool Kangaroo::setWeight(const double weight) {
	if (weight >= MIN_WEIGHT && weight <= MAX_WEIGHT) {
		this->weight = weight;
		return true;
	}
	else {
		cout << "\n*Invalid weight!*\n";
		return false;
	}
}

bool Kangaroo::setKind(const char* kind) {
	if (strlen(kind) < KIND_LENGTH) {
		strcpy(this->kind, kind);
		return true;
	}
	else {
		cout << "\n*Invalid kind!*\n";
		return false;
	}
}

bool Kangaroo::setName(const char* name) {
	if (strlen(name) < NAME_LENGTH) {
		strcpy(this->name, name);
		return true;
	}
	else {
		cout << "\n*Invalid kind!*\n";
		return false;
	}
}

int Kangaroo::getAge()const {
	return age;
}

double Kangaroo::getWeight()const {
	return weight;
}

char* Kangaroo::getKind()const {
	return kind;
}

char* Kangaroo::getName()const {
	return name;
}

Kangaroo& Kangaroo::operator+(const Kangaroo& kangaroo)const {
	Kangaroo* temp = new Kangaroo;
	if (this->getWeight() + kangaroo.getWeight() >= MAX_WEIGHT) {
		temp->setWeight(MAX_WEIGHT);
	}
	else {
		temp->setWeight(this->getWeight() + kangaroo.getWeight());
	}
	if (this->getAge() + kangaroo.getAge() >= MAX_AGE) {
		temp->setAge(MAX_AGE);
	}
	else {
		temp->setAge(this->getAge() + kangaroo.getAge());
	}
	//Take name of first and kind of second

	temp->setName(this->getName());
	temp->setKind(kangaroo.getKind());

	return *temp;
}

Kangaroo& Kangaroo::operator-(const Kangaroo& kangaroo)const {
	Kangaroo* temp = new Kangaroo;
	if (this->getWeight() - kangaroo.getWeight() <= MIN_WEIGHT) {
		temp->setWeight(MIN_WEIGHT);
	}
	else {
		temp->setWeight(this->getWeight() - kangaroo.getWeight());
	}
	if (this->getAge() - kangaroo.getAge() <= MIN_AGE) {
		temp->setAge(MIN_AGE);
	}
	else {
		temp->setAge(this->getAge() - kangaroo.getAge());
	}

	//Take name of first and kind of second

	temp->setName(this->getName());
	temp->setKind(kangaroo.getKind());

	return *temp;
}

Kangaroo& Kangaroo::operator=(const Kangaroo& kangaroo) {
	this->setAge(kangaroo.getAge());
	this->setWeight(kangaroo.getWeight());
	this->setKind(kangaroo.getKind());
	this->setName(kangaroo.getName());

	return *this;
}

bool Kangaroo::operator>(const Kangaroo& kangaroo)const {

	return (this->age > kangaroo.getAge()) || (this->weight > kangaroo.getWeight());
}

bool Kangaroo::operator<(const Kangaroo& kangaroo)const {

	return (this->age < kangaroo.getAge()) || (this->weight < kangaroo.getWeight());
}

bool Kangaroo::operator==(const Kangaroo& kangaroo)const {
	if (this->age == kangaroo.getAge() && this->weight == kangaroo.getWeight()) {
		return true;
	}
	else {
		return false;
	}
}

bool Kangaroo::operator>=(const Kangaroo& kangaroo)const {
	if (this->getCoef() >= kangaroo.getCoef()) {
		return true;
	}
	else {
		return false;
	}
}

bool Kangaroo::operator<=(const Kangaroo& kangaroo)const {
	if (this->getCoef() <= kangaroo.getCoef()) {
		return true;
	}
	else {
		return false;
	}
}

ostream& operator<<(ostream& stream, const Kangaroo& kangaroo) {
	stream << "Имя: " << kangaroo.getName() << endl;
	stream << "Тип: " << kangaroo.getKind() << endl;
	stream << "Возраст: " << kangaroo.getAge() << endl;
	stream << "Вес: " << kangaroo.getWeight() << endl;
	return stream;
}

#define _CRT_SECURE_NO_WARNINGS

#define MIN_AGE 1
#define MAX_AGE 8		//years
#define MIN_WEIGHT 0.1 //kg
#define MAX_WEIGHT 100	//kg
#define NAME_LENGTH 15
#define KIND_LENGTH 20

class KangFactory
{
public:

	static Kangaroo * createRisingAray(int amount);

	KangFactory();
	~KangFactory();
};

KangFactory::KangFactory()
{
}


KangFactory::~KangFactory()
{
}

Kangaroo* KangFactory::createRisingAray(int num) {
	Kangaroo* karr = new Kangaroo[num];
	for (int i = 0; i < num; i++) {
		int age = int(MIN_AGE + (((MAX_AGE - MIN_AGE)*1.0 / num)*(i + 1)));
		double weight = MIN_WEIGHT + ((MAX_WEIGHT - MIN_WEIGHT)*1.0 / num)*(i + 1);
		Kangaroo* temp = new Kangaroo(age, weight, "FKind", "FName");
		karr[i] = *temp;
		delete temp;
	}
	return karr;
}

template <class Type>
class Node
{
public:
	Type value;
	Node* next;

	Node();
	Node(Type& val);
	~Node();
	void display()const;

};

template<class Type>
Node<Type>::Node()
{
	next = nullptr;
}

template<class Type>
Node<Type>::~Node()
{
}

template<class Type>
Node<Type>::Node(Type& val) {
	this->value = val;
	next = nullptr;
}


template<class Type>
void Node<Type>::display()const {

	cout << endl << value << endl;
}

template<class Type>
class Stack
{
	Node<Type> *top;
public:
	Stack() : top(nullptr) {};

	void display()const;
	Type& push(Type& item);
	Type& pop();
	Type& pick()const;

	bool isEmpty()const;
	void clear();

	~Stack();
};

template<class Type>
void Stack<Type>::display()const {
	if (top != nullptr) {
		Node<Type>* cur;
		cur = top;
		cout << "\nDisplaying stack:\n";
		while (cur != nullptr) {
			cur->display();
			cur = cur->next;
		}
		cout << "\n End of stack \n";
	}
	else cout << "Stack is empty";
}

template<class Type>
Type& Stack<Type>::push(Type& item) {
	Node<Type>* temp = new Node<Type>(item);
	temp->next = top;
	top = temp;
	return item;
}

template<class Type>
Type& Stack<Type>::pop() {

	if (top != nullptr) {
		Node<Type>* temp;
		Type* ttemp = new Type(top->value);
		temp = top;
		top = top->next;
		delete temp;
		return *ttemp;
	}
	else {
		cout << "\nStack is empty!!!\n";
		system("pause");
		exit(0);
	}

}

template<class Type>
void Stack<Type>::clear() {
	while (top != nullptr) {
		Node<Type>* cur = top;
		top = top->next;
		delete cur;
	}
}

template<class Type>
Type& Stack<Type>::pick()const {
	if (top == nullptr) {
		system("pause");
		exit(0);
	}
	else {
		return top->value;
	}
}

template<class Type>
bool Stack<Type>::isEmpty()const {
	return top == nullptr;
}

template<class Type>
Stack<Type>::~Stack() {
	this->clear();
}

template<class Type>
class StackWorker
{
public:
	static Stack<Type>* mergeStacks(Stack<Type> *first, Stack<Type> *second);
	static void fillStackArr(Stack<Type>* stack, Type* arr, int size);
	StackWorker();
	~StackWorker();
};

template<class Type>
StackWorker<Type>::StackWorker() {

}

template<class Type>
Stack<Type>* StackWorker<Type>::mergeStacks(Stack<Type> *first, Stack<Type> *second) {
	Stack<Type>* result = new Stack<Type>;
	while (!first->isEmpty() && !second->isEmpty()) {
		if (first->pick() < second->pick()) {
			result->push(second->pop());
		}
		else {
			result->push(first->pop());
		}
	}
	while (!first->isEmpty()) {
		result->push(first->pop());
	}
	while (!second->isEmpty()) {
		result->push(second->pop());
	}
	return result;
}

template<class Type>
void StackWorker<Type>::fillStackArr(Stack<Type>* stack, Type* arr, int size) {
	for (int i = 0; i < size; i++) {
		stack->push(arr[i]);
	}
}

template<class Type>
StackWorker<Type>::~StackWorker()
{
}



int main() {
	setlocale(LC_ALL, "russian");
	Kangaroo *arr;
	Stack<Kangaroo>* first = new Stack<Kangaroo>;
	Stack<Kangaroo>* second = new Stack<Kangaroo>;
	Stack<Kangaroo>* third;
	int num;

	cout << "Введите размер первого массива: ";
	cin >> num;
	arr = KangFactory::createRisingAray(abs(num));
	StackWorker<Kangaroo>::fillStackArr(first, arr, num);
	delete[]arr;
	first->display();

	cout << "Введите размер второго массива: ";
	cin >> num;
	arr = KangFactory::createRisingAray(abs(num));
	StackWorker<Kangaroo>::fillStackArr(second, arr, num);
	delete[]arr;
	second->display();

	third = StackWorker<Kangaroo>::mergeStacks(first, second);
	third->display();



	/*
	Kangaroo * kang = new Kangaroo(5, 5, "name", "kind");
	cout << *kang;
	Node<Kangaroo>* node = new Node<Kangaroo>(*kang);
	node->display();
	*/
	/*
	Kangaroo* first = new Kangaroo(5, 16.5, "Kind1", "Name1");
	Kangaroo* second = new Kangaroo(*first);
	Kangaroo* third = new Kangaroo(*first + *second);
	cout << *first;
	cout << *second;
	cout << *third+*second+*third;
	*/
	cout << endl;
	system("pause");
	return 0;
}