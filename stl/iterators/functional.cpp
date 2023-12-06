#include <iostream>
#include <vector>
#include <list>
#include <type_traits>
#include <forward_list>
#include <functional>
#include <algorithm>

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


template<typename T>
struct Less
{
	bool operator()(const T& t1, const T& t2) const
	{
		return t1 < t2;
	}
};

template<typename T>
struct Greater
{
	bool operator()(const T& t1, const T& t2) const
	{
		return t1 > t2;
	}
};

template<typename T>
struct Plus
{
	T operator()(const T& t1, const T& t2) const
	{
		return t1 + t2;
	}
};

template<typename T>
struct Multiplies
{
	T operator()(const T& t1, const T& t2) const
	{
		return t1 * t2;
	}
};



int main()
{
	Logger(std::less<int>()(5, 10));
	Logger(std::greater<int>()(4, 1));
	Logger(std::greater_equal<int>()(4, 1));
	Logger(std::plus<int>()(4, 1));
	Logger(std::multiplies<int>()(4, 1));

	{
		std::vector<std::string> svec{ "a1", "a2", "a3", "a4", "a5" };
		Logger(svec);
		std::sort(svec.begin(), svec.end());
		Logger(svec);
		std::sort(svec.begin(), svec.end(), std::greater<std::string>{});
		Logger(svec);
		// note that we can give all kind of binary predicate to sort.
	}

	{
		Logger("negate function object");
		std::vector<int> ivec{ 1,2,3,4,5,-6,7123,123,1 };
		Logger(ivec);
		std::transform(ivec.begin(), ivec.end(), ivec.begin(), std::negate<int>{});
		Logger(ivec);
	}

	{
		Logger("plusfunction object");
		std::vector<int> x{2,3,4,5};
		std::vector<int> y{ 1,2,3,4 };
		std::list<int> mylist;
		Logger(mylist);
		std::transform(x.begin(), x.end(), y.begin(), std::back_inserter(mylist), std::plus<int>{});
		Logger(mylist);
	}

	{
		Logger("reverse usage:");
		std::vector<std::string> svec{ "halil", "zeynep", "ibo" };
		Logger(svec);
		std::reverse(svec.begin(), svec.end());
		Logger(svec);
	}

	{
		Logger("reverse_copy usage:");
		std::vector<std::string> svec{"halil", "zeynep", "ibo"};
		std::list<std::string> slist;
		Logger(svec);
		std::reverse_copy(svec.begin(), svec.end(), back_inserter(slist));
		Logger(slist);
	}

	{
		Logger("remove usage:");
		std::vector<std::string> svec{ "halil", "zeynep", "ibo" };
		Logger(svec);
		std::remove(svec.begin(), svec.end(), "halil");
		Logger(svec);
	}
	{
		Logger("remove_copy usage:");
		std::vector<std::string> svec{ "halil", "zeynep", "ibo" };
		std::list<std::string> slist;
		Logger(svec);
		std::remove_copy(svec.begin(), svec.end(), back_inserter(slist),"halil");
		Logger(slist);
	}
	{
		Logger("remove_copy_if usage:");
		std::vector<std::string> svec{ "halil", "zeynep", "ibo" };
		std::list<std::string> slist;
		Logger(svec);
		std::remove_copy_if(svec.begin(), svec.end(), back_inserter(slist), [](const std::string& s) { return s.find('e') != std::string::npos; });
		Logger(slist);
	}

}
