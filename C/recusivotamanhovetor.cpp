#include<stdio.h>
#include<stdlib.h>

#define N 10

int maior_num_vetor(int vet[N], int p, int u){
    if(vet[p] == vet[u]){
        return(vet[p]);
    }
    else{
       int m=maior_num_vetor(vet, p+1, u);
       if(m>vet[p]){
          return(m);
       }
       else{
           return(vet[p]);
       }
    }
}


int main(){
   int vet[N]={1,6,8,9,12,15,20,7,17,38};
   
   printf("O maior numero eh: %d", maior_num_vetor(vet, 0, N));
   system("pause");

}
