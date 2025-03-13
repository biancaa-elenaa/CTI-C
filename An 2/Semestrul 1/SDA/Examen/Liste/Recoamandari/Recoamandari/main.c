﻿/*
		Fie o aplicație care gestionează o rețea de profesioniști din întreaga lume, de tip LinkedIn. Pentru o persoană se memorează:

						un ID (număr întreg),
						un nume (maxim 35 caractere),
						o ocupație (maxim 35 caractere),
						o listă de recomandări.

		O recomandare trebuie să conțină:

					text (maxim 100 caractere fiecare),
					ID-ul persoanei care a făcut recomandarea.

		Structura trebuie să fie implementată utilizând lista simplu înlănțuită,

		iar fiecare persoană va conține un tablou static cu recomandările primite.

		Cerințe:
					Căutare profesioniști IT:

					Se cere crearea unei liste (statică sau dinamică) care să conțină

					3 profesioniști IT cu mai mult de 10 recomandări.

		Se va reprezenta grafic structura multilistei înainte și după apelul funcției de căutare.
*/;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECOMANDARI 16

typedef struct Recomandari {
	char text[100];
	int idPersoanaCareAFacutRecomandarea;
}Recomandari_t;

typedef struct Persoana {
	int id;
	char nume[35];
	char ocupatie[35];
	Recomandari_t recomandari[MAX_RECOMANDARI];
	int nrRecomandari;
	struct Persoana* nextPersoana;
}Persoana_t;

typedef Persoana_t* Multilista_t;

Persoana_t* initPersoana(int id, char* nume, char* ocupatie)
{
	Persoana_t* p = (Persoana_t*)malloc(sizeof(Persoana_t));

	if (p == NULL)
	{
		printf("eroare persoana\n");
		return NULL;
	}

	p->id = id;
	strcpy(p->nume, nume);
	strcpy(p->ocupatie, ocupatie);
	p->nrRecomandari = 0;
	p->nextPersoana = NULL;

	return p;

}

Recomandari_t* initRecomandare(char* text, int id)
{
	Recomandari_t* r = (Recomandari_t*)malloc(sizeof(Recomandari_t));

	if (r == NULL)
	{
		printf("eroare recomandare\n");
		return NULL;
	}

	strcpy(r->text, text);
	r->idPersoanaCareAFacutRecomandarea = id;

	return r;
}

void adaugaRecomandare(Persoana_t* p, Recomandari_t* r)
{
	if (p->nrRecomandari < MAX_RECOMANDARI)
	{
		p->recomandari[p->nrRecomandari++] = *r;
	}
	else
	{
		printf("S-a atins nr maxim de recomandari\n");
	}
}

void afiseazaRecomandari(Persoana_t* p)
{
	printf("  Recomandari: ");
	for (int i = 0; i < p->nrRecomandari; i++)
	{
		printf("Text: %s de la persoana cu ID=%d\n", p->recomandari[i].text, p->recomandari[i].idPersoanaCareAFacutRecomandarea);
	}
	printf("\n---------------\n");
}

void adaugaPersoana(Persoana_t* p, Multilista_t* multilista)
{
	if (*multilista == NULL)
	{
		*multilista = p;
	}
	else {
		Persoana_t* persoanaCurenta = *multilista;

		while (persoanaCurenta->nextPersoana != NULL)
		{
			persoanaCurenta = persoanaCurenta->nextPersoana;
		}
		persoanaCurenta->nextPersoana = p;
	}
}

void afisareMultilista(Multilista_t multilista)
{
	Persoana_t* p = multilista;
	while (p != NULL)
	{
		printf("ID: %d Nume: %s Ocupatie: %s ", p->id, p->nume, p->ocupatie);
		afiseazaRecomandari(p);
		p = p->nextPersoana;
	}

}

Multilista_t cautareProfesionisti(Multilista_t multilista)
{
	Multilista_t prof = NULL;
	if (multilista == NULL)
	{
		printf("multilista goala\n");
		return NULL;
	}
	else {
		Persoana_t* p = multilista;

		while (p != NULL)
		{
			// Verificăm condițiile: IT și >10 recomandări
			if (strcmp(p->ocupatie, "IT") == 0 && p->nrRecomandari > 10)
			{
				// Creăm o copie a nodului curent
				Persoana_t* copie = initPersoana(p->id, p->nume, p->ocupatie);

				// Copiem și recomandările
				for (int i = 0; i < p->nrRecomandari; i++)
				{
					adaugaRecomandare(copie, &p->recomandari[i]);
				}

				// Adăugăm copia în lista nouă
				adaugaPersoana(copie, &prof);
			}
			p = p->nextPersoana;
		}
	}
	return prof;
}

int main()
{
	Multilista_t multilista = NULL;

	Persoana_t* p1 = initPersoana(1, "Ana", "IT");
	Persoana_t* p2 = initPersoana(2, "bob", "maRKETING");
	Persoana_t* p3 = initPersoana(3, "Claudia", "IT");
	Persoana_t* p4 = initPersoana(4, "Mark", "IT");
	Persoana_t* p5 = initPersoana(5, "Eve", "HR");

	for (int i = 2; i <= 12; i++) {
		adaugaRecomandare(p1, initRecomandare("Recomandare IT pentru Ana", i));
	}
	for (int i = 1; i <= 8; i++) {
		adaugaRecomandare(p2, initRecomandare("Recomandare generala", i));
	}
	for (int i = 1; i <= 11; i++) {
		adaugaRecomandare(p3, initRecomandare("Recomandare IT pt Claudia", i));
	}
	for (int i = 1; i <= 15; i++) {
		adaugaRecomandare(p4, initRecomandare("Recomandare IT pentru Mark", i));
	}

	adaugaPersoana(p1, &multilista);
	adaugaPersoana(p2, &multilista);
	adaugaPersoana(p3, &multilista);
	adaugaPersoana(p4, &multilista);
	adaugaPersoana(p5, &multilista);

	//afisareMultilista(multilista);

	Multilista_t prof = cautareProfesionisti(multilista);

	afisareMultilista(prof);

}