#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int main(){
    char str1[100], str2[100];
    int i, j, t1=0, t2=0, cont=0;
    
    printf("Digite a string 2:");
    fgets(str1, 100, stdin);
    printf("Digite a string 2:");
    fgets(str2, 100, stdin);
    
    str1[strlen(str1)-1]='\0';
    str2[strlen(str2)-1]='\0';
    t1 = srtlen(str1);
    t2 = srtlen(str2);
    
    for(i=0, j=0; str1[i]!='\0' || str2[j]!='\0'; i++){
        if (tolower(str1[i]) == tolower(str2[j])){
            cont++;
            j++;
        }   
    }
    if (cont==t2){
        printf("Substring identificada, %s,%s", str1, str2 );
    }
    else{
        printf("Substring nao identificada, %s, %s", str1, str2);
    }
    
}