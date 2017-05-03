#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char func[10][100], auxfunc[100];
    int horario[10];
    int i, j;
    int hora, minuto, segundo, aux;
    
    for(i=0; i<10; i++){
        printf("Digite o nome:\n");
        fgets(func[i], 100, stdin);
        func[i][strlen(func[i])-1]= '\0';
        printf("Digite a hora de entrada:\n");
        scanf("%d %d %d", &hora, &minuto, &segundo);
        getchar();
        horario[i]=hora*3600+minuto*60+segundo; 
    }
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            if(horario[j]>horario[j+1]){
                aux=horario[j];
                horario[j]=horario[j+1];
                horario[j+1]=aux;
                strcpy(auxfunc, func[j]);
                strcpy(func[j], func[j+1]);
                strcpy(func[j+1], auxfunc);
            }
        }
    }
    for(i=0; i<10; i++){
        printf("Funcionarios:%d = %s\n",horario[i], func[i]);
    }
    
    system("pause");   
}
