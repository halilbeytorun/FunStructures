#include <iostream>


int factorial(int n)
{
    if(0 == n)
        return 1;
    
    return factorial(n-1) * n;
}

int IFactorial(int n)
{
    int result = 1;
    for(int i = 1; i <= n; i++)
    {
        result = result * i;
    }
    return result;
}

int main()
{
    std::cout << factorial(5) << "\n";
    std::cout << IFactorial(5) << "\n";
}