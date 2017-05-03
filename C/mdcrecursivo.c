#include<stdio.h>
#include<stdlib.h>

// Função que calcula o Maximo Divisor Comum entre dois números
void mdc(int a, int b){
	int , resto;
	
	if (a%b==0){
		return b;
		
	}
	else{
		return (mdc(b, (a%b)));
	}	
}

int main(){
	int a, b;

	printf("Digite os números inteiros:");
	scanf("%d %d", &a, &b);
	printf("MDC = %d \n", mdc(a, b));
}