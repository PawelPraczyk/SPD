// Permutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <fstream>
using namespace std;
int IleZadan;
int IleMaszyn;
//////////////////////////////
long long silnia(int max)
{
	long long sil = 1;

	for (int i = max; i > 1; i--)
		sil = sil * i;

	return sil;
}


void permutacja(int t[], int max)
{
	int i, j, k;

	if (max <= 1)
		return;

	i = max - 1;
	while ((i > 0) && (t[i - 1] >= t[i]))
		i--;

	if (i > 0) {
		j = max;
		while ((j > 0) && (t[j - 1] <= t[i - 1]))
			j--;
	}

	if ((i > 0) && (j > 0)) {
		k = t[i - 1];
		t[i - 1] = t[j - 1];
		t[j - 1] = k;
	}

	for (i++, j = max; i < j; i++, j--) {
		k = t[i - 1];
		t[i - 1] = t[j - 1];
		t[j - 1] = k;
	}
}

void wypisz(int t[], int max)
{
	int i;

	for (i = 0; i < max; i++)
		printf("%d%c", t[i], ' ');
	printf("\n");
}


/////////////////////////////////
void WczytanieDanych(int maszyna[100][100])
{

	ifstream data("data.txt");
	data >> IleZadan;
	//cout<<"ilezadan"<<IleZadan<<endl;
	data >> IleMaszyn;
	//cout<<"IleMaszyn"<<IleMaszyn<<endl;
	for (int i = 0; i<IleZadan; i++)
		for (int k = 0; k<IleMaszyn; k++)
			data >> maszyna[k][i];
}
void WszystkieMozliwosci(int maszyna[100][100], int indexZadan[100])
{
	int iZ[100];
	int m[100][100];
	int czasC = 0, czas1 = 0, czas2 = 0, roznica, opoznienie = 0;
	for (int i = 0; i<IleZadan; i++)
		iZ[i] = indexZadan[i] - 1;

	for (int i = 0; i<IleZadan; i++)
		for (int k = 0; k<IleMaszyn; k++)
		{
			m[k][i] = maszyna[k][iZ[i]];
		}

	for (int i = 0; i<IleZadan; i++)
	{
		czas2 = czas1 + m[1][i - 1];
		czas1 += m[0][i];
		//cout<<"index"<<iZ[i]<<endl;
		roznica = czas2 - czas1;
		opoznienie += roznica;
		//  cout<<opoznienie<<","<<endl;
		if (opoznienie<0)
			opoznienie = 0;


		//if(i==IleZadan-1)
		//opoznienie+=maszyna2[i];

	}

	//cout<<czas1<<endl;
	cout << czas1 + opoznienie + m[1][IleZadan - 1] << endl;
}




int main()
{
	int a[100][100];
	WczytanieDanych(a);
	//#define N 4 // podać liczbę z pliku dacnych
	int N = IleZadan;
	int t[N];
	int i, j;

	for (int i = 0; i < N; i++)
	{
		t[i] = i + 1; // tu wrzucić pokolei jak lecą  z pliku, teraz dalem przykładowo od 1 do N
	}


	cout << "czas wykonania kolejno zadan: ";
	wypisz(t, N);
	cout << "wynosi: ";
	WszystkieMozliwosci(a, t);
	cout << endl;
	for (i = 0; i < silnia(N) - 1; i++) {
		permutacja(t, N);
		cout << "czas wykonania kolejno zadan: ";
		wypisz(t, N);
		cout << "wynosi: ";
		WszystkieMozliwosci(a, t);
		cout << endl;
	}
	//cout<<a[0][0]<<","<<a[1][0]<<","<<a[2][0]<<","<<a[3][0];
	return 0;
}