#include <iostream>
#include <vector>
#include<list>
#include <type_traits>
#include <forward_list>
#include <algorithm>
#include <string>


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
    > : std::true_type{};



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
    {
        std::vector<int> ivec{ 1,2,3,4,4,4,5,6 };
        Logger("size of ivec: ", ivec.size());
        Logger("remove test for ivec : ", ivec);
        auto logic_end = std::remove_if(ivec.begin(), ivec.end(), [](int val) {return val == 4; });
        Logger("after remove ivec :", ivec);
        Logger("size of ivec: ", ivec.size());
        // remove algorithms returns logical end of the elements. use container's erase function to actually remove them:
        ivec.erase(logic_end, ivec.end());
        Logger("size of ivec: ", ivec.size());
        // ivec.erase(std::remove(ivec.begin(), ivec.end(), 3), ivec.end()); // remove-erase idiom
    }
    {
        // remove if char is aeiou
        std::string ssting{ "benim adim halil ibrahim, osmanli topraklarinda yasiyorum." };
        //ssting.erase(std::remove_if(ssting.begin(), ssting.end(), [](char a) {return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'; }), ssting.end());
        ssting.erase(std::remove_if(ssting.begin(), ssting.end(), [](char a) {return std::string{ "aeiou" }.find(a) != std::string::npos; }), ssting.end());
        Logger(ssting);
    }

    {   // unique
        std::vector<int> ivec{ 1,1,1,1,1,3,3,3,1,2,3,4,5,1,1,1,1,1,5,6,7,1,2 };
        Logger("size of ivec: ", ivec.size());
        Logger(ivec);
        ivec.erase(std::unique(ivec.begin(), ivec.end()), ivec.end());  // uses == operator
        Logger(ivec);
        Logger("size of ivec: ", ivec.size());
    }
    {
        std::string mystring{"my   name   is halil, i am  25 years old      I am currently worknig at MilSOFT"};
        Logger("remove spaces from: ", mystring.c_str());
        auto iter_end = std::remove_if(mystring.begin(), mystring.end(), [isspace = false] (char a) mutable
        {if (a == ' ')
        {
            if (isspace)
                return true;
            isspace = true;
            return false;
        }
        else
        {
            isspace = false;
            return false;
        }

        });
     
        mystring.erase(iter_end, mystring.end());
        Logger(mystring.c_str());
    }
}
