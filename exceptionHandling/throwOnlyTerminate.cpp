#include <iostream>
#include <typeinfo>
#include <cassert>
#include <exception>

void mytermiante()
{
	std::cout << "I am metermiante function...\n";
	/// ....
	std::exit(EXIT_FAILURE);
}

void f4()
{
	std::cout << "f4 called\n";
	throw 1;
	std::cout << "f4 returns\n";
}
void f3()
{
	std::cout << "f3 called\n";
	f4();
	std::cout << "f3 returns\n";
}
void f2()
{
	std::cout << "f2 called\n";
	f3();
	std::cout << "f2 returns\n";
}
void f1()
{
	std::cout << "f1 called\n";
	f2();
	std::cout << "f1 returns\n";
}
int main()
{
	auto f = std::set_terminate(&mytermiante);	// this function is called only in release mode for MSVS.
	std::cout << std::boolalpha << (f == &abort) << "\n";
	f1();
	std::cout << "main returns\n";
}

