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

#include "main.h"

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
    printf("Bitte etwas eingeben und ENTER drücken...\n");
    
    readLine(&s,MAXLAENGE);
    printf("Input war \"%s\"\n", s);
    
    reverse(s);

    return (EXIT_SUCCESS);
}

/**
 * Liest eine Zeile von maximal limit Zeichen ein.
 * Die Zeichen werden (inklusive Zeilenende-Zeichen) im übergebenen
 * Vektor s /0 terminiert abgelegt.
 * 
 * Quelle: Uebungen_2.pdf
 * 
 * @param s Zeiger auf den Vektor zum Speichern der Eingabe
 * @param limit Maximale Grösse des Vektors
 * @return Anzahl eingelesene Zeichen
 */
int readLine(char s[], int limit) {
    int i = 0;
    int c;
    c = getchar();
    while ((c != EOF) &&
            (c != '\n') &&
            (i < limit - 1)) {
        s[i] = c;
        i++;
        c = getchar();
    }
    if (c == '\n') {
        s[i] = '\n';
        i++;
    }
    s[i] = '\0';
    return i;
}

//?
char* reverse(char s[]){
    char rev[MAXLAENGE];
}


char* itoa(int i){
    //int len = strlen(s);
}



