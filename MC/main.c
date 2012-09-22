/* 
 * File:   main.c
 * Authoren: Fabian Mächler, Erismann Marcel
 *
 * Übung 2.2: Integer to String
 * Schreiben Sie eine Funktion char* itoa(int i), welche die übergebene Integerzahl in
 * dezimaler Darstellung als Zeichenkette zurück gibt. Die dazu benötigte Zeichenkette soll
 * dynamisch alloziert werden.
 * Zur Berechnung der Anzahl Zeichen eines Wertes in dezimaler Darstellung können Sie den 10er
 * Logarithmus mit der Funktion log10(...) berechnen. Den Absolutwert einer Zahl erhalten Sie mit
 *
 * Created on September 18, 2012, 3:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


char* reverse(char s[]);

#define MAXLAENGE 50

/*
 * 
 */
int main(int argc, char *argv[]) {
    char s[MAXLAENGE];

    printf("===========================================\n");
    printf("Übung 2.2\n");
    printf("Authoren: Fabian Mächler, Erismann Marcel\n");
    printf("===========================================\n");


    printf("Input war \"%s\"\n", s);

    reverse(s);

    return (EXIT_SUCCESS);
}

char* reverse(char s[]) {
    int s_len = strlen(s);
    char rev[s_len];
    char c;
    int i;

    for (i = 0; i < s_len; i++) {
        c = s[i];
        if (c != '\0') {
            rev[s_len - 1 - i] = c;
        }
    }
    rev[s_len] = '\0';

    return rev;
}

char* itoa(int i) {
    //int len = strlen(s);

    double log10(double z);
    int abs(int z);

}



