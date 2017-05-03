#include<stdio.h>
#include<stdlib.h>

int pitagoras(int enesimo, int i, int count){
	if (i==enesimo){
		return 0;
	}
	else{
		return (count + pitagoras(enesimo, i+1, count+1));
	}
}

int main(){
	int enesimo, count=1;
	
	printf("Digite qual é o numero:\n");
	scanf("%d", &enesimo);
	printf("O numero é:%d\n",pitagoras(enesimo, 0, count));
}