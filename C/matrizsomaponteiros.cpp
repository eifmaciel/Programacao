#include<stdio.h>
#include<stdlib.h>
# define n 4


//faz soma das diagonais de uma matriz

//funcao le matriz: esta funcao recebe a matriz declada na funcao main e faz o procedimento de ler a matriz
void le_matriz(int mat[n][n]){
     int i, j;
     
     for(i=0; i<n; i++){
         for(j=0; j<n; j++){
             printf("Digite o valor da matriz mat[%d][%d]", i, j);
             scanf("%d", &mat[i][j]);
         }
     }
}

//esta funcao recebe uma matriz e os endereços das variaveis somas que foram decladas na funcao main. Foi utilizado este metodo pois nao podemos retornar duas variaveis em funcoes
void soma_matriz(int mat[n][n],int *somap,int  *somas){
      int i;
      int soma1=0, soma2=0;
      for(i=0; i<n; i++){
          soma1 += mat[i][i];
          soma2 += mat[i][n-i-1];
      }
      *somap=soma1;
      *somas=soma2;
}


int main(){
    int mat[n][n], somap, somas=0;
    
    le_matriz(mat);
    soma_matriz(mat, &somap, &somas);
    printf("%d %d\n", somap, somas);
    system("pause");
}
