#include <iostream>
#include <typeinfo>
#include <cassert>
#include <exception>


class A
{
public:
	A()
	{
		std::cout << this << "  A address resource is taken\n";
	}
	~A()
	{
		std::cout << this << "  A address resource is given\n";
	}
};

class B
{
public:
	B()
	{
		std::cout << this << "  B address resource is taken\n";
	}
	~B()
	{
		std::cout << this << "  B address resource is given\n";
	}
};


void f4()
{
	A a1;
	B b1;
	throw std::exception();
}
void f3()
{
	B b1;
	f4();
}
void f2()
{
	A a1;
	f3();
}
void f1()
{
	f2();
}


int main()
{
	try
	{
		f1();
	}
	// destructors of the object created are called before going in here. If there would not be a catch function, 
	//	std::terminate function would call abort function and destructors would not be called. Notice the importance of RAII
	catch (const std::exception&)
	{
		std::cout << "Stopped at catch, notice destructor calls and understand the importance of RAII.\n";
		(void)getchar();
	}
}

