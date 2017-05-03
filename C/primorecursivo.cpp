#include<stdlib.h>
#include<stdio.h>

int primo(int n, int i){
    if(n%i==0 || n==1){
        return(0);
    }
    else if(i>n/2){
        return(1);
    }
    else{
        return(primo(n,i+1));
    }
}


int main(){
   int n;
   
   printf("Escreva um numero:\n");
   scanf("%d", n);
   if(primo(n, 2)){
       printf("O numero eh primo");
   }
   else{
       printf("o numero nao eh primo");
   }
   system("pause");
}
