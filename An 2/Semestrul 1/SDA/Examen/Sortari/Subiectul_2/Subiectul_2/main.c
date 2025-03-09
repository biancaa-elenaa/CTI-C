#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct agenda
{
	char nume[25];
	char telefon[10];
	int an;
	int venit;
}Agenda_t;

#define N 5

void citeste_fisier(Agenda_t* agenda, const char* filename)
{
	FILE* f = fopen(filename, "r");

	if (f == NULL)
	{
		printf("Nu se deschide fisierul\n");
		exit(-1);
	}

	for (int i = 0; i < N; i++)
	{
		fscanf(f, "%s", &agenda[i].nume);
		fscanf(f, "%s", &agenda[i].telefon);
		fscanf(f, "%d", &agenda[i].an);
		fscanf(f, "%d", &agenda[i].venit);
	}
}

void afiseazaDateAgende(Agenda_t* agende) {
	for (int i = 0; i < N; i++) {
		printf("Nume : % s - Telefon %s - An %d - Venit %d\n", agende[i].nume, agende[i].telefon, agende[i].an, agende[i].venit);
	}

	printf("---------------------------------------------------------------\n");
}

void swap(Agenda_t* el1, Agenda_t* el2)
{
	Agenda_t tmp;
	tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}

void mutare_venit(Agenda_t* agenda)
{
	int k = 1;
	for (int i = 0; i < N && k<3; i++)
	{
		if (agenda[i].venit < 1000)
		{
			swap(&agenda[i], &agenda[N - k]);
			k++;
		}
	}

}

void selection_sort(Agenda_t a[])
{
	int i, j, min; // min retine INDEXUL elementului cu valoare minima
	for (i = 0; i < N - 1; i++)
	{
		if (a[i].an >= 30 && a[i].an <= 40)
		{
			min = i;
			for (j = i + 1; j < N; j++)
			{
				if (a[j].an >= 30 && a[j].an <= 40)
				{
					if (strcmp(a[j].nume, a[min].nume) < 0)
						min = j;
				}
			}
			swap(&a[min], &a[i]);
		}
	}
}

void cerintaB_sortareNume(Agenda_t* agende) {
	int i, j, min;

	for (i = 0; i < N - 1; i++) {
		if (agende[i].an >= 30 && agende[i].an <= 40) {
			min = i;
		}
		else {
			continue;
		}

		for (j = i + 1; j < N; j++) {
			if (agende[j].an >= 30 && agende[j].an <= 40) {
				if (strcmp(agende[j].nume, agende[min].nume) < 0) {
					min = j;
				}
			}
		}

		swap(&agende[i], &agende[min]);
	}
}


int main()
{
	Agenda_t agenda[N];

	citeste_fisier(agenda, "input.txt");
	//printf("%d", agenda[0].an);
	//mutare_venit(agenda);
	afiseazaDateAgende(agenda);
	selection_sort(agenda);
	afiseazaDateAgende(agenda);


}