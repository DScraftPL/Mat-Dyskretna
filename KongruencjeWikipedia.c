#include <stdlib.h>
#include <stdio.h>
#include "NWD.h"

int main()
{
    long long x,W; UKon g; int n;
    scanf("%lli%i", &x, &n);
    int *temp = malloc(n * sizeof(int));
    for(int i=0; i<n; i++)
    {
        scanf("%i",&temp[i]);
    }
    g = CKon(x,temp,n);
    for(int i=0; i<n; i++)
    {
        PrintKon(1,g.a[i],g.n[i],1);
    }
    free(temp);
    W = DecKonBrute(g,n);
    printf("%lli\n",W);
}
