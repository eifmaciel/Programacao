#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char mat[10][100], aux[100];
    int i, j;
    
    
    for(i=0; i<10; i++){
        printf("Digite o nome:");
        fgets(mat[i], 100, stdin);
    }
    mat[i][strlen(mat[i]-1)] = '\0';
    
    
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            if(strcmp(mat[j], mat[j+1])>0){
                strcpy(aux, mat[j]);
                strcpy(mat[j], mat[j+1]);
                strcpy(mat[j+1], aux);
            }
        }
    }
    for(i=0; i<10; i++){
        printf("%d : %s\n", i , mat[i]);
    }
    system("pause");
}
