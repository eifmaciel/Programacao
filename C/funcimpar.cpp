#include<stdio.h>
#include<stdlib.h>



int impar(int num){
    if (num%2)!=0{
        return 1;
    }
    else{
       return 0;
    }
}

int main(){
    int num;
    
    printf("Digite um numero.\n");
    scanf("%d", num);
    
    if (impar(num)){
       printf("O numero eh impar.\n");
    }
    else{
       printf("O numero nao eh impar.\n");
    }
    system("pause");
}
