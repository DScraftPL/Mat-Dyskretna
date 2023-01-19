#include <stdio.h>
#include <stdlib.h>
#include "NWD.c"

int main()
{
    int x,y;
    scanf("%i%i",&x,&y);
    printf("%i\n",NWD(x,y));
    ZrNWD test = rNWD(x,y);
    printf("%i*%i + %i*%i = %i\n", x, test.s, y, test.t, NWD(x,y));
}
