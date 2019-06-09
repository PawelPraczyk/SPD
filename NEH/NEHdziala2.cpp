#include <iostream>
#include <fstream>
#include <cstdlib>
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

void SzeregowanieNEH(int maszyna[100][100],int NEH[100])
//LICZENIE SUMY CZASOW NA WSZYSTKICH MASZYNACH
{
	//cout<<"Kolejnosc Wykonywania zadan: ";
	int NEHsuma[IleZadan],suma=0,zamiana,iZ[IleZadan];
	int **m;
	m=new int *[IleMaszyn];
	for(int i=0;i<IleZadan;i++)
	new int[IleZadan];
	for(int i=0;i<IleZadan;i++)
	{
	for(int k=0;k<IleMaszyn;k++)
	{
		suma+=maszyna[k][i];
	}
	NEHsuma[i]=suma;
	NEH[i]=i;
	suma=0;
}
//SORTOWANIE BABELKOWE WARTOSCI WRAZ Z INDEKSAMI
for(int i=0;i<IleZadan;i++)
{
for(int k=1;k<IleZadan;k++)
{

		if(NEHsuma[k-1]<=NEHsuma[k])
		{
			zamiana=NEH[k];
			NEH[k]=NEH[k-1];
			NEH[k-1]=zamiana;

			zamiana=NEHsuma[k];
			NEHsuma[k]=NEHsuma[k-1];
			NEHsuma[k-1]=zamiana;
		}
}

}

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
        printf("%d%c", t[i],  ' ' );
    printf("\n");
}

void WczytanieDanych(int maszyna[100][100])
{

	ifstream data("data.txt");
	data >> IleZadan;
	data >> IleMaszyn;
	for(int i=0;i<IleZadan;i++)
	for(int k=0;k<IleMaszyn;k++)
	data>>maszyna[k][i];
}
int LiczCzas2(int maszyna[100][100],int indexZadan[100],int IloscZadan)
{
	int iZ[100],m[100][100];

	int Odblokuj[100][100],done[100][100],zajeta[100],gotowe=0,iloscgotowych[100];

	for(int i=0;i<IloscZadan;i++)
	{
	iZ[i]=indexZadan[i];
}
	for (int i=0;i<IloscZadan;i++)
	for (int k=0;k<IleMaszyn;k++)
	{
		m[k][i]=maszyna[k][iZ[i]];
	}



	for(int k=0;k<IleMaszyn;k++)
{
	iloscgotowych[k]=0;
}

	for(int i=0;i<IloscZadan;i++)
	for(int k=0;k<IleMaszyn;k++)
	{
		done[k][i]=0;
		Odblokuj[k][i]=0;
		zajeta[k]=0;
	}

	for (int AktualnyCzas=0;AktualnyCzas!=-1;AktualnyCzas++)
	{
		for(int i=0;i<IloscZadan;i++)
		for(int k=0;k<IleMaszyn;k++)
		{
			if(k==0)
			{
				if(i==0)
				if(Odblokuj[k][i]==0 && zajeta[k]<=AktualnyCzas)
			{

			Odblokuj[k][i]=1;
			zajeta[k]=m[k][i];

			}
				if(i!=0)
			    if(done[k][i-1]==1 && Odblokuj[k][i]==0 && zajeta[k]<=AktualnyCzas)
			{

			Odblokuj[k][i]=1;
			zajeta[k]=AktualnyCzas+m[k][i];

			}
		}
			if(k!=0)
			{
		if(i==0)
		if(done[k-1][i]==1 && Odblokuj[k][i]==0 && zajeta[k]<=AktualnyCzas)
	{

			Odblokuj[k][i]=1;
			zajeta[k]=AktualnyCzas+m[k][i];

}
		if(i!=0)
		if(done[k-1][i]==1 && done[k][i-1] && Odblokuj[k][i]==0 && zajeta[k]<=AktualnyCzas)
	{

			Odblokuj[k][i]=1;
			zajeta[k]=AktualnyCzas+m[k][i];

}

}
}

for(int i=0;i<IloscZadan;i++)
{
for(int k=0;k<IleMaszyn;k++)
{
	if(zajeta[k]==AktualnyCzas+1)
{
	if(k==0)
	if(i==0)
	{
	done[0][0]=1;
	Odblokuj[k][i]=2;
	gotowe=1;
	iloscgotowych[k]++;
}

if(k!=0)
if(i==0)
{
	done[k][0]=1;
	Odblokuj[k][0]=2;
	gotowe=1;
	iloscgotowych[k]++;
}

if(Odblokuj[k][i]==1)
{
	done[k][i]=1;
	Odblokuj[k][i]=2;
	gotowe=1;

	iloscgotowych[k]++;
}

}
gotowe=0;
}
if(done[IleMaszyn-1][IloscZadan-1]==1)
{
gotowe=AktualnyCzas+1;
AktualnyCzas=-2;
return gotowe;
}
}

}

}

	void WyswietlPermutacje(int N,int a[100][100],int t[100])
	{
		for (int i = 0; i < N; i++)
    {
        t[i] = i; // tu wrzuciæ pokolei jak lec¹  z pliku, teraz dalem przyk³adowo od 1 do N
    }


        cout<<"czas wykonania kolejno zadan: ";
        wypisz(t, N);
        cout<<"wynosi: ";
        cout<<LiczCzas2(a,t,N);
        cout<<endl;
    	for (int i = 0; i < silnia(N) - 1; i++)
            {
        permutacja(t, N);
        cout<<"czas wykonania kolejno zadan: ";
        wypisz(t, N);
        cout<<"wynosi: ";
        cout<<LiczCzas2(a,t,N);
        cout<<endl;
    }
	}
	int NEH(int a[100][100],int gotowyindex2[100])
	{
	    int Cmax=9999,gotowyindex[100],cmax=9999,gotowyindex3[100],index[100];
	    SzeregowanieNEH(a,index);
	    gotowyindex[0]=index[0];

	    for(int i=0;i<IleZadan;i++)
        {
            cmax=99999;
            gotowyindex3[i]=index[i];
        for(int j=0;j<i;j++)
        gotowyindex3[j]=gotowyindex2[j];

        if(i==0)
        gotowyindex2[0]=index[0];

        if(i!=0)
        for(int j=0;j<=i;j++)
        {
            for(int l=0;l<j;l++)
            gotowyindex[l]=gotowyindex3[l];

            gotowyindex[j]=gotowyindex3[i];
            for(int l=j;l<i;l++)
            gotowyindex[l+1]=gotowyindex3[l];

            if(cmax>LiczCzas2(a,gotowyindex,i+1))
            {

                cmax=LiczCzas2(a,gotowyindex,i+1);
                for(int l=0;l<=i;l++)
                gotowyindex2[l]=gotowyindex[l];
            }
        }
        }
return cmax;
}
void menu(int maszyna[100][100])
{
    int menuz=99,index[100];
    while(menuz!=0)
{
cout<<"0- wyjdz"<<endl;
cout<<"1- wyswietl Cmax dla NEH"<<endl;
cout<<"2- wyswietl kolejnosc NEH"<<endl;
cout<<"3- wyswietl permutacje (UWAGA NA ZBYT DUZA ILOSC ZADAN)"<<endl;
cout<<"4- wyswietl Cmax dla kolejnosci naturalnej (0,1,2,3...)"<<endl;
cout<<"5- wyswietl czas wszystkich zadan"<<endl;
cin>>menuz;
system("cls");
if(menuz==1)
cout<<"Cmax dla NEH wynosi:"<<NEH(maszyna,index)<<endl;
if(menuz==2)
{
    cout<<"KOLEJNOSC WYKONYWANIA ZADAN, PRZEZ ALGORYTM NEH: "<<endl;
    NEH(maszyna,index);
    for(int i=0;i<IleZadan;i++)
    cout<<index[i]<<", ";
    cout<<endl;
}
if(menuz==3)
WyswietlPermutacje(IleZadan,maszyna,index);
if(menuz==4)
{
for(int i=0;i<IleZadan;i++)
index[i]=i;
cout<<"Cmax dla kolejnosci naturalnej wynosi: "<<LiczCzas2(maszyna,index,IleZadan)<<endl;
}
if(menuz==5)
    for(int i=0;i<IleZadan;i++)
{
    for(int k=0;k<IleMaszyn;k++)
    cout<<maszyna[k][i]<<"    ";
    cout<<endl;
}
cout<<endl<<endl;
}
}
int main()
{
int a[100][100];
WczytanieDanych(a);
menu(a);
return 0;
}
