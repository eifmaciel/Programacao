#include<stdlib.h>
#include<stdio.h>

int main(){
    int x=4, *a, *p;
    //aqui foi pegado o endere�o de memoria e colocado no endere�o de memoria a;
    a=&x;
    printf("%x\n", a);
    //aqui pegamos o valor do endere�o de memoria e colocamos num ponteiro, para escreve-lo basta colocarmos *
    p=&x;
    printf("%x %x\n", p, *p);
    system("pause");
    
}
