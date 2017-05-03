#include<stdio.h>
#include<stdlib.h>
#define n 4

int main(){
    int a[n][n] = {{10, 12, 14, 16},
                    {6, 7, 8, 9},
                    {12, 15, 18, 21},
                    {20, 21, 22, 23}};
    int i, j, k, maiorprimo=0, pc=0, pl=0, cont;
    
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
           cont=0;
           for (k=1; k<=a[i][j]; k++){
              if (a[i][j]%k == 0){
                 cont++;
              }
           }
           if (cont==2 && i!=j && a[i][j]>maiorprimo){
                  maiorprimo=a[i][j];
                  pc=j;
                  pl=i;
           }
        }
    }
    if(pc>pl){
        printf("O numero primo esta acima da diagonal principal\n");
    }
    else if (pc<pl){
        printf("O numero primo esta abaixo da diagonal principal\n");
    }
    else{
         printf("Nao tem.\n");
    }
    system("pause");
}
