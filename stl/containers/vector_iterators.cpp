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
	// iterator, contant iterator, reverse iterator.
	std::vector<int> vec;
	auto iter1 = vec.begin();
	auto iter2 = vec.cbegin();
	auto iter3 = vec.rbegin();
	auto iter4 = vec.crbegin();

	// reverse iterator is a template class wrapping iterators, and const iterators..
	std::vector<int>::reverse_iterator; 
	std::vector<int>::const_reverse_iterator;
	std::reverse_iterator<std::vector<int>::iterator>;
}
