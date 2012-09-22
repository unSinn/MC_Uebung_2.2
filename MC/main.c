/* 
 * File:   main.c
 * Authoren: Fabian Mächler, Erismann Marcel
 *
 * Übung 2.2: Integer to String
 * Schreiben Sie eine Funktion char* itoa(int i), welche die übergebene Integerzahl in
 * dezimaler Darstellung als Zeichenkette zurück gibt. Die dazu benötigte Zeichenkette soll
 * dynamisch alloziert werden.
 * Zur Berechnung der Anzahl Zeichen eines Wertes in dezimaler Darstellung können Sie den 10er
 * Logarithmus mit der Funktion log10(...) berechnen. Den Absolutwert einer Zahl erhalten Sie mit abs().
 *
 * Created on September 18, 2012, 3:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


char* reverse(char s[]);
char* itoa(int i);

#define MAXLAENGE 50

/*
 * 
 */
int main(int argc, char *argv[]) {

    printf("===========================================\n");
    printf("Übung 2.2\n");
    printf("Authoren: Fabian Mächler, Erismann Marcel\n");
    printf("===========================================\n");


    int i = 76543;
    printf("Input war: \"%d\"\n", i);

    char* output = itoa(i);
     printf("Das ganze als Sring: \"%s\"\n", output);
    
    /*    reverse(s); */

    return (EXIT_SUCCESS);
}

/*char* reverse(char s[]) {
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
}*/

char* itoa(int i) {
    double j = (double) i;
    j  = (int) log10(j);
    int s_len = (int) j;
    char* output = (char*) malloc(sizeof (char) *
            s_len + 1);
    
    char eis = 31;
    output[0] = eis;

    output[s_len+1]= '\n';
    return output;
}



