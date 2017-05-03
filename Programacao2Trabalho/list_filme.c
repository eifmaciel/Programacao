#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

typedef struct filme Filme;
typedef struct ator Ator;
typedef struct filme_do_ator FilmedoAtor;
typedef struct ator_do_filme AtordoFilme;

struct filme {
    char nome[100];
    int ano;
    char diretor[100];
    AtordoFilme *lista_ator;
    Filme *prox;
};

struct ator {
    char nome[100];
    FilmedoAtor *lista_filme;
    Ator *prox;
};

struct filme_do_ator {
    Filme *filme;
    FilmedoAtor *prox;
};

struct ator_do_filme {
    Ator *ator;
    AtordoFilme *prox;
};

// Tira enter de string;
void tirar_enter(char str[100]){
    int j=0;
    while(str[j]!='\n'){
        j++;        
    }
    str[j]='\0';
}

//Transforma em maiusculo strings
void transforma_em_maiusculo(char str[100]){
    int len, i=0;

    for(i=0; str[i]; i++){
       str[i] = toupper(str[i]);
    }
    str[i]= '\0';
}

int minimum ( int a , int b , int c){
    if (a <= b && a <= c) return a;
    if (b <= c ) return b ;
    return c;
}

int LevenshteinDistance(char s[100] , char t[100]){
    int d [100][100];
    int m= strlen (s);
    int n= strlen (t);
    int i ,j ;
    for (i=0; i<=m; i ++){
        d[i][0] = i;
    } // deletion
    for (j=0; j<= n; j ++){
        d[0][j] = j; // insertion
    }
    for (j =1; j <= n; j ++){
        for (i=1; i<=m; i ++){
            if (s[i-1] == t[j-1]){
                d[i][j] = d[i-1][j-1];
            }
            else{
                d[i][j] = minimum (
                    d[i-1][j] + 1, // deletion
                    d[i][j-1] + 1, // insertion
                    d[i-1][j-1] + 1 // substitution
                );
            }
        }
    }
    return d[m][n];
}


//Busca filme com nome e ano recebidos por parametro.
Filme *busca_filme (Filme *nodo, char nome[100], int ano){
    if (nodo == NULL) return NULL ;
    if ((strcmp(nodo->nome , nome)==0) && (nodo->ano == ano)){
        return nodo;
    }
    return busca_filme(nodo->prox , nome, ano);
}

// Busca ator por nome recebido por parametro.
Ator *busca_ator (Ator *nodo, char nome[100]){
    if (nodo == NULL) return NULL ;
    if (strcmp(nodo->nome , nome)==0) return nodo;
    return busca_ator(nodo->prox , nome);
}

// Insere Filme em lista de filmes.
Filme *insere_filme(Filme **nodo){
    Filme *ptaux=NULL,  *ptaux2=NULL;

    ptaux = (Filme *)malloc(sizeof(Filme));
    ptaux->lista_ator = NULL;
    ptaux->prox = NULL;

    if(*nodo == NULL){
        *nodo = ptaux;
        return *nodo;
    }
    else{
        ptaux2 = *nodo;
        while (ptaux2->prox != NULL){
            ptaux2=ptaux2->prox;
        }
        ptaux2->prox = ptaux;
    }
    return ptaux;
}

// Insere Ator em lista de atores.
Ator *insere_ator(Ator **ator_inicio, char ator[100]){
    Ator *aux=NULL,  *aux2=NULL, *busca=NULL;
    FilmedoAtor *filmes_do_ator=NULL, *auxfilme=NULL;

    busca = busca_ator(*ator_inicio, ator);
    if (busca == NULL){
        // cria o ator
        aux = (Ator *)malloc(sizeof(Ator));
        strcpy(aux->nome, ator);
        aux->lista_filme = NULL;
        aux->prox = NULL;

        if(*ator_inicio == NULL){
            *ator_inicio = aux;
        }
        else{
            aux2 = *ator_inicio;
            while (aux2->prox != NULL){
                aux2=aux2->prox;
            }
            aux2->prox = aux;
        }
        return aux;
    }
    else{
        return busca;
    }
}

// Insere ator em lista de atores do filme.
void insere_ator_do_filme(Ator *ator, Filme *filme){
    AtordoFilme *aux2, *aux;

    aux = (AtordoFilme *)malloc(sizeof(AtordoFilme));
    aux->ator = ator;
    aux->prox = NULL;

    if (filme->lista_ator == NULL){
        filme->lista_ator = aux;
    }
    else{
        aux2 = filme->lista_ator;
        while (aux2->prox != NULL){
            aux2=aux2->prox;
        }
        aux2->prox = aux;
    }
}

// Insere filme em lista de filmes que o ator participou.
void insere_filme_do_Ator(Filme *filme, Ator *ator){
    FilmedoAtor *aux2, *aux;

    aux = (FilmedoAtor *)malloc(sizeof(FilmedoAtor));
    aux->filme = filme;
    aux->prox = NULL;

    if (ator->lista_filme == NULL){
        ator->lista_filme = aux;
    }
    else{
        aux2 = ator->lista_filme;
        while (aux2->prox != NULL){
            aux2=aux2->prox;
        }
        aux2->prox = aux;
    }
}

// Remove ator de lista de atores
void remove_ator(Ator **inicio, char nome[100]){    
    Ator *aux;
    if (*inicio == NULL) return;
    if (strcmp((*inicio)->nome, nome) != 0)
    {
        remove_ator(&((*inicio)->prox), nome);
        return;
    }
    aux = *inicio;
    (*inicio) = (*inicio)->prox;
    free(aux);
}

void busca_lista_fimes_ator(Ator *inicio, Ator **inicioAtor){
    int qtdFilmes = 0;
    qtdFilmes = conta_filmes_ator(inicio->lista_filme);
    if (qtdFilmes == 0)
        remove_ator(&(*inicioAtor), inicio->nome);
}

// Remove filme de lista de filmes.
void remove_filme(Filme **inicio, char nome[100]){    
    Filme *aux;
    if (*inicio == NULL) return;
    if (strcmp((*inicio)->nome, nome) != 0)
    {
        remove_filme(&((*inicio)->prox), nome);
        return;
    }
    aux = *inicio;
    (*inicio) = (*inicio)->prox;
    free(aux);    
}

// Remove lista de atores do filme.s
void remove_atores_filme(AtordoFilme **inicio){
    if(*inicio==NULL) return;
    remove_atores_filme(&(*inicio)->prox);
    free(*inicio);
    *inicio=NULL;
}

// Exclui o fime da lista de filmes do ator.
void exclui_filme_ator(FilmedoAtor **inicio, Filme *filme){   
    FilmedoAtor *aux;    
    if (*inicio==NULL) return;
    if ((*inicio)->filme != filme)
    {
        exclui_filme_ator(&((*inicio)->prox),filme);
        return;
    }
    aux = *inicio;
    (*inicio)=(*inicio)->prox;
    free(aux);    
}

//Conta o numero de filmes da lista de ator.
int conta_filmes_ator(FilmedoAtor *filmes){
    int qtdFilmes = 0;
    while(filmes != NULL){
        qtdFilmes++;
        filmes = filmes->prox;
    }
    return qtdFilmes;    
}


// Recebe a linha do arqui
void cria_conteudo(Filme **filme_inicio, Ator **ator_inicio, char linha[1000]){
    int i=0, j=0;
    char ator[100];
    Ator *meu_ator=NULL;
    Filme *meu_filme=NULL;

    tirar_enter(linha);
    char *tok = linha;

    meu_filme = insere_filme(&(*filme_inicio));

    while ((tok = strtok(tok, ",")) != NULL){
        i++;
        if(i==1){
            strcpy(meu_filme->nome, tok);
        }
        else if(i==2){
            meu_filme->ano = atoi(tok);
        }
        else if(i==3){
            strcpy(meu_filme->diretor, tok);
        }
        else if(i>3){
            strcpy(ator, tok);
            meu_ator = insere_ator(&(*ator_inicio), ator);
            insere_ator_do_filme(meu_ator, meu_filme);
            insere_filme_do_Ator(meu_filme, meu_ator);
        }
        tok = NULL;   
    }
}

// Le arquivo - a cada linha lida chama a função cria conteudo
void le_arquivo(Filme **filme_inicio, Ator **ator_inicio, char nome_arq[100]){
    int ano, i;
    FILE *arquivo;
    char linha[1000];
    char *result;

    arquivo=fopen(nome_arq,"rt");
    while (!feof(arquivo)){
        result = fgets(linha, 1000, arquivo);

        if (result){
            cria_conteudo(&(*filme_inicio), &(*ator_inicio), linha);
        }
    }
    fclose(arquivo);
}

// escreve filmes - dados e atores do filme
void escreve_conteudo(Filme *filme_inicio){
    AtordoFilme *aux;

    while(filme_inicio != NULL){
        printf("\tNome:%s, Ano:%d, Diretor:%s\n", filme_inicio->nome, filme_inicio->ano, filme_inicio->diretor);
        aux = filme_inicio->lista_ator;
        while (aux != NULL){
            printf("\tAtor:%s\n", aux->ator->nome);
            aux = aux->prox;
        }
        filme_inicio = filme_inicio->prox;
    }
}


//escreve lista atores.
void escreve_atores(Ator *ator_inico){

    while(ator_inico != NULL){
        printf("\tNome:%s\n", ator_inico->nome);
        ator_inico = ator_inico->prox;
    }
}

//Exercicios

//1) Listar todos os filmes de um determinado intervalo anos.
void exer_1(Filme *filme_inicio, int ano_inicio, int ano_fim){
    int i=0;
    while(filme_inicio != NULL){
        if(filme_inicio->ano >= ano_inicio && filme_inicio->ano <= ano_fim){
           printf("\tNome:%s, Ano:%d, Diretor:%s\n", filme_inicio->nome, filme_inicio->ano, filme_inicio->diretor);
           printf("\t*-----------------------------------------------------*\n");
           i++;
        }
        filme_inicio = filme_inicio->prox;
    }
    printf("\tSao %d filmes.\n", i);
}

//2) Listar todos os filmes em que dois atores dados trabalharam juntos.
void exer_2(Ator *ator, char nome1[100], char nome2[100]){
    int i=0, j=0;
    Ator *ator1, *ator2;
    FilmedoAtor *filme1, *filme2;
    
    ator1 = busca_ator(ator, nome1);
    ator2 = busca_ator(ator, nome2);

    if(ator1!=NULL && ator2!=NULL){
        printf("\tAtor 1:%s\n", ator1->nome);
        printf("\tAtor 2:%s\n", ator2->nome);
        filme1 = ator1->lista_filme;
        while(filme1 != NULL){
            filme2=ator2->lista_filme;
            while(filme2 != NULL){
                if (strcmp(filme1->filme->nome , filme2->filme->nome)==0){
                   printf("\tNome:%s, Ano:%d, Diretor:%s\n", filme1->filme->nome, filme1->filme->ano, filme1->filme->diretor);
                   printf("\t*---------------------------------------------------------------------------------------*\n");
                   i++;
                }
                filme2 = filme2->prox;
            }
            filme1=filme1->prox;
        }
    }
    if(i){
        printf("\tTrabalharam em %d filmes.\n", i);
    }
    else{
        printf("\tNao trabalharam juntos.\n");
    }
}

//3)Listar todos os filmes que contiverem no nome um dado substring.
void exer_3(Filme *filme, char str2[100]){
    int result=0;
    while (filme!=NULL){
        if(strstr(filme->nome, str2) != NULL){
            printf("\tNome:%s, Ano:%d, Diretor:%s\n", filme->nome, filme->ano, filme->diretor);
            result++;
        }
        filme=filme->prox;
    }
    if (result){
        printf("\tSão %d resultados da pesquisa.\n", result);
    }
    else{
        printf("\tNão existem filmes com este nome.\n");
    }
}

//4) Listar todos os filmes cujos nomes estejam a uma distância de no máximo duas alterações.
void exer_4(Filme *filme){
    Filme *filme2, *filme1;
    int tam1, tam2, distancia=0;

    filme1 = filme;

    while(filme1 != NULL){
        filme2 = filme1->prox;
        while(filme2 != NULL){
            distancia = LevenshteinDistance(filme1->nome, filme2->nome);
            if(distancia == 2){
                printf("\tNome 1:%s\n", filme1->nome);
                printf("\tNome 2:%s\n", filme2->nome);
                printf("\t*-------------------------------------------------*\n");
            }
            filme2 = filme2->prox;
            distancia = 0;
        }
        filme1 = filme1->prox;
    }
}

//5) Listar todos os atores cujos nomes estejam a uma distância de no máximo duas alterações.
void exer_5(Ator *ator){
    Ator *ator1, *ator2;
    int tam1, tam2, distancia=0;

    ator1 = ator;

    while(ator1 != NULL){
        ator2 = ator1->prox;
        while(ator2 != NULL){
            distancia = LevenshteinDistance(ator1->nome, ator2->nome);
            if((distancia == 2)){
                printf("\tNome 1:%s\n", ator1->nome);
                printf("\tNome 2:%s\n", ator2->nome);
                printf("\t*-------------------------------------------------*\n");
            }
            ator2 = ator2->prox;
            distancia=0;
        }
        ator1 = ator1->prox;
    }
}

// 6)Inserir novos filmes (o que inclui a atualização na lista de atores de todos os
// atores que trabalharem no filme). Se o filme já existir, emitir uma mensagem de erro.
void exer_6(Ator **ator, Filme **filme){
    Ator *meu_ator=NULL;
    Filme *meu_filme=NULL, *busca_f=NULL;
    char nome[100], diretor[100], ator_nome[100];
    int ano, tem_ator=0;

    setbuf (stdin,NULL);
    printf("Digite o nome do filme:\n");
    fgets(nome, 100, stdin);
    printf("Digite o ano do filme:\n");
    scanf("%d", &ano);
    setbuf (stdin,NULL);
    printf("Digite o nome do diretor:\n");
    fgets(diretor, 100, stdin);

    //Transforma em maiusculo as strings.
    tirar_enter(nome);
    tirar_enter(diretor);
    transforma_em_maiusculo(nome);
    transforma_em_maiusculo(diretor);

    busca_f = busca_filme(*filme, nome, ano);
    if(busca_f == NULL){
        meu_filme = insere_filme(&(*filme));
        strcpy(meu_filme->nome, nome);
        meu_filme->ano = ano;
        strcpy(meu_filme->diretor, diretor);

        printf("Digite 1 se o filme possui ator:\n");
        scanf("%d", &tem_ator);
        while(tem_ator!=0){
            setbuf (stdin,NULL);
            printf("Digite o nome dos atores\n");
            fgets(ator_nome, 100, stdin);
            tirar_enter(ator_nome);
            transforma_em_maiusculo(ator_nome);
            meu_ator = insere_ator(&(*ator), ator_nome);
            insere_ator_do_filme(meu_ator, meu_filme);
            insere_filme_do_Ator(meu_filme, meu_ator);
            printf("Digite 1 se o filme possui mais ator e 0 se não possui:\n");
            scanf("%d", &tem_ator);
        }
    }
}

// 7) Remoção de filmes (incluindo a remoção do filme na lista de cada um dos
// atores que participaram do mesmo. Se o ator ficar sem nenhum filme, remover o ator da lista
// de atores)
void exer_7(Filme *filme, Filme **filme_inicio, Ator **ator_inicio){
    Filme *filme_aux=NULL;
    Ator *ator=NULL, *aux_ator=NULL;

    while (filme->lista_ator != NULL){
        aux_ator = filme->lista_ator->ator;
        exclui_filme_ator(&(aux_ator)->lista_filme, filme);
        busca_lista_fimes_ator(aux_ator, &(*ator_inicio));
        filme->lista_ator = filme->lista_ator->prox;
    }                 
    remove_atores_filme(&(filme)->lista_ator);
    remove_filme(&(*filme_inicio), filme->nome);
}

// 9) Lista de todos os atores que trabalharam diretamente com um determinado
// diretor.
void exer_9(Filme *filme, char diretor[100]){
    AtordoFilme *aux;
    Filme *aux_filme;

    aux_filme = filme;
    while(aux_filme!=NULL){
        if(strcmp(aux_filme->diretor, diretor) == 0){
            aux = aux_filme->lista_ator;
            while(aux != NULL){
               printf("\tNome do ator:%s\n", aux->ator->nome);
               printf("\t*---------------------------------------------------------------------------------------*\n");
               aux = aux->prox;
            }
        }
        aux_filme = aux_filme->prox;
    }
}

// 10) Lista de todos os filmes que estão duplicados (mesmo nome e ano) no arquivo
// de dados.
void exer_10(Filme *inicio){
    Filme *aux = inicio;
    Filme *filme1 = NULL;
    while(aux != NULL){
        filme1 = aux->prox;
        while (filme1 != NULL){
            if ((strcmp(aux->nome, filme1->nome) == 0) && aux->ano == filme1->ano){
                printf("\t%s %d \n", filme1->nome, filme1->ano);
                printf("\t*---------------------------------------------------------------------------------------*\n");
            }
            filme1 = filme1->prox;
        }
        aux = aux->prox;
    }  
}

int main(){
    Filme *filme_inicio=NULL, *filme_aux=NULL;
    Ator *ator_inicio=NULL, *ator_aux=NULL;
    char nome_arq[100]="resumo.txt";
    int op=0, j=0, ano1, ano2;
    char nome1[100], nome2[100], filme[100];

    setlocale(LC_ALL, "");

    le_arquivo(&filme_inicio, &ator_inicio, nome_arq);
    system("clear");
    
    while(op<15){
        printf("Digite a opção desejada!\n");
        printf("\t1 - Listar todos os filmes de um determinado intervalo de anos.\n");
        printf("\t2 - Listar todos os filmes em que dois atores dados trabalharam juntos.\n");
        printf("\t3 - Listar todos os filmes que contiverem no nome um dado substring.\n");
        printf("\t4 - Listar todos os filmes cujos nomes estejam a uma distância de no máximo duas alterações.\n");
        printf("\t5 - Listar todos os atores cujos nomes estejam a uma distância de no máximo duas alterações.\n");
        printf("\t6 - Listar todos os autores.\n");
        printf("\t7 - Listar todos os filmes com autores.\n");
        printf("\t8 - Inserir novos filmes.\n");
        printf("\t9 - Remoção de filme:\n");
        printf("\t10- Inserção de ator em filme.\n");
        printf("\t11- Lista atores que trabalharam com diretor.\n");
        printf("\t12- Lista filmes duplicados.\n");
        printf("\tDigite 15 para sair:\n");
        scanf("%d", &op);

        if(op==1){
            printf("Digite os anos: Ex:1990, 1992.\n");
            scanf("%d, %d", &ano1, &ano2);
            exer_1(filme_inicio, ano1, ano2);
        }
        else if(op==2){
            setbuf (stdin,NULL);
            printf("Digite os nomes:");
            fgets(nome1, 100, stdin);
            fgets(nome2, 100, stdin);
            tirar_enter(nome1);
            tirar_enter(nome2);
            transforma_em_maiusculo(nome1);
            transforma_em_maiusculo(nome2);
            exer_2(ator_inicio, nome1, nome2);
        }
        else if(op==3){
            setbuf (stdin,NULL);
            printf("Digite o nome do filme para pesquisa:\n");
            fgets(filme, 100, stdin);
            tirar_enter(filme);
            transforma_em_maiusculo(filme);
            exer_3(filme_inicio, filme);
        }
        else if (op==4){
            exer_4(filme_inicio);
        }
        else if (op==5){
            exer_5(ator_inicio);
        }
        else if (op==6){
            escreve_atores(ator_inicio);
        }
        else if (op==7){
            escreve_conteudo(filme_inicio);
        }
        else if (op==8){
            exer_6(&ator_inicio, &filme_inicio);
        }
        else if (op==9){
            setbuf (stdin,NULL);
            printf("Remoção de filme!\n");
            printf("Digite o nome do filme:\n");
            fgets(nome1, 100, stdin);
            printf("Digite o ano do filme:\n");
            scanf("%d", &ano1);

            tirar_enter(nome1);
            transforma_em_maiusculo(nome1);

            filme_aux = busca_filme(filme_inicio, nome1, ano1);
            if (filme_aux != NULL){
                exer_7(filme_aux, &filme_inicio, &ator_inicio);
            }
            else {
                printf("Filme nao encontrado.\n");
            }
        }
        else if (op==10){
            setbuf (stdin,NULL);
            printf("Inclusão de Ator!\n");
            printf("Digite o nome do ator:\n");
            fgets(nome1, 100, stdin);
            printf("Digite o nome do filme:\n");
            fgets(nome2, 100, stdin);
            printf("Digite o ano do filme:\n");
            scanf("%d", &ano1);

            tirar_enter(nome1);
            transforma_em_maiusculo(nome1);
            tirar_enter(nome2);
            transforma_em_maiusculo(nome2);

            filme_aux = busca_filme(filme_inicio, nome2, ano1);
            if (filme_aux != NULL){
                ator_aux = insere_ator(&ator_inicio, nome1);
                insere_ator_do_filme(ator_aux, filme_aux);
                insere_filme_do_Ator(filme_aux, ator_aux);
            }
        }
        else if (op==11){
            setbuf (stdin,NULL);
            printf("Digite o nome do diretor:\n");
            fgets(nome1, 100, stdin);
            tirar_enter(nome1);
            transforma_em_maiusculo(nome1);
            exer_9(filme_inicio, nome1);
        }
        else if (op==12){
            exer_10(filme_inicio);
        }
    }
}