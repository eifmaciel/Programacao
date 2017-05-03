#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int main(){
    char str[100];
    int i, j=0, k, espaco=0;
    
    printf("Digite a String:");
    fgets(str, 100, stdin);
    i=0;
    while(str[i]!= '\n' && str[i] !='\0'){
        i++;
    }
    str[i]='\0';
    for(i=0,k=0; str[i]!='\0';i++){
        if(str[i]!= ' '){
            str[k++]=str[i];
        }
        else if(k!=0 && str[i+1]!= ' ' && str[i+1]!='\0'){
            str[k++]=str[i];
        }
    }
    str[k]='\0';
    printf("%s\n", str);
    system("pause");
}
