#include <iostream>
#include <typeinfo>


class A
{
public:
	virtual ~A() = default;
};
class B : public A
{
public:
};
class C : public B
{
public:
};

// Note: behaviour of typeid and dynamic_cast operations will change when the type given is not polymorphic!
// This example shows different thing.
int main()
{
	C c{};
	A* baseptr = &c;

	// if (dynamic_cast<B*>(baseptr))
	if (typeid(baseptr).name() == typeid(B).name())
	{
		std::cout << "success";
	}
	else
	{
		std::cout << "fail";
	}
}