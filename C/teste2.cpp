#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,aux;
    int vetor[5];
    printf("Informe 5 Datas:");   
    for(i=0;i<5;i++)
    {
         scanf("%d", &j);
         scanf("%d", &k);
         vetor[i] = k*100+j;
        
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
         printf("%d %d \n",vetor[i]%100, vetor[i]/100);
    }
    system("pause");
}
