#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

//######################################################################## Funkcje Gry

//Dla gry
void rysuj(char** t,int n); //rysuje plansze
char** przydziel(int n); //przydziela pamiec
void czysc(char** t,int n); //czysci pamiec
void zapchaj(char** t,int n); //zapycha pola spacjami
int los(int s,int k); //losuje liczby
int sprawdzenie(char** t,int n,char znak); //sprawdzenie czy ktos nie wygral
