#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>

using namespace std;

struct rekord
  {
      char znak;
      int liczba;
  };

const int n=5;

void wypelnianie(rekord T[][n], char min, char max, int mini, int maxi)
{
    srand(time(NULL));

    for (int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            T[i][j].znak=rand()%(max-min+1)+min;
            T[i][j].liczba=rand()%(maxi-mini+1)+mini;
        }
    }
}

void wymiana(rekord T[][n], int ktory)
{   int k, najwiekszy;
    rekord temp;
    for(int i=1; i<n; i++)
    {   najwiekszy=0;
        for(int j=0; j<i; j++)
        {

            if(T[i][j].znak+T[i][j].liczba>najwiekszy)
            {
                najwiekszy=(T[i][j].znak+T[i][j].liczba);
                k=j;

            }


        }
    temp=T[i][k];
    T[i][k]=T[i][ktory];
    T[i][ktory]=temp;
    }


}


void drukowanie(rekord T[][n],string napis)
{
    cout <<endl<<endl<< "Tablica "<< napis<<endl;
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << setw(8)<< T[i][j].znak<< "  "<< T[i][j].liczba;
        }
        cout <<endl;
    }
}


int main()
{
    rekord A[n][n], B[n][n];

    wypelnianie(A, 97,122,-9,9);
    wypelnianie(B,48,57,10,99);


    drukowanie(A,"A");
    drukowanie(B,"B");

    wymiana(A,n-1);
    wymiana(B,n-2);


    drukowanie(A,"A");
    drukowanie(B,"B");


    return 0;
}
