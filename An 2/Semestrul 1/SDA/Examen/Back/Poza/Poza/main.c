#include <stdio.h>
#define MAX_LINII 5
#define MAX_COLOANE 5

int vizitat[MAX_LINII][MAX_COLOANE];

//directii
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

/*
* vest,est,nord,sud
*/

void fill(int matrice[][MAX_COLOANE], int x, int y)
{
	matrice[x][y] = 3;

	if (y > 0 && matrice[x][y - 1] == 1)
	{
		fill(matrice, x, y - 1); //vest
	}

	if (y < (MAX_COLOANE - 1) && matrice[x][y + 1] == 1)
		fill(matrice, x, y + 1); //est

	if (x > 0 && matrice[x - 1][y] == 1)
		fill(matrice, x - 1, y);

	if (x < (MAX_LINII - 1) && matrice[x + 1][y] == 1)
		fill(matrice, x + 1, y);
}

int esteValid(int x, int y, int matrice[][MAX_COLOANE])
{
	return (x >= 0 && x < MAX_LINII && y >= 0 && y < MAX_COLOANE && matrice[x][y] == 1);
}

void fillDeplasamente(int matrice[][MAX_COLOANE], int x, int y)
{
	matrice[x][y] = 3;

	for (int d = 0; d < 4; d++)
	{
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (esteValid(nx, ny, matrice))
		{
			fillDeplasamente(matrice, nx, ny);
		}
	}
}

int numarObiecte(int matrice[][MAX_COLOANE])
{
	int nrObiecte = 0;
	for(int i=0;i<MAX_LINII;i++)
		for (int j = 0; j < MAX_COLOANE; j++)
		{
			if (matrice[i][j] == 1)
			{
				nrObiecte++;
				fillDeplasamente(matrice, i, j);
			}
		}

	return nrObiecte;
}


void afiseazaMatrice(int matrice[][MAX_COLOANE]) {
	for (int i = 0; i < MAX_LINII; i++) {
		for (int j = 0; j < MAX_COLOANE; j++) {
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
	printf("_________________\n");
}

int main()
{
	int matrice[MAX_LINII][MAX_COLOANE] = {
		{1,1,0,0,0},
		{1,1,0,0,0},
		{0,0,0,1,1},
		{0,0,1,0,0},
		{0,0,1,1,1}
	};

	afiseazaMatrice(matrice);
	//illDeplasamente(matrice, 0, 0);
	//afiseazaMatrice(matrice);
	int n = numarObiecte(matrice);
	printf("%d ", n);



}