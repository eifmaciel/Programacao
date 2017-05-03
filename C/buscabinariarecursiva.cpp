#include<stdlib.h>
#include<stdio.h>

#define N 10
//fazer busca binaria

int busca_binaria(int vet[N], int i, int f, int n){
    int m;
    
    if(i>f){
        return -1;
    }
    else{
        m=(i+f)/2;
        if(vet[m]==n){
           return m;
        }
        else if(n<vet[m]){
             return(busca_binaria(vet,n,i, m-1));           
        }
        else{
            return(busca_binaria(vet,n,m+1,f));
        }

}
