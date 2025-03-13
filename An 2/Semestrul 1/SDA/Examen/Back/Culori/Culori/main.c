#include <stdio.h>

#define N 4
#define M 5

void printMatrice(int matrice[][M])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			printf("%d ", matrice[i][j]);
		printf("\n");
	}
	printf("_____\n");
}

int culoareValida(int matrice[][M], int x, int y, int culoare)
{
	if (x > 0 && y > 0 && matrice[x - 1][y - 1] == culoare)
		return 0;
	if (x < (N - 1) && y>0 && matrice[x + 1][y - 1] == culoare)
		return 0;
	if (x > 0 && y < (M - 1) && matrice[x - 1][y + 1] == culoare)
		return 0;
	if (x < (N-1) && y < (M - 1) && matrice[x + 1][y + 1] == culoare)
		return 0;
	return 1;

}

void coloreaza(int matrice[][M])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int culoare = 1; culoare <= 4; culoare++)
			{
				matrice[i][j] = culoare;
				if (culoareValida(matrice, i, j, culoare) == 1)
				{
					break;
				}
			}
		}
	}
}

int main()
{
	int m[N][M] = { 0 };
	coloreaza(m);
	printMatrice(m);

}