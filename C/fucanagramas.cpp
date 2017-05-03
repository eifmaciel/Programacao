#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define n 100

void lerstring(char str[n]){
     int i=0;
     
     printf("Digite a string:\n");
     fgets(str, n, stdin);
     
     while(str[i]!='\0' && str[i]!='\n'){
         i++;
     }
     str[i]='\0';
}

int anagramas(char str1[n], char str2[n]){
    int i, j;
    
    for(i=0; str1[i]!='\0'; i++ ){
       for(j=0; str2[j]!='\0';j++){
           if(toupper(str1[i]) == toupper(str2[j]) && str1[i]!= ' '){
                str1[i]='#';
                str2[j]='#';
                break;
           }
       }
    }
    for(i=0; str1[i]!='\0'; i++){
        if(str1[i]!='#' && str1[i]!=' '){
            return 0;
        }
    }
    for(i=0; str2[i]!='\0'; i++){
        if(str2[i]!='#' && str2[i]!=' '){
            return 0;
        }
    }
    return 1;
}


int main(){
    char str1[n], str2[n];
    
    lerstring(str1);
    lerstring(str2);
    if (anagramas(str1, str2)){
       printf("eh anagrama. \n");
    }
    else{
       printf("Nao eh anagrama. \n");
    }
    system("pause");
}        
