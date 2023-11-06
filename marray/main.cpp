#include<iostream>


#define marray_Debug

template<typename T, size_t size>
class marray
{
public:
	T& operator[](size_t loc)
	{
#ifdef marray_Debug
		if (loc >= size || loc < static_cast<size_t>(0))
		{
			std::cout << "FATAL ERROR, BAD LOCATION IS GIVEN: " << loc << "\n";
			throw std::runtime_error("The index given is");
		}
#endif
		return m_data[loc];
	}
	const T& operator[](size_t loc) const
	{
#ifdef marray_Debug
		if (loc >= size || loc < static_cast<size_t>(0))
		{
			std::cout << "FATAL ERROR, BAD LOCATION IS GIVEN: " << loc << "\n";
			throw std::runtime_error("The index given is");
		}
#endif
		return m_data[loc];
	}
	T* operator+(const int& value)
	{
#ifdef marray_Debug
		if (value >= size || value < static_cast<size_t>(0))
		{
			std::cout << "FATAL ERROR, BAD LOCATION IS GIVEN: " << value << "\n";
			throw std::runtime_error("The index given is");
		}
#endif
		return m_data + value;
	}
	const T* operator+(const int& value) const
	{
#ifdef marray_Debug
		if (value >= size || value < static_cast<size_t>(0))
		{
			std::cout << "FATAL ERROR, BAD LOCATION IS GIVEN: " << value << "\n";
			throw std::runtime_error("The index given is");
		}
#endif
		return m_data + value;
	}

private:
	T m_data[size];
};


int main()
{
	const marray<double, 5> mConstDoubleArray{};
	//double value  = mDoubleArray[10];
	std::cout << *(mConstDoubleArray.operator+(2));

	marray<double, 10> mDoubleArray{};
	mDoubleArray[1] = (double)10;
	int a = 2;

	return 0;
}