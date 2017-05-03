#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int main(){
    char str[100], stremail[10];
    int i, j=0, espaco=0;
    
    printf("Digite o nome completo:");
    fgets(str, 100, stdin);
    
    str[strlen(str)-1]='\0';
    
    espaco = strlen(str)-1;
    
    while(str[espaco] != ' '){
        espaco--;
    }
    
    for(i=0, j=0; i<espaco; i++){
        if (i==0 || str[i-1] == ' '){
           stremail[j++]= tolower(str[i]);
        }
    }
    for(i=espaco+1; str[i] != 0 && j<8; i++){
        stremail[j++]=tolower(str[i]);
    }
    stremail[j]='\0';
    printf("Email= %s\n", stremail);
    system("pause");
}
    
    
