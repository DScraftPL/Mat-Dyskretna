#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int s;
    int t;
} ZrNWD;

typedef struct
{
    int a[100];
    int n[100];
} UKon;

//Policzenie NWD Algorytmem Euklidesa
int NWD(int, int);

//Policzenie Roszerzonego Algorytmu Euklidesa do struktury ZrNWD
ZrNWD rNWD(int, int);

//Policzenie Rozwiązania Kongruencji m * x = a (mod n)
int Kon(int, int, int);

//Tablica liczb pierwszych do n
int* Primes(int);

//Wypisanie kongruencji:
//PrintKon(m,a,n,tryb):
//tryb = 1 - Wypisanie kongruencji m * x = a (mod n)
//tryb = 0 - Wypisanie rozwiązania kongruencji (x = Kon(m,a,n) (mod n))
void PrintKon(int, int, int, int);

//Zapisanie liczby w strukturze
UKon CKon(long long, int*, int);

//Wypisanie rozdzielacza
void separator();

//Wypisanie liczby metoda brute-force
long long DecKonBrute(UKon, int);

//Wypisanie liczby metodą z wikipedii
long long DecKonWiki(UKon, int);

//Dodawanie Kongruencji (Układy Kongruencji muszą mieć te same moduły)
UKon AddKon(UKon, UKon, int);

//Odejmowanie Kongruencji (Układy Kongruencji muszą mieć te same moduły)
//Uwaga: Wpisywać w kolejności rosnącej
UKon SubKon(UKon, UKon, int);

//Mnożenie Kongruencji (Układy Kongruencji muszą mieć te same moduły)
UKon MulKon(UKon, UKon, int);

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
void PrintKon(int m, int a, int n, int k)
{
    if(k == 1)
    {
        if(m == 1)
        {
            printf("x = %i (mod %i)\n",a,n);
        }
        else
        {
            printf("%i * x = %i (mod %i)\n",m,a,n);
        }
    }
    else if(k == 0)
    {
        printf("x = %i + %i * k\n", Kon(m,a,n),n);
    }
    else
    {
        printf("%i * x = %i (mod %i)\n",m,a,n);
        printf("x = %i + %i * k\n", Kon(m,a,n),n);
    }
}

UKon CKon(long long x, int t[], int n)
{
    UKon B;
    for(int i=0; i<n; i++)
    {
        B.n[i] = t[i];
        B.a[i] = x % B.n[i];
    }
    return B;
}

void separator()
{
    printf("===============================\n");
}

long long DecKonBrute(UKon t, int n)
{
    int t_m[n], t_il[n];
    t_m[0] = t.a[0]; t_il[0] = t.n[0];
    for(int i=1; i<n; i++)
    {
        t_m[i] = Kon(1,t_m[i-1],t_il[i-1]);
        while(t_m[i] % t.n[i] != t.a[i])
        {
            t_m[i] += t_il[i-1];
        }
        t_il[i] = t_il[i-1] * t.n[i];
    }
    return t_m[n-1];
}

long long DecKonWiki(UKon t, int n)
{
    ZrNWD g; long long M=1, Mi, W=0, e;
    for(int i=0; i<n; i++)
    {
        M *= t.n[i];
    }
    for(int i=0; i<n; i++)
    {
        Mi = M/t.n[i];
        g = rNWD(t.n[i],Mi);
        e = g.t*Mi;
        W += e*t.a[i];
    }
    while(W<0)
    {
        W += M;
    }
    return W;
}

UKon AddKon(UKon a, UKon b, int n)
{
    UKon B;
    for(int i=0; i<n; i++)
    {
        B.n[i] = a.n[i];
        B.a[i] = (a.a[i] + b.a[i])%B.n[i];
    }
    return B;
}

UKon SubKon(UKon a, UKon b, int n)
{
    UKon B;
    for(int i=0; i<n; i++)
    {
        B.n[i] = a.n[i];
        B.a[i] = (a.a[i] - b.a[i])%B.n[i];
        while(B.a[i]<0)
        {
            B.a[i] += B.n[i];
        }
    }
    return B;
}

UKon MulKon(UKon a, UKon b, int n)
{
    UKon B;
    for(int i=0; i<n; i++)
    {
        B.n[i] = a.n[i];
        B.a[i] = (a.a[i] * b.a[i])%B.n[i];
    }
    return B;
}
