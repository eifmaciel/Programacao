#include<stdio.h>
#include<stdlib.h>

#define N 4

void le_matriz(int mat[N][N]){
    int i, j;
    
    for(i=0 ; i<N ; i++){
        for(j=0 ; j<N ; j++){
            printf("Digite o elementro mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
/*=================================*/
void escreve_matriz(int mat[N][N]){
    int i, j;
    
    for(i=0 ; i<N ; i++){
        for(j=0 ; j<N ; j++){
           if(j==N-1){
               printf("%d\n", mat[i][j]);
           }
           else{
               printf("%d\t", mat[i][j]);
           }
        }
    }
}
/*=================================*/
int quadrado(int mat[N][N]){
    int i, j, soma1 = 0, soma2 = 0;
    
    for(i=0 ; i<N ; i++){
        soma1 += mat[i][i];
        soma2 += mat[i][N-i-1];
    }
    
    if(soma1 != soma2){
        return(0);
    }
    
    for(i=0 ; i<N ; i++){
        soma2 = 0;
        for(j=0 ; j<N ; j++){
            soma2 += mat[i][j];
        }
        if(soma1 != soma2){
            return(0);
        }
    }
    
    for(j=0 ; j<N ; j++){
        soma2 = 0;
        for(i=0 ; i<N ; i++){
            soma2 += mat[i][j];
        }
        if(soma1 != soma2){
            return(0);
        }
    }
    
    return(1);  
}
/*=================================*/
int main(){
    int mat[N][N];

    le_matriz(mat);
    escreve_matriz(mat);
    
    if(quadrado(mat)){
        printf("Quadrado\n");
    }
    else{
        printf("Nao Quadrado\n");
    }
    
    system("pause");
}
