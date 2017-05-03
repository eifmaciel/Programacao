#include<stdio.h>
#include<stdlib.h>

#define N 10

int busca(int vet[n], int n, int p){
    if(p==N){
        return(p);
    }
    else if(vet[p]==n){
        return(-1);
    }
    else{
         return(busca(vet, n, p+1));
    }
}

int main(){
    printf("Busca: %d\n", busca(vet,10,0));

}
