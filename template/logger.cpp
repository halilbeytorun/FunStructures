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



    template<typename C>
    std::enable_if_t<is_stl_container<C>::value> LoggerImpl(const C& container)
    {
        for (auto i : container)
        {
            std::cout << i << ' ';
        }
    }
    template<typename T>
    std::enable_if_t<!is_stl_container<T>::value> LoggerImpl(const T& a)
    {
        std::cout << a << " ";
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
    std::vector<int> ivec{10,10,10,10};
    Logger(ivec);
    Logger(1,2,3,4);
    Logger("testing: ", 1, 2, " container tesing: ", ivec);
    int x{}, y{};
    double z{};
    Logger(x, y, z, 1, 2, 3L, "testing stuff");
}

