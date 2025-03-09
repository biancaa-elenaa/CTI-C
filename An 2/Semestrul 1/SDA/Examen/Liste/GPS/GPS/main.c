/*
* ra va avea următoarea componentă:

			Fiecare firmă de transport reprezintă o intrare separată într-o listă principală.

			Fiecare firmă de transport conține o listă secundară ordonată după codul GPS-urilor (corespunzătoare camioanelor fiecărei firme).

			Cel puțin una din liste va fi implementată dinamic.

	Funcționalități de implementat:
			Eliminare GPS: Se șterge un GPS identificat după cod din toate firmele.

			Să se aleagă un exemplu de listă care să cuprindă cel puțin 3 firme, fiecare cu cel puțin 5 GPS-uri.

			Să se reprezinte grafic structura multilistei pentru acest exemplu, înainte și după apelul funcției de eliminare GPS.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GPS {
	int cod;
	struct GPS* nextGPS;
}GPS_t;

typedef struct Firma {
	char nume[25];
	GPS_t* listaGPS;
	struct Firma* nextFirma;
}Firma_t;

typedef Firma_t* Multilista_t;

GPS_t* initGPS(int cod)
{
	GPS_t* gps = (GPS_t*)malloc(sizeof(GPS_t));

	if (gps == NULL)
	{
		printf("Eroare gps\n");
		return NULL;
	}

	gps->cod = cod;
	gps->nextGPS = NULL;

	return gps;
}

Firma_t* initFirma(char* nume)
{
	Firma_t* firma = (Firma_t*)malloc(sizeof(Firma_t));

	if (firma == NULL)
	{
		printf("Eroare firma\n");
		return NULL;
	}

	strcpy(firma->nume, nume);
	firma->listaGPS = NULL;
	firma->nextFirma = NULL;

	return firma;
}

void afisareFirma(Firma_t* firma)
{
	printf("Firma cu numele %s are urmatoarele GPS-uri: ", firma->nume);

	GPS_t* gps = firma->listaGPS;

	while (gps != NULL)
	{
		printf("%d ", gps->cod);
		gps = gps->nextGPS;
	}

	printf("\n__________________\n");
}

void adaugaGPSinFirma(GPS_t* gps, Firma_t* firma)
{
	if (firma->listaGPS == NULL)
	{
		firma->listaGPS = gps;
	}
	else
	{
		GPS_t* gpsCurent = firma->listaGPS;
		GPS_t* gpsAnt = NULL;

		//cautam unde trebuie pus 
		while (gpsCurent != NULL && (gps->cod > gpsCurent->cod))
		{
			gpsAnt = gpsCurent;
			gpsCurent = gpsCurent->nextGPS;
		}

		if (gpsAnt == NULL) //nu exista decat un element in lista
		{
			gps->nextGPS = gpsCurent;
			firma->listaGPS = gps;
		}
		else
		{
			gps->nextGPS = gpsCurent;
			gpsAnt->nextGPS = gps;
		}
	}
}

void adaugaFirmaInMultilista(Firma_t* firma, Multilista_t* multilista)
{
	if (*multilista == NULL){
	
		*multilista = firma;
		return;
	}

	Firma_t* fCurenta = *multilista;

	while (fCurenta->nextFirma != NULL)
	{
		fCurenta = fCurenta->nextFirma;
	}
	
	fCurenta->nextFirma = firma;

}

void afisareMultilista(Multilista_t *multilista)
{
	Firma_t* firma = *multilista;

	while (firma != NULL)
	{
		//printf("GBRGB");
		afisareFirma(firma);
		firma = firma->nextFirma;
	}
}

void eliminareGPS(Multilista_t* multilista, int cod)
{
	Firma_t* firmaCurenta = *multilista;

	while (firmaCurenta != NULL)
	{
		GPS_t* gpsCurent = firmaCurenta->listaGPS;
		GPS_t* gpsAnt = NULL;

		while (gpsCurent != NULL)
		{
			if (gpsCurent->cod == cod)
			{
				if (gpsAnt == NULL)
				{
					firmaCurenta->listaGPS = gpsCurent->nextGPS;
				}
				else
				{
					gpsAnt->nextGPS = gpsCurent->nextGPS;
				}
				free(gpsCurent);

				break;
			}
			gpsAnt = gpsCurent;
			gpsCurent = gpsCurent->nextGPS;
		}

		firmaCurenta = firmaCurenta->nextFirma;
	}
}

int main()
{
	Multilista_t multilista = NULL;

	Firma_t* f1 = initFirma("Firma1");
	Firma_t* f2 = initFirma("Firma2");

	adaugaGPSinFirma(initGPS(6), f1);
	adaugaGPSinFirma(initGPS(1), f1);
	adaugaGPSinFirma(initGPS(3), f1);
	adaugaGPSinFirma(initGPS(9), f1);

	adaugaGPSinFirma(initGPS(5), f2);
	adaugaGPSinFirma(initGPS(2), f2);
	adaugaGPSinFirma(initGPS(7), f2);
	adaugaGPSinFirma(initGPS(0), f2);

	//afisareFirma(f1);
	//afisareFirma(f2);

	adaugaFirmaInMultilista(f1, &multilista);
	adaugaFirmaInMultilista(f2, &multilista);

	afisareMultilista(&multilista);

	eliminareGPS(&multilista, 7);

	afisareMultilista(&multilista);

	

}