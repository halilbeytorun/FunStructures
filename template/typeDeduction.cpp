#include <iostream>


template<typename T>
void baz(T x) {}
template<typename T>
void baz_ref(T& x) {}
template<typename T>
void baz_forward(T&& x) {}



template<typename T>
void bar(T, T&&) {}

template<typename T>
void foo(T, T) {}



template<typename T>
void func(T)
{
	typename T::value_type x;	// typename keyword must be used to say that value_type is type member of the T class, not static data member, class keyword cannot be used here
}
class Myclass
{
public:
	class value_type {

	};
};

template<typename T>
struct my_remove_pointer
{
	using type = T;
};

template<typename T>
struct my_remove_pointer<T*>
{
	using type = T;
};
template<typename T>
struct my_remove_pointer<T*const>
{
	using type = T;
};

int main()
{
	const int c = 24;
	baz(c);	// top level constness vanishes...
	int a[10]{};
	baz(a);	// array to pointer decay
	int myx{};
	int& myx_ref = myx;
	baz(myx_ref);	// only int

	baz_ref(a);	// T is int[10] array	// referance is there so no copy still!!
	baz_ref(myx); //	T is int
	baz_ref(c);		// T is const int.

	baz_forward(10);	// T is int 
	baz_forward(myx);	// T is int& --> with && referance collapsing, function parameter will be int&
	baz_forward(c);		// T is const int& --> referance collapsing.
	baz_forward(a);

	auto init_list_var = { 1,2,3,4 };		// auto is initilizer_list
	//baz({ 1,2,3,4 });				// this is synhax error The only different type deduction between auto and template.


	foo(1, 1);
	// foo(1, 1.2);	// ambiguity error.

	int x{};
	//bar(x, x);	// Error, T is int for first function parameter but T is int & for the second function parameter.
	bar(10, 1);	// Ok T is int for first and second template paraemters. Template argument deduction is same for auto type deduction, except for initializer_list
	bar(x, std::move(x));	// OK, for R value expressions forwarding referance template argument will be T. For L value expressions, It will be T&	--> referance collapsing.


	int* ptr = &x;
	int** p = &ptr;
	auto* y = ptr;
	auto** z = p;
	// similar type deduction occurs for template argument deduction.

	func(Myclass{});

	typename my_remove_pointer<int*const>::type testing;
}

