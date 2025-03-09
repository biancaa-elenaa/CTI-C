/*
Fie un sistem de gestionare a unor paleți din cadrul unui depozit.
Depozitul este caracterizat printr-un nume unic, iar paleții printr-un cod numeric (maxim 8 cifre).
Structura va avea următoarea componentă:Fiecare depozit reprezintă o intrare separată într-o listă principală.
Fiecare depozit conține o listă secundară ordonată după codul paleților din acel depozit
(cel puțin una din liste va fi implementată dinamic).
Funcționalități de implementat:
Eliminare paleți: Ștergerea unui palet identificat după cod din toate depozitele.
Să se aleagă un exemplu de listă care să conțină cel puțin 3 depozite, fiecare cu cel puțin 5 paleți.
Reprezentare grafică a structurii multilistei înainte și după apelul funcției de eliminare.
Notă:
Algoritmul poate fi scris în pseudocod (stil C).
Se vor specifica complexitatea algoritmilor și justificarea structurii alese.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Palet {
	int cod;
	struct Palet* nextPalet;
}Palet_t;

typedef struct Depozit {
	char nume[20];// -> nume unic
	Palet_t* listaPaleti;
	struct Depozit* nextDepozit;
}Depozit_t;

typedef Depozit_t* Multilista_t;

Palet_t* initPalet(int cod)
{
	Palet_t* palet = (Palet_t*)malloc(sizeof(Palet_t));

	if (palet == NULL)
	{
		printf("eroare palet\n");
		return NULL;
	}
	palet->cod = cod;
	palet->nextPalet = NULL;
	return palet;
}

Depozit_t* initDepozit(char* nume)
{
	Depozit_t* depozit = (Depozit_t*)malloc(sizeof(Depozit_t));

	if (depozit == NULL)
	{
		printf("eroare depozit\n");
		return NULL;
	}
	strcpy(depozit->nume, nume);
	depozit->listaPaleti = NULL;
	depozit->nextDepozit = NULL;

	return depozit;	
}

void adaugaPaletinDepozit(Palet_t* paletDeAdaugat, Depozit_t* depozitInCareAdauga)
{
	if (depozitInCareAdauga->listaPaleti == NULL)
	{
		depozitInCareAdauga->listaPaleti = paletDeAdaugat;
	}
	else
	{
		//daca sunt paleti in lista trebuie sa adaugam in ordine
		Palet_t* paletCurent = depozitInCareAdauga->listaPaleti; //capatul listei de paleti
		Palet_t* paletAnt = NULL;

		//Parcurgem pana la pozitia corecta
		while ((paletCurent != NULL) && (paletCurent->cod < paletDeAdaugat->cod))
		{
			paletAnt = paletCurent;
			paletCurent = paletCurent->nextPalet;
		}

		if (paletAnt == NULL)
		{
			//Adaugam la inceput
			paletDeAdaugat->nextPalet = paletCurent;
			depozitInCareAdauga->listaPaleti = paletDeAdaugat;
		}
		else {
			paletDeAdaugat->nextPalet = paletCurent;
			paletAnt->nextPalet = paletDeAdaugat;

		}
	}
}

void afiseazaDepozit(Depozit_t* depozit)
{
	printf("Depozitul %s contine paletii: ", depozit->nume);

	Palet_t* paleti = depozit->listaPaleti;

	while (paleti != NULL)
	{
		printf("%d ", paleti->cod);
		paleti = paleti->nextPalet;
	}
	printf("\n---------------\n");
}

void adaugaDepozit_inMultilista(Depozit_t* depozit, Multilista_t* multilista)
{
	if (*multilista == NULL)
	{
		*multilista = depozit;
		return;
	}

	Depozit_t* depozitCurent = *multilista;

	while (depozitCurent->nextDepozit != NULL)
	{
		depozitCurent = depozitCurent->nextDepozit;
	}

	depozitCurent->nextDepozit = depozit;
}

void afiseazaMultilista(Multilista_t* multilista)
{
	Depozit_t* depozitCurent = *multilista;

	while (depozitCurent != NULL)
	{
		afiseazaDepozit(depozitCurent);
		depozitCurent=depozitCurent->nextDepozit;
	}
}

void stergePalet(Multilista_t* multilista, int cod)
{
	Depozit_t* depozitCurent = *multilista;

	while (depozitCurent != NULL)
	{
		Palet_t* paletCurent = depozitCurent->listaPaleti;
		Palet_t* paletAnt = NULL;

		while (paletCurent != NULL)
		{
			if (paletCurent->cod == cod)
			{
				//daca e primul palet
				if (paletAnt == NULL)
				{
					depozitCurent->listaPaleti = paletCurent->nextPalet;
				}
				else
				{
					paletAnt->nextPalet = paletCurent->nextPalet;
				}
				free(paletCurent);

				break;
			}

			paletAnt = paletCurent;
			paletCurent = paletCurent->nextPalet;
		}
		depozitCurent = depozitCurent->nextDepozit;

	}
}

int main()
{
	Multilista_t multilista = NULL;

	Depozit_t* d1 = initDepozit("depozit1");

	adaugaPaletinDepozit(initPalet(3), d1);
	adaugaPaletinDepozit(initPalet(1), d1);
	adaugaPaletinDepozit(initPalet(2), d1);
	adaugaPaletinDepozit(initPalet(4), d1);
	adaugaPaletinDepozit(initPalet(0), d1);

	//afiseazaDepozit(d1);

	Depozit_t* d2 = initDepozit("depozit2");

	adaugaPaletinDepozit(initPalet(6), d2);
	adaugaPaletinDepozit(initPalet(5), d2);
	adaugaPaletinDepozit(initPalet(8), d2);
	adaugaPaletinDepozit(initPalet(7), d2);
	adaugaPaletinDepozit(initPalet(9), d2);
	//afiseazaDepozit(d2);

	Depozit_t* d3 = initDepozit("depozit3");

	adaugaPaletinDepozit(initPalet(11), d3);
	adaugaPaletinDepozit(initPalet(10), d3);
	adaugaPaletinDepozit(initPalet(12), d3);
	adaugaPaletinDepozit(initPalet(13), d3);
	adaugaPaletinDepozit(initPalet(14), d3);
	//afiseazaDepozit(d3);

	adaugaDepozit_inMultilista(d1, &multilista);
	adaugaDepozit_inMultilista(d2, &multilista);
	adaugaDepozit_inMultilista(d3, &multilista);

	afiseazaMultilista(&multilista);

	stergePalet(&multilista, 9);

	afiseazaMultilista(&multilista);


	return 0;
}