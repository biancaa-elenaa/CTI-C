#ifndef nume

#define nume

typedef struct
{
  unsigned int cheie;
  int valoare;
}EL_t;

typedef struct
{
  EL_t *data;
  int max_space;
  int space;
}KVS_t;

KVS_t *initializare(void);

KVS_t* adauga(KVS_t *, EL_t);

void printKVS(KVS_t *);

int cauta(KVS_t*, unsigned);

void eliberare(KVS_t *);
#endif
