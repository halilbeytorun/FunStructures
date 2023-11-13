#include <iostream>



template<typename T>
class TypeTeller;	// Forward declering incomplete type

template<typename T>
void func(T x)
{
	TypeTeller<T> a;
}


int main()
{
	const int a[12]{};
	func(a);
}

