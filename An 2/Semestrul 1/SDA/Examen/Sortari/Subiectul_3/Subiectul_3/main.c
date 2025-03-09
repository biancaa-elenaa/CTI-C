#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct angajat {
	char nume[35];
	int salar;
	int bonus; //1- cu bonus , 0-fara bonus
}Angajat_t;

void citireFisier(Angajat_t* angajat, const char* filename)
{
	FILE* f = fopen(filename, "r");

	if (f == NULL)
	{
		printf("nu s-a deschis fisierul\n");
		exit(-1);
	}

	for (int i = 0; i < N; i++)
	{
		fscanf(f, "%s", &angajat[i].nume);
		fscanf(f, "%d", &angajat[i].salar);
		fscanf(f, "%d", &angajat[i].bonus);
	}
}

void swap(Angajat_t* el1, Angajat_t* el2)
{
	Angajat_t tmp;
	tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}

int mutareBonus(Angajat_t* angajat)
{
	int index=0;
	for (int i = 0; i < N; i++)
	{
		if (angajat[i].bonus == 1)
		{
			if (i != index)
			{
				swap(&angajat[i], &angajat[index]);
			}
			index++;
		}
		
	}
	return index;
}

void quicksort_salar(Angajat_t a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&a[prim], &a[(prim + ultim) / 2]);
	//mutare pivot pe prima pozitie
	Angajat_t pivot = a[prim];
	while (stanga <= dreapta) //partitionare
	{
		while (a[stanga].salar > pivot.salar)
			stanga++;
		while (pivot.salar > a[dreapta].salar)
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
		quicksort_salar(a, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort_salar(a, dreapta + 1, ultim);
}

void quicksort_nume(Angajat_t a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&a[prim], &a[(prim + ultim) / 2]);
	//mutare pivot pe prima pozitie
	Angajat_t pivot = a[prim];
	while (stanga <= dreapta) //partitionare
	{
		while (strcmp(a[stanga].nume,pivot.nume) < 0)
			stanga++;
		while (strcmp(pivot.nume, a[dreapta].nume) < 0)
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
		quicksort_nume(a, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort_nume(a, dreapta + 1, ultim);
}



void print(Angajat_t angajat[])
{
	for (int i = 0; i < N; i++)
	{
		printf("Nume: %s Salar: %d Bonus: %d\n", angajat[i].nume, angajat[i].salar, angajat[i].bonus);
	}
	printf("_________________________________\n");
}

int main()
{
	Angajat_t angajat[N];

	citireFisier(angajat, "input.txt");
	print(angajat);
	int index=mutareBonus(angajat);
	print(angajat);
	quicksort_nume(angajat, index, N - 1);
	print(angajat);

	//printf("%d", index);
}