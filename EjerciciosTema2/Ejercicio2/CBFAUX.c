#include "CBFAUX.h"

/* ---------------------------------------------------------- */
unsigned long factorial(unsigned long num)
{
    /* ---------------------------------------------------------- */
    unsigned long fact;
    unsigned long j;

    fact = 1;
    for (j = 1; j <= num; j++)
        fact *= j;
    return (fact);
}

/* ---------------------------------------------------------- */
unsigned long combinatorio(unsigned long m, unsigned long n)
{
    /* ---------------------------------------------------------- */

    if (n > m)
        return (0);
    else
        return (factorial(m) / (factorial(n) * factorial(m - n)));
}