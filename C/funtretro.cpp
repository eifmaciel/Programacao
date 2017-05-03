#include<stdlib.h>
#include<stdio.h>
// neste programa eh feita uma funcao que troca os valores de numeros inteiros, para isso temos que usar ponteiros.


void troca(int *a, int *b){
     int aux=*a; 
     *a=*b;
     *b=aux;
}



int main(){
    int a, b;
    
    printf("Digite os valores:");
    scanf("%d %d", &a, &b);
    troca(&a, &b);
    printf("main: %d %d\n", a, b);
    system("pause");
}
