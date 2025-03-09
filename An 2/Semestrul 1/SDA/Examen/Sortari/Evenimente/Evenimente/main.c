#include<stdio.h>
#include <string.h>

typedef struct Eveniment { // structura permite organizarea evenimentelor in mod clar si accesibil
	char id[5]; // fiecare eveniment este reprezentat de un ID de tip char
	int start; // de un timp in care incepe evenimentul
	int end; // si de un timp in care se termina
}Eveniment_t;

void swap(Eveniment_t* el1, Eveniment_t* el2) // O(1) se interschimba 2 valori
{
	Eveniment_t tmp;
	tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}

void deplasare(Eveniment_t a[], int stanga, int dreapta) // O(log n)
{
	int fiu = 2 * stanga + 1;
	while (fiu <= dreapta) 
	{
		if (fiu < dreapta && (a[fiu].end < a[fiu+1].end))
			//daca al doilea fiu are cheia cea mai mare
			fiu++;								//retinem al doilea fiu
		if (a[stanga].end < a[fiu].end)  //daca este necesar 
		{										 //schimba parinte cu fiu
			swap(&a[stanga], &a[fiu]);			 //si deplaseaza in jos
			stanga = fiu;
			fiu = 2 * stanga + 1;
		}
		else
			fiu = dreapta + 1;
	}
}
void heapsort(Eveniment_t a[], int n) //O(n * lon n)
{
	int i;
	//algoritmul lui Floyd 
	for (i = n / 2 - 1; i >= 0; i--) //se creaza ansamblul O(n)
		deplasare(a, i, n - 1);
	//extragerea maximului si refacerea ansamblului
	for (i = n - 1; i >= 1; i--) // O(n)
	{
		swap(&a[0], &a[i]);			//mutare element maxim pe pozitia a[i]
		deplasare(a, 0, i - 1);		//O(logn), se reface proprietatea de ansamblu
	}
}

void afiseazaEveniment(Eveniment_t e) //O(1)
{
	printf("ID: %s Start: %d End: %d \n", e.id, e.start, e.end);
}

void afiseazaEvenimente(Eveniment_t ev[], int n) //O(n)
{
	for (int i = 0; i < n; i++)
	{
		printf("ID: %s Start: %d End: %d", ev[i].id, ev[i].start, ev[i].end);
		printf("\n");
	}
	printf("________\n");
}

void planificaEveniment(Eveniment_t ev[], int n) //O(n)
{
	printf("Planificare: \n");
	afiseazaEveniment(ev[0]);

	int end = ev[0].end;

	for (int i = 1; i < n; i++)
	{
		if (ev[i].start >= end)
		{
			afiseazaEveniment(ev[i]);
			end = ev[i].end;
		}
	}
}

int main()
{
	int n = 3;

	Eveniment_t ev[3] = {
		{"ID1", 0, 5},
		{"ID2", 3, 11},
		{"ID3", 6, 10}
	};
	afiseazaEvenimente(ev, n);
	heapsort(ev, n);
	afiseazaEvenimente(ev, n);
	planificaEveniment(ev, n);

}