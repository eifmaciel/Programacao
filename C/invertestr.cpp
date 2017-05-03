#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void inverte(char str[100], int ini, int fim){
     char aux;
     
     if (ini<fim){
         aux = str[ini];
         str[ini] = str[fim];
         str[fim] = aux;
         inverte(str, ini+1, fim-1);
     }
     
}


int main(){
    char str[100];
    int ini=0, fim=0;
    
    printf("Escreva a palavra:\n");
    scanf("%s", str);
    fim = strlen(str)-1;
    inverte(str, ini, fim);
    printf("A string modificada eh: %s\n", str);
    system("pause");
}
