#include <stdio.h>
#include <math.h>

float f(float x)
{
    return pow(x,2)-3;
}

float bisectie(float a,float b,float (*f)(float),float tol)
{
    float c=(a+b) / 2;
    if ((b-a)/2 <= tol)
        return c;
    if(f(c) * f(b) < 0)
    {
        return bisectie(c,b,f,tol);

    }
    else
        return bisectie(a,c,f,tol);
}


int main()
{
    //printf("%f",f(0));
    printf("%f",bisectie(1,3,f,pow(10,-6)));
    return 0;
}
