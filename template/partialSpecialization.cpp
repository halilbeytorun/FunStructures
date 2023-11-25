#include <iostream>


template<typename T>
class Myclass	// Primary template
{
public:
	Myclass()
	{
		std::cout << "Myclass Primary template for type: " << typeid(T).name() << '\n';
	}
};

template<typename T>
class Myclass<T*>	// partial specialization for pointer types
{
public:
	Myclass()
	{
		std::cout << "Myclass Primary template for T*" << '\n';
	}
};
template<typename T>
class Myclass<T[]>	// partial specialization for pointer types
{
public:
	Myclass()
	{
		std::cout << "Myclass Primary template for T[]" << '\n';
	}
};

template<typename T>
class Myclass<T[5]>	// partial specialization for pointer types
{
public:
	Myclass()
	{
		std::cout << "Myclass Primary template for T[5]" << '\n';
	}
};


template<typename T>
struct ValCat	// Primary template
{
	static constexpr const char* value = "PR value";
};
template<typename T>
struct ValCat<T&>
{
	static constexpr const char* value = "L value";
};
template<typename T>
struct ValCat<T&&>
{
	static constexpr const char* value = "X value";
};
#define print_val_cat(expr) std::cout << "value category of expr '" #expr "' is : " << ValCat<decltype((expr))>::value << '\n';


template<int base, int exp>
struct Power
{
	static const int value = base * Power<base, exp - 1>::value;
};
template<int base>
struct Power<base, 0>
{
	static const int value = 1;
};

template<typename T, int n>
void foo(T(&a)[n])
{

}
// this is error since partial specialization is not legal for function templates.
//template<typename T>
//void foo<T, 1>(T(&a)[1])
//{
//
//}
//

template<typename T, typename U>
struct sameType
{
	sameType()
	{
		std::cout << "sameType Primary template\n";
	}
};

template<typename T>
struct sameType<T, T>	// partial specialization used for same types..
{
	sameType()
	{
		std::cout << "sameType partial specialization\n";
	}
};

template<typename T>
struct tupleSpec // Primary template
{};
template<typename T, typename U, typename K, typename M>
struct tupleSpec<std::tuple<T, U, K, M>>
{};
template<typename T>
struct tupleSpec<std::tuple<T>>
{};


template<typename T>
void tupleSpecFunc() {}
// this is again illegal
//template<typename T>
//void tupleSpecFunc<std::tuple<T>>()
//{}


template<typename T>
struct IsPointer : std::false_type {};
template<typename T>
struct IsPointer<T*> : std::true_type {};

int main()
{
	Myclass<int> m1;
	Myclass<long> m2;
	Myclass<char*> m3;
	Myclass<int[]> m4;
	Myclass<double[5]> m5;

	print_val_cat(1);

	Power<7, 3>::value;

	IsPointer<int>::value;
	IsPointer<int*>::value;

	sameType<int, int> testing;
	tupleSpec < std::tuple<int, int, double, long>> testtupleSpec;
	tupleSpec<std::tuple<int>> testtupleSpec1;
}
