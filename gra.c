#include "gra.h"


void rysuj(char **t,int n)
{
    int i,j;	//dla for`a
    linia(n*7+n);   //rysuje linie pozioma - wielkosc zalezy od wielkosci pola
    for(i=0;i<n;i++)	//petla od 0 do n-1
    {
        for(j=0;j<n;j++)	//taka sama petla
        {
            if(t[i][j] != ' ')printf("   %c   ",t[i][j]);   //jezeli pole ma jakis znak to go wypisuje
            else
            printf(" %2i%3i ",i,j);     //inaczej wypisuje numer pola
            if(j < n-1)printf("|");     //rysuje linie pionowe
        }
        printf("\n");	//jezeli koniec lini to przechodzi do nastepnej
        linia(n*7+n);	//rysuje linie pozioma
    }
}

char** przydziel(int n)
{
    char** t;	//deklaracja wskaznika
    int i;	//do petli
    t = (char **)malloc(sizeof(char *) * n);    //tworzy tablice jednowymiarowa o wielkosci chara*n
    for(i=0;i<n;i++)
        t[i] = (char*)malloc(sizeof(char) * n);     //tworzy tablice 2-wymiarowa
    return t;   //zwraca tablice
}

void czysc(char** t,int n)
{   int j;	//do for`a
    for(j=0;j<n;j++)    //zwalnianie pamieci w sposob odwrotny (tzn. najpierw 2-wymiar)
        free(t[j]);
    free(t);
}

void zapchaj(char** t,int n)
{
    int i,j;	//do petli
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            t[i][j]=' ';    //zapychanie kazdego pola przez ' ', aby pousuwac smieci z pamieci
}

int los(int s,int k)	//s - od , k - do
{
    int l;	//zmienna na liczbe
    l = s + rand()%k;   //losuje z przedzialu od s do k
    return l;       // i zwraca
}

int sprawdzenie(char** t,int n,char znak)	//zwraca numer gracza ktory wygral lub 0 jezeli nikt nie wygral
{
    int gracz = 1,i,j;	// zmienna na gracza i zmienne na petle
    int licz1 = 0,licz2 = 0;	// zmienne na pion i poziom
    int skos1 = 0,skos2 = 0;	//zmienne na skosy
    if(znak == 'X')gracz = 2;   //jaki gracz jest sprawdzany
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(t[i][j] == znak)licz1++;     //naliczanie poziomu
            if(t[j][i] == znak)licz2++;     //naliczanie pionu
            if((i == j) && (t[i][j] == znak))skos1++;   //naliczanie skosu od lewej
            if((i+j+1 == n) && (t[i][j] == znak))skos2++;   //naliczanie skosu od prawej
        }
        if((licz1 == n) || (licz2 == n))return gracz;   //sprawdzenie poziomo i pionowo
        else    //jak nie ma to zeruje poziom i pion...
        {
            licz1 = 0;
            licz2 = 0;
        }
    }
    if((skos1 == n) || (skos2 == n))return gracz;   //sprawdzenie skosow
    return 0;
}
