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

class DividePredicate
{
public:
	DividePredicate(int val) : mval(val) {}
	bool operator()(int x) const {

		return x % mval == 0;
	}
private:
	int mval;
};

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

		Logger("The counted value in ivec: ", count(ivec.begin(), ivec.end(), 6));

		auto count_if_result = std::count_if(ivec.begin(), ivec.end(), [](decltype(ivec)::value_type x) {return (x % 3) == 0; });
		Logger("count if result is: ", count_if_result);

		auto mycount_if_result = Count_if(ivec.begin(), ivec.end(), [](decltype(ivec)::value_type x) {return (x % 3) == 0; });
		Logger("count if result for my function is: ", mycount_if_result);
	}

	{
		Logger("predicate for callable objects....");
		std::vector<int> ivec{ 3,6,9,12,15,18 };

		auto mycount_if_result = Count_if(ivec.begin(), ivec.end(), DividePredicate(2));
		Logger("count if result for my function is: ", mycount_if_result);
	}


}
