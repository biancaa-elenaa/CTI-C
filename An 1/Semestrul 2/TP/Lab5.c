#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned* makeRandArray(unsigned n)
{
    unsigned *v=malloc(n*sizeof(unsigned));
    if(v==NULL)
    {
        perror("eroare la alocare\n");
        exit(-1);
    }
    for(int i=0;i<n;i++)
    {
        v[i]=rand();
    }
    return v;
}

int* makeRandLimitArray(unsigned n, int a, int b)
{
    if (a > b)
    return NULL;

    int *v=malloc(n*sizeof(unsigned));

    if(v==NULL)
    {
        perror("eroare la alocare1\n");
        exit(-1);
    }

    for(int i=0;i<n;i++)
    {
        v[i]=rand()%(b-a+1) + a;
    }

    return v;
}

/*
Implementati o functie cu antetul int* makeRandFlexiArray(unsigned n, int (*getNewElem)(int*, unsigned)) 
care genereaza un vector alocat dinamic cuprinzand elemente numere psoedoaleatoare. Pentru generarea unui nou element 
din vector se va face apel la o functie "concreta" primita sub forma unui pointer la o functie care primeste drept 
argumente un tablou si numarul sau curent de elemente. Implementati functii "concrete" pentru generarea unor vectori 
monoton crescatori si monoton descrescatori.
*/

int getNewElem_asc(int *v,unsigned size)
{
    int aux;
    aux=rand();
    while(aux<=v[size-1])
    {
        aux=rand();
    }
    return aux;
}


int* makeRandFlexiArray(unsigned n,int (*getNewElem)(int* ,unsigned))
{
    int *v=malloc((n+1)*sizeof(int));
    if(v==NULL)
    {
        perror("Eroare la alocarea dinamica2\n");
        exit(-1);
    }
    v[0] = rand();
    for(int i=1;i<n;i++)
    {
        v[i]=getNewElem(v,i);
    }
    return v;

}

void print_array(int*v,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(0));
    int *array=NULL;
    int n;
    scanf("%d",&n);
    array=makeRandFlexiArray(n,getNewElem_asc);
    print_array(array,n);
    free(array);
    return 0;
}