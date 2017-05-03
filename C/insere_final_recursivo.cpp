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

void insere_fim_lista(int n, Tnodo **inicio){
 
    if(*inicio==NULL){
        *inicio=(Tnodo *)malloc(sizeof(Tnodo));
        (*inicio)->numero=n;
        (*inicio)->prox=NULL;
        return;
    }
    insere_fim_lista(n, &(*inicio)->prox);
}

int main (){
    int i, x, num;
    Tnodo *inicio=NULL, *aux=NULL, *aux2;
    
    for(i=0; i<5; i++){
        printf("Digite um numero:");
        scanf("%d", &num);
        insere_fim_lista(num, &inicio);
    }
    escreve_lista_recursiva(inicio);
    system("pause");
}
