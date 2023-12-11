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
		std::vector<int> x(100'000, 98);
		Logger(x.size());
		std::vector<int> y{ 99 };
		Logger(x < y);
	}

	{
		std::vector<int> ivec{ 3,6,8,1 };
		std::list<int> ilist{ 3,6,9,1 };
		Logger(std::lexicographical_compare(ivec.begin(), ivec.end(), ilist.begin(), ilist.end()));
		Logger(std::lexicographical_compare(ivec.begin(), ivec.end(), ilist.begin(), ilist.end(), std::greater() ));	// gets binary predicate.
	}
}
