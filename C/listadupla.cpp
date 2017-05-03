#include<stdio.h>
#include<stdlib.h>


struct nodo {
       char valor;
       struct nodo *prox, *ant;};

void insercao_inicio(struct nodo **inicio, struct nodo **fim, int val){
     struct nodo *aux=NULL;
     if(*inicio==NULL){
         *inicio=(struct nodo*)malloc(sizeof(struct nodo));
         (*inicio)->valor=val;
         (*inicio)->ant=NULL;
         (*inicio)->prox=NULL;
         *fim=*inicio;              
     }
     else if(val<(*inicio)->valor){
          aux=(struct nodo*)malloc(sizeof(struct nodo));
          aux->valor=val;
          aux->prox=*inicio;
          aux->ant=NULL;
          *inicio->ant=aux;
     }
}

int main(){
    struct nodo *inicio=NULL, *fim=NULL;
    int i, n;
    
    for(i=0; i<5;i++){    
       printf("Digite o elemento da lista:");
       scanf("%d", n);
       insercao_inicio(&inicio, &fim, n);
    }
}
