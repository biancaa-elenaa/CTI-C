#include <stdio.h>
#define nmax 10
int a[nmax];  // tablou de maxim nmax elemente

int pos[nmax] = {0,1,2,3,4,5,6,7,8,9};  //tabloul de posibilitati

int solutii;
void afiseaza_solutia()
{
    int i;
    for (i = 0; i < nmax; i++)
        printf("%d ", a[i]);
    printf("\n");
    solutii++;
}

int acceptabil(int pos, int k)
{
    //elementele din solutie trebuie sa fie unice
    if (k > 0 && (a[k - 1] % 2 == 0) && (pos % 2 == 0))
        return 0;

    if (k < 5) {
        for (int i = 0; i < k; i++) {
            if (i == 0 && a[i] != 0) {
                return 0;
            }

            if (i == 1 && a[i] != 7) {
                return 0;
            }

            if ((i == 2 || i == 3) && a[i] != 9) {
                return 0;
            }
        }
    }


    if (k == (nmax-1) && (pos != 0))
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

    if (solutii >= 5)
        return;

    if (solutie(k))              //solutie completa (avem n elemente)
        afiseaza_solutia();
    else
    {
        for (i = 0; i < nmax; i++)  // parcurgem pe rand posibilitatile
        {
            aux = pos[i];
            if (acceptabil(aux, k)) {//daca posibilitatea  e acceptabila
                a[k] = pos[i];
                permuta(k + 1);   // back1(posibilitate_k+1)
                a[k] = -1;
            }
            //sterge_inregistrarea lipseste din aceasta implementare;
        }
    }
}   /*permuta*/

int main(void)
{
  
    permuta(0);
}