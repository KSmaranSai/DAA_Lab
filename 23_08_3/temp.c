#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{

    printf("\n%d", gcd(6, 3));
    return 0;
}