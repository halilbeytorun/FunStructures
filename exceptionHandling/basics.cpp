#include <iostream>
#include <typeinfo>
#include <cassert>
#include <exception>



class Base
{
public:
	virtual ~Base() {}
	virtual const char* str() const
	{
		return "Base";
	}
};
class Der : public Base
{
public:
	virtual const char* str() const override
	{
		return "Der";
	}
};
class Ser : public Base
{
public:
	virtual const char* str() const override
	{
		return "Ser";
	}
};

class Mer : public Base
{
public:
	virtual const char* str() const override
	{
		return "Mer";
	}
};
class SDer : public Der
{
public:
	virtual const char* str() const override
	{
		return "SDer";
	}
};


void f4()
{
	std::cout << "f4 called\n";
	throw Der{};// Change the throw expression here to play.
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
	try {
		f1();
	}
	catch (Der& r)	// should put the special one before general one like this.
	{
		std::cout << "exception caught in function main catch(Der)\n";
		std::cout << r.str() << "\n";	// virtual dispatch activated.
	}
	// upcasting occurs in exception catch, if not special derived class cathch is not written, this will be called (other than Der classes in this case)
	catch (Base& r)
	{
		std::cout << "exception caught in function main catch(Base)\n";
		std::cout << r.str() << "\n";	// virtual dispatch activated.
	}
	// catch parameter must be same type with the thrown parameter, no implicit standard conversions work
	catch (int x) {
		std::cout << "exception caught in function main catch(int x) x =" << x << "\n";
	}
	catch (double x) {
		std::cout << "exception caught in function main catch(double x)\n";
	}
	catch (long x) {
		std::cout << "exception caught in function main catch(long x)\n";
	}
	// default case.
	catch (...)
	{
		std::cout << "exception caught in function main catch(...)\n";
	}
}

