#include<stdio.h>
#include<stdlib.h>

// Recursividade exemplo2

void escreve(int n){
   if (n>0){
      escreve(n-1);
      printf("%d\n", n);
      
   }
}

int main(){
    int n;
    printf("Digite um numero:\n");
    scanf("%d", &n);
    escreve(n);
    system("pause");

}
