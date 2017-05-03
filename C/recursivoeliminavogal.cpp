#include<stdlib.h>
#include<stdio.h>

#define N 100

void elimina_vogal(char str[N], int i, int j){
     if(str[i] == '\0'){
         str[j]='\0';
     }
     else if(str[i]== 'a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
         elimina_vogal(str, i+1, j);
     }
     else{
        str[j]=str[i];
        elimina_vogal(str, i+1, j+1);
     }
}

int main(){
    char str[N]="arara";
    int i=0, j=0;
    
    elimina_vogal(str, i, j);
    printf("elimina vogal:%s", str);
    system("pause");

}
