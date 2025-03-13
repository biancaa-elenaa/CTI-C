/*
Considerăm o matrice pătratică cu N linii și N coloane. În această matrice sunt definite 4 zone:

zona 1, formată din elementele situate strict deasupra diagonalei principale și strict deasupra diagonalei secundare;
zona 2, formată din elementele situate strict deasupra diagonalei principale și strict sub diagonala secundară;
zona 3, formată din elementele situate strict sub diagonala principală și strict sub diagonala secundară;
zona 4, formată din elementele situate strict sub diagonala principală și strict deasupra diagonalei secundare;

Implementati o functie care primeste o matrice pătratică și un număr natural Z, reprezentând o zonă din matrice. Să se determine suma elementelor din zona Z.
*/
#include <stdio.h>
#include <stdlib.h>

void citeste_matrice(int **matrice,int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        scanf("%d",&matrice[i][j]);
    }
}

void zone_matrice(int **matrice,int n,int Z)
{
    int s=0;
    switch(Z)
    {
        case 1: 
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    if(i < j && i+j < n-1)
                    s+=matrice[i][j];

            }
            printf("Suma zonei %d este %d",Z,s);
            break;
        }
        case 2:
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    if( i < j && i+j > n-1 )
                        s+=matrice[i][j];
            }
            printf("Suma zonei %d este %d",Z,s);
            break;
        }
        case 3:
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    if( i > j && i+j > n-1 )
                        s+=matrice[i][j];
            }
            printf("Suma zonei %d este %d",Z,s);
            break;
        }
        case 4:
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    if( i > j && i+j < n-1 )
                        s+=matrice[i][j];
            }
            printf("Suma zonei %d este %d",Z,s);
            break;
        }
        default:
        {
            printf("Zona introdusa nu este corecta\n");
            break;
        }
    }
}

int main()
{
    int **matrice=NULL;
    int n,Z;
    scanf("%d %d",&n,&Z);
    if((matrice = malloc(n*sizeof(int *))) == NULL)
    {
        perror("Eroare la alocare\n");
        exit(-1);
    }
    for(int i=0;i<n;i++)
    {
        if((matrice[i] = malloc(n*sizeof(int))) == NULL)
        {
            perror("Eroare la alocare 1\n");
            exit(-1);
        }
    }

    citeste_matrice(matrice,n);
    zone_matrice(matrice,n,Z);

    //eliberare memorie
    for(int i=0;i<n;i++)
        free(matrice[i]);

    free(matrice);

    
    return 0;
}