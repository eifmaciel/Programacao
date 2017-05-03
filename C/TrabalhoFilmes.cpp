#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

typedef struct atoresFilme
{
  struct ator *ator;
  struct atoresFilme *prox;
}TAtoresFilme;

typedef struct ator
{
  char nome[100];
  struct ator *prox; 
  struct filmesAtor *filmes;
}TAtor;

typedef struct filme
{
  char nome[100];
  int ano;
  char diretor[100];  
  struct filme *prox; 
  struct atoresFilme *atores;
}TFilme;

typedef struct filmesAtor
{
  struct filme *filme;       
  struct filmesAtor *prox;
}TFilmesAtor;

void flush_in(){
    int ch;
    while((ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

char *replace_str(const char s[], const char *old, const char *new1)

{

    char *ret;

    int i, count = 0;

    int newlen = strlen(new1);

    int oldlen = strlen(old);

 

    for (i = 0; s[i] != '\0'; i++)    

    {

        if (strstr(&s[i], old) == &s[i]) 

        {

            count++;

            i += oldlen - 1;

        }

    }

    ret = (char *)malloc(i + count * (newlen - oldlen));

    if (ret == NULL)

        exit(EXIT_FAILURE);

    i = 0;

    while (*s)

    {

        if (strstr(s, old) == s) //compare the substring with the newstring

        {

            strcpy(&ret[i], new1);

            i += newlen; //adding newlength to the new string

            s += oldlen;//adding the same old length the old string

        }

        else

        ret[i++] = *s++;

    }

    ret[i] = '\0';

    return ret;
    printf("%s \n", ret);

}

int procuraString(const char* string1, const char* string2)
{
    char *pt; 
    pt = strstr(string1, string2); 
    if(pt) 
       return 1;
    else 
         return 0;
}

void listaFilmesIntervaloAnos(TFilme *inicio, int ano1, int ano2)
{
	if(inicio != NULL)
	{
        if (inicio->ano >= ano1 && inicio->ano <= ano2)
    		printf("%s - %d\n",inicio->nome, inicio->ano);    		
		listaFilmesIntervaloAnos(inicio->prox, ano1, ano2);
	}	
}


TAtor *procuraAtorEmFilme(TAtoresFilme *atores, char ator[])
{
    while(atores != NULL)
    {
        if(strcmp((atores->ator)->nome, ator) == 0)
            return atores->ator;
        atores = atores->prox;
    }
    return NULL;
}

TFilme *procuraFilmeEmAtor(TFilmesAtor *filmes, char filme[])
{
    while(filmes != NULL)
    {
        if(strcmp((filmes->filme)->nome, filme) == 0)
            return filmes->filme;
        filmes = filmes->prox;
    }
    return NULL;
}

void listaFilmesAtores(TFilme *inicio, char ator1[], char ator2[])
{
    while(inicio != NULL)
    {     
        if(procuraAtorEmFilme(inicio->atores, ator1) != NULL && procuraAtorEmFilme(inicio->atores, ator2) != NULL)              
    		printf("%s \n",inicio->nome);
        inicio = inicio->prox;
	}	
}

int buscaNomeFilme(TFilme *inicio, char parteNome[])
{
	if(strpbrk(inicio->nome, parteNome) != NULL)
		return 1;
	else
		return 0;
}

void listaFilmesNome(TFilme *inicio, char parteNome[])
{
    while(inicio != NULL)
    {     
        if(procuraString(inicio->nome, parteNome) == 1)
            printf("%s \n",inicio->nome);
        inicio = inicio->prox;            
	}	
}


int listarFilmesAtores(TAtor *inicio, char ator1[], char ator2 [])
{
	int achou1 = 0, achou2 = 0;
    while(inicio != NULL )
    {
        if (strcmp(inicio->nome,ator1)==0) 
        	achou1 = 1;
		if (strcmp(inicio->nome,ator2)==0) 
        	achou2 = 1;        
        inicio=inicio->prox;
    }
    return (achou1 & achou2);	
}

TFilme *procuraFilme(TFilme *inicio, char nome[])
{
    while(inicio != NULL )
    {
        if (strcmp(inicio->nome,nome)==0) 
            return inicio;
        inicio=inicio->prox;
    }
    return NULL;
}

void atoresEmFilme(TAtoresFilme *atores)
{
     while(atores != NULL)
     {
	    printf("%s \n",(atores->ator)->nome);
	    atores=atores->prox;
     }           
}

void filmesEmAtor(TFilmesAtor *filmes)
{
     while(filmes != NULL)
     {
	    printf("%s \n",filmes->filme->nome);
	    filmes=filmes->prox;
     }           
}


TAtor *procuraAtor(TAtor *inicio, char nome[])
{
    while(inicio != NULL )
    {
        if (strcmp(inicio->nome,nome)==0) 
            return inicio;
        inicio=inicio->prox;
    }
    return NULL;
}

/*
TFilmesAtor *retornaFimFilmesEmAtor(TFilmesAtor *inicio)
{
    if (inicio==NULL) return NULL;
    retornaFimFilmesEmAtor((inicio)->prox);
}

TAtoresFilme *retornaFimAtoresEmFilme(TAtoresFilme *inicio)
{
    if (inicio==NULL) return NULL;
    retornaFimAtoresEmFilme((inicio)->prox);
}
*/

void insereAtorEmFilme(TAtoresFilme **inicio, TAtor *ator)
{
    if (*inicio==NULL)
    {
        *inicio = (TAtoresFilme*)malloc(sizeof(TAtoresFilme));
        (*inicio)->prox = NULL;
        (*inicio)->ator = ator;
    }
    else 
        insereAtorEmFilme(&(*inicio)->prox,ator);                   
}

void insereFilmeEmAtor(TFilmesAtor **inicio, TFilme *filme)
{     
    if (*inicio==NULL)
    {
        *inicio = (TFilmesAtor*)malloc(sizeof(TFilmesAtor));
        (*inicio)->prox = NULL;
        (*inicio)->filme = filme;
    }
    else 
        insereFilmeEmAtor(&(*inicio)->prox,filme);     
}

TFilme *insereFilme(TFilme **inicio, char nome[], int ano, char diretor[])
{
    TFilme *aux;
    if (*inicio == NULL || strcmp((*inicio)->nome,nome)>=0)
    {
        aux = (TFilme*)malloc(sizeof(TFilme));
        strcpy(aux->nome, nome);
        strcpy(aux->diretor, diretor);        
        aux->ano = ano;
        aux->atores = NULL;
        aux->prox = *inicio ;
        *inicio = aux ;
        return aux;        
    }
    else
        return insereFilme(&((*inicio)->prox), nome, ano, diretor);       
}

TAtor *insereAtor(TAtor **inicio, char nome[])
{
      
    TAtor *aux;
    if (*inicio == NULL || strcmp((*inicio)->nome,nome)>=0)
    {
        aux = (TAtor*)malloc(sizeof(TAtor));
        strcpy(aux->nome, nome);
        aux->filmes = NULL;
        aux->prox = *inicio ;
        *inicio = aux ;
        return aux;        
    }
    else
        return insereAtor(&((*inicio)->prox), nome);             
}

TFilme *procuraFilmeNomeAno(TFilme *inicio, TFilme *filme, char nome[], int ano)
{
     while(inicio != NULL)
     {
         if (inicio != filme && strcmp(inicio->nome, nome) == 0 && inicio->ano == ano)
             return inicio;
         inicio = inicio->prox;
     }
     return NULL;
}


void imprimeFilmes(TFilme *inicio)
{
     while(inicio != NULL)
     {
	    printf("%s \n",inicio->nome);
	    inicio=inicio->prox;
     }      
}

void imprimeFilmesDuplicados(TFilme *inicio)
{
     TFilme *aux = inicio;
     TFilme *auxInicioFilme = NULL, *filme = NULL, *filme1 = NULL;
     while(aux != NULL)
     {
        filme = procuraFilmeNomeAno(inicio, aux, aux->nome, aux->ano);
        if (filme != NULL)
        {
            filme1 = procuraFilmeNomeAno(auxInicioFilme, filme, filme->nome, filme->ano);
            if (filme1 == NULL)
            {
                insereFilme(&auxInicioFilme, filme->nome, filme->ano, filme->diretor);            
                printf("%s %d \n", filme->nome, filme->ano);
            }
        }
	    aux = aux->prox;
     }  
}


void imprimeAtores(TAtor *inicio)
{
     while(inicio != NULL)
     {
	    printf("%s \n",inicio->nome);
	    inicio=inicio->prox;
     }      
}

int minimo( int a, int b, int c)
{
    if (a <= b && a <= c) 
        return a;
    if (b <= c) 
        return b;
    return c;
}

int distanciaLevenshtein(char s[], char t[])
{
    int d [100][100];
    int m = strlen(s);
    int n = strlen(t);
    int i,j;
    for (i = 0;i <= m;i++)
        d[i][0] = i; // deletion
    for (j = 0;j <= n;j++)
        d[0][j] = j; // insertion
    for (j = 1;j <= n;j++)
        for (i = 1;i <= m;i++)
            if (s[i - 1] == t[j - 1])
                d[i][j] = d[i - 1][j - 1];
            else
                d[i][j] = minimo(
                             d[i - 1][j] + 1, // deletion
                             d[i][j - 1] + 1, // insertion
                             d[i - 1][j - 1] + 1 // substitution
                          );
    return d[m][n];
}

void percorreFilmes(TFilme *inicio, char nome[])
{
     while(inicio != NULL)
     {
        if(strcmp(nome, inicio->nome) != 0)
        {                   
          if( distanciaLevenshtein(nome, inicio->nome) <= 2)
    	      printf("Filme 1 %s Filme 2 %s \n",nome, inicio->nome);
        }
	    inicio=inicio->prox;
     }       
}

void imprimeDistancia2Filmes(TFilme *inicio)
{
     TFilme *aux = inicio;
     while(aux != NULL)
     {
	    percorreFilmes(inicio, aux->nome);
	    aux=aux->prox;
     }      
}

void percorreAtores(TAtor *inicio, char nome[])
{
     while(inicio != NULL)
     {
        char teste1[100];
        strcpy(teste1, inicio->nome);
        if(strcmp(nome, inicio->nome) != 0)
        {                   
          if( distanciaLevenshtein(nome, inicio->nome) <= 2)
    	      printf("Ator 1 %s Ator 2 %s \n",nome, inicio->nome);
        }
	    inicio=inicio->prox;
     }       
}

void imprimeDistancia2Atores(TAtor *inicio)
{
     TAtor *aux = inicio;
     while(aux != NULL)
     {
	    percorreAtores(inicio, aux->nome);
	    aux=aux->prox;
     }      
}

void imprimeAtoresDiretor(TFilme *inicio, char diretor[])
{
     /*TAtor *inicioAtorAux = NULL, *ator;           
     TFilme *inicioFilmeAux = inicio;                
     inicioFilmeAux->atores = NULL;
     TAtoresFilme *atores = NULL;
     while(inicio != NULL)
     {
        if(strcmp(diretor, inicio->diretor) == 0)
        {           
           atores = inicio->atores;
           while(atores != NULL)
           {           
              ator = procuraAtor(inicioAtorAux, (atores->ator)->nome);
              if (ator == NULL)
                ator = insereAtor(&inicioAtorAux, (atores->ator)->nome);
              insereAtorEmFilme(&(inicioFilmeAux)->atores, ator);
              atores = atores->prox;
           }
        }
	    inicio=inicio->prox;
     }           
     atoresEmFilme(inicioFilmeAux->atores);                    
     */
     TAtor *inicioAtorAux = NULL, *ator;           
     TAtoresFilme *atores = NULL;
     while(inicio != NULL)
     {
        if(strcmp(diretor, inicio->diretor) == 0)
        {           
           atores = inicio->atores;
           while(atores != NULL)
           {           
              ator = procuraAtor(inicioAtorAux, (atores->ator)->nome);
              if (ator == NULL)
                ator = insereAtor(&inicioAtorAux, (atores->ator)->nome);
              atores = atores->prox;
           }
        }
	    inicio=inicio->prox;
     }           
    imprimeAtores(inicioAtorAux);                                  
}


void removeAtor(TAtor **inicio, char nome[])
{    
    TAtor *aux;
    if (*inicio == NULL) return;
    if (strcmp((*inicio)->nome, nome) != 0)
    {
        removeAtor(&((*inicio)->prox), nome);
        return;
    }
    aux = *inicio;
    (*inicio) = (*inicio)->prox;
    free(aux);    
}

void removeFilme(TFilme **inicio, char nome[])
{    
    TFilme *aux;
    if (*inicio == NULL) return;
    if (strcmp((*inicio)->nome, nome) != 0)
    {
        removeFilme(&((*inicio)->prox), nome);
        return;
    }
    aux = *inicio;
    (*inicio) = (*inicio)->prox;
    free(aux);    
}

void desalocaAtoresdoFilme(TAtoresFilme **inicio)
{
    if(*inicio==NULL) return;
    desalocaAtoresdoFilme(&(*inicio)->prox);
    free(*inicio);
    *inicio=NULL;
}

void removeFilmedoAtor(TFilmesAtor **inicio, TFilme *filme)
{   
    TFilmesAtor *aux;    
    if (*inicio==NULL) return;
    if ((*inicio)->filme != filme)
    {
        removeFilmedoAtor(&((*inicio)->prox),filme);
        return;
    }
    aux = *inicio;
    (*inicio)=(*inicio)->prox;
    free(aux);    
}

int contaFilmesAtor(TFilmesAtor *filmes)
{
     int qtdFilmes = 0;
     while(filmes != NULL)
     {
	    qtdFilmes++;
	    filmes = filmes->prox;
     }
     return qtdFilmes;    
}

void verificaFimesAtor(TAtor *inicio, TAtor **inicioAtor)
{
    int qtdFilmes = 0;
    qtdFilmes = contaFilmesAtor(inicio->filmes);
    if (qtdFilmes == 0)
        removeAtor(&(*inicioAtor), inicio->nome);
}

void desalocaFilmedeAtores(TFilme *inicio, TAtoresFilme *atores, TAtor **inicioAtor) 
{
   TAtor *ator = NULL;
   while (atores != NULL)
   {
      ator = atores->ator;
      removeFilmedoAtor(&(ator)->filmes, inicio);
      verificaFimesAtor(ator, &(*inicioAtor));
      atores = atores->prox;
   }
}

int opcaoMenu()
{
    int opcao;    
    printf("0 - Sair\n");        
    printf("1 - Listar todos os filmes de um determinado intervalo de anos.\n");    
    printf("2 - Listar todos os filmes em que dois atores dados trabalharam juntos.\n");
    printf("3 - Listar todos os filmes que contiverem no nome um dado substring.\n");
    printf("4 - Listar todos os filmes cujos nomes estejam a uma distância de no máximo duas alterações.\n");
    printf("5 - Listar todos os atores cujos nomes estejam a uma distância de no máximo duas alterações.\n");
    printf("6 - Inserir novos filmes.\n");
    printf("7 - Remoção de filme.\n");
    printf("8 - Inclusão de um dado ator em um filme.\n");
    printf("9 - Lista de todos os atores que trabalharam diretamente com um determinado diretor.\n");
    printf("10 - Lista de todos os filmes que estão duplicados (mesmo nome e ano) no arquivo de dados.\n");
    printf("11 - Lista todos os filmes de um ator.\n");            
    printf("12 - Lista todos o atores de um filme.\n");
    printf("13 - Lista todos os filmes.\n");    
    printf("14 - Lista todos os atores.\n");        
    scanf("%d", &opcao);
    if(opcao<=14 && opcao>=0)
        return opcao;
    else
        return -1;   
}

int main ()
{
    setlocale(LC_ALL, "");
    TFilme *inicioFilme = NULL, *filme;     
    TAtor *inicioAtor = NULL, *ator;      
    int i, opcao = -1, ano, campo = 0, filmeInserido = 0, ano1, ano2, opcaoAtor = -1, ano3, cont = 0;
    FILE *arquivo; //Apontador arquivo
    arquivo = fopen("Resumo.txt","r");
    char linhaArquivo[800], ator1[100], ator2[100], parteNome[100], ator3[100], nomeFilme[100], diretor1[100], nome1[100], linha2;
    char *linha, *nome, *diretor, *nomeAtor, *pos, *virgula = ",", *virgulaComEspaco = " ,", *linha1;  
	while(fgets(linhaArquivo,800,arquivo))
    { //passa por todo arquivo, linha a linha
        //linha1 = replace_str(linhaArquivo, virgula, virgulaComEspaco);
        //linha = strtok(linha1, ",");
        linha = strtok(linhaArquivo, ",");
        strupr(linha);
        while(linha != NULL)
        { 
          if (linha[(strlen(linha)-1)] == '\n') linha[(strlen(linha)-1)] = '\0';                                                             
          //linha[(strlen(linha)-1)] = '\0';
          if (campo==0)
          {
            nome = linha;
            filmeInserido = 0;            
          }
          else if (campo==1)
          {
            ano = atoi(linha);
            
          }
          else if (campo==2)
          {
            diretor = linha;
            }
          else
          {  
            if (filmeInserido == 0)
            {
                filme = insereFilme(&inicioFilme, nome, ano, diretor);
                filmeInserido = 1;
            }
            nomeAtor = linha;
            //if ((pos=strchr(nomeAtor, '\n')) != NULL)
            //    *pos = '\0';                        
            ator = procuraAtor(inicioAtor, nomeAtor);
            if (ator == NULL)
                ator = insereAtor(&inicioAtor, nomeAtor);
            insereFilmeEmAtor(&(ator)->filmes, filme);            
            insereAtorEmFilme(&(filme)->atores, ator);            
          }
          linha = strtok(NULL, ",");
          campo++;
        }  
        campo = 0;
        cont++;
    }
	fclose(arquivo);
	
    while(opcao!=0)
    {
        printf("\n");
        opcao = opcaoMenu();    
        if(opcao!=-1)
        {
            switch(opcao)
            {
               case 1: // Listar todos os filmes de um determinado intervalo de anos.
                 printf("Informe o intervalo de anos para a consulta:\n");
                 printf("Ano1: ");
                 scanf("%d", &ano1);
                 printf("Ano2: ");
                 scanf("%d", &ano2);
                 listaFilmesIntervaloAnos(inicioFilme, ano1, ano2);                 
               break;
            
               case 2: // Listar todos os filmes em que dois atores dados trabalharam juntos.
                 printf("Informe os atores para a consulta:\n");
                 printf("Ator1: ");
                 flush_in();
                 gets(ator1);
                 printf("Ator2: ");
                 gets(ator2);
                 strupr(ator1);
                 strupr(ator2);
                 listaFilmesAtores(inicioFilme, ator1, ator2);
               break;
               
               case 3: // Listar todos os filmes que contiverem no nome um dado substring.
                 printf("Informe parte do nome do filme que deseja consultar:\n");
                 flush_in();                 
                 gets(parteNome);
                 strupr(parteNome);
                 listaFilmesNome(inicioFilme, parteNome);
               break;               
               
               case 4: // Listar todos os filmes cujos nomes estejam a uma distância de no máximo duas alterações.
                    imprimeDistancia2Filmes(inicioFilme);
               break;
               
               case 5: // Listar todos os atores cujos nomes estejam a uma distância de no máximo duas alterações.
                    imprimeDistancia2Atores(inicioAtor);                 
               break;
               
               case 6: // Inserir novos filmes (o que inclui a atualização na lista de atores de todos os
                       // atores que trabalharem no filme). Se o filme já existir, emitir uma mensagem de erro.
                    flush_in();                                        
                    printf("Informe o nome do filme:");
                    gets(nome1);
                    printf("Informe o ano do filme:");
                    scanf("%d", &ano3);
                    flush_in();                     
                    printf("Informe o diretor do filme:");
                    gets(diretor1);
                    filme = procuraFilme(inicioFilme, nome1);
                    if (filme == NULL)
                    {        
                        strupr(nome1);
                        strupr(diretor1);
                        filme = insereFilme(&inicioFilme, nome1, ano3, diretor1);
                        printf("Filme %s inserido.\n", nome1);                                                                                         
                        while(opcaoAtor!=0)
                        {                        
                            printf("Informe o ator do filme ou 0 para cancelar:");
                            gets(nomeAtor);
                            strupr(nomeAtor);
                            if (strcmp(nomeAtor, "0") != 0)
                            {                            
                                ator = procuraAtor(inicioAtor, nomeAtor);
                                if (ator == NULL)
                                {
                                    ator = insereAtor(&inicioAtor, nomeAtor);
                                    printf("Ator %s inserido.\n", nomeAtor);                                                                                                     
                                }
                                insereFilmeEmAtor(&(ator)->filmes, filme);
                                insereAtorEmFilme(&(filme)->atores, ator);
                            }
                            else opcaoAtor = 0;
                        }
                    }
                    else
                        printf("Este filme jah existe.\n");                
               break;
               
               case 7: // Remoção de filmes (incluindo a remoção do filme na lista de cada um dos
                       // atores que participaram do mesmo. Se o ator ficar sem nenhum filme, remover o ator da lista de atores)
                    flush_in();                                        
                    printf("Informe o nome do filme:");
                    gets(nome1);  
                    strupr(nome1);                                         
                    filme = procuraFilme(inicioFilme, nome1);
                    if (filme != NULL)
                    {                   
                        desalocaFilmedeAtores(filme, filme->atores, &inicioAtor);
                        desalocaAtoresdoFilme(&(filme)->atores);
                        removeFilme(&inicioFilme, nome1);
                    }       
                    else
                        printf("Filme nao encontrado.\n");                                    
               break;
               
               case 8: // Inclusão de um dado ator em um filme (se o ator ainda não existir na lista de atores deve ser incluído)
                    printf("Informe o filme:");
                    flush_in();                     
                    gets(nome1);
                    strupr(nome1);
                    filme = procuraFilme(inicioFilme, nome1);               
                    if (filme != NULL)
                    {
                        printf("Informe o ator:");                        
                        gets(nomeAtor);
                        strupr(nomeAtor);                           
                        ator = procuraAtor(inicioAtor, nomeAtor);
                        if (ator == NULL)
                        {
                            ator = insereAtor(&inicioAtor, nomeAtor);
                            printf("Ator %s inserido.\n", nomeAtor);                                                                                                     
                        }
                        if (procuraAtorEmFilme(filme->atores, nomeAtor) == NULL)
                            insereAtorEmFilme(&(filme)->atores, ator);
                        else
                            printf("Ator %s jah esta no filme.\n", nomeAtor);                                                                                                                             
                        if (procuraFilmeEmAtor(ator->filmes, nome1) == NULL)                            
                            insereFilmeEmAtor(&(ator)->filmes, filme);
                        else
                            printf("Filme %s jah esta no ator.\n", nome1);                                                                                                                             
                    }
                    else
                        printf("Filme nao encontrado.\n");                                    
               break;
               
               case 9: // Lista de todos os atores que trabalharam diretamente com um determinado diretor.
                    printf("Informe o diretor do filme:");
                    flush_in();                      
                    gets(diretor1);       
                    strupr(diretor1);
                    imprimeAtoresDiretor(inicioFilme, diretor1);
               break;
               
               case 10: // Lista de todos os filmes que estão duplicados (mesmo nome e ano) no arquivo de dados.
                    imprimeFilmesDuplicados(inicioFilme);                    
               break;            
 
               case 11: // Lista todos os filmes de um ator.
                    printf("Informe o ator:");
                    flush_in();                    
                    gets(nomeAtor);  
                    strupr(nomeAtor);
                    ator = procuraAtor(inicioAtor, nomeAtor);
                    if (ator != NULL)
                        filmesEmAtor(ator->filmes);
                    else
                        printf("Ator nao encontrado. \n");                    
               break;                           
 
               case 12: // Lista todos os atores de um filme.
                    printf("Informe o filme:");
                    flush_in();                      
                    gets(nome1);  
                    strupr(nome1);                                                     
                    filme = procuraFilme(inicioFilme, nome1);
                    if (filme != NULL)
                        atoresEmFilme(filme->atores);               
                    else
                        printf("Filme nao encontrado. \n");                                        
               break;                                          
               
               case 13: // Lista todos os filmes.
                    imprimeFilmes(inicioFilme);                                   
               break;                                          
               
               case 14: // Lista todos os atores.
                    imprimeAtores(inicioAtor);                                  
               break;                                                                        

            }                    
        }
        else
            printf("Opcao invalida.");    
    }
	system("pause");	
}
