#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10

typedef struct echipa {
	char nume[25];
	int punct;
	int buget;
	char oras[25];
}Echipa_t;

void citireFisier(Echipa_t* echipa, const char* filename)
{
	FILE* f = fopen(filename, "r");

	if (f == NULL)
	{
		printf("Eroare fiser\n");
		exit(-1);
	}

	for (int i = 0; i < N; i++)
	{
		fscanf(f, "%s", &echipa[i].nume);
		fscanf(f, "%d", &echipa[i].punct);
		fscanf(f, "%d", &echipa[i].buget);
		fscanf(f, "%s", &echipa[i].oras);

	}

	fclose(f);
}

void print(Echipa_t echipa[])
{
	for (int i = 0; i < N; i++)
	{
		printf("%s %d %d %s\n", echipa[i].nume, echipa[i].punct, echipa[i].buget, echipa[i].oras);
	}
	printf("-------------------------\n");
}

void swap(Echipa_t* el1, Echipa_t* el2)
{
	Echipa_t tmp;
	tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}

void mutarePuncte(Echipa_t* echipa)
{
	int bigger45 = 0;
	int lower20 = N - 1;

	for (int i = 0; i <= lower20;i++)
	{
		if (echipa[i].punct > 45)
		{
			if (i != bigger45)
			{
				swap(&echipa[i], &echipa[bigger45]);
			}
			bigger45++;
		}
		else if (echipa[i].punct < 20)
		{
			while (lower20 > i && echipa[lower20].punct < 20)
			{
				lower20--;
			}
			if (i != lower20)
			{
				swap(&echipa[i], &echipa[lower20]);
				i--;
			}
			lower20--;
		}
	}
}

void quicksort(Echipa_t a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&a[prim], &a[(prim + ultim) / 2]);
	//mutare pivot pe prima pozitie
	Echipa_t pivot = a[prim];
	while (stanga <= dreapta) //partitionare
	{
		while (a[stanga].punct > pivot.punct)
			stanga++;
		while (pivot.punct > a[dreapta].punct)
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

void sort(Echipa_t echipa[])
{
	int index[N];
	Echipa_t tmp[N];
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		if (echipa[i].buget > 100000)
		{
			index[count] = i;
			tmp[count] = echipa[i];
			count++;
		}
	}

	quicksort(tmp, 0, count - 1);

	for (int i = 0; i < count; i++)
	{
		echipa[index[i]] = tmp[i];
	}
}

int main()
{
	Echipa_t echipa[N];
	citireFisier(echipa,"input.txt");
	print(echipa);
	//mutarePuncte(echipa);
	sort(echipa);
	print(echipa);
}