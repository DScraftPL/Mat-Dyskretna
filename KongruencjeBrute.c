#include <stdlib.h>
#include <stdio.h>
#include "NWD.h"

int main()
{
    UKon t; long long x,R; int n;
    scanf("%lli%i",&x,&n);
    int *temp = malloc(sizeof(int)*n), t_m[n], t_il[n];
    for(int i=0; i<n; i++)
    {
        scanf("%i",&temp[i]);
    }
    t = CKon(x,temp,n);
    free(temp);
    separator();
    for(int i=0; i<n; i++)
    {
        PrintKon(1,t.a[i],t.n[i],1);
    }
    separator();
    R = DecKonBrute(t, n);
    printf("%lli\n", R);
}
