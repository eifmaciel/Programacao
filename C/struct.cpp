#include<stdio.h>
#include<stdlib.h>

int main(){
    struct dma {
        int dia;
        int mes;
        int ano;
    };
    struct dma data[5];
    struct dma data2[5];
    int i, j;
    printf("Digite as datas:");
    for(i=0;i<5;i++){
        scanf("%d %d %d", &data[i].dia, &data[i].mes, &data[i].ano);
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(data[j].ano>data[j+1].ano){
               data2[i]=vet[j];
              vet[j]=vet[j+1];
              vet[j+1]=aux; 
            }
        }
    }
    system("pause");
}
