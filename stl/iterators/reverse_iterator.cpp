#include <iostream>
#include <vector>
#include<list>
#include <type_traits>
#include <forward_list>
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

template<typename Iter>
void display_range(Iter beg, Iter end)
{
	while (beg != end)
	{
		std::cout << *beg << ' ';
		beg++;
	}
	std::cout << '\n';
}

template<typename InIter, typename Unpred>
int Count_if(InIter beg, InIter end, Unpred f)
{
	int cnt{};
	while (beg != end)
	{
		if (f(*beg))
		{
			cnt++;
		}
		++beg;
	}
	return cnt;
}

int main()
{
	{
		std::vector<int> ivec{ 3,6,9,12,15,18 };
		auto riter = ivec.rbegin();
		auto iter = riter.base();

		//	std::cout << *ivec.rend();// this is error.

		std::cout << "comparing reverse iterator with iterator: " << (iter == ivec.end()) << '\n';

		Logger("Displaying ivec with normal iterators");
		display_range(ivec.begin(), ivec.end());
		Logger("Displaying ivec with reverse iterators");
		display_range(ivec.rbegin(), ivec.rend());

	}

	{
		// delete the last desired value (2) in this case
		std::vector<int> find_value{ 3,2,6,2,8,2,9,6,2,1,4,6,7 };
		Logger("The value of vector is: ");
		Logger(find_value);
		int val = 2;
		if (auto riter = find(find_value.rbegin(), find_value.rend(), val); riter != find_value.rend())	// find normally finds the first element but with reverse iterator we solved it.
		{
			find_value.erase(prev(riter.base()));
			Logger("After deleting last ", val);
			Logger(find_value);
		}
		else {
			Logger("Could not find it");
		}
	}

	{
		std::vector<int> ivec{ 3,6,9,12,15,18 };

		Logger("The counted value in ivec: ", count(ivec.begin(), ivec.end(), 6));
		
		auto count_if_result = std::count_if(ivec.begin(), ivec.end(), [](decltype(ivec)::value_type x) {return (x % 3) == 0; });
		Logger("count if result is: ", count_if_result);
	}
}
