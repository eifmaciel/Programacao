#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define R 1000
#define N 24
#define M 100

/*********************************************************************************/
double tempo_corrente(){
     struct timeval tval;
     gettimeofday(&tval, NULL);
     return (tval.tv_sec + tval.tv_usec/1000000.0);
}


/*********************************************************************************/
char **cria_matriz (int n){
	int i;
	char **mat = (char **)malloc(sizeof(char *)*n);
	
	for (i=0;i<n;i++){
		mat[i] = (char *)malloc(sizeof(char)*M);
	}
	return(mat);
}

/*********************************************************************************/

void desaloca_matriz(int n, char **mat){

	int i;
	
	for (i=0;i<n;i++){
		free(mat[i]);
	}
}

/*********************************************************************************/

FILE *abre_arquivo(char *arquivo){

	FILE *arq = fopen(arquivo,"r");

	if ( arq == NULL ){
		printf("Erro ao abrir o arquivo %s\n", arquivo);
		exit(0);
	}
	
	return(arq);
}

/*********************************************************************************/
int numero_nomes(FILE *arq){
	char aux[100];

        fseek(arq,0,SEEK_SET); 	

	int c = 0;

	while (fgets(aux,100,arq) ){
		c++;
	}

	return (c);
} 
/*********************************************************************************/

void le_dados(int n, FILE *arq, char **matriz){
	int i;

        fseek(arq,0,SEEK_SET); 	

	for (i=0; i<n; i++){
		fgets(matriz[i],M,arq);
	}
}

/*********************************************************************************/
void bubblesort(int n, char **matriz){

	char aux[M];
	int i, j;
	for ( i=0; i < n-1; i++){
		for(j=0; j <n-1; j++){
			if (strcmp(matriz[j],matriz[j+1]) > 0 ){
				strcpy(aux,matriz[j]);
				strcpy(matriz[j],matriz[j+1]);
				strcpy(matriz[j+1],aux);

			}
		}
	}
}
/*********************************************************************************/

void converte_maiuscula(int n, char **matriz){
	int i, j;

	for (i=0;i<n;i++){
		for( j=0; j<strlen(matriz[i]); j++){
			matriz[i][j] = toupper(matriz[i][j]);
		}
	}
	
}

/*********************************************************************************/
void escreve_dados(int n, char **matriz){

	int i;
	for (i=0;i<n;i++){
		printf("%s",matriz[i]);
	}
}
/*********************************************************************************/
void fecha_arquivo(FILE *arq){
	fclose(arq);
}

/*********************************************************************************/
int main(int argc, char **argv){
	int i, n, metodo;
	FILE *arq;
	char **matriz = NULL;
	double inicio, fim;

	if ( argc != 2 ){
		printf("%s < entrada >\n ", argv[0]);
		exit(0);
	}

	inicio = tempo_corrente();	
	
	for (i=0; i<R;i++){

		arq = abre_arquivo(argv[1]);
	
		n = numero_nomes(arq);

		matriz = cria_matriz(n);
	
		le_dados(n, arq, matriz);

		converte_maiuscula(n,matriz);
			
		bubblesort(n, matriz);

		//escreve_dados(n, matriz);
		
		desaloca_matriz(n,matriz);

		fecha_arquivo(arq);
	}

	fim = tempo_corrente();	

	printf("Tempo = %f\n", fim - inicio);


	return(0);
}

/*********************************************************************************/




