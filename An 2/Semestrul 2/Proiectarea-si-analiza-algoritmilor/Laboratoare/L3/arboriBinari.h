#ifndef __ARBORIBINARI_H
#define __ARBORIBINARI_H

#include <stdint.h>

#define MAX_NODURI 255

typedef uint8_t TipCheie;

typedef uint8_t TipIndex;

// Actualizarea structurii Nod pentru a folosi TipNodB
typedef struct TipNodB
{
  TipCheie cheie;
  struct TipNodB *stanga;
  struct TipNodB *dreapta;
} TipNodB;

typedef struct
{
  TipNodB *radacina; 
  uint8_t capacitateMaxima;
  uint8_t capacitate;
} TipArboreBinar;

TipArboreBinar *CreeazaArbore(uint8_t capacitateMaxima);

TipNodB *FiuStanga(TipNodB *n);

TipNodB *FiuDreapta(TipNodB *n);

TipCheie CheieB(TipNodB *n);

TipNodB *CreeazaNod(TipCheie cheie);

void PrinteazaNod(TipNodB *n);

void InsereazaB(TipArboreBinar *a, TipCheie cheie);

void EliberareNoduri(TipNodB *n);

void EliberareArbore(TipArboreBinar *a);

void InOrdineB(TipNodB *n);

void PreOrdineB(TipNodB *n);

void PostOrdineB(TipNodB *n);

TipNodB *SuprimareB(TipNodB *radacina, TipCheie cheie);

#endif
