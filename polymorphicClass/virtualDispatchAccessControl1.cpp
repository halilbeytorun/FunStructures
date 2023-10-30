#include <iostream>

class Base
{
public:
	virtual void foo()
	{
		std::cout << "Base";
	}
};
class Der : public Base
{
private:
	virtual void foo() override
	{
		std::cout << "Der";
	}
};
void gf(Base* p)
{
	p->foo();
}
int main()
{
	Der myder;

	gf(&myder);	// this is valid, access control is done for Base class's foo function. virtual dispatch is done at run time.
	//myder.foo();	// this is error.
}