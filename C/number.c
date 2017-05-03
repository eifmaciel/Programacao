#include<stdio.h>
#include<stdlib.h>


//Função que escreve os numeros ate o numero maior e na volta ate o numero menor
void number(int num1, int num2){		
	if (num1<=num2){
		printf("%d \n", num1);
		number(num1+1, num2);
		if (num1 != num2){
			printf("%d \n", num1);
		}
	}
}


int main(){
	int num1, num2;

	printf("Digite os números inteiros:");
	scanf("%d %d", &num1, &num2);
	number(num1, num2);
}