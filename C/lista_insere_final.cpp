#include<stdlib.h>
#include<stdio.h>

typedef struct nodo {
        int numero; 
        struct nodo *prox;
}Tnodo;

void escreve_lista_recursiva(Tnodo *lista){
     if (lista!=NULL){
          printf("%d\n",lista->numero);
          escreve_lista_recursiva(lista->prox);
    }
}

int main (){
    int i, x, num;
    char nome[30];
    Tnodo *inicio=NULL, *aux=NULL, *aux2;
    
    for(i=0; i<5; i++){
        printf("Digite um numero:");
        scanf("%d", &num);
        aux=(Tnodo *)malloc(sizeof(Tnodo));
        aux->numero=num;
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
