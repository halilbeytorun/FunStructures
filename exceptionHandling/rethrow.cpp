#include <iostream>
#include <typeinfo>
#include <cassert>
#include <exception>
#include <memory>


void bar()
{
	try
	{
		throw std::out_of_range{ "value out of range" };
	}
	catch (const std::exception& ex)
	{
		std::cout << "error is catched in bar function...\n";
		std::cout << "the address of the exception object is: " << &ex << "\n";
		//throw ex;	// object slicing will occur here.
		throw;
	}
}


int main()
{
	try
	{
		bar();
	}
	catch (const std::out_of_range& ex)
	{
		std::cout << "error is catched in main function...\n";
		std::cout << "out_of_range\n";
		std::cout << "the address of the exception object is: " << &ex << "\n";
	}
	catch (const std::exception& ex)
	{
		std::cout << "error is catched in main function...\n";
		std::cout << "exception\n";
		std::cout << "the address of the exception object is: " << &ex << "\n";
	}
}

