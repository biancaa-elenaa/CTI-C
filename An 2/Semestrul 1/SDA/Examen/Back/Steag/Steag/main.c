#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#define nmax 3
#define NR_CULORI 6
char* a[nmax];  // tablou de maxim nmax elemente
char* pos[] = {"alb","galben","rosu","verde","albastru","negru"};  //tabloul de posibilitati

void afiseaza_solutia()
{
    int i;
    for (i = 0; i < nmax; i++)
        printf("%s ", a[i]);
    printf("\n");
}

int acceptabil(char* pos, int k)
{
    //elementele din solutie trebuie sa fie unice
    int i;
    for (i = 0; i < k; i++)
        if (strcmp(a[i],pos) == 0)
            return 0;
    if (k == 1 && (strcmp("galben", pos) != 0) && (strcmp("verde", pos) != 0))
    {
        return 0;
    }
    return 1;
}

int solutie(int k)
{
    return (k == nmax);  //solutia cuprinde n elemente
}

void permuta(int k)  //k pasul, n -nr de elemente
{
    int i;
    char *aux= (char*)malloc(10*sizeof(char));
    if (solutie(k))              //solutie completa (avem n elemente)
        afiseaza_solutia();
    else
    {
        for (i = 0; i < NR_CULORI; i++)  // parcurgem pe rand posibilitatile
        {
            strcpy(aux, pos[i]);
            if (acceptabil(aux, k)) {//daca posibilitatea  e acceptabila
                a[k] = pos[i];
                //strcpy(a[k], pos[i]);
                permuta(k + 1);   // back1(posibilitate_k+1)
            }
            //sterge_inregistrarea lipseste din aceasta implementare;
        }
    }
}   /*permuta*/

int main()
{
    permuta(0);
	return 0;
}