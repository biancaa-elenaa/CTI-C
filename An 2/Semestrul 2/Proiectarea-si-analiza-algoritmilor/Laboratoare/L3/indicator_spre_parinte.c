#include <stdio.h>
#include <stdint.h>

#define MAX_NODURI 100

// implementare "indicator spre parinte"

typedef uint8_t TipCheie; // tipul cheii

typedef struct
{
  uint8_t parinte;
  TipCheie cheie;
}TipNod; // un nod are o cheie si un parinte

typedef struct
{
  TipNod noduri[MAX_NODURI]; // un vector static pentru nodurile din arbore
  uint8_t dimensiune; // numarul de noduri
}TipArbore;

typedef uint8_t TipIndex;

TipIndex Parinte(TipIndex n, TipArbore a) 
{
  return a.noduri[n].parinte;
}

TipIndex PrimulFiu(TipArbore a, TipIndex n) // n este parinte, pe al carui fiu il cautam
{
  if(!n)
    return 0;
  
  for(int i = 0; i <= a.dimensiune; i++)
    {
      if(a.noduri[i].parinte == n)
	return i;
    }
  
  return 0;
}

TipIndex FrateDreapta(TipArbore a, TipIndex n) // n este un nod, pe al carui frate drept il cautam
{
  if(!n)
    return 0;
  
  for(int i = n + 1; i <= a.dimensiune; i++)
    {
      if(a.noduri[i].parinte == a.noduri[n].parinte)
	return i;
    }
  return 0;
}

TipCheie Cheie(TipIndex n, TipArbore a)
{
  return a.noduri[n].cheie;
}

TipIndex Radacina(TipArbore a)
{
  if(!a.dimensiune)
    return 0;
  return 1;
}

TipArbore InitializeazaArbore(TipArbore a)
{
  // initializam toate nodurile posibile(de la 0 la MAX - 1) cu 0
  for(int i = 0; i < MAX_NODURI; i++)
    {
      a.noduri[i].parinte = 0;
      a.noduri[i].cheie = 0;
    }
  
  a.dimensiune = 0; // dimensiunea e 0, nu avem niciun nod
  
  return a;
}

TipArbore Insereaza(TipArbore a, TipIndex parinte, TipIndex cheie)
{
  a.dimensiune++;
  a.noduri[a.dimensiune].parinte = parinte;
  a.noduri[a.dimensiune].cheie = cheie;

  return a;
}

TipArbore Suprima(TipArbore a, TipIndex n)
{
  a.noduri[n].cheie = 0;
  a.noduri[n].parinte = 0;
  
  for(TipIndex i = 0; i <= a.dimensiune; i++)
    {
      if(a.noduri[i].parinte == n)
	{
	  a.noduri[i].cheie = 0;
	  a.noduri[i].parinte = 0;
	}
    }

  for(TipIndex i = n; i <= a.dimensiune; )
    {
      if(a.noduri[i].parinte == 0 && a.noduri[i].cheie == 0)
	{
	  for(TipIndex j = i + 1; j <= a.dimensiune; j++)
	    {
	      if(a.noduri[j].parinte > i)
		a.noduri[j].parinte--;
	      
	      a.noduri[j-1] = a.noduri[j];
	    }
	  a.dimensiune--;
	}
      if(a.noduri[i].parinte !=0 && a.noduri[i].cheie !=0)
	i++;
    }
  
  return a;
}

void PrintareArbore(TipArbore a)
{
  printf("Cheie:   ");
  for(int i = 0; i <= a.dimensiune; i++)
    {
      printf("%d ", a.noduri[i].cheie);
    }
  printf("\n");

  printf("Parinte: ");
  for(int i = 0; i <= a.dimensiune; i++)
    {
      printf("%d ", a.noduri[i].parinte);
    }
  printf("\n----------------------------------\n");
}

void PreOrdine(TipArbore a, TipIndex n)
{
  if(!n)
    return;
  
  printf("%d ", n);
  
  TipIndex pf = PrimulFiu(a, n);
  PreOrdine(a, pf);

  TipIndex fd = pf;
  while((fd = FrateDreapta(a, fd)))
    PreOrdine(a, fd);
}

void InOrdine(TipArbore a, TipIndex n)
{
  if(!n)
    return;
  
  TipIndex pf = PrimulFiu(a, n);
  InOrdine(a, pf);

  printf("%d ", n);

  TipIndex fd = pf;
  while((fd = FrateDreapta(a, fd)))
    InOrdine(a, fd);
}

void PostOrdine(TipArbore a, TipIndex n)
{
  if(!n)
    return;
  
  TipIndex pf = PrimulFiu(a, n);
  PostOrdine(a, pf);

  TipIndex fd = pf;
  while((fd = FrateDreapta(a, fd)))
    PostOrdine(a, fd);

  printf("%d ", n);
}

int main(void)
{
  TipArbore a = InitializeazaArbore(a);

  a = Insereaza(a, 0, 1);
  a = Insereaza(a, 1, 2);
  a = Insereaza(a, 1, 3);
  a = Insereaza(a, 1, 4);
  a = Insereaza(a, 2, 5);
  a = Insereaza(a, 2, 6);
  a = Insereaza(a, 4, 7);
  a = Insereaza(a, 5, 8);

  PrintareArbore(a);

  printf("PreOrdine: ");
  PreOrdine(a, 1);
  printf("\n----------------------------------\n");

  printf("InOrdine: ");
  InOrdine(a, 1);
  printf("\n----------------------------------\n");

  printf("PostOrdine: ");
  PostOrdine(a, 1);
  printf("\n----------------------------------\n");

  // a = Suprima(a, 2);
  // PrintareArbore(a);
  return 0;
}
