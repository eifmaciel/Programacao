#include<stdlib.h>
#include<stdio.h>

typedef struct nodo {
    int numero; 
    struct nodo *prox;
}Tnodo;

// remocao inicio da lista
void remove_inicio(struct nodo **inicio){
    Tnodo *ptaux=*inicio;
    if(*inicio==NULL) return;
    *inicio=ptaux->prox;
    free(ptaux);
}

// limpar toda lista
void limpa_lista(struct nodo **inicio){
    Tnodo *ptaux=*inicio, *ptaux2=NULL;
    if (*inicio==NULL) return;
    while(*inicio!=NULL){
        *inicio=ptaux->prox;
        free(ptaux);
        ptaux=*inicio;
    }
    *inicio=NULL;
}

//Remove final da lista

void remove_final(struct nodo **inicio){
    Tnodo *ptaux=*inicio;

    if (*inicio==NULL) return;
    if (((*inicio)->prox)==NULL){
        free(*inicio);
        *inicio=NULL;
    }
    else remove_final(&(*inicio)->prox);
}

// Funcao escreve lista: Esta funcao recebe uma lista, enquanto não chegar ao final da lista ela escreve o numero

void escreve_lista(Tnodo *nodo){
    while (nodo!=NULL){
        printf("%d\t",nodo->numero);
        nodo=nodo->prox;
    }
    printf("\n");
}

// Funcao escreve lista: Esta funcao recebe uma lista, enquanto não chegar ao final da lista ela escreve o numero recursivamente
void escreve_lista_recursiva(Tnodo *nodo){
    if (nodo!=NULL){
        printf("%d\n",nodo->numero);
        escreve_lista_recursiva(nodo->prox);
    }
}

// Funcao insere elemento ao final da lista.

void insere_fim(Tnodo **nodo, int n){
    Tnodo *ptaux=NULL, *ptaux2=NULL;

    ptaux = (Tnodo *)malloc(sizeof(Tnodo));
    ptaux->numero = n;
    ptaux->prox = NULL;

    if(*nodo == NULL){
        *nodo = ptaux;
    }
    else{
        ptaux2 = *nodo;
        while (ptaux2->prox != NULL){
            ptaux2=ptaux2->prox;
        }
        ptaux2->prox = ptaux;
    }
}

// Funcao insere elemento no inicio da lista

void insere_inicio(Tnodo **nodo, int n){
    Tnodo *aux=NULL;

    aux=(Tnodo *)malloc(sizeof(Tnodo));
    aux->numero=n;
    aux->prox=*nodo;
    *nodo=aux;
}

int main (){
    int i, x, num, op=0;
    Tnodo *aux=NULL, *raiz=NULL;

    while(op<7){
        printf("Digite 1 para adcionar no inicio:\n");
        printf("Digite 2 para adcionar no final:\n");
        printf("Digite 3 para remover no inicio:\n");
        printf("Digite 4 para remover no final:\n");
        printf("Digite 5 para remover toda lista:\n");
        printf("Digite 6 para escrever lista:\n");
        printf("Digite 7 para sair:\n");

        scanf("%d", &op);

        if(op==1){
            for(i=0; i<5; i++){
                printf("Digite um numero:");
                scanf("%d", &num);
                insere_inicio(&raiz, num);
            }
            escreve_lista(raiz);
        }
        else if(op==2){
            for(i=0; i<5; i++){
                printf("Digite um numero:");
                scanf("%d", &num);
                insere_fim(&raiz, num);
            }
            escreve_lista(raiz);
        }
        else if(op==3){
            remove_inicio(&raiz);
            escreve_lista(raiz);
        }
        else if(op==4){
            remove_final(&raiz);
            escreve_lista(raiz);
        }
        else if(op==5){
            limpa_lista(&raiz);
            escreve_lista(raiz);
        }
        else if (op==6){
            escreve_lista(raiz);
        }
    }
}
