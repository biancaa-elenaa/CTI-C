#include <stdio.h>
#include "hs_utils.h"

unsigned estePrim(unsigned long long n) 
{
    if(n<2)
        return 0;
    for(int d=2;d*d<n;d++)
        if(n%d==0)
            return 0;
    return 1;
}

int ePalindrom(unsigned x) 
{
    int aux = 0,n=x;
    while(n != 0 )
    {
        aux= aux * 10 + n%10;
        n=n/10;
    }

    if(aux == x)
        return 1;
    else
        return 0;

}
unsigned getFibboTerm(unsigned x)
{
    int a=0,b=1,c=0;
    if(x==0)
        return 0;
    else if(x==1)
        return 1;
    for(int i=2;i<x;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}