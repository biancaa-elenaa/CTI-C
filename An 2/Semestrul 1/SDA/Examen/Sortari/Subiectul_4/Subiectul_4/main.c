#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 7

typedef struct student {
	char nume[35];
	int varsta;
	int premii; //1-Da 0-Nu
}Student_t;

void citireFisier(Student_t* a, const char* filename)
{
	FILE* f = fopen(filename, "r");

	if (f == NULL)
	{
		printf("Eroare fisier\n");
		exit(-1);
	}

	for (int i = 0; i < N; i++)
	{
		fscanf(f, "%s", &a[i].nume);
		fscanf(f, "%d", &a[i].varsta);
		fscanf(f, "%d", &a[i].premii);

	}

	fclose(f);
}

void swap(Student_t* el1, Student_t* el2)
{
	Student_t tmp;
	tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}

int mutarePremii(Student_t* a)
{
	int index = 0;

	for (int i = 0; i < N; i++)
	{
		if (a[i].premii == 1)
		{
			if (i != index)
			{
				swap(&a[i], &a[index]);
			}
			index++;
		}
	}

	return index;
}

void quicksort(Student_t a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&a[prim], &a[(prim + ultim) / 2]);
	//mutare pivot pe prima pozitie
	Student_t pivot = a[prim];
	/*
	while (stanga <= dreapta) //partitionare
	{
		while (a[stanga].cheie < pivot.cheie)
			stanga++;
		while (pivot.cheie < a[dreapta].cheie)
			dreapta--;
		if (stanga < dreapta)
			swap(&a[stanga++], &a[dreapta--]);
		else
			stanga++;
	}*/
	while (stanga <= dreapta) //partitionare
	{
		while (strcmp(a[stanga].nume,pivot.nume) > 0)
			stanga++;
		while (strcmp(pivot.nume,a[dreapta].nume) > 0)
			dreapta--;
		if (stanga < dreapta)
			swap(&a[stanga++], &a[dreapta--]);
		else
			stanga++;
	}
	//mutare pivot la locul sau final
	swap(&a[dreapta], &a[prim]);
	//apelurile recursive
	if (prim < dreapta - 1)
		quicksort(a, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort(a, dreapta + 1, ultim);
}


void print(Student_t* studenti)
{
	for (int i = 0; i < N; i++)
	{
		printf("Nume: %s Varsta: %d Premii: %d\n", studenti[i].nume, studenti[i].varsta, studenti[i].premii);

	}
	printf("--------------------------------------------\n");
}

int main()
{
	Student_t studenti[N];

	citireFisier(studenti, "input.txt");

	int index = mutarePremii(studenti);

	print(studenti);

	quicksort(studenti, 0, index-1);

	print(studenti);




}