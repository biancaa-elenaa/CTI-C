#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct Student {
	char nume[20];
	struct Student* nextStudent;
}Student_t;

typedef struct Conferinta {
	int id;
	char parola[20];
	Student_t* waitingRoom;
	struct Conferinta* nextConferinta;

}Conferinta_t;

typedef Conferinta_t* Multilista_t;

Student_t* initStudent(char* nume)
{
	Student_t* s = (Student_t*)malloc(sizeof(Student_t));

	if (s == NULL)
	{
		printf("BTTB");
		return NULL;
	}
	strcpy(s->nume, nume);
	s->nextStudent = NULL;
	return s;
}

Conferinta_t* initConferinta(int id, char* parola)
{
	Conferinta_t* c = (Conferinta_t*)malloc(sizeof(Conferinta_t));

	if (c == NULL)
	{
		printf("SB");
		return NULL;
	}

	c->id = id;
	strcpy(c->parola, parola);
	c->nextConferinta = NULL;
	c->waitingRoom = NULL;
	return c;
}

void adaugaStudentiInWaitingRoom(Conferinta_t* c, Student_t* s)
{
	if (c->waitingRoom == NULL)
	{
		c->waitingRoom = s;
	}
	else {
		//cautam locul unde trebuie adaugat
		Student_t* sCurent = c->waitingRoom;
		Student_t* sAnt = NULL;

		while (sCurent != NULL && strcmp(sCurent->nume, s->nume) < 0)
		{
			sAnt = sCurent;
			sCurent = sCurent->nextStudent;
		}

		if (sAnt == NULL)
		{
			s->nextStudent = sCurent;
			c->waitingRoom = s;
			return;
		}
		else {
			s->nextStudent = sCurent;
			sAnt->nextStudent = s;
		}
		
	}
}

void afisareStudent(Student_t* s)
{
	printf("%s ", s->nume);
}

void afisareConferinta(Conferinta_t* c)
{
	printf("Depozitul cu id-ul %d si parola %s are in wr: ", c->id, c->parola);

	Student_t* s = c->waitingRoom;

	while (s != NULL)
	{
		afisareStudent(s);
		s = s->nextStudent;
	}
	printf("\n___________________\n");
}

void adaugaConferinta(Multilista_t* m, Conferinta_t* c)
{
	if (*m == NULL)
	{
		*m = c;
		return;
	}

	Conferinta_t* cCurent = *m;

	while (cCurent->nextConferinta != NULL)
	{
		cCurent = cCurent->nextConferinta;
	}

	cCurent->nextConferinta = c;
}

void afiseazaMultilista(Multilista_t* m)
{
	Conferinta_t* c = *m;

	while (c != NULL)
	{
		afisareConferinta(c);
		c = c->nextConferinta;
	}
}

void acceptareStudenti(Multilista_t* m, char ch)
{
	Conferinta_t* c = *m;

	while (c != NULL)
	{
		Student_t* sCurent = c->waitingRoom;
		Student_t* sAnt = NULL;

		while (sCurent != NULL)
		{
			if (sCurent->nume[0] == ch)
			{
				if (sAnt == NULL) // primul student trebuie sters
				{
					c->waitingRoom = sCurent->nextStudent;
				}
				else
				{
					sAnt->nextStudent = sCurent->nextStudent;
				}
				
			}

			sAnt = sCurent;
			sCurent = sCurent->nextStudent;
		}

		c = c->nextConferinta;
	}
}

int main()
{
	Multilista_t multilista = NULL;

	Conferinta_t* conf1 = initConferinta(1, "parola1");

	adaugaStudentiInWaitingRoom(conf1, initStudent("Sna"));
	adaugaStudentiInWaitingRoom(conf1, initStudent("Fna"));
	adaugaStudentiInWaitingRoom(conf1, initStudent("Ana"));
	adaugaStudentiInWaitingRoom(conf1, initStudent("Bna"));

	//afisareConferinta(conf1);

	Conferinta_t* conf2 = initConferinta(2, "parola2");

	adaugaStudentiInWaitingRoom(conf2, initStudent("cna"));
	adaugaStudentiInWaitingRoom(conf2, initStudent("lna"));
	adaugaStudentiInWaitingRoom(conf2, initStudent("Ana"));
	adaugaStudentiInWaitingRoom(conf2, initStudent("dna"));

	//afisareConferinta(conf2);

	Conferinta_t* conf3 = initConferinta(3, "parola3");

	adaugaStudentiInWaitingRoom(conf3, initStudent("xna"));
	adaugaStudentiInWaitingRoom(conf3, initStudent("rna"));
	adaugaStudentiInWaitingRoom(conf3, initStudent("Ana"));
	adaugaStudentiInWaitingRoom(conf3, initStudent("dna"));

	//afisareConferinta(conf3);

	adaugaConferinta(&multilista, conf1);
	adaugaConferinta(&multilista, conf2);
	adaugaConferinta(&multilista, conf3);

	afiseazaMultilista(&multilista);

	printf("\n*****************\n");

	acceptareStudenti(&multilista, 'A');

	
	afiseazaMultilista(&multilista);
}