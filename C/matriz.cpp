#include<stdio.h>
#include<stdlib.h>


/*Matrizes rentabilidade*/

int main(){
    float m[14][12] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {1.0, 0.9, 1.1, 0.8, 1.2, 1.1, 0.9, 0.8, 0.9, 0.7, 0.8, 1.0},
                {0.5, 0.7, 1.0, 0.4, 0.4, 0.5, 0.7, 0.6, 1.4, 1.4, 0.9, 0.2},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    
    int i=0, j=0, mesin=0, mesfim=0, anoin=0, anofim=0 ;
    float valor=0, total=0;
    
    printf("Digite o mes inicial:\n");
    scanf("%d", &mesin);
    printf("Digite o ano inicial:\n");
    scanf("%d", &anoin);
    printf("Digite o valor:\n");
    scanf("%f", &valor);
    printf("Digite o mes final:\n");
    scanf("%d", &mesfim);
    printf("Digite o mes final:\n");
    scanf("%d", &anofim);

    i = anoin-2000;

    for(i=anoin-2000; i<=anofim-2000; i++){
        for(j=0; j<12; j++){
            if (i==anoin-2000 && j-1>=mesin){
                total += m[i][j-1];
            }
            else if(i==anofim-2000 && j-1<=mesfim){
                total += m[i][j-1];
            }
            else if(i<anofim-2000 && i>anoin-2000){
                total += m[i][j-1];
            }
        }
    }
    
    printf("O total eh %f\n", total);
}