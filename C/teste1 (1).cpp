#include<stdio.h>
#include<stdlib.h>

void ordena_vet(int vet[10]){
     int i, j, aux;
     for(i=0; i<9; i++){
       for (j=0; j<9; j++){
           if (vet[j]>vet[j+1]){
              aux=vet[j];
              vet[j]=vet[j+1];
              vet[j+1]=aux;               
           }
       }
    }   
}

int main(){
    int num[10];
    int i;
    for(i=0;i<10;i++){ 
        printf("Escreva um numero:");
        scanf("%d", &num[i]);
    }
    ordena_vet(num);
    for(i=0; i<10; i++){
        printf("%d\n", num[i]);
    }
    system("pause");
}
