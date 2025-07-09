#include <stdio.h>
int main(){
    unsigned int unsignedDecimal = 123;   // 123 decimale
    unsigned int octal = 0123;             // 83 decimale (lo 0 iniziale indica un valore ottale)
    unsigned int hexadecimal = 0x1A;       // 26 decimale (0x) indica che la rappresentazione è in esadecimale
    int sum;
    sum=unsignedDecimal+octal+hexadecimal;
    printf("La somma è: %d",sum);
    return 0;
}