#include<stdio.h>
#include<stdlib.h>

int main(){
    char nomes[10][21], aux[21];
    for(i=0; i<10; i++){
        scanf("%s", nomes[i]);
    }
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
           if(strcmp(nomes[j], nomes[j+1])>0){
               strcpy(aux, nomes[j]);
               strcpy(nomes[j], nomes[j+1]);
               srtcpy(nomes[j+1], aux);
           }
        }
    }
}
