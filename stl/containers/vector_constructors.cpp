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



int main()
{
	{
		std::vector<int> v1;	// default ctor
		std::vector<int> v2{};// default ctor

		std::vector<int> v3();	// this is function decleration (most vexing parse)
	}
	
	{	// copy ctor, move ctor 
		std::vector<std::string> svec{"halil", "ibo"};
		auto myvec{ svec };	// copy ctor is called.		// deep copy is performed.
		auto myvec2{ std::move(svec)};	// move ctor is called.	// only pass the array pointer hold inside, does not copy its members..
		// here svec is in moved from state.. staple and consistent within itself but standard does not dictate anything else, but most cases its size will be 0.
	}

	{	//std::size_t input
		std::vector<int> ivec(100);	// objects inside default constructed.	// if the object does not have default ctor, then error.
	}
	{	// std::size_t, T		--> fill constructor
		std::vector<std::string> svec(10,"halil");	// 10 times halil strings..
	}
	{// initializer_list
		std::vector<int> x{ 10 };	// , size of x is 1.
	}
	{// range parameter ctor.
		std::list<int> mylist{ 1,2,3,4,5 };
		std::vector<int> myvec{mylist.begin(), mylist.end()};

		int a[] = { 1,3,3,4,5 };
		std::vector<int> avec(a, a + 2);
		//Logger(avec);
	}
	
}
