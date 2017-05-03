#include<stdio.h>
#include<stdlib.h>


void binary(int num){
	if(num>0){
		binary(num/2);
		printf("%d",num%2);
	}
}

int main(){
	int num;

	printf("Digite um numero:\n");
	scanf("%d", &num);
	binary(num);
	printf("\n");

}