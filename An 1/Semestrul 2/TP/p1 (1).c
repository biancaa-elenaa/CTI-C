/*
1. Algoritmul de cautare binara a unui element intr-un tablou ordonat. 

a) Implementati o functie recursiva cu antetul int cataBin(int x, int v[], unsigned stg, unsigned dr); 
care cauta elementul x in tabloul v ordonat (nu conteaza daca crescator sau descrescator) si returneaza pozitia 
pe care sa gaseste una dintre aparitiile lui x sau -1 daca x nu apare in tablou.

b)Implementati functia de mai sus, in maniera nerecursiva (iterativa)

*/

#include <stdio.h>
#include <time.h>


int cataBin(int x, int v[], unsigned stg, unsigned dr)
{
    if(stg > dr)
        return -1;
    
    int mijloc = (stg + dr)/2;

    if(v[mijloc] == x)
        return mijloc;
    else
    if(v[mijloc] > x)
        return cataBin(x,v,stg,mijloc -1);
    else
        return cataBin(x,v,mijloc+1,dr);
}

int cataBin_iterativ(int x,int v[],int size)
{
    int stg=0,mijloc;
    int dr=size-1;
    int poz=-1;

    while(stg <= dr && poz==-1)
    {
        mijloc = (stg + dr) /2;
        if(v[mijloc] == x)
            poz=mijloc;
        else
        if (v[mijloc] < x)
        {
            stg=mijloc + 1;
        }
        else
        {
            dr=mijloc - 1;
        }
        
    }

    return poz;


}

int main()
{
   
    int v[]={1,3,5,13,25,56,100};
    int n=sizeof(v)/sizeof(v[0]);
    int x=5;
    printf("Pozitia la care se gaseste %d este %d\n",x,cataBin_iterativ(x,v,n));
    
}


