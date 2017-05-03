#include<stdio.h>
#include<stdlib.h>
#define n 15

/* Função que le matriz */
void le_matriz(int mat[n][n]){
     int i, j;
     
     for(i=0; i<n; i++){
         for(j=0; j<n; j++){
             printf("Digite o número da posicao mat[%d][%d]", i,j);
             scanf("%d", &mat[i][j]);
         }
     }
}
/* Função que escreve matriz */
void escreve_matriz(int mat[n][n]){
     int i, j;
     
     for(i=0; i<n; i++){
         for(j=0; j<n; j++){
             printf("%d%d", mat[i][j]);
         }
     }

}
/* Função que ver se é percymetric matriz */
int percymetrix(int mat[n][n]){
    int i, j, d, k;
    
    for(i=0, k=n-1; i<n; i++, k--){
        for(j=0, d=n-1; j<n; j++, d--){
            return (1);
        }
    }
    return (0);
}

int main(){
    int a[n][n];
    
    le_matriz(a);
    escreve_matriz(a);
    
    if(percymetrix(a)){
        printf("A matriz eh precymetric matrix");
    }
    else{
        printf("A matriz nao eh precymetric matrix");
    }
}
