#include <stdio.h>
#define N 3
#define M 3

void afiseazaMatrice(float matrice[][M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%f ", matrice[i][j]);
		}
		printf("\n");
	}
	printf("\n\n-----------------------------------------------------------------------\n\n");
}

int dx[] = {-1,1,0,0,-1,-1,1,1};
int dy[] = {0,0,-1,1,-1,1,-1,1};

float vizitat[N][M];

int eValid(float matrice[][M], int x, int y, float curent)
{
	return (x >= 0 && x < (N - 1) && y>=0 && y<(M - 1) && vizitat[x][y] == 0 && curent > matrice[x][y]);
}

void fill(float matrice[][M], int x, int y)
{
	vizitat[x][y] = 1;

	if (x == 0 || (x == N - 1) || y == 0 || y == (M - 1))
	{
		afiseazaMatrice(vizitat);
		vizitat[x][y] = 0;
		return;
	}

	for (int d = 0; d < 8; d++)
	{
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (eValid(matrice, nx, ny, matrice[x][y]))
		{
			fill(matrice, nx, ny);
		}
	}
	//vizitat[x][y] = 0;
}


int main()
{
	float matrice[N][M] = {
		{5.0,4.0,3.0},
		{6.0,7.0,2.0},
		{9.0,8.0,1.0}
	};

	int x = 1;
	int y = 1;

	fill(matrice, x, y);
	//afiseazaMatrice(matrice);
}