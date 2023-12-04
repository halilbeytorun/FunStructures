#include <iostream>
#include <vector>
#include<list>
#include <type_traits>
#include <forward_list>

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
	std::vector<int> ivec{10,2,56};
	std::vector<int>::const_iterator a = ivec.begin();
	auto citer = ivec.cbegin();
	Logger( "value hold by constant iterator: ", * citer);

}
