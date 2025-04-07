#include <iostream>
#include <cmath>

double sinFunc(double x)
{
    return sin(x * x);
}

double cosFunc(double x)
{
    return cos(x * x);
}

double tanFunc(double x)
{
    return tan(x * x);
}

double cotFunc(double x)
{
    return 1.0 / tan(x * x);
}

double functionToTake(double x, double (*func)(double))
{
    return func(x);
}

double integration(double a, double b, int n, double (*func)(double))
{
    double h = (b - a) / n;
    double sum = 0.5 * (functionToTake(a, func) + functionToTake(b, func));
    for (int i = 1; i < n; ++i)
    {
        sum += functionToTake(a + i * h, func);
    }
    return h * sum;
}

int main()
{
    double integralStart = 0;
    double integralEnd = M_PI / 4;
    int n = 2323;

    int choice{0};
    std::cout << "choose a function to integrate:" << std::endl;
    std::cout << "1) sin(x*x)" << std::endl;
    std::cout << "2) cos(x*x)" << std::endl;
    std::cout << "3) tan(x*x)" << std::endl;
    std::cout << "4) cot(x*x)" << std::endl;
    std::cout << "choose from 1 to 4 which function you want to integrate:" << std::endl;

    double (*selectedFunc)(double);

    do
    {
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            selectedFunc = sinFunc;
            break;
        case 2:
            selectedFunc = cosFunc;
            break;
        case 3:
            selectedFunc = tanFunc;
            break;
        case 4:
            selectedFunc = cotFunc;
            break;
        default:
            std::cout << "nonono, choose something from the list" << std::endl;
            continue;
        }
    } while (choice < 1 || choice > 4);

    double result = integration(integralStart, integralEnd, n, selectedFunc);

    std::cout << "integral is about " << result << std::endl;

    return 0;
}