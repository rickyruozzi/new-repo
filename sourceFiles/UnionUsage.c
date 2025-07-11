#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* NetworkERR = "È stato impossibile connettersi alla rete, verificare il collegamento alla rete internet";
const char* FileERR = "È stato impossibile usufruire del file fornito";
const char* InputERR = "È stato impossibile utilizzare l'input fornito";

typedef enum {
    ERRORE_FILE,
    ERRORE_RETE,
    ERRORE_INPUT
} TipoErrore;

// Struct per errori di rete
typedef struct {
    char url[100];
} NetworkError;

// Struct per errori di input
typedef struct {
    char input[50];
} InputError;

// Struct per errori di file
typedef struct {
    char fileName[50];
} FileError;

// Union che contiene un solo tipo di errore
typedef union {
    NetworkError network;
    InputError input;
    FileError file;
} ErrorMessage;

// Struttura principale per rappresentare un errore
typedef struct {
    TipoErrore tipo;
    ErrorMessage messaggio;
} Errore;

// Funzione di stampa
void stampa_errore(Errore e) {
    switch (e.tipo) {
        case ERRORE_RETE:
            printf("Errore di rete:\n");
            printf("%s\n", NetworkERR);
            printf("URL: %s\n", e.messaggio.network.url);
            break;
        case ERRORE_INPUT:
            printf("Errore di input:\n");
            printf("%s\n", InputERR);
            printf("Input problematico: %s\n", e.messaggio.input.input);
            break;
        case ERRORE_FILE:
            printf("Errore di file:\n");
            printf("%s\n", FileERR);
            printf("File: %s\n", e.messaggio.file.fileName);
            break;
        default:
            printf("Tipo di errore sconosciuto.\n");
            break;
    }
}

// Test
int main() {
    Errore e1 = {
        .tipo = ERRORE_RETE,
        .messaggio.network = {"https://example.com"}
    };

    Errore e2 = {
        .tipo = ERRORE_INPUT,
        .messaggio.input = {"username"}
    };

    Errore e3 = {
        .tipo = ERRORE_FILE,
        .messaggio.file = {"config.txt"}
    };

    stampa_errore(e1);
    printf("\n");
    stampa_errore(e2);
    printf("\n");
    stampa_errore(e3);

    return 0;
}