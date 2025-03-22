#include <stdio.h>
#include<string.h>
#include "Bib.h"

TTree readFile(TTree a, FILE* f) {

	TKey cheie = 0;
	TNodeRef parinte = 0;

	while (fscanf(f, "%hhu %hhu", &cheie, &parinte) == 2)
	{
		printf("Valori citite: %hhu %hhu\n", cheie, parinte);

		a = InsertNode(a, parinte, cheie);
	}

	return a;

}

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		printf("Incorrect\n");
		return -1;
	}

	FILE* f = fopen(argv[1], "r");
	FILE* o = fopen(argv[3], "w");
	if (!f)
	{
		printf("Eroare fisier\n");
		return -2;
	}

	TTree a = { 0 };

	//initializare arbore
	a = InitTree(a);

	a = readFile(a, f);


	switch (argv[2][0])
	{
	case 'B':
		printArray(a, o);
		break;
	case 'a':
		printf("\n PreOrdine: \n");
		preOrder(a, 1);
		printf("\n InOrdine: \n");
		inOrder(a, 1);
		printf("\n PostOrdine: \n");
		postOrder(a, 1);

		break;
	default:
		break;
	}

	fclose(f);
	fclose(o);
}