#include <iostream>


template<typename T>
T foo(T) {}

template<>
int foo(int) { return {}; }

void foo(int) {}

template<typename T>
typename T::value_type baz(T) {}	// this was substitution for baz(2) call		
									//	double::value_type<double> baz(double)	--> since double::value_type has no meaning, 
									//	it is removed from function overload set. (substitution failure)

void baz(double) {}


template<typename T>
void doubleCallable(T) = delete;
void doubleCallable(double) {}

template<typename T>
void func(T x) {}

template<typename T>
void func(T* x) {}

template<typename T>
void func(T** x) {}


int main()
{
	foo(2);	// observe which one is called.
	baz(2);

	doubleCallable(1.);	// can only be called with double type expression.


	int x{};
	func(x);		// calls first function
	func(&x);	// calls second function
	int* ptr = &x;
	func(&ptr);	// calls third function

}
