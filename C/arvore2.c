#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
  int numero;
  struct nodo *pEsquerda;
  struct nodo *pDireita;  
}TNodo;

void inOrdem(TNodo *raiz){
    if(raiz==NULL) return;
    inOrdem(raiz->pEsquerda);
    printf("%d\n", raiz->numero);
    inOrdem(raiz->pDireita);
}

void preOrdem(TNodo *raiz){
    if(raiz==NULL) return;
    printf("%d\n", raiz->numero);    
    preOrdem(raiz->pEsquerda);
    preOrdem(raiz->pDireita);
}

int altura(TNodo *raiz){
	
	if(!raiz) return -1;
	int altesq = altura(raiz->pEsquerda);
	int altdir = altura(raiz->pDireita);
	if(altesq>altdir)
		return(altesq + 1);
	else
		return(altdir + 1);
}

void posOrdem(TNodo *raiz)
{
    if(raiz==NULL) return;
    posOrdem(raiz->pEsquerda);
    posOrdem(raiz->pDireita);
    printf("%d\n", raiz->numero);        
}

void inserir(TNodo **pRaiz, int numero)
{
    if (*pRaiz == NULL)
    {
        * pRaiz = (TNodo *) malloc(sizeof(TNodo));
        (*pRaiz)->pEsquerda = NULL;
        (*pRaiz)->pDireita = NULL;
        (*pRaiz)->numero = numero;
    }
    else if(numero <(*pRaiz)->numero)
        inserir(&(*pRaiz)->pEsquerda, numero);
    else
        inserir(&(*pRaiz)->pDireita, numero);
}

int estritamente_binaria(TNodo *raiz){
    
}


int main ()
{    
    TNodo *raiz=NULL;     
    int dado = -1;;
    while(dado!=0)
    {
        printf("Informe o valor ou zero para sair:\n");                                       
        scanf("%d", &dado);
        if(dado!=0) 
           inserir(&raiz, dado);                  
    }
    printf("InOrdem\n");         
    inOrdem(raiz);
    printf("PreOrdem\n");         
    preOrdem(raiz);
    printf("PosOrdem\n");    
    posOrdem(raiz);   
	
	printf("ALTURA=%d\n", altura(raiz));
}
