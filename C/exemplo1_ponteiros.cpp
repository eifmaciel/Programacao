#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct nodo {
        char nome[30]; 
        struct nodo *prox;
}Tnodo;

int main (){
    int i, x;
    char nome[30];
    Tnodo * inicio, * aux ;
    
    printf("Digite os nomes:");
    scanf("%s", nome);
    inicio=(Tnodo *)malloc(sizeof(Tnodo));
    strcpy(inicio->nome, nome);
    inicio->prox=NULL ;
    printf("Digite 1 para ADD outro nome ou 0 para Sair");
    scanf("%d", &x);
    
    while(x!=0){
        printf("Digite os nomes:");
        scanf("%s", nome);
        aux=(Tnodo*)malloc(sizeof(Tnodo));
        strcpy(aux->nome, nome);
        aux->prox=inicio;
        inicio=aux;
        printf("Digite 1 para ADD outro nome ou 0 para Sair");
        scanf("%d", &x);
    }
    aux = inicio;

    while(aux != NULL){
            printf("%s\n", aux->nome);
            aux = aux->prox;        
    };

    system("pause");
}
