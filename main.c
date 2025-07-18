/**
 * @file main.c
 * @author Riccardo Ruozzi
 * @brief 
 * @version 0.1
 * @date 2025-07-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Hello World!\n");  // stampa senza \n
    printf("Scegli quale programma avviare!\n");
    printf("1-per le prove di visualizzazione\n2-per il programma che somma 3 uint\n"
    "3-per invertire i valori di un array\n4-per controllare la prima ricorrenza in un valore in un array di interi casuali"
    "\n5-per invertire una stringa\n");
    fflush(stdout);          // svuota il buffer, la stringa appare subito
    int scelta; /**<variabile per la scelta */
    scanf("%d", &scelta);
    switch(scelta){
        case 1:
        system("executable\\ProveDiVisualizzazione.exe");
        break;
        case 2: 
        system("executable\\FindSum.exe");
        break;
        case 3: system("executable\\reverseArray.exe");
        break;
        case 4:
        system("executable\\findElement.exe");
        break;
        case 5:
        system("executable\\reverseString.exe");
        break;
        case 6:
        system("executable\\valutaStudenti.exe");
        break;
        case 7:
        system("executable\\UnionUsage.exe");
        break;
    }
    return 0;
}
