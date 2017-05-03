#include<stdio.h>
#include<stdlib.h>

#define N 100


void escreve(char str[N], int n){
     if(str[n]!='\0'){
         if (str[n]>='a' && str[n]<='z'){
             printf("%c", str[n]);
         }
         escreve(str, n+1);
         if(str[n]>='A' && str[n]<='Z'){
             printf("%c", str[n]);
         }
     }
}


int main(){
    char str[N]="tesHxy$cP";
    int n=3;
    
    escreve(str, n);
    system("pause"); 
}
