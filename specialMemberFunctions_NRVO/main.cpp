#include <iostream>


class Myclass
{
public:
	Myclass()
	{
		std::cout << "default ctor\n";
	}
	Myclass(const Myclass&)
	{
		std::cout << "copy ctor\n";
	}
	Myclass(Myclass&&)
	{
		std::cout << "move ctor\n";
	}

	Myclass& operator=(const Myclass&)
	{
		std::cout << "copy assignment operator\n";
		return *this;
	}
	Myclass& operator=(Myclass&&)
	{
		std::cout << "move assignment operator\n";
		return *this;

	}

};

Myclass foo()
{
	Myclass m;
	return m;
}



int main()
{
	//Myclass a;
	//a = foo();
	//foo();

	Myclass a = foo();
	//foo();

}