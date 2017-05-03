#include<stdlib.h>
#include<stdio.h>
#include<string.h>


typedef struct data {
    int dia;
    int mes;
    int ano;
}tdata;


typedef struct cli {
    char nome[30];
    tdata nascimento;
    float saldo;
} cliente;

int main(){
    cliente lista[10]={{"Jose", {9, 10, 1994}, 50.00}, {"Adilson", {12, 11, 1998}, 15.000}, {"Joao", {12, 01, 1998}, 10.000},
    {"Adelson", {30, 01, 1998}, 52.000}, {"Bernardo", {12, 01, 1998}, 30.000},{"William", {12, 01, 1998}, 100.000},{"Eduardo", {12, 01, 1998}, 300.000},
    {"Jonatas", {12, 01, 1998}, 10.000}, {"Teles", {12, 01, 1998}, 40.000}, {"Tiago", {12, 01, 1998}, 99.000}};
    cliente aux;
    int i, j;
    
    
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {         
             if(strcmp(lista[j].nome, lista[j+1].nome) > 0){
                  aux = lista[j];
                  lista[j] = lista[j+1];
                  lista[j+1] = aux;
             }
        }
    }
    
    for(i=0;i<;i++){
        if(lista[i].saldo >= 10.000){
            printf("%s, %d, %d, %d %f\n", lista[i].nome, lista[i].nascimento.dia, lista[i].nascimento.mes, lista[i].nascimento.ano, lista[i].saldo);
        }
    }


    system("pause");
}
