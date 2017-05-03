#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int primo(int n){
    int i, count=0;
    
    for (i=2; i<=sqrt(n); i++){
        if(n%i==0){
           return(0);
        }
    }
    if (n!=1){
       return(1);
    }
    else{
         return (0);
    }
}

int main(){
     int i;
     for (i=1; i<=1000000; i++){
         if (primo(i)){
            printf("%d ",i);
         }
     }
     system("pause");
}
