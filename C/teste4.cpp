#include<stdio.h>
#include<stdlib.h>

int main(){
    int i, j, aux;
    int cadastro[5], partido[5], votos[5];
    
    printf("Digite os candidatos:");
    for(i=0; i<5; i++){
        scanf("%d %d %d", &cadastro[i], &partido[i], &votos[i]);
    }
    
    for(i=0; i<4; i++){
       for(j=0; j<4; j++){
          if(partido[j]>partido[j+1]||partido[j]==partido[j+1]&& votos[j]>votos[j+1]){
              aux=partido[j];
              partido[j]=partido[j+1];
              partido[j+1]=aux;
              aux=0;
              aux=cadastro[j];
              cadastro[j]=cadastro[j+1];
              cadastro[j+1]=aux;
              aux=0;
              aux=votos[j];
              votos[j]=votos[j+1];
              votos[j+1]=aux;
          }
       }
    }
    for(i=0; i<5; i++){
        printf("%d %d %d", &partido[i], &cadastro[i], votos[i]);
    }
    system("pause");
    

}
