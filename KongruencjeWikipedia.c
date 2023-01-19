#include <stdlib.h>
#include <stdio.h>
#include "NWD.c"

int main()
{
    long long M=1,x,Mi,W=0;
    int n,e;
    ZrNWD g;
    scanf("%lli%i",&x,&n);
    int t_n[n],t_a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%i",&t_n[i]);
        t_a[i] = x%t_n[i];
        M *= t_n[i];
    }
    printf("===============================\n");
    for(int i=0; i<n; i++)
    {
        printf("x = %i (mod %i)\n",t_a[i],t_n[i]);
    }
    printf("===============================\n");
    for(int i=0; i<n; i++)
    {
        Mi = M/t_n[i];
        g = rNWD(t_n[i],Mi);
        e = g.t*Mi;
        W += e*t_a[i];
        printf("%lli %i %i %lli\n",Mi,g.t,e,W);
    }
    printf("%lli\n",W);
}
