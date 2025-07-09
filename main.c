#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Hello World!\n");  // stampa senza \n
    printf("Scegli quale programma avviare!\n");
    printf("1-per le prove di visualizzazione\n2-per il programma che somma 3 uint\n");
    fflush(stdout);          // svuota il buffer, la stringa appare subito
    int scelta;
    scanf("%d", &scelta);
    switch(scelta){
        case 1:
        system("executable\\ProveDiVisualizzazione.exe");
        break;
        case 2: 
        system("executable\\FindSum.exe");
        break;
    }
    return 0;
}
