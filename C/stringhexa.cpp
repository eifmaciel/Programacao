#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>


int main(){
    char str[10];
    int i, j=0, num=0;
    
    printf("Digite o valor hexadecimal:");
    fgets(str, 10, stdin);
    
    j=strlen(str)-1;
    str[j]= '\0';
    j--;
    
    for (i=0; str[i] != '\0' ; i++, j--){
        if(str[i]>='A' && str[i]<='F'){
            num+=(str[i]-55)*pow(16, j);
        }
        else if(str[i]>='a' && str[i]<='f'){
            num+=(str[i]-87)*pow(16, j);
        }
        else{
             num+=(str[i]-48)*pow(16, j);
        }
    }
    printf("Numero em hexadecimal: %s, em Decimal : %d\n", str, num);
    system("pause");   
}
