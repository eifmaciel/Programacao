#include<stdlib.h>
#include<stdio.h>

#define N 5
int substring(char str[N], char str2[5], int i, int k){
	if (str[i]!='\0'){
		if (str[i]==str2[k]){
			substring(str, str2, i+1, k+1);
		}
		else{
			return 0;
		}
		
	}
}