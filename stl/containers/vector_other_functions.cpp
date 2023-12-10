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
		std::vector<int> myvec{};
		Logger("size of myvec: ", myvec.size(), "       capacity of myvec: ", myvec.capacity());
		auto cap = myvec.capacity();
		while (myvec.size() < 100'000)
		{
			myvec.push_back(1);
			if (cap != myvec.capacity())
			{
				Logger("reallocation is occured: ", myvec.capacity());
				cap = myvec.capacity();
			}
		}
		myvec.resize(10);
		Logger("the capacity of myvec is still big, must shrink it: ", myvec.capacity(), "    size of myvec: ", myvec.size());
		myvec.shrink_to_fit();
		Logger("capacity after shrinknig: ", myvec.capacity());
	}

	{
		std::vector<int> myvec;
		myvec.resize(100);
		Logger("capacity after resizing: ", myvec.capacity(), "   size after resizing: ", myvec.size());
	}
	{
		std::vector<int> myvec;
		myvec.reserve(100);
		Logger("capacity after reserve: ", myvec.capacity(), "   size after reserve: ", myvec.size());
	}

	{
		// iterating over vector
		Logger("iterating over vector");
		std::vector<int> myvec{ 1,2,3,4,5 };
		for (auto x : myvec)
		{
			x = 1;
		}
		Logger(myvec);
		for (auto &x : myvec)
		{
			x = 1;
		}
		Logger(myvec);
		for (auto &&x : myvec)
		{
			x = 2;
		}
		Logger(myvec);
	}

	{
		// accessing elements of vector
		// []// like in string			--> accessing wrong index will be undefined behaviour.
		// .at function // like in string class--> accessing wrong index will be out_of_range exception!
		// .front, .back() all container classes. returns with referance semantics.		--> using them in an empty vector is undefined behaviour!
		// all of the are const overloaded.
		Logger("accessing elements of vector");

		std::vector<std::string> svec{ "halil", "ibo", "biyik" };
		svec[0] += " ibrahim";
		svec.front() += " beytorun";
		svec.back() += " musti";
		Logger(svec);
	}

	{
		std::vector<int> myvec;
		auto beg = myvec.begin();
		auto end = myvec.end();
		// these are okay, not undefined behaviour. and they are equal..
		std::list<int> x;
		std::copy(myvec.begin(), myvec.end(), back_inserter(x));	// this function is okay, no undefined behaviour.
	}

	{
		// changing the size of the vector.

	}
}
