#include <iostream>
#include <vector>
#include<list>
#include <type_traits>
#include <forward_list>
#include <algorithm>
#include <string>

template<typename ...Ts>
void Logger(Ts&& ...args)
{
	(std::cout << ... << std::forward<Ts>(args)) << '\n';
}
template<typename C>
void Logger(C& container, typename C::value_type* = nullptr)
{
	for (auto i : container)
	{
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

class Myclass
{
public:
	Myclass()
	{
		Logger("default ctor");
	}
	Myclass(int, int, int)
	{
		std::cout << "Myclass(int, int,int)\n";
	}
	Myclass(double, double)
	{
		Logger("double double");
	}
	Myclass(const Myclass&)
	{
		Logger("copy ctor");
	}
	Myclass(Myclass&&) noexcept
	{
		Logger("move ctor");
	}
};

template<typename T>
class Vector
{
public:
	void push_back(const T&);
	void push_back(T&&);	// function parameter is not universal referance
	template<typename ...Args>
	void emplace_back(Args&&... args)	// universal referance...
	{
		//new (ptr) T(std::forward<Args>(args)...);
	}
};

int main()
{
	std::vector<Myclass> vec;
	vec.reserve(100);

	Myclass m;
	vec.push_back(m);	// there are two push back functions..
	vec.push_back(Myclass{});

	vec.emplace_back(2, 6, 9);	// perfect forwarding mechanisim used, forwarding to class arguments..
	vec.emplace_back(2, 2 );


}
