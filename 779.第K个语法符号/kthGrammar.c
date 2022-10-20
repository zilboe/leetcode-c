#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int kthGrammar(int n, int k)
{
    --k;
    int res = 0;
    while (k > 0)
    {
        k &= k - 1;
        res ^= 1;
    }
    return res;
}
int main()
{
    printf ("%d\n",kthGrammar(5,14));

    return 0;
}