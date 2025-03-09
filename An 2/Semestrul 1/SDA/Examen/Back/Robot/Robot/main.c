#include <stdio.h>
#define N 4
#define M 4

typedef struct coordonate
{
	int x,y;
}Coordonate_t;

typedef struct Robot {
	Coordonate_t coordonataCurenta;
	int energie;
}Robot_t;

Coordonate_t deplasari[4];
Robot_t robot;

int matrice[N][M] = {
	{0,0,0,0},
	{0,-1,-1,0},
	{0,1,0,0},
	{-1,0,0,0}

};
int vizitat[N][M];

void initializare() //int pos[] variabila globala
{	//initializarea posibilitatilor de deplasare Posibilitățile de deplasare sunt Nord, Est, Sud, Vest
	deplasari[0].x = 0; // Nord
	deplasari[0].y = -1;// y scade spre Nord

	deplasari[1].x = 1; // Est – x creste spre Est
	deplasari[1].y= 0;

	deplasari[2].x= 0; // Sud
	deplasari[2].x = 1; // y creste spre Sud

	deplasari[3].x = -1;// Vest – x scade spre Vest
	deplasari[3].y = 0;
}

int solutie(Coordonate_t c)
{
	if (c.x == 0 || c.y == 0 || c.x == N - 1 || c.y ==M - 1) //daca am ajuns la margine
		return 1;
	else
		return 0;
}

int acceptabil(Coordonate_t c)
{
	if (matrice[c.x][c.y] != -1 && c.x >= 0 && c.y >= 0 && c.x < N && c.y < M && vizitat[c.x][c.y]==0 && robot.energie>0) //daca este liber si coordonata se afla in dimensiunile matricei
		return 1;
	else return 0;
}

void afiseaza_solutia(int matrice[][M])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			printf("%d ", matrice[i][j]);
		printf("\n");
	}
	printf("\n");
}
void labirint()  //k pasul, c coordonata curenta
{
	int i; 
	Coordonate_t aux;
	if (solutie(robot.coordonataCurenta))        //solutie completa
		afiseaza_solutia(vizitat);
	else
	{
		for (i = 0; i < 4; i++)  // parcurgem pe rand posibilitatile
		{
			aux.x = robot.coordonataCurenta.x + deplasari[i].x;
			aux.y = robot.coordonataCurenta.y + deplasari[i].y;
			if (acceptabil(aux)) {//daca posibilitatea  e acceptabila
				int energieCurenta = robot.energie;

				robot.coordonataCurenta = aux;
				robot.energie += matrice[robot.coordonataCurenta.x][robot.coordonataCurenta.y];


				vizitat[robot.coordonataCurenta.x][robot.coordonataCurenta.y] = 1; //marcheaza ca vizitat
				labirint();     // back1(posibilitate_k+1)
				vizitat[robot.coordonataCurenta.x][robot.coordonataCurenta.y] = 1; //sterge marcajul ca vizitat

				robot.coordonataCurenta.x -= deplasari[i].x;
				robot.coordonataCurenta.y -= deplasari[i].y;
				robot.energie = energieCurenta;
			}
		}
	}
}   /*labirint*/

int main(void)
{
	initializare();

	robot.coordonataCurenta.x = 2;
	robot.coordonataCurenta.y = 2;
	robot.energie = 13;

	vizitat[robot.coordonataCurenta.x][robot.coordonataCurenta.y] = 1;

	labirint();
	return 0;
}