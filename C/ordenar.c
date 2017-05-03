#include<stdlib.h>
#include<stdio.h>

typedef struct nome{
	char nome[100];
}

typedef struct data{
	char data[100];
	struct nome *nomes;
	struct data *prox;
}Tdata;


 void cria_lista(){

 }
int main(){
	FILE *arq;
	char nome[100];
	arq = fopen("resumo.txt", "r");
	char *l;
	char linha[10000];
	char *tok = linha;
	Tdata *dt=NULL;
	int data;
	i=0;
  	while(linha[i]!=','){
   		i++;
   	}
	for(j=0; j<i; j++){
	   	nomeS[j] = linha[j];
	}
	nomes[j] = '\0';
	  
	if(linha[i]!='\n'){
	   i++;
	   j = 0;
	   while(linha[i]!='\n'){
	    dataS[j] = linhaArquivo[i];
	    i++;
	    j++;
	   }
	   dataS[j] = '\0';
	  }  
	        char *token = strtok(dataS,"/");
        int cont = 0;
     while (token != NULL)
        {   
            if(cont == 0)           
                dia = atoi(token);
            else if(cont == 1)
                mes = atoi(token);
            else
                ano = atoi(token);
            cont++;
            token = strtok(NULL,"/");
     }

	while (!feof(arq)){
        l = fgets(linha, 10000, arquivo);
        int i=0;
	    tok = strtok(tok, ","));
		printf("%s\n");

	    	
	        tok = NULL;
	    cria_lista(&dt, tok);
	}
    fclose(arquivo);

}