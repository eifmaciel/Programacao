#include<stdio.h>
#include<stdlib.h>

#define N 4

int numeros_repetidos(int vet[N], int i){
	if(i==N-1){
		return 0;
	}
	else if(vet[i]==vet[i+1]){
		return (1+numeros_repetidos(vet, i+1));
	}
	else{
		return (numeros_repetidos(vet, i+1));
	}
}

int main(){
	int vet[N]={1, 2, 2, 2};

	printf("numeros repetidos é: %d\n", numeros_repetidos(vet, 0));
}