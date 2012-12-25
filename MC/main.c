/* 
 * File:   main.c
 * Authoren: Fabian Mächler, Erismann Marcel
 *
 * Übung 2.2: Integer to String
 * Schreiben Sie eine Funktion char* itoa(int i), welche die übergebene 
 * Integerzahl in
 * dezimaler Darstellung als Zeichenkette zurück gibt. 
 * Die dazu benötigte Zeichenkette soll
 * dynamisch alloziert werden.
 * Zur Berechnung der Anzahl Zeichen eines Wertes in 
 * dezimaler Darstellung können Sie den 10er Log
 * Logarithmus mit der Funktion log10(...) berechnen. 
 *
 * Created on September 18, 2012, 3:37 PM
 * 
 * Der code baut auf dem von Fabian Mächler auf.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* itoa(int i);

/*
 * 
 */
int main(int argc, char *argv[]) {

    printf("===========================================\n");
    printf("Uebung 2.2\n");
    printf("Authoren: Fabian Maechler, Erismann Marcel\n");
    printf("===========================================\n");


    /*
     * Hier irgend einen Integer definieren.
     */
    int i;

    printf("Integer Zahl in String umwandeln:\n");
    printf("Geben Sie eine Zahl ein: \n");
    scanf("%d", &i); 

    char* output = itoa(i);
    printf("Die Zahl als String: \"%s\"\n", output);

    /*
     * Speicher freigeben.
     */
    free(output); /* Gibt den Speicher wieder frei */

    printf("===========================================\n");
    printf("Ende der Uebung 2.2");

    return (0);
}

/*
 * Gibt einen char-Pointer zurück, indem sich die der Integer i als char befindet.
 * Am Ende befindet sich ein '\0'
 * 
 * ASCII 48 – 57 = numbers '0'-'9'
 */
char* itoa(int i) {
    double lg = log10(i);

    /*
     * zum Beispiel sei i: 123
     * log_10(123) =  ~ 2.089
     */
    int s_len = (int) lg + 1; /*s_len hat gleichviele Stellen wie dei eingegebende Zahl*/

    /*
     * Speicher reservieren für die Länge des Strings + '\0'     
     */
    char* output = (char*) malloc(sizeof (char) * s_len + 1);

    int j = s_len - 1; /* wir wollen das output-Array von der zweithintersten zum ersten Index auffüllen */
    /*
     * Wir identifizieren jeweils immer die letzte Ziffer und teilen i dann durch 10.
     *
     */
    while (i > 0) {
        /* 
         * i % 10 gibt jeweils die letzte Ziffer zurück.
         *  (123 % 10 = 3)
         * UND
         * der int Wert 48 entspricht dem Ascii 0
         *  (char c = 48 + 1 = '1')
         *  48 +(123 %10)...48 +3= 51..51 in ASCIi ist 3..die 3 
         * wir im im array beim index j der ist ja momentan der zweithinterste gespeichert
         *
         * 123/10 = 12 weil int und so
         */
        
        output[j] = 48 + (i % 10);  
        i = i / 10; 
        j--;
    }

    /*die letzte Speicherbox der char array wird mit dem \0 abgefüllt*/
    output[s_len] = '\0'; 


    return output;
}