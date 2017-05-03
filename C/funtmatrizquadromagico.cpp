#include<stdio.h>
#include<stdlib.h>
#define n 4

/* Função que le matriz */
void le_matriz(int mat[n][n]){
     int i, j;
     
     for(i=0; i<n; i++){
         for(j=0; j<n; j++){
             printf("Digite o número da posicao mat[%d][%d]\n", i,j);
             scanf("%d", &mat[i][j]);
         }
     }
}
int quadrado_magico(int mat[n][n]){
    int i, j;
    int contl=0, contc=0, conts=0, cont=0;
    
    for(i=0; i<n; i++){
        cont+=mat[i][i];
    }
    for(i=0; i<n; i++){
        conts+=mat[i][n-1-i];
    }
    if(conts!=cont){
        return 0;
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            contl+=mat[i][j];
            contc+=mat[j][i];
        }
    }
    return 1; 
}


int main(){
    int mat[n][n];
    le_matriz(mat);
    if (quadrado_magico(mat)){
       printf("Eh um quadro magicico.\n");
    }
    else{
       printf("Nao eh um quadro magico.\n");
    }
    system("pause");
}
