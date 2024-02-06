#include <iostream>
#include <tuple>

double e(int x, int n)
{
    static double p =1, f = 1;
    double r{};
    if(0 == n)
        return 1;
    r = e(x, n-1);
    p = p * x;  // these operations are done at returning time.
    f = f * n;
    return r + p/f;
}

/// @brief same operation without static variables, an extra recursive function can be created to preserve function return type.
/// @param x 
/// @param n 
/// @return result, p, f 
std::tuple<double,double,double> edifferent(int x, int n)
{
    if(0 == n)
        return std::make_tuple(1.0,1.0,1.0);
    auto [r,p,f] = edifferent(x, n-1);
    p = p * x;
    f = f * n;    
    return std::make_tuple(r + p/f,p,f);
}

/// @brief Horner's method.
/// @param x 
/// @param n 
/// @return 
double eHorner(int x, int n)
{
    static double s = 1;
    if(0 == n)
        return s;
    s = 1 + s*x/n;
    return eHorner(x,n-1);
}

double eIterative(int x, int n)
{
    double s=1;
    double num = 1;
    double denum = 1;

    for(int i = 1; i <= n; i++)
    {
        num = num * x;
        denum = denum * i;
        s = s + num/denum;
    }
    return s;
}


int main()
{
    std::cout << e(1,10) << "\n";
    std::cout<< std::get<0>(edifferent(1,10)) << "\n";
    std::cout << eHorner(1,10) << "\n";
    std::cout << eIterative(1,10) << "\n";
}