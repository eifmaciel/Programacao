#include<stdio.h>
#include<stdlib.h>

void escreve_ao_contrario(int i, int j){
	if (i<=j){
		printf("%d\n", i);
		escreve_ao_contrario(i+1, j);
		if (i != j){
			printf("%d \n", i);
		}
	}
}

int main(){
	int i, j;

	printf("Digite os numeros:\n");
	scanf("%d %d", &i, &j);
	escreve_ao_contrario(i, j);
}