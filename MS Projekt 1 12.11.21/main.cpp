//Zadanie – Dla zadanej tablicy liczb ca³kowitych znajdŸ maksymalny iloczyn dwóch elementów znajduj¹cych siê w tablicy.
//Przyk³ad:
//Wejœcie: A[] = [-10,5,8,-4,1]
//Wyjœcie: Czynniki generuj¹ce najwiêkszy iloczyn to pary: [-10,-4] oraz [5,8]


#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>
using namespace std;

void quicksort(int *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while(tablica[i]>v) i++;
        while(tablica[j]<v) j--;
        if(i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j>lewy) quicksort(tablica,lewy, j);
    if(i<prawy) quicksort(tablica, i, prawy);
}

int main()
{
    fstream dane, wyniki;
    int *tab, n;
    double a, czas;
    long iloczynMax;
    clock_t start, stop;

    dane.open("dane.txt", ios::in);
    wyniki.open("wyniki.txt", ios::out);
    if(dane.good()==false)
    {
        cout << "Plik dane.txt nie istnieje! Dolacz plik do folderu projektu i sprobuj ponownie.";
        return 0;
    }
    cout<<"Ile liczb znajduje sie w tablicy? ";
    cin>>n;

    tab = new int [n];

    start = clock();
    for(int i=0; i<n; i++)
    {
        dane>>a;
        tab[i]=a;
    }

    quicksort(tab, 0, n-1);

    cout << endl;
    iloczynMax = tab[0] * tab[1];
    cout << "Maksymalny iloczyn: " << iloczynMax << endl;

    cout << "Pary liczb generujace najwiekszy iloczyn: " << endl;
    wyniki << "Pary liczb generujace najwiekszy iloczyn: " << endl;
    for (int i=1; i<n; i++)
    {
        if (tab[i-1]*tab[i]==iloczynMax)
        {
            cout << tab[i-1] << " " << tab[i] << endl;
            wyniki << tab[i-1] << " " << tab[i] << endl;
        }
    }
    stop = clock();
    czas = (double)(stop - start)/CLOCKS_PER_SEC;
    cout << "Czas pracy programu: " << czas << endl;
    return 0;
}
