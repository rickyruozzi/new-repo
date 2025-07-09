#include <stdio.h>

int main() {
    printf("Hello World!\n");  // stampa senza \n
    printf("Scegli quale programma avviare!\n");
    fflush(stdout);          // svuota il buffer, la stringa appare subito
    int scelta;
    scanf("%d", &scelta);
    switch(scelta){
        case 1:
        system("./ProveDiVisualizzazione.c");
    }

    printf("%d\n", scelta);

    return 0;
}
