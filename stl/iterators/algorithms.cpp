#include <iostream>
#include <vector>
#include<list>
#include <type_traits>
#include <forward_list>
#include<algorithm>

/*
	* iterator categories
	- Input iterator-- > input_iterator_tag
	- output iterator-- > output_iterator_tag
	- forward iterator-- > forward_iterator_tag
	- bideractional iterator-- > bidirectional_iterator_tag
	- random - access iterator-- > random_access_iterator_tag
*/

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


// Minimal Input iterator and output iterator is neeeded for the corresponding template parameters.
// Algorithms that writes in range, returns the place after it wrote its last position
// The objects that InIter and OutIter are holding must be assignable, <int,double>, Spec created objects..
template<typename InIter, typename OutIter>
OutIter Copy(InIter beg, InIter end, OutIter destbeg)
{
	while (beg != end)
	{
		*destbeg = *beg;
		++beg;
		++destbeg;
	}
	return destbeg;
}

template<typename InIter, typename Key>
InIter Find(InIter beg, InIter end, const Key& key)
{
	while (beg != end)
	{
		if (*beg == key)
		{
			return beg;
		}
		beg++;
	}
}

template<typename C>
class BackInsertIterator
{
public:
	BackInsertIterator(C& c) : mc(c) {}
	BackInsertIterator<C>& operator*()
	{
		return *this;
	}
	BackInsertIterator<C>& operator++()
	{
		return *this;
	}
	BackInsertIterator<C>& operator++(int)
	{
		return *this;
	}
	BackInsertIterator<C>& operator=(const typename C::value_type& rhs)
	{
		mc.push_back(rhs);
		return *this;
	}

private:
	C& mc;
};
template<typename C>
BackInsertIterator<C> BackInserter(C& c)
{
	return BackInsertIterator<C>{c};
}

int main()
{

	{
		std::vector<int>::value_type;
		std::vector<double>::iterator::value_type;

		std::vector<int> ivec{ 1,3,5,7,9,13 };
		std::list<int> ilist(6);

		Copy(ivec.begin(), ivec.end(), ilist.begin());
		Logger(ilist);
	}
	{
		std::vector<int>::value_type;
		std::vector<double>::iterator::value_type;

		std::vector<int> ivec{ 1,3,5,7,9,13 };
		std::list<int> ilist;
		// Undefined behaviour would happen if we call Copy
		//Copy(ivec.begin(), ivec.end(), ilist.begin());
	}
	{// random access iterator
		std::vector<int> ivec(10);
		// notice that sort algorithm is designed for random access iterator categoty. (we can understand that from looking into sort function template parameter name)
		std::sort(ivec.begin(), ivec.end());

		std::list<int> ilist(10);
		// std::sort(ilist.begin(), ilist.end()); // this is error.
	}


	{
		std::vector<int>::value_type;
		std::vector<double>::iterator::value_type;

		std::vector<int> ivec{ 1,3,5,7,9,13 };
		std::list<int> ilist;
		// Undefined behaviour would NOT HAPPEN
		Copy(ivec.begin(), ivec.end(), BackInserter(ilist));
		Logger("BackInsertIterator :");
		Logger(ilist);
	}
}
