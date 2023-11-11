#include <iostream>
#include <typeinfo>
#include <cassert>
#include <exception>
#include <memory>



void bar()
{
	throw std::runtime_error{ "error!" };
}
void foo()noexcept	// throwed exceptions will call std::termiante!
{
	bar();
}

int main()
{
	try
	{
		foo();
	}
	catch (const std::exception&)
	{
		std::cout << "exception caught\n";
	}
}

