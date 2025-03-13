#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include <time.h>

int main(void)
{
  clock_t start, end;
  double cpu_time_used;
  
  KVS_t *data = initializare();

  EL_t elem;
  elem.cheie = 10;
  elem.valoare = 5;
  start = clock();
  data = adauga(data, elem);
  end = clock();
  cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);
  printf("%f\n", cpu_time_used);
  elem.cheie = 7;
  elem.valoare = 12;

  
  
  start = clock();
  printKVS(data);
  end = clock();
  cpu_time_used = ((double)(end - start) / CLOCKS_PER_SEC);
  printf("%f\n", cpu_time_used);
  printf("%d %d\n", cauta(data, 5), cauta(data, 7));
  eliberare(data);
  return 0;
}

