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

/*
 * 
 */
int main(int argc, char *argv[]) {

    printf("===========================================\n");
    printf("Übung 2.2\n");
    printf("Authoren: Fabian Mächler, Erismann Marcel\n");
    printf("===========================================\n");


    /*
     * Hier irgend einen Integer definieren.
     */
    int i = 123456;
    
    printf("Input war: \"%d\"\n", i);

    char* output = itoa(i);
    printf("Das ganze als Sring: \"%s\"\n", output);
    
    /*
     * Speicher freigeben.
     */
    free(output);

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

/*
 * Gibt einen char-Pointer zurück, indem sich die der Integer i als char befindet.
 * Am Ende befindet sich ein '\0'
 * 
 * ASCII 48 – 57 = numbers '0'-'9'
 */
char* itoa(int i) {
    double l10 = log10(i);
    
    /*
     * log_10(123) =  ~ 2.089
     */
    int s_len = (int) l10 + 1;
    
    /*
     * Speicher reservieren für die Länge des Strings + '\0'     
     */
    char* output = (char*) malloc(sizeof (char) *
            s_len + 1);

    int j = s_len - 1;
    /*
     * Wir identifizieren jeweils immer die letzte Ziffer und teilen i dann durch 10.
     *  (Wir schieben i eins nach rechts)
     * 
     * Wenn wir bei i < 10 sind, wird i = 0.
     *  (5/10 = 0 weil i ein ganzzahliger Datentyp ist)
     */
    while (i > 0) {
        /* 
         * i % 10 gibt jeweils die letzte Ziffer zurück.
         *  (123 % 10 = 3)
         * 
         * UND
         * 
         *  (char c = 48 + 1 = '1')
         * 
         */
        output[j] = 48 + (i % 10);
        i = i / 10;
        j--;
    }

    output[s_len] = '\0';

    /*
     * Nun ist das ganze noch verkehrt, also drehen wir den String mit der Methode
     * aus Übung 2.1 um.
     */
    reverse(output);

    return output;
}



