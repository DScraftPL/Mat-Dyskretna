#include <stdio.h>
#include <stdlib.h>

typedef struct zrNWD
{
    int s;
    int t;
} ZrNWD;

int NWD(int a, int b)
{
    int r;
    while(b!=0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

ZrNWD rNWD(int a, int b)
{
    ZrNWD n;
    int q,r,s[2],t[2],temp_t, temp_s;
    s[0] = 1;
    s[1] = 0;
    t[0] = 0;
    t[1] = 1;
    while(a%b!=0)
    {
        r = a%b;
        q = a/b;
        a = b;
        b = r;
        temp_t = t[0] - t[1]*q;
        t[0] = t[1];
        t[1] = temp_t;
        temp_s = s[0] - s[1]*q;
        s[0] = s[1];
        s[1] = temp_s;
    }
    n.t = t[1];
    n.s = s[1];
    return n;
}

int Kon(int m, int a, int n)
{
    int nwd = NWD(m,n);
    while(a<=0)
    {
        a += n;
    }
    if(nwd%a == 0)
    {
        m = m/nwd;
        n = n/nwd;
        a = a/nwd;
    }
    if(NWD(m,n) == 1)
    {
        ZrNWD t = rNWD(m,n);
        return (a*t.s)%n;
    }
    else
    {
        return -1;
    }
}

int *PRIMES(int n){
    int t[10000];
    for(int i=1; i<10000; i++)
    {
        t[i] = 0;
    }
    for(int i=2; i<10000; i++)
    {
        if(t[i]==0)
        {
            for(int j=2; j*i<10000; j++)
            {
                t[i*j]=1;
            }
        }
    }
    int *B,it=0,i=2;
    B = malloc(n * sizeof(int));
    while(it<n)
    {
        if(t[i]==0)
        {
            B[it] = i;
            it++;
        }
        i++;
    }
    return B;
}
