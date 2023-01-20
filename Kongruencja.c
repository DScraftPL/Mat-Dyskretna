#include <stdlib.h>
#include <stdio.h>
#include "NWD.h"

int main()
{
    int m,a,n;
    printf("m*x = a (mod n)\n");
    scanf("%i%i%i",&m,&a,&n);
    printf("%i * x = %i (mod %i)\nx = %i + %i * k\n",m,a,n,Kon(m,a,n),n);
}
