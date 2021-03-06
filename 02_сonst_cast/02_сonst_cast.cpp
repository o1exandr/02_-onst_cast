/*
Завдання 2.
Перевірити чи можна «прибрати » сonst за допомогою операції сonst_cast<> з
С-рядка(const char * t =”my text” )
С++-рядка(const string* ps = new string(“my test”))
константи екземпляру класу(const  int field)
*/

#include "stdafx.h"
#include <iostream> 
#include <string>


using namespace std;

class Some
{
private:
	 const int field = 10;

public:

	int getField()const
	{
		return field;
	}

	void setField(int f)
	{
		const int * p = &field;
		*const_cast<int*> (p) = f;
	}

	void print()const
	{
		cout << "\ngetField before const_cast:\t" << getField() << endl;
		*const_cast<int*>(&field) = 15;
		cout << "getField after const_cast:\t" << getField() << endl;
	}
};


int main()
{
	const char* t = "my text";
	const string ps = "my test";
	
	
	// С-рядка(const char * t =”my text” )
	//- - - - - - - 
	cout << "t before: " << t << endl;
	t = "123";
	//t[0] = 'y'; //не дає змінити окремий символ
	char* tmp = const_cast<char*>(t);
	//tmp[0] = 'y'; //вдалось прибрати const й змінити символ, але ми отримали помилку на етапі компіляції
	cout << "t after: " << t << endl; 

	// С++-рядка(const string* ps = new string(“my test”))
	//- - - - - - - 
	cout << "\nstring ps before: " << ps << endl;
	//ps = "your test"; //не дає змінити текст
	string* tmpPS = const_cast<string*>(&ps);
	*tmpPS = "new test";
	cout << "string ps after: " << ps << endl;

	// константи екземпляру класу(const  int field)
	//- - - - - - - 
	Some s;
	s.print();
	

	cout << endl;
	system("pause");
	return 0;
}