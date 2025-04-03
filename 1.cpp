#include <iostream>
#include <cmath>

double functionToTake(double x)
{
    return sin(x * x);
}

double integration(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.5 * (functionToTake(a) + functionToTake(b));
    for (int i = 1; i < n; ++i)
    {
        sum += functionToTake(a + i * h);
    }
    return h * sum;
}

int main()
{
    double integralStart = 0;
    double integralEnd = M_PI / 4;
    int n = 2323;
    double result = integration(integralStart, integralEnd, n);
    std::cout << "integral value is about " << result << std::endl;
    return 0;
}