#include "funkcja.h"
#include <math.h>

int mzero(double x1, double x2, double epsilon, int method, double *x0)
{
    double f1, f2, f0;
    int i;

    f1 = f(x1), f2 = f(x2);
    if (f1 * f2 > 0)
        return -1;

    i = 2;
    do
    {
        if (method != 0)
            *x0 = (f2 * x1 - f1 * x2) / (f2 - f1);
        else
            *x0 = 0.5 * (x1 + x2);

        f0 = f(*x0);

        if (f0 * f1 > 0)
        {
            x1 = *x0;
            f1 = f0;
        }
        else
        {
            x2 = *x0;
            f2 = f0;
        }

        i++;
    } while (fabs(f0) > epsilon || fabs((x2 - x1) / *x0) > epsilon);

    return i;
}