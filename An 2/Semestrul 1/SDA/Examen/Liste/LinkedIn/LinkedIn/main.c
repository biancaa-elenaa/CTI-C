﻿/*
	Fie o aplicație care gestionează o rețea de profesioniști din întreaga lume, de tip LinkedIn. Pentru o persoană se memorează:

					un ID (număr întreg),
					un nume (maxim 35 de caractere),
					o ocupație (maxim 35 de caractere),

					precum și o listă de conexiuni profesionale.

	Se cere să se implementeze o structură bazată pe lista simplu înlănțuită (dinamică),

	articulată cu tabele pentru a gestiona eficient persoanele. Structura va avea următoarea componentă:

		Fiecare persoană reprezintă un nod într-o listă principală.

		Fiecare persoană conține un tabel implementat în mod static,

			cu conexiunile profesionale pe care le are (colegi de echipă, persoane de la resurse umane etc.).

	Funcționalități:
		Adăugare conexiune în lista unei persoane: Adăugarea unei conexiuni în lista secundară.

		Să se aleagă un exemplu de listă care să cuprindă cel puțin 3 persoane, fiecare cu cel puțin 5 conexiuni.

		Să se reprezinte grafic structura multilistei pentru acest exemplu, înainte și după apelul funcției de adăugare conexiune.

*/

;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONEXIUNI 5

typedef struct Conexiune {
	int idConexiune;
	char numeConexiune[35];
	char ocupatieConexiune[35];
}Conexiune_t;

typedef struct Persoana {
	int id;
	char nume[35];
	char ocupatie[35];
	Conexiune_t conexiuni[MAX_CONEXIUNI]; //tablou static de conexiuni
	int nrConexiuni;
	struct Persoana* nextPersoana;
}Persoana_t;

typedef Persoana_t* Multilista_t;

Conexiune_t* initConexiune(int id, char numeConexiune[], char ocupatieConexiune[])
{
	Conexiune_t* c = (Conexiune_t*)malloc(sizeof(Conexiune_t));

	if (c == NULL)
	{
		printf("eroare conexiune\n");
		return NULL;
	}

	c->idConexiune = id;
	strcpy(c->numeConexiune, numeConexiune);
	strcpy(c->ocupatieConexiune, ocupatieConexiune);

	return c;

}

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
	p->nrConexiuni = 0;
	p->nextPersoana = NULL;

	return p;
}

void adaugaConexiune(Persoana_t* p, Conexiune_t* conexiune)
{
	if (!p)
	{
		printf("nu exista persoana");
		return;
	}
	if (p->nrConexiuni < MAX_CONEXIUNI)
	{
		p->conexiuni[p->nrConexiuni++] = *conexiune;
	}
	else {
		printf("prea multe coneiuni\n");
	}
}

void adaugaPersoana(Multilista_t* multilista, Persoana_t* persoana)
{
	if (*multilista == NULL)
	{
		*multilista = persoana;
	}
	else
	{
		Persoana_t* persoanaCurenta = *multilista;

		while (persoanaCurenta->nextPersoana != NULL)
		{
			persoanaCurenta = persoanaCurenta->nextPersoana;
		}

		persoanaCurenta->nextPersoana = persoana;
	}
}

void afiseazaConexiuni(Persoana_t* persoana) {
	printf("Conexiuni: \n");

	for (int i = 0; i < persoana->nrConexiuni; i++) {
		printf("ID : %d -> Nume : %s -> Ocupatie : %s \n",
			persoana->conexiuni[i].idConexiune,
			persoana->conexiuni[i].numeConexiune,
			persoana->conexiuni[i].ocupatieConexiune);
	}
	printf("------------------------------------------\n");
}

void afiseazaMultilista(Multilista_t* multilista) {
	Persoana_t* persoanaCurenta = *multilista;

	while (persoanaCurenta != NULL) {
		printf("Persoana cu numele : %s -- ID : %d -- ocupatie : %s\n",
			persoanaCurenta->nume,
			persoanaCurenta->id,
			persoanaCurenta->ocupatie);
		afiseazaConexiuni(persoanaCurenta);
		persoanaCurenta = persoanaCurenta->nextPersoana;
	}
}

int main()
{
	Multilista_t multilista = NULL;

	Persoana_t* persoana1 = initPersoana(1, "Daria", "Itista to be");
	Persoana_t* persoana2 = initPersoana(2, "Dan", "Angajat MAI");
	Persoana_t* persoana3 = initPersoana(3, "Anisia", "eleva");

	adaugaPersoana(&multilista, persoana1);
	adaugaPersoana(&multilista, persoana2);
	adaugaPersoana(&multilista, persoana3);

	printf("Multilista initiala fara conexiuni\n");

	afiseazaMultilista(&multilista);

	adaugaConexiune(persoana1, initConexiune(4, "David", "Designer"));
	adaugaConexiune(persoana1, initConexiune(5, "Eve", "QA Engineer"));
	adaugaConexiune(persoana1, initConexiune(6, "Frank", "HR Specialist"));
	adaugaConexiune(persoana1, initConexiune(7, "Grace", "Scrum Master"));
	adaugaConexiune(persoana1, initConexiune(9, "Patricia", "profesoara"));

	adaugaConexiune(persoana2, initConexiune(6, "Frank", "HR Specialist"));
	adaugaConexiune(persoana2, initConexiune(7, "Grace", "Scrum Master"));

	adaugaConexiune(persoana3, initConexiune(8, "Heidi", "DevOps Engineer"));
	adaugaConexiune(persoana3, initConexiune(9, "Ivan", "Backend Developer"));


	printf("Multilista initiala cu cateva conexiuni\n");

	afiseazaMultilista(&multilista);

	adaugaConexiune(persoana1, initConexiune(10, "Jenny", "Frontend Developer"));

	printf("Multilista dupa adaugarea unei conexiuni peste limita\n");

	afiseazaMultilista(&multilista);

	return 0;
}