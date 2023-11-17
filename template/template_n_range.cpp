#include <iostream>
#include <vector>
#include <list>

template<typename Pos>
void Print(Pos beg, Pos end)
{
	while (beg != end)
	{
		std::cout << *beg << ' ';
		++beg;
	}
	std::cout << '\n';
}

int main()
{
	int a[] = { 0,1,2,3,4 };
	Print(a, a + 5);// template type deduction, T will be int*	--> valid call.

	std::vector<int> ivec{ 1,2,3,4,5,6,7,8 };
	Print(ivec.begin(), ivec.end());

	std::list<int> ilist{ 1,2,3,4,5,6 };
	Print(ilist.begin(), ilist.end());
}