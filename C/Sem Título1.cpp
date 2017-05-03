#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    char matriz[10][12]={{'A','B','C','D','E','F','G','H','I','J','K','L'},
                         {'M','N','O','P','M','R','S','T','U','V','W','X'},
                         {'Y','Z','T','E','E','T','E','A','H','G','D','E'},
                         {'P','R','O','R','G','A','M','A','I','J','H','T'},
                         {'Q','W','O','M','A','I','R','O','G','L','A','F'},
                         {'D','F','G','H','U','K','C','V','B','N','O','P'},
                         {'D','L','O','A','M','A','R','G','O','R','P','I'},
                         {'F','I','B','O','N','A','C','C','I','E','R','T'},
                         {'A','G','U','A','I','F','P','R','I','M','O','S'},
                         {'A','B','C','D','L','F','G','H','I','J','H','I'}};
    char palavra[10];
    int i,j,k,cont=0,cont1=0,cont2=0,cont3=0,u;
    printf("Digite a palavra:");
    fgets(palavra,10,stdin);
    for(i=0;i<10;i++){
       for(j=0;j<12;j++){
          if(matriz[i][j]==palavra[0]){
            for(k=0;palavra[k]!='\0';k++){
               if(j+k<12&& matriz[i][j+k]==palavra[k]){
                 cont++;
                 }
                 else if(j-k<12&& matriz[i][j-k]==palavra[k]){
                        cont1++;
                        }
                        else if(i+k<12&& matriz[i][i+k]==palavra[k]){
                               cont2++;
                               }
                               else if(i-k<12&& matriz[i][i-k]==palavra[k]){
                                      cont3++;
                                      }
               }
            }
          }
       }
    u=strlen(palavra)-1;
    palavra[u]='\0';
    if(cont==u || cont1==u || cont2==u ||cont3==u){
      printf("existe");
      }
      else printf("não existe");
    system("pause");
    }   
    
