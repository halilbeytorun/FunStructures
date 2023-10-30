#include <iostream>

class Base
{
public:
	void bar()
	{
		foo();
	}
private:
	virtual void foo()
	{
		std::cout << "Base";
	}
};
class Der : public Base
{
public:
	virtual void foo() override {
	std::cout << "Der";
	}	// this is also valid
};
void gf(Base* p)
{
	//p->foo();	// this is error.
	p->bar();	// this is valid, derived foo will be called in the end.
}
int main()
{
	Der myder;
	gf(&myder);
}
//*Herb Sutter
//NVI
//* can override base class's virtual private function (NVI)
//used very much called Non Virtual Interface(NVI)
