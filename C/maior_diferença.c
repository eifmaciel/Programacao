#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 6

int maior_diferenca(int vet[N], int i){
    if(i==N-2){
        return (abs(vet[i]-vet[i+1]));
    }
    else {
        int m= maior_diferenca(vet, i+1);
        if (abs(vet[i]-vet[i+1]) > m)){
            return (vet[i]-vet[i+1]);
        }
        else{
            return m;
        }
}

int main(){
    int vet[N]={8,6,3,7,3,2};

    printf("O valor e: %d\n", maior_diferenca(vet, 0));
}