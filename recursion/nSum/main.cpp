#include <iostream>

// can use sum formula directly..
int sum(int n)
{
    if(0 == n)
        return 0;
    return sum(n-1) + n;
}
int Isum(int n)
{
    int sum = 0;
    for(int i = 0; i <=n; i++)
    {
        sum = sum + i;
    }
    return sum;
}

int main()
{
    std::cout << sum(5) << "\n";
    std::cout << Isum(5) << "\n";
}