#include<stdio.h>
#include<stdlib.h>


//Função que ve se a string eh palindromo ou não recursivamente
int palindromo(char str[100], int posinicial, int posfinal){
	if ((str[posinicial] == str[posfinal]) && (str[posinicial] != ' ')){
		if (posinicial==posfinal || posinicial+1 == posfinal){
			return 1;
		}
		else{
			palindromo(str, posinicial+1, posfinal-1);
		}
	}
	else if ((str[posinicial] != str[posfinal]) && (str[posinicial] != ' ')){
		return 0;
	}
}


int main(){
	int posinicial=0, posfinal, i;
	char str[100], literal;
	
	printf("Digite a string: \n");
	fgets(str, 100, stdin);
	i=0;
    while(str[i]!= '\n' && str[i] !='\0'){
        i++;
    }
    str[i]='\0';
	posfinal = i-1;
	if (palindromo(str, posinicial, posfinal)){
		printf("eh palindromo\n");
	}
	else{
		printf("nao eh palindromo \n");
	}
}