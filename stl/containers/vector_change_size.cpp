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
		// changing the size of the vector.
		std::vector<int> ivec(10, 5);
		Logger("size = ", ivec.size(), " cap= ", ivec.capacity());
		Logger(ivec);
		ivec.resize(24);	// new elements value initialized..
		Logger("size = ", ivec.size(), " cap= ", ivec.capacity());
		Logger(ivec);
		ivec.resize(32, 10);
		Logger(ivec);
		ivec.resize(10);
		Logger(ivec);
		ivec.clear();
		Logger("size = ", ivec.size(), " cap= ", ivec.capacity());
		ivec.resize(10, 1);
		ivec.resize(0);
		Logger("size = ", ivec.size(), " cap= ", ivec.capacity());
		ivec.push_back(10);
		Logger("size = ", ivec.size(), " cap= ", ivec.capacity());
		ivec = { 1,2 };
		Logger("size = ", ivec.size(), " cap= ", ivec.capacity());

	}
	{
		// assign function, allows more complex assignments than assignment operator.
		// can use range
		Logger("assign function, allows more complex assignments than assignment operator.");
		std::list<std::string> slist{ "halil", "zeynep", "ibi" };
		std::vector<std::string> svec;
		svec.assign(slist.begin(), slist.end());
		Logger(svec);
		Logger(slist);
		svec.assign(10, "halil");
		Logger(svec);
	}
}
