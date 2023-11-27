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


// with that writing, selection is done before specialization.. SFINAE is used!
// If T is not pointer, enable_if's false specialization will be selected which does not have type which would caluse substitution failure...
// Just change std::is_pointer_v according to your constraint to use SFINAE and enable_if. (like std::is_same, std::is_integral ..)
template<typename T>
std::enable_if_t<std::is_pointer_v<T>> enable_if_return_func(T) {}
void enable_if_return_func(double) {}


template<typename T, typename U = std::enable_if_t<std::is_pointer_v<T>, T>>
void enable_if_template_param_func(T) {}
void enable_if_template_param_func(double) {}

template<typename T>
void enable_if_function_param_func(T x, std::enable_if_t<std::is_pointer_v<T>>* = nullptr) {}	// second param void pointer
void enable_if_function_param_func(double) {}


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


	enable_if_return_func(12);	// SFINAE d out
	enable_if_template_param_func(12);// SFINAE d out
	enable_if_function_param_func(12);// SFINAE d out

}
