#include <stdio.h>
#include<stdlib.h>
int findLen(char *s){
    int i=0;
    int count=0;
    while(s[i]!='\0'){
        count=count+1;
        i=i+1;
    }
    return count;
}

void reverseString(char *s, char *d, int len){
    for(int i=0; i<len; i++){
        d[i]=s[len-1-i];
    }
    d[len]='\0';
}

int main(){
    char string[]="Riccardo";
    int len=findLen(string);
    printf("lunghezza : %d\n",len);
    char *reverse=(char *)malloc(sizeof(char)*(len+1));
    reverseString(string, reverse, len);
    printf("Originale: %s\n",string);
    printf("Stringa Invertita: %s\n", reverse);
}