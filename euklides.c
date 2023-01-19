#include <stdio.h>
#include <stdlib.h>
#include "NWD.c"

int main()
{
    int x,y,m,a,n,a1,a2,n1,n2;
    printf("======================NWD======================\n");
    scanf("%i%i",&x,&y);
    printf("%i\n",NWD(x,y));
    ZrNWD test = rNWD(x,y);
    printf("%i*%i + %i*%i = %i\n", x, test.s, y, test.t, NWD(x,y));
    printf("======================Kongruencja======================\n");
    printf("m * x = a mod n\n");
    scanf("%i%i%i",&m,&a,&n);
    printf("%i\n", Kon(m,a,n));
    printf("======================Układ Kongruencji (1)======================\n");
    scanf("%i%i%i",&x,&n1,&n2);
    a1 = x%n1;
    a2 = x%n2;
    printf("rozwiazanie 1: %i\n",Kon(1,a1,n1));
    printf("rozwiazanie 2: %i\n",Kon(n1, a2-Kon(1,a1,n1), n2));
    printf("rozwiazanie w %i * %i (= %i): \n%i\n", n1, n2, n1*n2, Kon(1,a1,n1) + n1*Kon(n1, a2-Kon(1,a1,n1), n2));
    printf("======================Układ Kongruencji (2)======================\n");
    scanf("%i%i",&x,&n);
    int tn[n],ta[n],tk[n];
    for(int i=0; i<n; i++)
    {
        scanf("%i",&tn[i]);
        ta[i]=x%tn[i];
    }
    tk[0] = Kon(1,ta[0],tn[0]);
    for(int i=1; i<n; i++)
    {
        tk[i] = Kon(tn[i-1],ta[i]-tk[i-1],tn[i]);
    }
    int suma = tk[0];
    //printf("%i %i %i %i\n", tk[0], tn[0], ta[0], suma);
    for(int i=1; i<n; i++)
    {
        suma += tn[i-1]*tk[i];
        //printf("%i %i %i %i\n", tk[i], tn[i], ta[i], suma);
    }
    printf("%i",suma);
}
