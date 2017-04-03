#include "dodatki.h"
//######################################################################## Funkcje Dodatkowe

void linia(int l)
{
    int i;	//petla
    for(i = 0;i < l;i++)
        printf("-");        //rysuje l razy '-'
    printf("\n");			//na koniec lamie linie
}

char* intToStr(int n)
{
     int i = 0;	//petla
     char *tmp = (char*)malloc(23);		//tworzy zmienne pomocnicze i przydziela im pamiec
     char *ret = (char*)malloc(23);
     if(n < 0) {        //zamiana ujemnej na dodatnia i wypisanie znaku '-' jezeli byla ujemna
          *ret = '-';
          i++;
          n = -n;
     }
     do {
          *tmp = n % 10 + 48;   //zamiana kazdej cyfry na string
          n -= n % 10;
          if(n > 9) *tmp++;
     }
     while(n /= 10);    //dopoki sa cyfry do zamiany
     while(ret[i++] = *tmp--);      //ustalanie dlugosci ciagu
     i-=2;          //korekta
     ret[i]='\0';   //korekta 2	(pokazanie gdzie jest koniec ciagu)
     return ret;    //zwrot
}

char* czas()
{
    time_t rawtime;	//zmienna przechowujaca czas
    struct tm * timeinfo;	//struktura trzymajaca czas
    time( &rawtime );	//zapisanie czasu do zmiennej
    timeinfo = localtime ( &rawtime );	//konwersja na odpowiedni format
    return asctime(timeinfo);   //zwraca lokalny czas
}

void log(char* tekst)
{
    FILE *plik=NULL;	//zmienna pokazujaca na plik
    plik = fopen("log.txt","at");   //otwarcie pliku do dopisywania tekstowo
    fprintf(plik,"%s ",tekst);      //zapis do pliku
    fclose(plik);                   //zamkniecie go
}

void rysujdopliku(char **t,int n)   // patrz: void rysuj(...) , to samo tylko do pliku
{
    int i,j;	//petla
    FILE *plik = NULL;	//wskaznik na plik
    plik = fopen("log.txt","at");   //otwarcie pliku do dopisu(a) tekstowego(t)
    fprintf(plik,"\nObecny stan gry : \n");	//wpisanie
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(t[i][j] != ' ')fprintf(plik,"   %c   ",t[i][j]);	//zapisuje pojedyncze komorki pola tak jak w funkcji blizniaczej
            else
            fprintf(plik," %2i%3i ",i,j);
            if(j < n-1)fprintf(plik,"|");
        }
        fprintf(plik,"\n");	//przejscie do nowej lini
    }
    fclose(plik);   //zamkniecie pliku
}
