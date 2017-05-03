#include<stdlib.h>
#include<stdio.h>

// Este programa le 20 numeros e se for par coloca em um arquivo se for impar escreve em outro arquivo;
void escreve_arquivo(FILE *arquivo, int n){
    fprintf(arquivo,"%d\n",n);
}

void le_arquivo(FILE *arquivo){
    int n;
    while (fscanf(arquivo,"%d" ,&n)!= EOF ){
        printf ("%d\n ", n);
    }
    fclose(arquivo);
}

int main(){
    FILE *arq1, *arq2, *arq1_le, *arq2_le;
    int num, i;

    arq1=fopen("par.txt","wt");
    arq2=fopen("impar.txt","wt");

    for(i=0; i<20;i++){
        printf("Digite o numero a ser gravado no arquivo:\n");
        scanf("%d", &num);
        if(num%2 == 0){
            escreve_arquivo(arq1, num);
        }
        else{
            escreve_arquivo(arq2, num);
        }
    }
    fclose(arq1);
    fclose(arq2);
    arq1_le=fopen("par.txt","rt");
    arq2_le=fopen("impar.txt","rt");
    printf("Arquivo dos pares:\n");
    le_arquivo(arq1_le);
    printf("Arquivo dos impares:\n");
    le_arquivo(arq2_le);
}