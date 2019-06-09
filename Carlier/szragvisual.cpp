// Schrage.cpp : Defines the entry point for the console application.
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int global=0;
int IleZadan, IleOperacji;
class Zadanie
{
public:
	int r, p, q;
	int nrZad;

	Zadanie()
	{
		r = 0;
		p = 0;
		q = 0;
		nrZad = 0;
	}
};

Zadanie rmax(vector<Zadanie> dane)
{
	Zadanie zad;
	int rMax = 0;
	for (int i = 0; i < dane.size(); i++)
	{
		if (rMax < dane[i].r)
		{
			zad = dane[i];
			rMax = dane[i].r;
		}

	}
	return zad;
}

int find(vector<Zadanie> dane, int nrZad)
{
	for (int i = 0; i < dane.size(); i++)
	{
		if (nrZad == dane[i].nrZad)
			return i;

	}
}

Zadanie rmin(vector<Zadanie> dane)
{
	int rMin = 10000;
	Zadanie zad;
	for (int i = 0; i < dane.size(); i++)
	{
		if (rMin >= dane[i].r)
		{
			zad = dane[i];
			rMin = dane[i].r;
		}

	}
	return zad;
}

Zadanie qmax(vector<Zadanie> dane)
{
	Zadanie zad;
	int qMax = 0;
	for (int i = 0; i < dane.size(); i++)
	{
		if (qMax < dane[i].q)
		{
			zad = dane[i];
			qMax = dane[i].q;
		}

	}
	return zad;
}

vector<Zadanie> Wczytaj_dane()
{

	ifstream data("in200.txt");
	data >> IleZadan;
	data >> IleOperacji;
	vector<Zadanie> dane(IleZadan);
	for (int i = 0; i < IleZadan; i++)
	{
		dane[i].nrZad = i + 1;
		data >> dane[i].r;
		data >> dane[i].p;
		data >> dane[i].q;
	}
	return dane;

}

int znajdz_max(int a, int b)
{
	return (a > b) ? a : b;
}
void wypisz(vector<Zadanie> dane)
{
	for (int i = 0; i < IleZadan; i++)
		cout << dane[i].nrZad << " ";
	cout << endl;
}

int Cmax(vector<Zadanie> dane)
{
	vector<int> zmienna2(IleZadan);
	vector<int> zmienna1(zmienna2.size() + 1);
	zmienna1[0] = 0;
	zmienna1[1] = znajdz_max(dane[0].r, 0 + 0);
	zmienna2[0] = zmienna1[1] + dane[0].p;
	for (int j = 2; j <= IleZadan; j++)
	{
		zmienna1[j] = znajdz_max(dane[j - 1].r, zmienna1[j - 1] + dane[j - 2].p);
		zmienna2[j - 1] = zmienna1[j] + dane[j - 1].p;
	}
	for (int i = 0; i < zmienna2.size(); i++)
	{
		zmienna2[i] = zmienna2[i] + dane[i].q;
	}
		vector<int>::iterator it = max_element(begin(zmienna2), end(zmienna2));
	int index = distance(zmienna2.begin(), it);
	return zmienna2[index];
}

int b(vector<Zadanie> dane)
{
	vector<int> zmienna2(IleZadan);
	vector<int> zmienna1(zmienna2.size() + 1);
	zmienna1[0] = 0;
	zmienna1[1] = znajdz_max(dane[0].r, 0 + 0);
	zmienna2[0] = zmienna1[1] + dane[0].p;
	for (int j = 2; j <= IleZadan; j++)
	{
		zmienna1[j] = znajdz_max(dane[j - 1].r, zmienna1[j - 1] + dane[j - 2].p);
		zmienna2[j - 1] = zmienna1[j] + dane[j - 1].p;
	}
	for (int i = 0; i < zmienna2.size(); i++)
	{
		zmienna2[i] = zmienna2[i] + dane[i].q;
	}
	vector<int>::iterator it = max_element(begin(zmienna2), end(zmienna2));
	int index = distance(zmienna2.begin(), it);
	return index;
}

int a(vector<Zadanie> dane)
{
	int aa=0;
	int zmienna2=0;
	zmienna2 =dane[0].r;
	for (int i = 1; i < dane.size(); i++)
	{
		zmienna2 = zmienna2 + dane[i-1].p;
		if (dane[i].r > zmienna2)
		{
			zmienna2 = dane[i].r;
			aa = i;
		}
		}
	return aa;
}


vector<Zadanie> Schrage(vector<Zadanie> dane)
{
	int i = 1;
	vector<Zadanie> Omega;
	vector<Zadanie> Ng(0);
	vector<Zadanie> Nn(IleZadan);
	Nn = dane;
	Zadanie j;
	int t = rmin(Nn).r;
	while (Ng.size() != 0 || Nn.size() != 0)
	{
		while (Nn.size() != 0 && rmin(Nn).r <= t)
		{
			j = rmin(Nn);

			Ng.push_back(j);
			Nn.erase(Nn.begin() + find(Nn, j.nrZad));

		}
		if (Ng.size() == 0)
			t = rmin(Nn).r;
		else
		{
			j = qmax(Ng);
			Ng.erase(Ng.begin() + find(Ng, j.nrZad));
			Omega.push_back(j);
			i++;
			t = t + j.p;
		}
	}
	return Omega;
}

int c(vector<Zadanie> dane,int a,int b)
{
	int cc = 999999;
	for (int i = a; i < b; i++)
		if (dane[i].q < dane[b].q)
		{
			cc = i;
		}
				return cc;
}


int Schragev2(vector<Zadanie> dane)
{
	int cmax = 0;
	vector<Zadanie> Ng(0);
	vector<Zadanie> Nn(IleZadan);
	Nn = dane;
	Zadanie j;
	Zadanie l;
	int t = 0;
	l.q = 9999;
	l.p = 0;

	while (Ng.size() != 0 || Nn.size() != 0)
	{
		while (Nn.size() != 0 && rmin(Nn).r <= t)
		{
			j = rmin(Nn);

			Ng.push_back(j);
			Nn.erase(Nn.begin() + find(Nn, j.nrZad));

			if (j.q > l.q)
			{
				l.p = t - j.r;
				t = j.r;

				if (l.p > 0)
				{
					Ng.push_back(l);
				}
			}
		}
		if (Ng.size() == 0)
			t = rmin(Nn).r;
		else
		{
			j = qmax(Ng);
			Ng.erase(Ng.begin() + find(Ng, j.nrZad));
			l = j;
			t = t + j.p;
			cmax = znajdz_max(cmax, t + j.q);
		}
	}
	return cmax;
}
bool koniec=false;
int UB = 999999;
vector<Zadanie> piG;

vector<Zadanie> Carlier(vector<Zadanie> dane)
{
	if (koniec == false)
	{
		int pom;
		int aa = a(Schrage(dane)), bb = b(Schrage(dane));
		int cc = c(Schrage(dane), aa, bb); //co to znaczy najwiekszy indeks?
		vector<int>K(dane.size());
		int LB;
		int rK = 999999, pK = 0, qK = 999999, hK;
		int rKc = 999999, pKc = 0, qKc = 999999, hKc;
		vector<Zadanie> pi = Schrage(dane);
		vector<Zadanie> daneOryginal=pi;
		int U = Cmax(pi);
		if (U < UB)
		{
			UB = U;
			piG = pi;
		}
		if (cc == 999999)
		{
			cout << UB << "  :  " << endl;
			koniec = true;
			return piG;
		}
		for (int i = cc + 1; i < bb + 1; i++) {
			K[i - (cc + 1)] = i;
			if (rK > pi[i].r)
				rK = pi[i].r;
			if (qK > pi[i].q)
				qK = pi[i].q;
			pK += pi[i].p;
		}
		pi[cc].r = znajdz_max(pi[cc].r, (rK + pK));
		LB = Schragev2(pi);
		hK = rK + pK + qK;

		for (int i = cc; i < bb + 1; i++) {
			K[i - (cc)] = i;
			if (rKc > pi[i].r)
				rKc = pi[i].r;
			if (qKc > pi[i].q)
				qKc = pi[i].q;
			pKc += pi[i].p;
		}
		hKc = rKc + pKc + qKc;
		pom = znajdz_max(hKc, hK);
		LB = znajdz_max(LB, pom);
		if (LB < UB)
		{
			Carlier(pi);
		}
		pi = daneOryginal; //odtworz rpic?
		pi[cc].q = znajdz_max(pi[cc].q, (qK + pK));
		LB = Schragev2(pi);
		pom = znajdz_max(hK, hKc);
		LB = znajdz_max(LB, pom);
		if (LB < UB)
		{
			Carlier(pi);
		}
		pi = daneOryginal; //odtworz qpic?
	}
	return piG;
}

int liczp(vector<Zadanie> dane)
{
	int suma=0;
	for (int i = 0; i < dane.size(); i++)
		suma = suma + dane[i].p;
	return suma;
}

int main()
{
	int probab=0;
	vector<Zadanie> dane;
	dane = Wczytaj_dane();
	cout << endl << "Cmax for Schrage: " << Cmax(Schrage(dane)) << endl;
	wypisz(Schrage(dane));
	cout << "Cmax for Schrage pmtn:" << Schragev2(dane) << endl;
	cout << "a: " << a(Schrage(dane)) << endl;
	cout << "b:" << b(Schrage(dane)) << endl;
	cout << "c: " << c(Schrage(dane), a(Schrage(dane)), b(Schrage(dane))) << endl;
	cout << "kolejnosc Caliera: ";
	wypisz(Carlier(dane));
	cout << "Cmax Caliera: ";
	cout<<Cmax(Carlier(dane)) << endl;
	cout << "gotowe" << endl;
}