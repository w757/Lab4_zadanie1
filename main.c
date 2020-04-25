#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define R 100000000

int szukanie_slowa (char *tekst, char *slowo, int x, int y){

    int i;

    for (i = 0; i < y; i ++){
        if(tekst[x+i] != slowo[i]) return 1;
    }

    //Jeśli wszystkie litery się zgadzają sprawdzamy czy wyraz kończy się w tym miejscu
    if ((tekst [x+y] < 65 || (tekst[x+y] > 90 && tekst[x+y] < 97) || tekst[x+y] > 122)) return 2;
}

int main()
{
    char* tekst = malloc (R * sizeof(char));
    char* szukane_slowo = malloc (15 * sizeof (char));
    int rozmiar_pliku = 0, rozmiar_slowa = 0, il_wystapien = 0;

    FILE *plik = fopen("/home/w/Pulpit/Studia/lab_classes_C/Zadanie_1/tekst.txt", "r");

    if ((plik = fopen("/home/w/Pulpit/Studia/lab_classes_C/Zadanie_1/tekst.txt", "r")) == NULL) {
        printf ("Nie mogę otworzyć pliku!\n");
        exit(1);
    }

    tekst[0] = getc( plik );

    while( tekst[rozmiar_pliku] != EOF )                        //Wczytywanie pliku do tablicy
    {
        rozmiar_pliku++;

        tekst[rozmiar_pliku] = getc( plik );
        if(tekst[rozmiar_pliku]>64 && tekst[rozmiar_pliku]<91)          //Zmiana wielkości liter
            tekst[rozmiar_pliku]+=32;
    }

    printf("Podaj słowo, którego szukasz: ");
    scanf("%s", szukane_slowo);

    while( szukane_slowo[rozmiar_slowa] != '\0' )           //Określanie długości słowa
    {
        if(szukane_slowo[rozmiar_slowa] > 64 && szukane_slowo[rozmiar_slowa] < 91)
            szukane_slowo[rozmiar_slowa] += 32;

        rozmiar_slowa++;

    }



    for (int i = 0; i < rozmiar_pliku; i++){

        //Sprawdzenie czy w tekście rozpoczeło się nowe słowo i czy pierwsza litera zgadza się z ty szukanym (jeśli nie, nie ma sensu ich sprawdzać)
        if((tekst[i-1] < 65 || (tekst[i-1] > 90 && tekst[i-1] < 97) || tekst[i-1] > 122) && (tekst[i] == szukane_slowo[0])){

            if(szukanie_slowa( tekst, szukane_slowo, i, rozmiar_slowa) == 2){
                il_wystapien++;                                  //Jeśli występuje dane słowo, licznik zostaje zwiększony a funkcja
                i = i + rozmiar_slowa;                               //powtarza się dalej od miejsca w którym skończy się słowo

            }
        }

    }

    printf("%i\n", il_wystapien );
    fclose (plik);
    return 0;
}
