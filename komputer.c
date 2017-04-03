#include "dodatki.h"
#include "komputer.h"

void komputer(char** t,int n,int *x,int *y)
{   int i,j;	//petla
    int licz1=0,licz2=0,liczx1=0,liczx2=0;	//sprawdzanie pionu i poziomu obu graczy
    int skos1=0,skos2=0,skosx1=0,skosx2=0;	//sprawdzanie skosu
    log("Komputer");	//zapis gracza do pliku
    //******************************************************* Faza I - dobijanie
	//czyli oblicza czy moze wygrac 1 ruchem
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(t[i][j] == 'O')licz1++;     //naliczanie poziomu
            if(t[j][i] == 'O')licz2++;     //naliczanie pionu
            if(t[i][j] == 'X')liczx1++;     //naliczanie poziomu
            if(t[j][i] == 'X')liczx2++;     //naliczanie pionu

            if((i == j) && (t[i][j] == 'O'))skos1++;   //naliczanie skosu od lewej
            if((i+j+1 == n) && (t[i][j] == 'O'))skos2++;   //naliczanie skosu od prawej
            if((i == j) && (t[i][j] == 'X'))skosx1++;   //naliczanie skosu od lewej
            if((i+j+1 == n) && (t[i][j] == 'X'))skosx2++;   //naliczanie skosu od prawej
        }
        if(liczx1 == n-1 && licz1 == 0)   //sprawdzenie poziomo,czy jest szansa na zwyciestwo
        {
            *x=i;	//x jest staly
            do{
                *y=los(0,n);
            }while(t[*x][*y] != ' ');   //petla sprawdzajaca poprawnosc wyboru
            return;
        }
        else	//inaczej zeruje
        {
            licz1=0;
            liczx1=0;
        }
        if(liczx2 == n-1 && licz2 == 0)   //sprawdzenie pionowo
        {
            *y=i;	//y jest staly
            do{
                *x=los(0,n);
            }while(t[*x][*y] != ' ');	//petla sprawdzajaca poprawnosc wyboru
            return;
        }
        else	//inaczej zeruje
        {
            licz2=0;
            liczx2=0;
        }
    }
    if(skosx1 == n-1 && skos1 == 0) //sprawdzanie skosu od lewej
    {
        do{
            *x=los(0,n);	//y i x musza byc takie same
            *y=*x;
        }while(t[*x][*y] != ' ');	//petla sprawdzajaca poprawnosc wyboru
        return;
    }
    if(skosx2 == n-1 && skos2 == 0) //sprawdzanie skosu od prawej
    {
        do{
            *x=los(0,n);	//y + x musza dawac n-1
            *y=n-*x-1;
        }while(t[*x][*y] != ' ');	//petla sprawdzajaca poprawnosc wyboru
        return;
    }
    //******************************************************* Faza II - obrona
	//czyli oblicza czy przeciwnik moze wygrac 1 ruchem i go blokuje
	//nie trzeba tu obliczac skosow bo mozna uzyc te z poprzedniej fazy
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(t[i][j] == 'O')licz1++;     //naliczanie poziomu
            if(t[j][i] == 'O')licz2++;     //naliczanie pionu
            if(t[i][j] == 'X')liczx1++;     //naliczanie poziomu
            if(t[j][i] == 'X')liczx2++;     //naliczanie pionu
        }
        if(liczx1 == 0 && licz1 == n-1)   //sprawdzenie poziomo czy przeciwnik ma szanse na wygrana
        {
            *x=i;
            do{
                *y=los(0,n);
            }while(t[*x][*y] != ' ');
            return;
        }
        else
        {
            licz1=0;
            liczx1=0;
        }
        if(liczx2 == 0 && licz2 == n-1)   //sprawdzenie pionowo
        {
            *y=i;
            do{
                *x=los(0,n);
            }while(t[*x][*y] != ' ');
            return;
        }
        else
        {
            licz2=0;
            liczx2=0;
        }
    }
    if(skosx1 == 0 && skos1 == n-1) //skos1
    {
        do{
            *x=los(0,n);
            *y=*x;
        }while(t[*x][*y] != ' ');
        return;
    }
    if(skosx2 == 0 && skos2 == n-1) //skos2
    {
        do{
            *x=los(0,n);
            *y=n-*x-1;
        }while(t[*x][*y] != ' ');
        return;
    }
    //******************************************************* Faza III - budowa ataku
	//oblicza gdzie najlepiej zajmowac pola jezeli faza 1,2 nie doprowadzila do zakonczenia tury
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(t[i][j] == 'O')licz1++;     //naliczanie poziomu
            if(t[j][i] == 'O')licz2++;     //naliczanie pionu
            if(t[i][j] == 'X')liczx1++;     //naliczanie poziomu
            if(t[j][i] == 'X')liczx2++;     //naliczanie pionu
        }
        if(liczx1 == n/2 && licz1 == 0)   //sprawdzenie poziomo gdzie najlepiej zaatakowac
        {
            *x=i;
            do{
                *y=los(0,n);
            }while(t[*x][*y] != ' ');
            return;
        }
        else
        {
            licz1=0;
            liczx1=0;
        }
        if(liczx2 == n/2 && licz2 == 0)   //sprawdzenie pionowo
        {
            *y=i;
            do{
                *x=los(0,n);
            }while(t[*x][*y] != ' ');
            return;
        }
        else
        {
            licz2=0;
            liczx2=0;
        }
    }
    if(skosx1 == n/2 && skos1 == 0)
    {
        do{
            *x=los(0,n);
            *y=*x;
        }while(t[*x][*y] != ' ');
        return;
    }
    if(skosx2 == n/2 && skos2 == 0)
    {
        do{
            *x=los(0,n);
            *y=n-*x-1;
        }while(t[*x][*y] != ' ');
        return;
    }
    do
    {   //jezeli zadna faza nie odniosla sukcesu losuje pole do zajecia
        *x=los(0,n);
        *y=los(0,n);
    }while(t[*x][*y] != ' ');	//petla sprawdzajaca poprawnosc wyboru
}
