#include<iostream>


#define marray_Debug


class Mint {
public:
	explicit Mint(int x = 0) : mx{ x } {}

	// sign operators
	Mint operator+() const
	{
		return *this;
	}
	Mint operator-() const
	{
		return Mint{ -mx };
	}

	Mint& operator+=(const Mint& other)
	{
		mx += other.mx;
		return *this;
	}

	Mint& operator-=(const Mint& other)
	{
		mx -= other.mx;
		return *this;
	}

	Mint& operator/=(const Mint& other)
	{
		if (other.mx == 0)
			throw std::runtime_error{ "divide by zero error" };
		mx /= other.mx;
		return *this;
	}

	Mint& operator++()//prefix
	{
		++mx;
		return *this;
	}

	Mint operator++(int)//postfix
	{
		Mint temp{ *this };
		++* this;// calling prefix ++ operator. But we should return the other value.
		// operator++();	// same as above.
		return temp;
	}


	Mint& operator--()//prefix
	{
		--mx;
		return *this;
	}

	Mint operator--(int)//postfix
	{
		Mint temp{ *this };
		--* this;// calling prefix -- operator. But we should return the other value.
		// operator--();	// same as above.
		return temp;
	}




	friend bool operator<(const Mint& lhs, const Mint& rhs)	// since these hidden friend global function is friend of Mint, it can reach private members.
	{
		return lhs.mx < rhs.mx;
	}

	friend bool operator==(const Mint& lhs, const Mint& rhs)	// since these hidden friend global function is friend of Mint, it can reach private members.
	{
		return lhs.mx == rhs.mx;
	}

	// inserter
	friend std::ostream& operator<<(std::ostream& os, const Mint& mint)
	{
		return os << mint.mx;
	}
	// extractor
	friend std::istream& operator>>(std::istream& os, Mint& mint)
	{
		return os >> mint.mx;
	}
private:
	int mx;
};

inline bool operator!=(const Mint& lhs, const Mint& rhs)
{
	return !(lhs == rhs);
}

inline bool operator>(const Mint& lhs, const Mint& rhs)
{
	return rhs < lhs;
}
inline bool operator>=(const Mint& lhs, const Mint& rhs)
{
	return !(lhs < rhs);
}

inline bool operator<=(const Mint& lhs, const Mint& rhs)
{
	return !(rhs < lhs);
}

// scott mayers recommended like this, implement += operator then use it to implement  binary + operator.
inline Mint operator+(const Mint& r1, const Mint& r2)
{
	return Mint{ r1 } += r2;
}
// scott mayers recommended like this, implement -= operator then use it to implement  binary - operator.
inline Mint operator-(const Mint& r1, const Mint& r2)
{
	return Mint{ r1 } -= r2;
}
// scott mayers recommended like this, implement /= operator then use it to implement  binary / operator.
inline Mint operator/(const Mint& r1, const Mint& r2)
{
	return Mint{ r1 } /= r2;
}


int main()
{

	Mint myint1{ 1 };
	Mint myint2{ 2 };
	Mint myint3{ 3 };
	Mint myint4{ 4 };


	myint3 = myint1 + myint2;
	std::cout << myint3;


	return 0;
}