#include <stdio.h>
#define nmax 6
int a[nmax];  // tablou de maxim nmax elemente
int pos[] = { 0,1 };  //tabloul de posibilitati

void afiseaza_solutia()
{
    int i;
    for (i = 0; i < nmax; i++)
        printf("%d", a[i]);
    printf("\n");
}

int acceptabil(int pos, int k)
{
    //elementele din solutie trebuie sa aiba 2 cifre 0,4 de 1
    //nu se accepta 11 si 0 la final
    if (k>=1 && a[0] == 1 && a[1] == 1)
        return 0;
    if (a[nmax - 1]==0 && k==nmax)
        return 0;
    int nr0=0, nr1 = 0;

    for (int i = 0; i < k; i++) {
        if (a[i] == 1)
        {
            nr1++;
        }
        if (a[i] == 0)
        {
            nr0++;
        }
    }
    
    if (pos == 1 && nr1 >= 4)
        return 0;
    if (pos == 0 && nr0 >= 2)
        return 0;

    return 1;
}

int solutie(int k)
{
    return (k == nmax);  //solutia cuprinde n elemente
}

void permuta(int k)  //k pasul, n -nr de elemente
{
    int i, aux;
    if (solutie(k))              //solutie completa (avem n elemente)
        afiseaza_solutia();
    else
    {
        for (i = 0; i < 2; i++)  // parcurgem pe rand posibilitatile
        {
            aux = pos[i];
            if (acceptabil(aux, k)) {//daca posibilitatea  e acceptabila
                a[k] = pos[i];
                permuta(k + 1);   // back1(posibilitate_k+1)
            }
            //sterge_inregistrarea lipseste din aceasta implementare;
        }
    }
}   /*permuta*/

int main(void)
{
    permuta(0);
}