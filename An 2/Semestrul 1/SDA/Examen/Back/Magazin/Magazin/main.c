#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Produs {
	int cod;
	struct Produs* nextProdus;

}Produs_t;

typedef struct Magazin {
	char nume[35];
	Produs_t* listaProduse;
	struct Magazin* nextMagazin;
}Magazin_t;

typedef Magazin_t* Multilista_t;

Produs_t* initProdus(int cod)
{
	Produs_t* p = (Produs_t*)malloc(sizeof(Produs_t));

	if (p == NULL)
	{
		printf("eroare Produs\n");
		return NULL;
	}

	p->cod = cod;
	p->nextProdus = NULL;

	return p;
}

Magazin_t* initMagazin(char *nume)
{
	Magazin_t* p = (Magazin_t*)malloc(sizeof(Magazin_t));

	if (p == NULL)
	{
		printf("eroare magazin\n");
		return NULL;
	}

	strcpy(p->nume, nume);
	p->listaProduse = NULL;
	p->nextMagazin = NULL;

	return p;
}

void adaugaProduse(Produs_t* p, Magazin_t* m)
{
	if (m->listaProduse == NULL)
	{
		m->listaProduse = p;
	}
	else {
		Produs_t* pCurent = m->listaProduse;
		Produs_t* pAnt = NULL;

		while ((pCurent != NULL) && (p->cod > pCurent->cod))
		{
			pAnt = pCurent;
			pCurent = pCurent->nextProdus;
		}

		if (pAnt == NULL)
		{
			p->nextProdus = pCurent;
			m->listaProduse = p;
		}
		else
		{
			p->nextProdus = pCurent;
			pAnt->nextProdus = p;
		}
	}
}

void printMagazine(Magazin_t* m)
{
	printf("Magazinul %s contine produsele: ", m->nume);

	Produs_t* p = m->listaProduse;

	while (p != NULL)
	{
		printf("%d ", p->cod);
		p = p->nextProdus;
	}
	printf("\n______________\n");
}

void adaugaMagazin(Magazin_t* m, Multilista_t* multilista)
{
	if (*multilista == NULL)
	{
		*multilista = m;
		return;
	}
	
	Magazin_t* mCurent = *multilista;

	while (mCurent->nextMagazin != NULL)
	{
		mCurent = mCurent->nextMagazin;
	}
	mCurent->nextMagazin = m;

}

void afisareMultilista(Multilista_t multilista)
{
	Magazin_t* m = multilista;

	while (m != NULL)
	{
		printMagazine(m);
		m = m->nextMagazin;
	}
}

void eliminareProdus(Multilista_t* multilista,int cod)
{
	Magazin_t *mCurent = *multilista;

	while (mCurent != NULL)
	{
		Produs_t* pCurent = mCurent->listaProduse;
		Produs_t* pAnterior = NULL;

		while (pCurent != NULL)
		{
			if (pCurent->cod == cod)
			{
				if (pAnterior == NULL)
				{
					mCurent->listaProduse = pCurent->nextProdus;

					free(pCurent);
				}

				else
				{
					pAnterior->nextProdus = pCurent->nextProdus;
					free(pCurent);
				}
				break;
			}
			pAnterior = pCurent;
			pCurent = pCurent->nextProdus;
		}

		mCurent = mCurent->nextMagazin;
	}

}


int main()
{
	Multilista_t multilista = NULL;

	Magazin_t* m1 = initMagazin("M1");
	Magazin_t* m2 = initMagazin("M2");

	for (int i = 5; i > 0; i--)
	{
		adaugaProduse(initProdus(i), m1);
	}
	for (int i = 10; i > 5; i--)
	{
		adaugaProduse(initProdus(i), m2);
	}

	//printMagazine(m1);
	adaugaMagazin(m1, &multilista);
	adaugaMagazin(m2, &multilista);
	//printf("GBs");

	afisareMultilista(multilista);
	eliminareProdus(&multilista, 3);
	afisareMultilista(multilista);
}