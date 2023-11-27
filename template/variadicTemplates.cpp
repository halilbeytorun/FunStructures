#include <iostream>


template<typename T>
void recursive_print(const T& r)
{
	std::cout << r << "\n";
}
template<typename T, typename ...TS>
void recursive_print(const T& r, const TS& ... args)
{
	recursive_print(r);
	recursive_print(args...);
}


template <typename ...Ts>
void comma_print(const Ts& ...args)
{
	//int a[] = { ((std::cout << args << "\n"), 0)... };	// must know comma operator
	(void)std::initializer_list<int>{ ((std::cout << args << "\n"), 0)... };
}

template<typename ...TS>
auto unary_left_fold_sum(const TS& ...args)
{
	return (... + args);	// unary left fold
	// (((p1 + p2) + p3) + p4)
}
template<typename ...TS>
auto unary_right_fold_sum(const TS& ...args)
{
	return (args + ...);	// unary right fold
}

template<typename T, typename ...TS>
auto binary_left_fold_sum(T init, TS ...args)
{
	return (init + ... + args);
}

template<typename T, typename ...TS>
auto binary_right_fold_sum(T init, TS ...args)
{
	return (args + ... + init);
}

// can be used as debugging code instead of std::cout.
template<typename ...Args>
void fprint(Args&& ...args)
{
	(std::cout << ... << std::forward<Args>(args)) << '\n';	// binary left fold.
}


int main()
{
	recursive_print(2, 3.4, 7L, "halil");
	std::cout << "\n";
	std::cout << "\n";
	comma_print(2, 3.4, 7L, "halil");
	std::cout << "\n";
	std::cout << "\n";
	std::cout << unary_left_fold_sum(1, 3, 5);
	std::cout << "\n";
	std::cout << "\n";
	std::cout << unary_right_fold_sum(1, 3, 5);

	std::cout << "\n";
	std::cout << "\n";
	std::cout << binary_left_fold_sum(1, 3, 5, 7, 9);

	std::cout << "\n";
	std::cout << "\n";
	fprint("halil", " ibrahim", 18, 2.3);


}
