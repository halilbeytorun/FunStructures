#include <iostream>

template<int n>
struct counter : counter<n - 1>
{
	counter()
	{
		std::cout << n << ' ';
	}
};
template<>
struct counter<0>
{
};
template<int n>
struct Factorial
{
	static const int value = n * Factorial<n - 1>::value;
};

template<>
struct Factorial<1>
{
	static const int value = 1;
};


template<typename T>
void func(T x)
{
	std::cout << "primary template" << typeid(T).name() << "\n";
}

template<>	// diamond in community
void func(int)	// can write void func<int>(int)
{
	std::cout << "explicit specialization for int\n";
}

int main()
{
	counter<100> a;
	Factorial<5>::value;	// c0mpile time calculated

	func(1.2);
	func(1.2f);
	func(1u);
	func(1);
}
