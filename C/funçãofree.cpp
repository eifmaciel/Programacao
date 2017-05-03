#include<stdio.h>
#include<stdlib.h>


struct nodo {
       char valor;
       struct nodo *prox;};

/*--------------------------------------------*/

void desaloca (struct nodo **inicio){
     struct nodo *ptaux=*inicio, *ptaux2=NULL;
     while (ptaux!=NULL){
           ptaux2=ptaux;
           ptaux=ptaux->prox;
           free(ptaux2);}
     *inicio=NULL;
}

/*--------------------------------------------*/

void desaloca_recursiva (struct nodo **inicio){
     if (*inicio==NULL) return;
     desaloca(&(*inicio)->prox);
     free(*inicio);
     *inicio=NULL;
}

/*--------------------------------------------*/

void escreve_lista_recursiva(struct nodo *lista){
     if (lista!=NULL){
          printf("%d\n",lista->valor);
          escreve_lista_recursiva(lista->prox);
    }
}

/*--------------------------------------------*/

struct nodo *procura(struct nodo *inicio,int n){
       if (inicio==NULL) return NULL;
       if (inicio->valor==n) return inicio;
       return procura(inicio->prox,n);
}

/*--------------------------------------------*/

int compara(struct nodo * inicio1 , struct nodo * inicio2){
    if ( inicio1 == NULL && inicio2 == NULL ) return 1;
    if ( inicio1 == NULL || inicio2 == NULL ) return 0;
    if ( strcmp ( inicio1 ->nome , inicio2 -> nome )!=0) return 0;
    return compara ( inicio1 ->prox , inicio2 -> prox );
}

/*--------------------------------------------*/
int main (){
    int i, x, num;
    struct nodo *inicio=NULL, *aux=NULL, *aux2;
    
    for(i=0; i<5; i++){
        printf("Digite um numero:");
        scanf("%d", &num);
        aux=(struct nodo *)malloc(sizeof(struct nodo));
        aux->valor=num;
        aux->prox=NULL;
        if (inicio==NULL){
            inicio=aux;
        }
        else{
            aux2=inicio;
            while (aux2->prox!=NULL){
                  aux2=aux2->prox;
            }
            aux2->prox=aux;
            
        }
    }
    escreve_lista_recursiva(inicio);
    system("pause");
}
