#include <iostream>



template<typename T>
class TypeTeller;	// Forward declering incomplete type

template<typename T>
void func(T x)
{
	TypeTeller<T> a;
}

template<typename T>
void bar(T&& arg) 
{
	TypeTeller<T> a;
}


int main()
{
	const int a[12]{};
	//func(a);	// template argument deduction, array is deduced into const int *

	int x{};
	//bar(x);	// T is int&	arg is int&
	bar(1);	// T is int		arg is int&&
	
}

