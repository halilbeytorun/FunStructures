#include <iostream>


class A
{
public:
	A()
	{
		std::cout << "Default ctor\n";
	}
	// If this is made explicit, then the code won't compile.
	A(int)
	{
		std::cout << "conversion ctor\n";
	}
	A& operator=(const A& other)
	{
		std::cout << "copy assignment operator\n";
		return *this;
	}
	// If this is commented, copy assignment operator would be called.
	A& operator=(A&& other)
	{
		std::cout << "move assignment operator\n";
		return *this;
	}

};

int main()
{
	A a;
	a = 1;
}
