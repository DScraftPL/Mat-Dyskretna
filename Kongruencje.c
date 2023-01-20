#include <stdlib.h>
#include <stdio.h>
#include "NWD.h"

int main()
{
    int x,n;
    scanf("%i%i",&x,&n);
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
    while(t_m[0]%t_n[1]==t_a[1])
    {
        t_m += t_n[0];
    }
}
