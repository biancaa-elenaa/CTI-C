#include <stdio.h>
#include <stdlib.h>

void citeste_matrice(int **matrice,int nr_linii,int nr_coloane)
{
    for(int i=0;i<nr_linii;i++)
    {
        for(int j=0;j<nr_coloane;j++)
        scanf("%d",&matrice[i][j]);
    }
}

void suma_minima(int **a,int nr_linii,int nr_coloane)
{
    for(int i=0;i<nr_linii;i++)
    {
        int s=0,max_elem=0;
        for(int j=0;j<nr_coloane;j++)
        {
            if(max_elem < a[i][j])
            {
                max_elem = a[i][j];
            }
            s=s+a[i][j];
        }
        printf("Suma minima pentru linia %d este %d \n",i,s-max_elem);
    }
}

int prim(int n)
{
    if(n<2)
        return 0;  // nu este prim

    for(int d=2;d*d<n;d++)
    {
        if(n % d == 0)
        return 0;
    }
    return 1; // este prim

}

int indici_pari_elem_prim(int **matrice,int nr_linii,int nr_coloane)
{
    int nr=0;

    for(int i=0;i<nr_linii;i+=2)
    {
        for(int j=0;j<nr_coloane;j++)
        {
            if( prim(matrice[i][j]) == 1) 
                nr++;
        }
    }

    return nr;
}

void permuta_coloane(int **matrice,int nr_linii,int nr_coloane)
{

    for(int i=0;i<nr_linii;i++)
    {
        int aux=matrice[i][0];
        for(int j=1;j<nr_coloane;j++)
        {
            matrice[i][j-1]=matrice[i][j];
        }
        matrice[i][nr_coloane - 1]=aux;
    }

}

void swap_min_max(int ** matrice,int nr_linii,int nr_coloane)
{  
    int minim=matrice[0][nr_coloane - 1],i_min=0,i_max=0,maxim=matrice[0][0];
    int aux=0;
    for( int i=1;i<nr_linii;i++)
    {
        if( minim > matrice[i][nr_coloane -1])
        {
            minim=matrice[i][nr_coloane-1];
            i_min=i;
        }
        if(maxim < matrice[i][0])
        {
            maxim=matrice[i][0];
            i_max=i;
        }

    }
    aux=matrice[i_min][nr_coloane-1];
    matrice[i_min][nr_coloane-1] = matrice[i_max][0];
    matrice[i_max][0]=aux;

}

int elemente_egale(int **matrice,int nr_linii,int nr_coloane)
{
    int nr=0;
    for(int i=0;i<nr_linii;i++)
    {
        int ok=1;
        for(int j=1;j<nr_coloane && (ok==1);j++)
        {
            if(matrice[i][j] != matrice[i][j-1])
                ok=0;
        }
        if(ok == 1)
            nr++;
    }
    return nr;
}

void afisare_matrice(int **matrice,int nr_linii,int nr_coloane)
{
    for(int i=0;i<nr_linii;i++)
    {
        
        for(int j=0;j<nr_coloane;j++)
        {
            printf("%d ",matrice[i][j]);
        }
        printf("\n");
        
    }
}

int main()
{
    int nr_linii,nr_coloane;
    scanf("%d %d",&nr_linii,&nr_coloane);

    int **matrice=NULL;
    if( (matrice = malloc(nr_linii * sizeof(int *))) == NULL )
    {
        printf("Eroare alocare 1\n");
        exit(-1);
    }
    for( int i=0;i<nr_linii;i++)
    {
        if( (matrice[i] = malloc(nr_coloane * sizeof(int))) == NULL)
        {
            printf("Eroare alocare 2\n");
            exit(-1);
        }
    }
    citeste_matrice(matrice,nr_linii,nr_coloane);
    //afisare_matrice(matrice,nr_linii,nr_coloane);
    //suma_minima(matrice,nr_linii,nr_coloane);
    //printf("Numarul elementelor prime de pe linii pare este %d\n",indici_pari_elem_prim(matrice,nr_linii,nr_coloane));
    //permuta_coloane(matrice,nr_linii,nr_coloane);
    //swap_min_max(matrice,nr_linii,nr_coloane);
    afisare_matrice(matrice,nr_linii,nr_coloane);
    printf("%d linii au toate elementele egale\n",elemente_egale(matrice,nr_linii,nr_coloane));

    //eliberere memorie

    for(int i=0;i<nr_linii;i++)
        free(matrice[i]);
    free(matrice);

    return 0;
}