#ifndef __PRIMFIU_FRATEDREAPTA_H

#define __PRIMFIU_FRATEDREAPTA_H

#include <stdint.h>

#define MAX_NODURI 255

typedef uint8_t TipCheie; // tipul cheii

typedef struct
{
  uint8_t primulFiu;
  uint8_t frateDreapta;
  TipCheie cheie;
}TipNod; // un nod are o cheie si un parinte

typedef struct
{
  TipNod noduri[MAX_NODURI]; // un vector static pentru nodurile din arbore
  uint8_t dimensiune; // numarul de noduri
}TipArbore;

typedef uint8_t TipIndex;

TipIndex Parinte(TipArbore a, TipIndex n);

TipIndex PrimulFiu(TipArbore a, TipIndex n);

TipIndex FrateDreapta(TipArbore a, TipIndex n);

TipCheie Cheie(TipIndex n, TipArbore a);

TipIndex Radacina(TipArbore a);

TipArbore InitializeazaArbore(TipArbore a);

TipArbore Insereaza(TipArbore a, TipIndex parinte, TipIndex cheie);

void PrintareArbore(TipArbore a);

void PreOrdine(TipArbore a, TipIndex n);

void InOrdine(TipArbore a, TipIndex n);

void PostOrdine(TipArbore a, TipIndex n);

TipArbore Suprima(TipArbore a, TipIndex n);

#endif
