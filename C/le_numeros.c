#include<stdio.h>
#include<stdlib.h>


//Função que escreve os numeros ate o numero maior e na volta ate o numero menor
void le_number(int n, int *maior_num, int *menor_num){

	printf("Digite os números inteiros:");
	scanf("%d", &n);
	if (n>0){
		if(*menor_num==0 || *maior_num==0){
			*menor_num=n;
			*maior_num=n;
		}
		else if (n>*maior_num){
			*maior_num=n;
		}
		else if (n<*menor_num){
			*menor_num=n;
		}
		le_number(n, maior_num, menor_num);
	}
}


int main(){
	int n=0, maior_num=0, menor_num=0;
	le_number(n, &maior_num, &menor_num);
	printf("O numero maior= %d,\n O numero menor=%d, \n", maior_num, menor_num);
}