#include "Methods.h"
#include <cmath>
double function(const double& x)
{
    return pow((x*x*x-1),-0.5);
}

double trapezium_method(double(&function)(const double&), const double& start, const double& end, const unsigned long& n)
{
    double h = (end - start) / n;
    double f = 0;

    for (int i = 1; i < n - 1; ++i)
    {
        f += function(start + h * i);
    }

    return h * (function(start) + 2 * f + function(end)) / 2;
}

double calculate_trapezium_method(double(&function)(const double&), const double& start, const double& end, const double& epsilon)
{
    long n = 10;
    double intg1 = 0;
    double intg2 = trapezium_method(function, start, end, n);

    while (abs(intg1 - intg2) > 3 * epsilon)
    {
        n *= 2;
        intg1 = intg2;
        intg2 = trapezium_method(function, start, end, n);
    }

    return intg2;
}

double simson_method(double(&function)(const double&), const double& start, const double& end, const unsigned long& n)
{
    unsigned int m = n / 2;
    double h = (end - start) / n;
    double f1 = 0;
    double f2 = 0;

    for (int i = 1; i <= m; ++i)
    {
        f1 += function(start + (double(i) * 2 - 1) * h);
    }

    for (int i = 1; i <= m - 1; ++i)
    {
        f2 += function(start + (double(i) * 2) * h);
    }

    return h * (function(start) + 4 * f1 + 2 * f2 + function(end)) / 3;
}

double calculate_simson_method(double(&function)(const double&), const double& start, const double& end, const double& epsilon)
{
    long n = 10;
    double integral_1 = 0;
    double integral_2 = simson_method(function, start, end, n);

    while (abs(integral_1 - integral_2) > 15 * epsilon)
    {
        n *= 2;
        integral_1 = integral_2;
        integral_2 = simson_method(function, start, end, n);
    }

    return integral_2;
}
