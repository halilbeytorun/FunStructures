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
	{// insert
		Logger("insert function");
		std::vector<std::string> svec{ "halil", "veli", "coding" };
		std::list<std::string> names{ "BURAK", "FEDAI" };
		Logger(svec);
		svec.insert(svec.begin(), "ali");
		Logger(svec);
		svec.insert(std::next(svec.begin()), "deli");
		svec.insert(svec.end(), "ahmet");
		Logger(svec);
		svec.insert(svec.begin(), { "zeki", "dogu", "dicle" });	// initializer list insert
		svec.insert(svec.begin(), 3, "bilal");					// fill insert
		Logger(svec);
		auto iter = svec.insert(svec.begin(), names.begin(), names.end());// range insert.
		Logger(svec);
		Logger(*iter);
	}


	{// emplace
		Logger("emplace function");
		std::vector<std::string> svec{ "halil", "veli", "coding" };
		std::list<std::string> names{ "BURAK", "FEDAI" };
		Logger(svec);
		svec.emplace(svec.begin(), "ali");
		Logger(svec);
		svec.emplace(std::next(svec.begin()), "deli");
		svec.emplace(svec.end(), "ahmet");
		Logger(svec);
		svec.emplace(svec.begin(), 20, 'T');	// emplace passes these values into string's ctor
		Logger(svec);
		auto iter = svec.emplace(svec.begin(), *names.begin());
		Logger(svec);
		//Logger(*iter);
	}

	{
		// remove element pop_back
		Logger("remove element, pop_back");
		std::vector<std::string> tvec{ "halil", "ali", "veli", "deli", "ahmet", "mahmet", "gunes", "ates"};
		while (!tvec.empty())
		{
			tvec.pop_back();
			Logger(tvec);
		}
	}


	{
		// remove element erase
		Logger("remove element, pop_back");
		std::vector<std::string> tvec{ "halil", "ali", "veli", "deli", "ahmet", "mahmet", "gunes", "ates" };
		auto iter = tvec.erase(tvec.begin());
		Logger(tvec);
		Logger(*iter);
		tvec.erase(prev(tvec.end()));
		Logger(tvec);
		tvec.erase(tvec.begin(), tvec.end() - 1);
		Logger(tvec);
	}

}
