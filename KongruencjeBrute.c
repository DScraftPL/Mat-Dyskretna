#include <stdlib.h>
#include <stdio.h>
#include "NWD.h"

// trzeba i tak odtworzyc, wiec musi byc przynajmniej 1 zmienna musi byc wielkosci danej liczby :/

int main()
{
    long long x;
    int n;
    scanf("%lli%i",&x,&n);
    int t_m[n],t_n[n],t_a[n],t_il[n];
    for(int i=0; i<n; i++)
    {
        scanf("%i",&t_n[i]);
        t_a[i] = x%t_n[i];
    }
    printf("===============================\n");
    for(int i=0; i<n; i++)
    {
        printf("x = %i (mod %i)\n",t_a[i],t_n[i]);
    }
    printf("===============================\n");
    t_m[0] = t_a[0];
    t_il[0] = t_n[0];
    for(int i=1; i<n; i++)
    {
        t_m[i] = Kon(1,t_m[i-1],t_il[i-1]);
        while(t_m[i] % t_n[i] != t_a[i])
        {
            t_m[i] += t_il[i-1];
        }
        t_il[i] = t_il[i-1] * t_n[i];
        printf("x = %i (mod %i)\n",t_m[i],t_il[i]);
    }
    printf("%i\n", t_m[n-1]);
}
