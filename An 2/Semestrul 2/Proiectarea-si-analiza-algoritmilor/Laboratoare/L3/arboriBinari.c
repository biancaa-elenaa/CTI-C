#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "arboriBinari.h"

TipArboreBinar *CreeazaArbore(uint8_t capacitateMaxima)
{
  TipArboreBinar *a = NULL;
  a = (TipArboreBinar *)malloc(sizeof(TipArboreBinar));
  if(!a)
    {
      perror("eroare la alocarea arborelui binar");
      exit(-1);
    }

  a->radacina = NULL;
  a->capacitateMaxima = capacitateMaxima;
  a->capacitate = 0;
  
  return a;
}

TipNodB *FiuStanga(TipNodB *n)
{
  return n->stanga;
}

TipNodB *FiuDreapta(TipNodB *n)
{
  return n->dreapta;
}

TipCheie CheieB(TipNodB *n)
{
  return n->cheie;
}

TipNodB *CreeazaNod(TipCheie cheie)
{
  TipNodB *nodNou = (TipNodB *)malloc(sizeof(TipNodB));
  if(!nodNou)
    {
      perror("eroare la alocarea memoriei pentru un nod nou");
      exit(-1);
    }

  nodNou->cheie = cheie;
  nodNou->stanga = NULL;
  nodNou->dreapta = NULL;
  
  return nodNou;
}

void PrinteazaNod(TipNodB *n)
{
  printf("Cheie: %d\t", n->cheie);
  
  if(n->stanga)
    printf("Fiu stang: %d\t", n->stanga->cheie);
  else
    printf("Fiu stang: NULL\t");

  if(n->dreapta)
    printf("Fiu drept: %d\n", n->dreapta->cheie);
  else
    printf("Fiu drept: NULL\n");
}

void InsereazaB(TipArboreBinar *a, TipCheie cheie)
{
  if(a->capacitate >= a->capacitateMaxima)
    {
      printf("capacitate depasita!\n");
      return;
    }

  TipNodB *nodNou = CreeazaNod(cheie);

  if(a->radacina == NULL)
    {
      a->radacina = nodNou;
      return;
    }
  
  TipNodB *curent = a->radacina;
  TipNodB *parinte = NULL;

  while(curent)
    {
      parinte = curent;
      if(cheie < curent->cheie)
	curent = curent->stanga;
      else
	curent = curent->dreapta;
    }

  if(cheie < parinte->cheie)
    parinte->stanga = nodNou;
  else
    parinte->dreapta = nodNou;

  a->capacitate++;
}

void EliberareNoduri(TipNodB *n)
{
  if(!n)
    return;

  EliberareNoduri(n->stanga);
  EliberareNoduri(n->dreapta);
  free(n);
}

void EliberareArbore(TipArboreBinar *a)
{
  EliberareNoduri(a->radacina);
  free(a);
}

void InOrdineB(TipNodB *n)
{
  if(!n)
    return;

  InOrdineB(n->stanga);
  //printf("%d ", n->cheie);
  PrinteazaNod(n);
  InOrdineB(n->dreapta);
}

void PreOrdineB(TipNodB *n)
{
  if(!n)
    return;

  PrinteazaNod(n);
  PreOrdineB(n->stanga);
  PreOrdineB(n->dreapta);
}

void PostOrdineB(TipNodB *n)
{
  if(!n)
    return;

  PostOrdineB(n->stanga);
  PostOrdineB(n->dreapta);
  PrinteazaNod(n);
}

TipNodB *SuprimareB(TipNodB *radacina, TipCheie cheie)
{
  if(!radacina)// arbore gol 
    return radacina;

  if(cheie < radacina->cheie) // daca cheia cautata este mai mica
    radacina->stanga = SuprimareB(radacina->stanga, cheie); // vom cauta in subarborele stang
  else if(cheie > radacina->cheie) // daca este mai mare
    radacina->dreapta = SuprimareB(radacina->dreapta, cheie); // in subarborele drept
  else // daca e chiar radacina->cheie, adica am gasit nodul de sters
    {
      if(!radacina->stanga) // nu are fiu stang
	{
	  TipNodB *temp = radacina->dreapta;
	  free(radacina);
	  return temp;
	}
      else if(!radacina->dreapta) // nu are fiu drept
	{
	  TipNodB *temp = radacina->stanga;
	  free(radacina);
	  return temp;
	}

      // are si fiu stang si fiu drept
      TipNodB *temp = radacina->dreapta;
      while(temp->stanga != NULL) // ne deplasam spre stanga, pentru a gasi min
	temp = temp->stanga;

      radacina->cheie = temp->cheie; // inlocuim valoarea cu cea a succesorului
      radacina->dreapta = SuprimareB(radacina->dreapta, temp->cheie); // stergem succesorul din dreapta
    }

  return radacina;
}

