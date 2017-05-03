#include<stdlib.h>
#include<stdio.h>

int main(){
    int x=4, *a, *p;
    //aqui foi pegado o endereço de memoria e colocado no endereço de memoria a;
    a=&x;
    printf("%x\n", a);
    //aqui pegamos o valor do endereço de memoria e colocamos num ponteiro, para escreve-lo basta colocarmos *
    p=&x;
    printf("%x %x\n", p, *p);
    system("pause");
    
}
