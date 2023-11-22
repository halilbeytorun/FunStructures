#include <iostream>
#include<set>

template<typename T>
using Ptr = T*;
Ptr<int> p = nullptr;


template<typename T>
using Arten = T[10];
Arten<int> x;
Arten<double> y;

template<typename T, int n>
using Array = T[n];

Array<char, 30> x1;



template<typename T>
using ipiar = std::pair<T, int>;

template<typename T>
using eq_pair = std::pair<T, T>;
eq_pair<char> test;

template<typename K>
using gset = std::set<K, std::greater<K>>;

template<typename T>
struct hib
{
	using type = T*;
};
template<typename T>
using hib_t = typename hib<T>::type;



int main()
{
	hib_t<int> test{};
	// std example
	std::remove_pointer_t<int*> test2{};

}
