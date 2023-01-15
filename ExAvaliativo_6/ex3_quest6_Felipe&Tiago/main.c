#include <stdio.h>
#include <stdlib.h>

int FatorDuplo(int n)
{
    if(n == 1)
    {
        return 1;
    }
    if(n % 2 == 1)
    {
        return n * FatorDuplo(n - 2);
    }

}

int main()
{
    int n;
    int j = 5;

    n = FatorDuplo(j);
    printf("\nFatorial Duplo do numero %d: %d",j, n);

    return 0;
}
