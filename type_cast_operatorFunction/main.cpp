#include <iostream>

class Counter {
public:
	Counter() = default;
	explicit Counter(int x) : mx{ x } {};

	Counter& operator++()//prefix
	{
		++mx;
		return *this;
	}
	Counter operator++(int)//postfix
	{
		Counter temp{ *this };
		++* this;
		return temp;
	}
	explicit operator int()const
	{
		return mx;
	}

private:
	int mx{};
};

int main()
{
	Counter mycounter{ 34 };
	for (int i = 0; i < 10; ++i)
	{
		++mycounter;
	}
	mycounter++;

	auto x1 = static_cast<int>(mycounter);
	auto x2 = (int)mycounter;
	auto x3 = int(mycounter);
	std::cout << "x1:" << x1 << " x2:" << x2 << " x3:" << x3 << "\n";
	//int ival = mycounter;	// this one is error....

}
