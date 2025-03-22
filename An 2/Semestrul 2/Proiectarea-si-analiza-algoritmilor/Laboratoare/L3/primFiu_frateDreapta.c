#include <stdio.h>
#include <stdint.h>
#include "primFiu_frateDreapta.h"

TipIndex Parinte(TipArbore a, TipIndex n) 
{
  for(TipIndex i = 0; i <= a.dimensiune; i++)
    {
      TipIndex fiu = a.noduri[i].primulFiu;

      while(fiu)
	{
	  if(fiu == n)
	    return i;

	  fiu = a.noduri[fiu].frateDreapta;
	}
    }

  return 0;
}

TipIndex PrimulFiu(TipArbore a, TipIndex n) 
{
  return a.noduri[n].primulFiu;
}

TipIndex FrateDreapta(TipArbore a, TipIndex n) 
{
  return a.noduri[n].frateDreapta;
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
      a.noduri[i].primulFiu = 0;
      a.noduri[i].frateDreapta = 0;
      a.noduri[i].cheie = 0;
    }
  
  a.dimensiune = 0; // dimensiunea e 0, nu avem niciun nod
  
  return a;
}

TipArbore Insereaza(TipArbore a, TipIndex parinte, TipIndex cheie)
{
  a.dimensiune++;

  if(!a.noduri[parinte].primulFiu)
    a.noduri[parinte].primulFiu = a.dimensiune;
  else
    {
      TipIndex fiu = a.noduri[parinte].primulFiu;
      while(a.noduri[fiu].frateDreapta != 0)
	{
	  fiu = a.noduri[fiu].frateDreapta;
	}
      a.noduri[fiu].frateDreapta = a.dimensiune;
    }

  a.noduri[a.dimensiune].primulFiu = 0;
  a.noduri[a.dimensiune].frateDreapta = 0;
  a.noduri[a.dimensiune].cheie = cheie;

  return a;
}

TipArbore Suprima(TipArbore a, TipIndex n)
{
  if (n >= a.dimensiune) 
    return a;

  TipIndex parinte = Parinte(a, n);

  if (parinte == -1)
    {
      a.dimensiune = 0; 
      return a;
    }
    
  TipIndex fiu = a.noduri[parinte].primulFiu;
  if (fiu == n)
    a.noduri[parinte].primulFiu = a.noduri[n].frateDreapta;
  else
    {
      while (fiu != -1 && a.noduri[fiu].frateDreapta != n) 
	fiu = a.noduri[fiu].frateDreapta;
      if (fiu != -1) 
	a.noduri[fiu].frateDreapta = a.noduri[n].frateDreapta;
    }

  TipIndex fiuCurent = a.noduri[n].primulFiu;
  while (fiuCurent != -1)
    {
      TipIndex urmatorulFiu = a.noduri[fiuCurent].frateDreapta;
      a.noduri[fiuCurent].primulFiu = a.noduri[fiuCurent].frateDreapta = a.noduri[fiuCurent].cheie = 0;
      a.dimensiune--; 
      fiuCurent = urmatorulFiu;
    }
    
  a.noduri[n].primulFiu = a.noduri[n].frateDreapta = a.noduri[n].cheie = 0;
  for (TipIndex i = n; i < a.dimensiune; i++) 
    a.noduri[i] = a.noduri[i + 1];

  a.dimensiune--;  
  return a;
}


void PrintareArbore(TipArbore a)
{
  printf("Cheie: ");
  for(int i = 0; i <= a.dimensiune; i++)
    {
      printf("%d ", a.noduri[i].cheie);
    }
  printf("\n");

  printf("PF:    ");
  for(int i = 0; i <= a.dimensiune; i++)
    {
      printf("%d ", a.noduri[i].primulFiu);
    }
  printf("\n");

  printf("FD:    ");
  for(int i = 0; i <= a.dimensiune; i++)
    {
      printf("%d ", a.noduri[i].frateDreapta);
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

/*
TipArbore TransformareArbBinar(TipArbore a) 
{
  for(TipIndex i = 0; i <= a.dimensiune; i++)
    {
      TipIndex primulFiuCurent = a.noduri[i].primulFiu;
      TipIndex frateDreaptaCurent = a.noduri[i].frateDreapta;

      if(primulFiuCurent && !frateDreaptaCurent)
	continue;
      else if(primulFiuCurent && frateDreaptaCurent)
	{
	  a.noduri[i].primulFiu = primulFiuCurent;
	  while(frateDreaptaCurent)
	    {
	      a.noduri[a.noduri[primulFiuCurent].primulFiu].frateDreapta = frateDreaptaCurent;
	      primulFiuCurent = frateDreaptaCurent;
	      frateDreaptaCurent = a.noduri[primulFiuCurent].frateDreapta;
	    }
	}
      else if(!primulFiuCurent && frateDreaptaCurent)
	{
	  a.noduri[i].primulFiu = frateDreaptaCurent;
	}
    }

  return a;
}
*/
