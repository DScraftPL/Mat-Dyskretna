#include <stdlib.h>
#include <stdio.h>
#include "NWD.h"

int main()
{
    long long x1,x2,W; UKon u1,u2,u3; int n;
    scanf("%i", &n);
    int *temp = malloc(n * sizeof(int));
    for(int i=0; i<n; i++)
    {
        scanf("%i",&temp[i]);
    }
    scanf("%lli%lli",&x1,&x2);
    u1 = CKon(x1,temp,n);
    u2 = CKon(x2,temp,n);
    free(temp);
    u3 = MulKon(u1,u2,n);
    W = DecKonBrute(u3, n);
    printf("%lli\n", W);
}
