#ifndef __PROIECT_H
#define __PROIECT_H

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>


int* makeRandArray(int);

int* makeRandLimitArray(unsigned , int , int );

int getNewElem_asc(int *,unsigned );

int* makeRandFlexiArray(unsigned ,int (*)(int* ,unsigned));

void print_array_csv(int *,int, char *);

void print_array(int *,int);

double* distributia_Gauss(int ,double ,double);

int* distributia_Poisson(int,double );

void print_double_array_csv(double *,int,char *);

#endif