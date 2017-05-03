#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,ano, mes, dia, aux, j;
    int vetor[5];
    printf("Informe 5 Datas:");
    for(i=0;i<5;i++)
    {
         scanf("%d", &dia);
         scanf("%d", &mes);
         scanf("%d", &ano);
         vetor[i] = ano*10000+mes*100+dia;
        
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {         
             if(vetor[i] < vetor[j]){
                  aux = vetor[i];
                  vetor[i] = vetor[j];
                  vetor[j] = aux;
             }
        }
    }           
    for(i=0;i<5;i++)
    {
         printf("ano: %d %d %d \n",vetor[i]/10000, ((vetor[i]%10000)/100), vetor[i]%100);
    }
    system("pause");
}

