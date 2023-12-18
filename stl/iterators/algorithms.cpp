#include <iostream>
#include <vector>
#include<list>
#include <type_traits>
#include <forward_list>
#include<algorithm>

/*
* 
* iterator categories
	- Input iterator-- > input_iterator_tag
	- output iterator-- > output_iterator_tag
	- forward iterator-- > forward_iterator_tag
	- bideractional iterator-- > bidirectional_iterator_tag
	- random - access iterator-- > random_access_iterator_tag
*
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

template<typename InIter, typename Ty>
int Count(InIter beg, InIter end, const Ty& val)
{
	int count{};
	while (beg != end)
	{
		if (val == *beg)
		{
			count++;
		}
		beg++;
	}
	return count;
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

// Finds the first key value found in the container. Iter can be iterator or reverse iterator.
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

template<typename InIter, typename Pr>
InIter Find_If(InIter beg, InIter end, Pr cond)
{
	while (beg != end)
	{
		if (cond(*beg))
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


// UFunc does not have to be predicate (bool return) but it needs to be unary.
// Note that algorithms what write in range returns after last position it writes.
template<typename InIter, typename OutIter, typename UFunc>
OutIter Transform(InIter beg, InIter end, OutIter destbeg, UFunc f)
{
	while (beg != end)
	{
		*destbeg++ = f(*beg++);
	}
	return destbeg;
}



// UFunc does not have to be predicate (bool return) but it needs to be binary.
// Note that algorithms what write in range returns after last position it writes.
template<typename InIter1, typename InIter2, typename OutIter, typename BiFunc>
OutIter Transform(InIter1 beg1, InIter1 end, InIter2 beg2, OutIter destbeg, BiFunc f)
{
	while (beg1 != end)
	{
		*destbeg++ = f(*beg1++, *beg2++);
	}
	return destbeg;
}

template<typename Iter, typename Ufunc>
Ufunc Foreach(Iter beg, Iter end, Ufunc f)
{
	while (beg != end)
	{
		f(*beg++);
	}
	return f;	// return the callable because f can be callable object.
}



int main()
{
	/*
	* Algorithms in here are:
	* std::count, std::count_if, std::copy, std::copy_if, std::find, std::find_if, std::sort, std::tranform (2 overload), std::for_each
	*/
	
	{
		Logger("count algorithm:");
		std::vector<int> ivec{ 1,2,3,3,3,3,5,6,7 };
		auto result = Count(ivec.begin(), ivec.end(), 3);
		Logger("Counted: ", 3, " and result is: ", result);
		// there is also count if algorithm
		//std::count() // the template parameter names says that it requires min input iterator

	}

	{
		Logger("Copy algorithm written by me. Note that destination container can be different container.");
		std::vector<int>::value_type;
		std::vector<double>::iterator::value_type;

		std::vector<int> ivec{ 1,3,5,7,9,13 };
		std::list<int> ilist(6);

		Copy(ivec.begin(), ivec.end(), ilist.begin());
		Logger(ilist);
	}
	{
		Logger("Note that undefined behaviour would happen if destionation container does not have enoguh space and back_inserter is not used");
		std::vector<int>::value_type;
		std::vector<double>::iterator::value_type;

		std::vector<int> ivec{ 1,3,5,7,9,13 };
		std::list<int> ilist;
		// Undefined behaviour would happen if we call Copy
		//Copy(ivec.begin(), ivec.end(), ilist.begin());
	}

	{
		Logger("Find algorithm written by me:");
		std::vector<int> ivec{ 1,2,3,4,5,6 };
		Logger(ivec);
		auto iter = Find(ivec.begin(), ivec.end(), 2);
		Logger("the found result is: ", *iter);
		iter = Find_If(ivec.begin(), ivec.end(), [](const int a) {return a == 5; });
		Logger("the found result is: ", *iter);
	}

	{// random access iterator
		Logger("std::vector<int>::iterator:iterator_category: ", typeid(std::vector<int>::iterator::iterator_category).name());	// random access iterator category: 
		std::vector<int> ivec{2,1,8,2,5,9,10,1,16,32};
		// notice that sort algorithm is designed for random access iterator categoty. (we can understand that from looking into sort function template parameter name)
		Logger(ivec);
		std::sort(ivec.begin(), ivec.end());
		Logger(ivec);
		std::sort(ivec.rbegin(), ivec.rend());
		Logger(ivec);

		std::list<int> ilist(10);
		// std::sort(ilist.begin(), ilist.end()); // this is error.
	}


	{
		Logger("Back Insert Iterator example: ");
		std::vector<int>::value_type;
		std::vector<double>::iterator::value_type;

		std::vector<int> ivec{ 1,3,5,7,9,13 };
		std::list<int> ilist;
		// Undefined behaviour would NOT HAPPEN
		Copy(ivec.begin(), ivec.end(), BackInserter(ilist));
		Logger(ilist);
	}


	// Transform
	{
		std::vector<std::string> svec{"halil", "ibo", "ahmetwtwtwtw"};
		std::vector<std::size_t> lvec;
		Logger("Transform function implementation......");
		Transform(svec.begin(), svec.end(), BackInserter(lvec), [](const std::string& s) {return s.length(); });
		Logger(lvec);

		Transform(svec.rbegin(), svec.rend(), BackInserter(lvec), [](const std::string& s) {return s.size(); });
		Logger(lvec);

		// Operate on itself.
		Transform(svec.begin(), svec.end(), svec.begin(), [](std::string& s) { std::reverse(s.begin(), s.end()); return s; });
		Logger(svec);

	}

	{
		int a[] = { 1,3,5,7,12,67, 20, 56, 90 };
		std::vector<int> ivec = { 11,22,33,12, 41, 12, 32, 98, 89 };
		std::list<int> my_list;
		Logger("Double Transform function implementation......");
		// The caller is responsible for the equality of .size of both containers
		Transform(std::begin(a), std::end(a), std::begin(ivec), std::back_inserter(my_list), [](const int a, const int b) {return a * a + b * b; });
		Logger(my_list);
	}

	{
		Logger("For each function implementation......");
		std::vector<int> ivec = { 1,3,5,6,1,15,5,2,7,87,97,1 };
		Foreach(std::begin(ivec), std::end(ivec), [](int& a) {a++; });
		Logger(ivec);
	}

	{
		Logger("any_of, all_of, none_of examples....");
		std::vector<int> ivec{ 2,4,2,2,2,6,0 };
		Logger(std::any_of(ivec.begin(), ivec.end(), [](int x) {return x % 2 != 0; }));
		Logger(std::all_of(ivec.begin(), ivec.end(), [](int x) {return x % 2 == 0; }));
		Logger(std::none_of(ivec.begin(), ivec.end(), [](int x) {return x % 2 != 0; }));
	}

	{
		Logger("max element");
		std::vector<std::string> svec{"halia", "zeynep", "a1", "a2", "a3", "a3", "a5"};
		Logger(svec);
		auto iter=std::max_element(svec.begin(), svec.end());
		Logger("max = ", *iter, " max idx = ", std::distance(svec.begin(), iter));
		std::advance(iter, 3);
		Logger("max = ", *iter, " max idx = ", std::distance(svec.begin(), iter));

		auto mpair = std::minmax_element(svec.begin(), svec.end());
		Logger(*mpair.first," ", * mpair.second);

		auto [first, second] = std::minmax_element(svec.begin(), svec.end());	// structured_binding
		Logger(*first, " ", *second);
	}
}
