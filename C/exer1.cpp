#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char str1[1000], str2[1000];
    int i, k, num, j;
    
    printf("Digite a string");
    scanf("%s", str1);
    i=0;
    k=0;
    while(str1[i]!='\0'){
        if(str1[i]!='\#'){
            str2[k++]=str1[i++];
        }
        else{
            i++;
            num=0;
            while(str1[i]>='0' && str1[i]<='9'){
                num=num*10+(str1[i]-'0');
            }
            for(j=0; j<num; j++){
                str2[k++]=' ';
            }
        }
    }
    ////falta copiar espaço
    



}
