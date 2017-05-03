#include<stdio.h>
#include<stdlib.h>

#define N 100

void troca_caracteres(char str[N], int p, char t, char q){
	if(str[p]!='\0'){
		if(str[p]==q){
			str[p]=t;
		}
		troca_caracteres(str, p+1, t, q);
	}
}

int main(){
	char str[N], t, q;

	printf("Digite a palavra e as letras que deseja trocar:\n");
	scanf("%s %c %c", str, &t, &q);
	troca_caracteres(str, 0,t, q);
	printf("A string é :%s\n", str);
}