#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Eveniment {
	char id[10];
	int prioritate;
	long momentActivare;
	struct Eveniment* nextEveniment;
}Eveniment_t;

typedef struct LP {
	char prioritate[5];
	Eveniment_t* eveniment;
}LP_t;

//multilista are 8 elemente o facem cu vector
// cu pointeri : typedef LP_t* Multilista_t;

typedef struct multilista
{
	LP_t listaPrincipala[8];
}Multilista_t;

typedef struct Coada {
	Eveniment_t* prim;
	Eveniment_t* ultim;
}Coada_t;

Coada_t* initCoada()
{
	Coada_t* c = (Coada_t*)malloc(sizeof(Coada_t));

	if (c == NULL)
	{
		printf("Eroare coada\n");
		return NULL;
	}

	c->prim = NULL;
	c->ultim = NULL;

	return c;
}

void adaugaCoada(Coada_t* c, Eveniment_t* ev)
{
	if (c->prim == NULL) // COADA E GOALA
	{
		c->prim = ev;
		c->ultim = ev;
	}
	else {
		c->ultim->nextEveniment = ev;
		c->ultim = c->ultim->nextEveniment;
	}
}

Eveniment_t* initEveniment(char *id, int prioritate, long momentActivare)
{
	Eveniment_t* ev = (Eveniment_t*)malloc(sizeof(Eveniment_t));

	if (ev == NULL)
	{
		printf("Eroare eveniment\n");
		return NULL;
	}
	strcpy(ev->id, id);
	ev->prioritate = prioritate;
	ev->momentActivare = momentActivare;
	ev->nextEveniment = NULL;
	return ev;
}

Multilista_t initMultilist() {
	Multilista_t ml;

	for (int i = 0; i < 8; i++) {
		sprintf(ml.listaPrincipala[i].prioritate, "P%d", i + 1);
		ml.listaPrincipala[i].eveniment = NULL;
	}

	return ml;
}

void adaugaEveniment(Multilista_t* m1, Eveniment_t* ev)
{
	LP_t* lCurenta = &m1->listaPrincipala[ev->prioritate - 1];

	if (!lCurenta->eveniment)
	{
		lCurenta->eveniment = ev;
	}
	else if (!lCurenta->eveniment->nextEveniment)
	{
		if (lCurenta->eveniment->momentActivare < ev->momentActivare)
		{
			lCurenta->eveniment->nextEveniment = ev;
		}
		else {
			ev->nextEveniment = lCurenta->eveniment;
			lCurenta->eveniment = ev;
		}
	}
	else
	{
		Eveniment_t* evCurent = lCurenta->eveniment;
		Eveniment_t* evAnterior = NULL;

		while (evCurent != NULL && evCurent->momentActivare < ev->momentActivare) {
			evAnterior = evCurent;
			evCurent = evCurent->nextEveniment;
		}

		evAnterior->nextEveniment = ev;
		ev->nextEveniment = evCurent;
	}

}

void printCoada(Coada_t coada) {
	Eveniment_t* curent = coada.prim;

	while (curent != NULL) {
		printf("FIFO - ");
		printf("%s %ld, ", curent->id, curent->momentActivare);
		curent = curent->nextEveniment;
	}

	putchar('\n');
}
void printEveniment(LP_t* listaPrincipala) {
	Eveniment_t* evCurent = listaPrincipala->eveniment;

	while (evCurent != NULL) {
		printf("%s %ld, ", evCurent->id, evCurent->momentActivare);
		evCurent = evCurent->nextEveniment;
	}
}

void printMultilista(Multilista_t ml) {
	for (int i = 0; i < 8; i++) {
		printf("%s - ", ml.listaPrincipala[i].prioritate);

		if (ml.listaPrincipala[i].eveniment != NULL)
			printEveniment(&ml.listaPrincipala[i]);

		printf("\n");
	}
}

void deservesteEveniment(Multilista_t* ml, Coada_t* coada) {
	for (int i = 7; i >= 0; i--) {
		if (ml->listaPrincipala[i].eveniment != NULL) {
			Eveniment_t* evScos = ml->listaPrincipala[i].eveniment;
			ml->listaPrincipala[i].eveniment = ml->listaPrincipala[i].eveniment->nextEveniment; // am scos practic evenimentul din lista
			adaugaCoada(coada, evScos);
			break;
		}
	}
}

void afiseazaEvenimente(Eveniment_t* ev)
{
	if (ev == NULL)
	{
		return;
	}

	printf("%s %ld, ", ev->id, ev->momentActivare);

	afiseazaEvenimente(ev->nextEveniment);
}

int main()
{
	Multilista_t ml = initMultilist();

	Eveniment_t* e1 = initEveniment("e1", 1, 100);
	Eveniment_t* e2 = initEveniment("e2", 2, 20);
	Eveniment_t* e3 = initEveniment("e3", 1, 30);
	Eveniment_t* e4 = initEveniment("e4", 4, 40);
	Eveniment_t* e7 = initEveniment("e7", 7, 700);

	adaugaEveniment(&ml, e1);
	adaugaEveniment(&ml, e2);
	adaugaEveniment(&ml, e3);
	adaugaEveniment(&ml, e4);
	adaugaEveniment(&ml, e7);

	printf("Initial: \n");
	printMultilista(ml);

	Coada_t* coada = initCoada();

	deservesteEveniment(&ml, coada);

	printf("Dupa scos\n");
	printMultilista(ml);
	printf("\n Coada :\n");
	printCoada(*coada);


	printf("AFISARE EVENIMENTE RECURSIV: \n");
	afiseazaEvenimente(e3);

	return 0;

}