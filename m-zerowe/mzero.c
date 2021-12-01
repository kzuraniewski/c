#include "funkcja.h"
#include <math.h>
#include <stdio.h>

#define MAX_STEPS 1000

int mzero(double x1, double x2, double epsilon, int method, double *x0)
{
    double f1, f2, f0;
    int i;
    f1 = f(x1), f2 = f(x2);

    if (f1 * f2 > 0)
        return -1;

    i = 2;

    if (method == 0)
    {
        do
        {
            *x0 = (x1 + x2) / 2;

            f0 = f(*x0);
            if (f0 == 0.0)
                break;

            else if (f0 * f1 < 0)
            {
                x2 = *x0;
                f2 = f(x2);
            }

            else
            {
                x1 = *x0;
                f1 = f(x1);
            }

            i++;
        } while (fabs(x2 - x1) >= epsilon);

        return i;
    }

    else if (method == 1)
    {
        do
        {
            f0 = f(*x0), f1 = f(x1);

            x2 = x1 - (x1 - *x0) * f1 / (f1 - f0);
            f2 = f(x2);

            *x0 = x1;
            f0 = f1;
            x1 = x2;
            f1 = f2;

            i++;

            if (i >= MAX_STEPS)
                return -1;

        } while (fabs(f2) > epsilon);

        return i;
    }

    return -1;
}