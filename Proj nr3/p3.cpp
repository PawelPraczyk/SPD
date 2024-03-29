// NEHU.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <math.h> 
#include <iostream>
#include <fstream>
using namespace std;
int IleZadan;
int IleMaszyn;
float StartTemperature = 10000;
float StopTemaperature = 1;
float p, s = 0;

int a[100][100];
int pi[100];
int piprim[100];

void WczytanieDanych()
{
	int l = 1;
	ifstream data("data.txt");
	data >> IleZadan;
	data >> IleMaszyn;
	for (int i = 0; i < IleZadan; i++)
	{
		for (int k = 0; k<IleMaszyn; k++)
			data >> a[k][i];
		
		
	}
	


	for (int i = 0; i < IleZadan; i++)
	{
		for (int j= 0; j < IleMaszyn; j++)
			cout << a[j][i] << " ";
		cout << endl;
		
	}
}

int cmaxpi()
{
	int czas =0;
	int tab[100][100];
	for (int i = 1; i<IleMaszyn + 1; i++)
		for (int j = 1; j<IleZadan + 1; j++)
			//max(element poprzedni, element z góry)+wartość w tym
			//punkcie, (tablica danych indeksowana odwrotnie oraz
			//bez zerowego wiersza i kolumny
			tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]) + a[pi[j - 1] - 1][i - 1];
	czas = tab[IleMaszyn][IleZadan];
	//cout << Cmax<<' ';
	return czas;
}



int cmaxpiprim()
{
	int czas = 0;
	int tab[100][100];
	for (int i = 1; i<IleMaszyn + 1; i++)
		for (int j = 1; j<IleZadan + 1; j++)
			//max(element poprzedni, element z góry)+wartość w tym
			//punkcie, (tablica danych indeksowana odwrotnie oraz
			//bez zerowego wiersza i kolumny
			tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]) + a[piprim[j - 1] - 1][i - 1];
	czas = tab[IleMaszyn][IleZadan];
	//cout << Cmax<<' ';
	return czas;
}


void Move()
{
	int a, b;
	a = rand() % IleZadan;
	b = rand() % IleZadan;
	swap(piprim[a], piprim[b]);
}

void Check()
{
	
	if (cmaxpi() <= cmaxpiprim())
		p = exp((cmaxpiprim() - cmaxpi()) / StartTemperature);
	else
		p = 1;
	s = ((float)rand() / (RAND_MAX));
	if (p >= s)
		for (int i = 0; i < IleZadan; i++)
			pi[i] = piprim[i];
	else
		for (int i = 0; i < IleZadan; i++)
			piprim[i] = pi[i];

	StartTemperature = StartTemperature * 0.99; 

	cout << "Cmax: " << cmaxpi()<<" ";
}

void WypiszKolej()
{

	cout << " Kolejnosc: ";
	for (int i = 0; i < IleZadan; i++)
		cout << pi[i] << " ";
	cout << "P = " << p <<endl;

}

int main()
{
	WczytanieDanych();

	for (int i = 0; i < IleZadan; i++)
	{
		pi[i] = i + 1;
		piprim[i] = i + 1;
	}

	while (StartTemperature > StopTemaperature)
	{
		Move();
		Check();
		WypiszKolej();
	}



	return 0;
}