#include<iostream>
using namespace std;

class Book
{
	char* name;
	int pages;
public:
	Book(const char* n);
	Book(const char* n, int p);
	void Print();
	~Book();
};
Book::Book(const char* n)
{
	if (name != nullptr)
	{
		delete[]name;
	}
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}
Book::Book(const char* n, int p):Book(n)
{
	pages = p;
}
void Book::Print()
{
	cout << "Book: " << name <<endl;
	cout << "Pages: " << pages <<endl;
}
Book::~Book()
{
	delete[] name;
}
class Student
{
	char* name;
	const double step;// !!
	Book book; //!!!
public:
	Student();
	Student(const char* n, double st, const char* bookName, int bookPages);
	~Student();
	void Print();

};
Student::Student():step(0), book(nullptr, 0)
{
	name = nullptr;
}
Student::Student(const char* n, double st, const char* bookName, int bookPages): step(st), book(bookName, bookPages)
{
	if (name != nullptr)
	{
		delete[]name;
	}
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}
Student::~Student()
{
	delete[]name;
}
void Student::Print()
{
	cout << "Student: " << name << endl << "Step: " << step << endl;
	book.Print();
}
int main()
{
	Book VRI("Vse Radi Igru", 1000);
	Student U("Nil", 3000, "Vse Radi Igru", 1000);
	U.Print();
}