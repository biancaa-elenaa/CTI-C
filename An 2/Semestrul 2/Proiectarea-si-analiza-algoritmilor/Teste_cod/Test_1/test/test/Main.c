#include <stdio.h>
#include "Bib.h"

TTree readFile1(TTree a, FILE* f)
{
	int cheie, parinte;

	while (fscanf(f, "%d %d", &cheie, &parinte) == 2)
	{
		printf("Valori citite: %d %d\n", cheie, parinte);
		a = InsertNode(a, parinte, cheie);
	}

	return a;
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		printf("Eroare argumente\n");
		return -1;
	}

	FILE* f = fopen(argv[1], "r");

	if (f == NULL)
	{
		printf("Eroare fisier\n");
		return -2;
	}

	TTree a = { 0 };

	a = InitTree(a);
	a = readFile1(a,f);

	printArray(a);

	printf("\n preOrder \n");
	preOrder(a, 1);



}