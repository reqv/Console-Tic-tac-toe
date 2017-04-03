#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

//Dodatkowe
void linia(int l); //rysuje linie
char* intToStr(int n); //zamienia inta na string
void log(char* tekst); //zapisuje do pliku log.txt
char* czas(void); //podaje aktualna godzine i czas w postaci stringa
void rysujdopliku(char **t,int n); //rysuje tablice w pliku
