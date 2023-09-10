#include <iostream>

enum class Weekday {
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};

std::ostream& operator<<(std::ostream& os, const Weekday& wd)
{
	static const char* const p[] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
	};
	return os << p[static_cast<int>(wd)];
}
//prefix
Weekday& operator++(Weekday& wd)
{
	using enum Weekday;	// C++20
	return wd = wd == Saturday ? Sunday : static_cast<Weekday>(static_cast<int>(wd) + 1);
}
//postfix
Weekday operator++(Weekday& wd, int)
{
	Weekday temp{ wd };
	++wd;
	return temp;
};


int main()
{
	auto wd{ Weekday::Sunday };
	for (int i = 0; i < 100; ++i)
	{
		std::cout << wd++ << '\n';
	}
	auto x = wd;
	std::cout << wd << '\n';
}
