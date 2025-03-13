#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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

void print_array(int *v,int n)
{
    for(unsigned i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");
}

double *distributia_Gauss(int size,double med,double dev_stdr)
{
    double *array=(double *) malloc(size*sizeof(double));
    double u1,u2;

    if(array == NULL)
        return NULL;

    for(unsigned i=0;i<size;i++)
    {
       u1=(double) rand() / RAND_MAX;
       u2=(double) rand() / RAND_MAX;

       array[i]=sqrt(-2*log(u1)) * cos(2 * M_PI * u2);

    }

    return array;
}
int *distributia_Poisson(int size,double lambda)
{
    int *array=(int *) malloc(size*sizeof(int));

    if(array == NULL)
        return NULL;

     for(unsigned i=0;i<size;i++)
    {
       double L=exp(-lambda);
       double p = 1.0;
       int k=0;

        do{
            k++;
            p *= (double) rand()/RAND_MAX;
        }while(p > L);

       array[i]=k-1;
    }

    return array;
}

void print_double_array(double *v,int n)
{
    for(unsigned i=0;i<n;i++)
    {
        printf("%2f ",v[i]);
    }
    printf("\n");
}


int main()
{
    srand(time(0));
    /*
    int *array=NULL;
    int n;
    scanf("%d",&n);
    array=makeRandFlexiArray(n,getNewElem_asc);
    print_array(array,n);
    free(array);
    */
    double *gauss=distributia_Gauss(100,0,1);
    print_double_array(gauss,100);

    printf("\n--------\n");

    int *poisson=distributia_Poisson(100,2);
    print_array(poisson,100);


    return 0;
}