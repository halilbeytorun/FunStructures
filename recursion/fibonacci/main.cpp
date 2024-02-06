#include <iostream>

int fibIter(int n)
{
    int t0 = 0;
    int t1 = 1;
    int s{};
    if(n <= 1)
        return n;
    
    for(int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int fibRec(int n)
{
    if(1 >= n)
        return n;
    return fibRec(n-2) + fibRec(n-1);
}

int F[10];
int fibMemo(int n)
{
    if (1 >= n)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if(-1 == F[n-2])
        {
            F[n-2] = fibMemo(n-2);
        }
        if(-1 == F[n-1])
        {
            F[n-1] = fibMemo(n-1);
        }
        F[n] = F[n-2] + F[n-1];
        return F[n];
    }
}

int main()
{
    std::cout << fibIter(10) << "\n";
    std::cout << fibRec(10) << "\n";

    // init memoizated array.
    for(int i = 0; i < 10; i++)
    {
        F[i] = -1;
    }
    std::cout << fibMemo(10) << "\n";


}