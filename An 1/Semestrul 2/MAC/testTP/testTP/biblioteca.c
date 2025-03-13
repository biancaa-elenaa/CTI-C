#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

#define chunck 10

KVS_t *initializare(void)
{
  KVS_t *new = calloc(1, sizeof(KVS_t));
  if(new == NULL){
    printf("Eroare");
    return NULL;
  }
  else{
    new->data = calloc(chunck, sizeof(EL_t));
    new->max_space = 1;
    new->space = 0;
    return new;
  }
}

KVS_t *adauga(KVS_t *vector, EL_t element_to_add)//Complexitate timp O(1)
{
  if(vector->max_space < vector->space){
    vector->max_space = vector->max_space + chunck;
    vector->data = realloc(vector->data, vector->max_space * sizeof(EL_t));
  }
  
  vector->data[vector->space] = element_to_add;
  vector->space++;
  return vector;
}

void printKVS(KVS_t *vector)//Complexitate timp O(n)
{
  for(int i = 0;i < vector->space;i++)
    printf("%d=%d\n", vector->data[i].cheie, vector->data[i].valoare);
}

int cauta(KVS_t *vector, unsigned cheie)//Complexitate timp O(n)
{
  for(int i = 0;i < vector->space;i++){
    if(vector->data[i].cheie == cheie){
      return i;
    }
  }
  return -1;
}

void eliberare(KVS_t *vector)
{
  free(vector->data);
  free(vector);
}
