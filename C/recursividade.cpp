#include<stdio.h>
#include<stdlib.h>

// Recursividade

void escreve(int n){
   if (n>0){
      printf("%d\n", n);
      escreve(n-1);
   }
}

int main(){
    int n;
    printf("Digite um numero:\n");
    scanf("%d", &n);
    escreve(n);
    system("pause");

}
