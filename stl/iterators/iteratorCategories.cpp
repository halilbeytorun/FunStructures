#include <iostream>
#include <vector>
#include<list>
#include <type_traits>
#include <forward_list>
#include <set>

template<typename ...Ts>
void Logger(Ts&& ...args)
{
	(std::cout << ... << std::forward<Ts>(args)) << '\n';
}

//	*iterator categories
//	- Input iterator
//	- output iterator
//	- forward iterator
//	- bideractional iterator
//	- random-access iterator
//	- contigious iterator

template<typename Iter>
void algo(Iter beg, Iter end)
{
	static_assert(std::is_same_v<typename Iter::iterator_category, std::random_access_iterator_tag>, "only for random access iterators");
}



int main()
{
	// Containers have to have these nested types!	Look cppref containers named requiremens for more.
	std::vector<int>::value_type{};
	std::vector<double>::iterator::value_type{};

	// Forward iterator
	{
		// forward_list iterator is forward iterator category.
		std::forward_list<int> x(10);
		auto iter1 = x.begin();
		auto iter2 = x.begin();
		iter1++;	// valid
		++iter2;
		*iter1;	// valid
		iter1 == iter2;
		//iter1--;
		// --iter1;
		//auto b = iter1 < iter2;	// not valid
	}

	// biderectional iterator
	{
		// list iterator is biderectional iterator category.
		std::list<int> x(10);
		auto iter1 = x.begin();
		auto iter2 = x.end();
		iter1++;	// valid
		++iter1;
		*iter1;	// valid
		iter1 == iter2;
		iter2--;
		--iter2;
		//auto b = iter1 < iter2;	// not valid
	}

	// random-access iterator		// similar to raw pointers.
	{
		// vector iterator is random-access iterator category.
		std::vector<int> x(10);
		auto iter1 = x.begin();
		auto iter2 = x.end();
		iter1++;	// valid
		++iter1;
		*iter1;	// valid
		iter1 == iter2;
		iter2--;
		--iter2;
		auto b = iter1 < iter2;	// valid
		iter1 += 3;
		(++iter1)[2];
	}


	Logger(typeid(std::forward_list<int>::iterator::iterator_category).name());
	Logger(typeid(std::list<int>::iterator::iterator_category).name());
	Logger(typeid(std::vector<int>::iterator::iterator_category).name());
	Logger(typeid(std::set<int>::iterator::iterator_category).name());

	{
		std::vector<int> x(10);
		algo(x.begin(), x.end());
	}

	// This is error.
	{
		//std::list<int> x(10);
		//algo(x.begin(), x.end());
	}

}
