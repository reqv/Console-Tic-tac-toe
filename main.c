#include "gra.h"
#include "komputer.h"
#include "dodatki.h"

#define c system("cls");	//definiuje ze zamiast "c" wstawi "system("cls");" czyli czysci ekran
#define p getchar();	//definiuje ze zamiast "p" wstawi "getchar();" czyli zatrzyma program

//Glowne
void gra(int graczy); //uruchamia gre
void autor(void); //wyswietla informacje o autorze

//######################################################################## MAIN

int main()  //tylko menu
{
    int wybor=0;    //zmienna do wyboru opcji w menu
    srand(time(0));	//inicjuje losowanie na podstawie czasu
    do{
        c;	//clear
        printf("Kolko i Krzyzyk\n");	//wypisuje na ekran
        printf("----------------\n\n");
        printf("1)Gra z komputerem \n2)Gra z kumplem \n3)O autorze \n0)Koniec \n\nWybierasz : ");
        scanf("%d",&wybor);		//wczyta wybor od uzytkownika
        switch(wybor)
        {
            case 1:gra(1); break;	// 1 - gra z 1 graczem
            case 2:gra(2); break;	// 2 - gra z 2 graczami
            case 3:autor(); break;	// 3 - wczytanie funkcji autor
            default:wybor=0;	//automatycznie wybor = 0
        }
    }while(wybor!=0);   //zwalnia menu jezeli wybor = 0
    return 0;
}
//######################################################################## Funkcje Glowne

void gra(int graczy)
{
    int n;  //przechowuje wielkosc mapy
    int x,y,licznik=0,kto,win=0;    //x,y pozycja do wstawienia X lub O,   licznik tur,   kogo tura,   kto wygral
    char** tab;     // pole gry
    char gracz1[50],gracz2[50]="Komputer",znak;     //imiona graczy i pole przechowujace aktualny znak (X,O)
    printf("wielkosc mapy: ");	//pyta o wielkosc mapy
    scanf("%d",&n);		//wczytuje ta wartosc
    printf("Imie pierwszego gracza: ");	//pyta o imie 1 gracza
    scanf("%s",gracz1);
    if(graczy > 1)      //jezeli graczy jest wiecej niz 1 zmieniamy imie 2 gracza
    {
        printf("Imie drugiego gracza: ");	//pyta o imie 2 gracza
        scanf("%s",gracz2);
        log("\n\n========= Nowa gra na dwoch graczy =========\n");	//zapisuje do pliku
    }
    else
        log("\n\n========= Nowa gra z komputerem =========\n");		//jezeli 1 gracz to to zapisuje do pliku
    log("Aktualny czas i data:");   //zapisywanie danych do pliku
    log(czas());
    log("Wielkosc mapy:");
    log(intToStr(n));
    log("\n\n");
    tab = przydziel(n);     //przydzielanie odpowiedniej ilosci pamieci
    zapchaj(tab,n);         //zapychanie pola pustymi znakami
    kto = los(1,2);         //losowanie gracza ktory rozpocznie rozgrywke
    while( (licznik != n*n) && (win == 0 )) //gra toczy sie do wyczerpania pul lub do zwyciestwa
    {
        c;	//clear
        if(kto == 1)kto = 2;    //zamiana gracza	(jak 1 to 2 jak 2 to 1)
        else
            kto = 1;
        printf("TURA: %i\n\nGracz 1: %s\nGracz 2: %s\n",licznik+1,gracz1,gracz2);   //wyrysowanie elementow...
        rysuj(tab,n);       //...wraz z polem gry
        znak = 'X';         //aktualny znak ustawia sie na X
        if((kto == 1) || ((kto == 2) && (graczy > 1)))  //jezeli kolej ktoregos z graczy
            do
            {
                printf("Kolej gracza: ");	//wypisuje
                if(kto == 1)            //gracz 1   wybiera pole
                {
                    log(gracz1);	//nazwa gracza do pliku
                    znak = 'O';		//zmiana znaku na "O"
                    printf("%s\n",gracz1);
                    printf("wybierasz pole: ");		//wczytanie pola od gracza
                    scanf("%i%i",&x,&y);
                }
                    else        //jezeli nie gracz 1 to gracz 2
                        {
                            log(gracz2);	//nazwa gracza do pliku
                            printf("%s\n",gracz2);
                            printf("wybierasz pole: ");		//wczytanie pola od gracza
                            scanf("%i%i",&x,&y);
                        }
                if(x < 0)x = -x;    //jezeli podal ujemne pola... to staja sie dodatnie
                if(y < 0)y = -y;
            }while((x > n) || (y > n) || (tab[x][y] != ' '));   //sprawdzenie czy pole jest prawidlowe
        else    //  jezeli nie kolej graczy to kolej komputera
            komputer(tab,n,&x,&y);	//wybor pola przez komputer
        tab[x][y] = znak;   //wstawienie znaku na pole
        win = sprawdzenie(tab,n,znak);  //sprawdzenie zwyciestwa
        log("zajmuje pole:");       //zapis kolejnych danych do pliku
        log(intToStr(x));
        log(intToStr(y));
        rysujdopliku(tab,n);    //zapis tablicy do pliku
        log("\n");
        licznik++;      // tura + 1
    }
    c;
    switch(win)     //sprawdza jak zakonczyla sie gra
    {	// 0 - remis, 1 i 2 - wygrana odpowiedniego gracza
        case 0:printf("Remis!\n\nNacisnij enter, aby kontynuowac...\n"); log("Gra zakonczona remisem!"); p; p; break;	//wypisanie na ekran i do pliku oraz zatrzymanie programu
        case 1:printf("Wygral gracz %s!\n\nNacisnij enter, aby kontynuowac...\n",gracz1); log("Gra wygrana przez gracza"); log(gracz1); p; p; break;
        case 2:printf("Wygral gracz %s!\n\nNacisnij enter, aby kontynuowac...\n",gracz2); log("Gra wygrana przez gracza"); log(gracz2); p; p; break;
        default:printf("Remis!\n\nNacisnij enter, aby kontynuowac...\n");
    }
    czysc(tab,n);   //zwalnia wczesniej przydzielona pamiec
    c;
}

void autor()
{
    c;
    printf("autor: Patryk Kosiorek\n");	//wypisanie autora
    p; p;
}
