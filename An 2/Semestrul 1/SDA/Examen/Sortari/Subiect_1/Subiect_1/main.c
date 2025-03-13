#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int cheie;
}tip_element;

tip_element a[5000];

void swap(tip_element* el1, tip_element* el2)
{
	tip_element tmp;
	tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}


void quicksort(tip_element a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&a[prim], &a[(prim + ultim) / 2]);
	//mutare pivot pe prima pozitie
	tip_element pivot = a[prim];
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
	}
	//mutare pivot la locul sau final
	swap(&a[dreapta], &a[prim]);
	//apelurile recursive
	if (prim < dreapta - 1)
		quicksort(a, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort(a, dreapta + 1, ultim);
}

int separare_negative(tip_element a[], int size)
{
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i].cheie < 0)
		{
			if (i != index)
			{
				swap(&a[i].cheie, &a[index].cheie);
			}
			index++;
		}
	}
	return index;
}

void print(tip_element a[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	tip_element a[] = {1, -7, 5, 2,-1,6,-9};
	int size = sizeof(a) / sizeof(a[0]);

	int index = separare_negative(a, size);
	print(a, size);

	quicksort(a, index, size - 1);
	print(a, size);

	
}