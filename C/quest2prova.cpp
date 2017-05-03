#include<stdio.h>
#include<stdlib.h>
#define n 1000

/* Função que troca extenção de arquivos8*/
void altera(char arquivo[n]){
    int i, pos=-1;
    
    for(i=0; arquivo[i]!='\0'; i++){
        if(arquivo[i]=='.'){
            pos=i;
        }
    }
    if(pos!=-1){
        arquivo[pos+1]='b';
        arquivo[pos+2]='k';
        arquivo[pos+3]='p';
        arquivo[pos+4]='\0';
    }
    else{
         arquivo[i]='.';
         arquivo[i+1]='b';
         arquivo[i+2]='k';
         arquivo[i+3]='p';
         arquivo[i+4]='\0';
    
    }
}

int main(){
    char arquivo[n];
    
    printf("Digite o nome:");
    scanf("%s", arquivo);
    altera(arquivo);
    printf("%s\n", arquivo);
    system("pause");
}
