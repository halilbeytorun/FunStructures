#include <iostream>



template<typename T>
class TypeTeller;	// Forward declering incomplete type

template<typename T>
void func(T x)
{
	TypeTeller<T> a;
}

template<typename T>
void bar(T, T&&) {}


int main()
{
	const int a[12]{};
	func(a);	// type deduction, array is deduced into const int *


	
}

