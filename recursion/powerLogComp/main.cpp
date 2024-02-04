#include <iostream>

/// @brief m power n with log n time and space complexity.
/// @param m 
/// @param n 
/// @return m^n
int power(int m, int n)
{
    if(0 == n)
        return 1;
    if(0 == n%2)
    {
        return power(m*m , n/2);
    }
    else
    {
        return m * power(m*m, (n-1)/2);
    }
}

int Ipower(int m, int n)
{
    int totalResult = 1;

    while(true)
    {
        if(0 == n)
        {
            break;
        }
        if(0 == n%2)
        {
            m = m * m;
            n = n / 2;
        }
        else
        {
            totalResult = totalResult * m;
            m = m * m;
            n = (n-1) / 2;
        }
    }
    return totalResult;
}

int main()
{
    std::cout << power(2,3) << "\n";
    std::cout << power(2,4) << "\n";
    std::cout << power(2,5) << "\n";
    std::cout << power(2,6) << "\n";

    std::cout << "----Iterative----\n";

    std::cout << Ipower(2,3) << "\n";
    std::cout << Ipower(2,4) << "\n";
    std::cout << Ipower(2,5) << "\n";
    std::cout << Ipower(2,6) << "\n";

}