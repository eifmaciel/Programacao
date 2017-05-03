#include<stdio.h>
#include<stdlib.h>

int main(){
	int bait, bait2;
	FILE *arq1, *arq2;
	long posicao=0;
	int l1, l2;
	arq1 = fopen ("enterprise.bmp" ,"rb");
	arq2 = fopen ("enterprise.bmp" ,"rb");
	
	while(!feof(arq1) && !feof(arq2) && posicao == 0){
		l1 = fread (&bait, 1, 1, arq1);
		l2 = fread (&bait2, 1, 1, arq2);
		if(bait != bait2){
			posicao = ftell (arq1);
			printf("Nao sao iguais na posicao %lu .\n", posicao);
		}
	}
}
