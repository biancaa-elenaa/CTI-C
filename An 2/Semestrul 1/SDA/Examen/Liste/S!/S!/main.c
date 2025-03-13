
/*
* Lista cu numar impar de elemente.Sa se gaseasca si sa se stearga elementul din mijloc
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
	int info;
	struct nod* urm;
}Nod_t;

typedef Nod_t* Lista_t;


Lista_t prim = NULL;

Lista_t insertie_fata(int info)
{
	Nod_t* nod = (Nod_t*)(malloc(sizeof(Nod_t)));

	if (nod)
	{
		nod->info = info;
		nod->urm = prim;

		prim = nod;
	}

	return nod;
}

void afiseazaLista(Lista_t lista)
{
	while (lista)
	{
		printf("%d ", lista->info);
		lista = lista->urm;
	}
	printf("\n");
}

Lista_t stergeMijloc(Lista_t l)
{
	if (l == NULL)
	{
		printf("lista goala\n");
		return NULL;
	}

	if (l->urm == NULL)
	{
		free(l);
		l = NULL;

		return NULL;
	}

	Lista_t nodUrmator = l;
	Lista_t nodUrmator_2 = l;
	Lista_t nodAnterior = NULL;

	while (nodUrmator_2->urm != NULL)
	{
		nodAnterior = nodUrmator;
		nodUrmator = nodUrmator->urm;
		nodUrmator_2 = nodUrmator_2->urm->urm;
	}

	if (nodAnterior)
	{
		nodAnterior->urm = nodUrmator->urm;

		free(nodUrmator);
	}
	return l;
}

int main()
{
	Lista_t lista = NULL;
	lista = insertie_fata(3);
	lista = insertie_fata(1);
	lista = insertie_fata(5);
	lista = insertie_fata(6);
	lista = insertie_fata(9);
	lista = insertie_fata(0);
	lista = insertie_fata(4);
	afiseazaLista(lista);
	lista = stergeMijloc(lista);
	afiseazaLista(lista);

}