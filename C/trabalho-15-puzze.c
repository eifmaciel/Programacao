//Criadora: Eliane Isadora Faveron Maciel
//Este é um trabalho de programação. Tem o objetivo de desnvolver o jogo 15-puzzle.
// Observação este programa foi feito em linux, por este motivo não funcionará corretamente em windows;

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h> 

// Esta função gera a matriz com numeros aleatórios
void gera_matriz(int mat[4][4]){
    int i=0, j=0, k=0, l=0, m=0;
    int vet[16]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    srand( (unsigned)time(NULL) );
    
    for (k=0; k<4; k++){
        for(j=0; j<4; j++){ 
            i = rand() % 16;
            while(vet[i]==1){
                i++;
                if(i>=16){
                    i=0;
                }
            }
            mat[k][j] = i;
            vet[i] = 1;
        }
    } 
}

// Esta função escreve matriz
void escreve_matriz(int mat[4][4]){
    int i, j;

    system("clear");
    printf("\t\t\t15 - Puzzle\n\n\n");
    printf("Digite a função que deseja realizar:\n\tn . Novo Jogo.\n\ts . Para sair.\n\nLetras para movimentar:\n\n\tb = para baixo;\n\tc = para cima;\n\td = para a direita;\n\te = para a esquerda;\n\n\n");
    printf("-----------------------------------------------------------------\n");
    for (i=0; i<4; i++){
        for(j=0; j<4; j++){
            printf("|\t%d\t", mat[i][j]);
        }
        printf("|\n");
        printf("-----------------------------------------------------------------\n");
    }
}

// Esta  função movimenta a posição para baixo
void movimenta_b(int mat[4][4]){
    int aux, i, j;

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if (mat[i][j] == 0 && i > 0){
                mat[i][j] = mat[i-1][j];
                mat[i-1][j] = 0;
            }
        }
    }
}

// Esta função mivimenta para a direita
void movimenta_d(int mat[4][4]){
    int aux, i, j, trocou=0;

    for(i=0; i<4 && trocou == 0; i++){
        for(j=0; j<4 && trocou == 0; j++){
            if (mat[i][j] == 0 && j > 0){
                mat[i][j] = mat[i][j-1];
                mat[i][j-1] = 0;
                trocou = 1;
            }
        }
    }
}

// movimenta para a esquerda
void movimenta_e(int mat[4][4]){
    int aux, i, j, trocou=0;

    for(i=0; i<4 && trocou == 0; i++){
        for(j=0; j<4 && trocou == 0; j++){
            if (mat[i][j] == 0 && j < 3){
                mat[i][j] = mat[i][j+1];
                mat[i][j+1] = 0;
                trocou = 1;
            }
        }
    }
}

// movimenta para cima
void movimenta_c(int mat[4][4]){
    int aux, i, j, trocou=0;

    for(i=0; i<4 && trocou == 0; i++){
        for(j=0; j<4 && trocou == 0; j++){
            if (mat[i][j] == 0 && i < 3){
                mat[i][j] = mat[i+1][j];
                mat[i+1][j] = 0;
                trocou = 1;
            }
        }
    }
}

//função verifica se ganhou!
int verifica(int mat[4][4]){
    int i , j, count=0, n=0;
    
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            n++;
            if (mat[i][j]== n){
                count++;
            }
        }
    }
    if (count==15 && mat[3][3] == 0){
        return 1;
    }
    else{
        return 0;
    }
}

// Este é o jogo chama as funções de movimentar;
int play(int mat[4][4]){
    char comando;
    while(verifica(mat) == 0){
        scanf("%c", &comando);
        if(toupper(comando)=='B'){
            movimenta_b(mat);
            escreve_matriz(mat);
        }
        if (toupper(comando)=='D'){
            movimenta_d(mat);
            escreve_matriz(mat);
        }
        if (toupper(comando)=='E'){
            movimenta_e(mat);
            escreve_matriz(mat);
        }
        if(toupper(comando)=='C'){
            movimenta_c(mat);
            escreve_matriz(mat);  
        }
        if(toupper(comando)=='N'){
            gera_matriz(mat);
            escreve_matriz(mat);
        }
        if(toupper(comando)=='S'){
            return 0;
        }
    }
    return 1;
}

// função principal chama a função de jogo se ganhou mostra a mensagem
int main(){
    int mat[4][4];
    int i,j, c;
    gera_matriz(mat);
    escreve_matriz(mat);

    if (play(mat)){
        printf("Parabéns! Você conseguiu\n");
        printf("Digite 1 para continuar:\n");
        scanf("%d", &c);
        if (c==1){
            gera_matriz(mat);
            escreve_matriz(mat);
            play(mat);
        }
    }
    else{
        return 0;
    }
}