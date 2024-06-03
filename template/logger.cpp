#include <iostream>
#include <typeinfo>
#include <cassert>
#include <exception>
#include <memory>
#include <vector>
#include <type_traits>


namespace impl
{

    // Check if a type is an STL container using SFINAE
    template <typename T, typename = void>
    struct is_stl_container : std::false_type {};

    template <typename T>
    struct is_stl_container<T,
        std::void_t<
            typename T::value_type,
            typename T::size_type,
            typename T::allocator_type,
            typename T::iterator,
            typename T::const_iterator,
            decltype(std::declval<T>().size()),
            decltype(std::declval<T>().begin()),
            decltype(std::declval<T>().end())
        >
    > : std::true_type {};
    // template<>
    // struct is_stl_container<std::string> : std::false_type{};

    template<typename T>
    std::enable_if_t<!is_stl_container<T>::value> LoggerImpl(const T& a)
    {
        std::cout << a << " ";
    }

    template<typename T, std::size_t n>
    std::enable_if_t<!is_stl_container<T>::value> LoggerImpl(const T (&a)[n])
    {
        for(int i = 0; i < n; i++)
        {
            std::cout << a[i] << " ";
        }
        std::cout << "\n";
    }


    template<typename C>
    std::enable_if_t<is_stl_container<C>::value> LoggerImpl(const C& container)
    {
        if constexpr(std::is_same<C, std::string>::value)
        {
            std::cout << container;
        }
        else
        {
            for (auto iter = container.begin(); iter != container.end(); iter++)
            {
                LoggerImpl(*iter);
                if constexpr(is_stl_container<typename C::value_type>::value)
                {
                    if(container.end() != std::next(iter))
                        std::cout << '\n';
                }
            }
        }
    }

    template<typename T, typename ...Ts>
    void LoggerImpl(const T& a, const Ts& ...args)
    {
        LoggerImpl(a);
        LoggerImpl(args...);
    }
}


template<typename ...Ts>
void Logger(const Ts& ...args)
{
	impl::LoggerImpl(args...);
    std::cout << "\n";
}



int main()
{
	std::vector<std::string> test;
	test.push_back("halil");
	test.push_back("ahmet");
	test.push_back("ali");
	test.push_back("veli");
	Logger(test);

    int a[] = {0, 1, 2, 3, 4, 5};
    Logger(a);
    Logger(a, test);

}

