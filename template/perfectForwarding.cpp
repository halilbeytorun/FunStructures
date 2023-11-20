#include <iostream>
#include <vector>
#include <list>
#include <string>

class Myclass {};

void foo(Myclass&)
{
	std::cout << "foo(Myclass &) " << "\n";
}

void foo(const Myclass&)
{
	std::cout << "foo(const Myclass &) " << "\n";
}

void foo(Myclass&&)
{
	std::cout << "foo(Myclass &&) " << "\n";
}

template<typename T>
void call_foo(T&& r)// perfect forwarding, remember type deduction..
{
	foo(std::forward<T>(r));	// preserving the value category of the input.
}

int main()
{
	Myclass mx;
	const Myclass cx;

	foo(mx);
	call_foo(mx);

	foo(cx);
	call_foo(cx);

	foo(Myclass{});
	call_foo(Myclass{});
}
