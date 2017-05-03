#include <stdio.h>
#include <stdlib.h>

// typedef struct nodo {
//     int dado;
//     struct nodo *fesq, *fdir;
// }Tnodo;

// void inserir(Tnodo **pRaiz, int numero){
//     if (*pRaiz == NULL){
//         *pRaiz = (Tnodo *) malloc(sizeof(Tnodo));
//         (*pRaiz)->fesq = NULL;
//         (*pRaiz)->fdir = NULL;
//         (*pRaiz)->dado = numero;
//     }
//     else if(numero <(*pRaiz)->dado){
//         inserir(&(*pRaiz)->fesq, numero);
//     }
//     else{
//         inserir(&(*pRaiz)->fdir, numero);
//     }
// }

// int altura(Tnodo *raiz){

//     if(raiz == NULL){
//         return (-1);
//     }
//     int altesq = altura(raiz->fesq);
//     int altdir = altura(raiz->fdir);
//     if(altesq>altdir){
//         return altesq +1;
//     }
//     else{
//         return altdir +1;
//     }
// }

// void HeapInsert(A, key){
//     heap size[A] ← heap size[A] + 1
//     i ← heap size[A]
//     while i > 1 & A[Parent(i)] < key
//     A[i] ← A[Parent(i)]
//     i ← Parent(i)
//     A[i] ← key
// }

int pai(int index){
    return index/2;
}
void troca(int index1, int index2, int heap[100]){
    int aux;
    aux = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = aux;
}

void corrige_subindo (int index, int heap[100]){
// Se index não é a raiz e o valor do index for maior do que o valor de seu pai ,
// troca seus valores ( index e pai ( index )) e corrige para o pai
    if (index>1 && heap[index]>heap[pai(index)]){
        troca(heap[index] , heap[pai(index)], heap);
        corrige_subindo(pai(index), heap);
    }
}


void insere_heap(int val, int heap[], int tamheap){
    heap[tamheap++]=val;
    corrige_subindo(tamheap-1, heap);
}

int main(){
    // Tnodo *raiz;
    int i, num;
    int heap[100];
    int tamheap=0;

    // for(i=0;i<4; i++){
    //     printf("Digite um numero:\n");
    //     scanf("%d", &num);
    //     inserir(&raiz, num);
    // }
    // printf("%d\n", altura(raiz));
    for (i=0; i<10; ++i){
        printf("Digite um valor:\n");
        scanf("%d", &num);
        insere_heap(num, heap[i], tamheap);
    }
    for(i=0;i<10;i++){
        printf("%d\t", heap[i]);
    }
}
