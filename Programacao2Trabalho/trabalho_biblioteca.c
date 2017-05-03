// Sistema de Estrutura de dados - Biblioteca
// Desevolvedora : Eliane Isadora Faveron Maciel
// 2015

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<locale.h>

typedef struct livro Livro;
typedef struct autor Autor;
typedef struct editora Editora;
typedef struct livros_da_editora LivrosEditora;
typedef struct livros_do_autor LivrosAutor;
typedef struct lista_autores ListaAutores;


struct livro {
    char titulo[200], ISBN[20];
    int ano, pag, n_exemp;
    Editora *l_editora;
    ListaAutores *lista_autor;
    Livro *prox;
};

struct autor {
    char nome[100];
    LivrosAutor *lista_livros_autor;
    Autor *prox;
};

struct editora {
    char nome[100];
    LivrosEditora *lista_livros_editora;
    Editora *prox;
};

struct livros_da_editora {
    Livro *livro;
    LivrosEditora *prox;
};

struct livros_do_autor {
    Livro *livro;
    LivrosAutor *prox;
};

struct lista_autores {
    Autor *autor;
    ListaAutores *prox;
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

//Busca livro com titulo ou ISBN recebidos por parametro.
Livro *busca_livro (Livro *nodo, char str[200]){
    if (nodo == NULL) return NULL ;
    if (strcmp(nodo->titulo , str)==0){
        return nodo;
    }
    return busca_livro(nodo->prox, str);
}

Livro *consulta_livro (Livro *nodo, char str[200]){
    if (nodo == NULL) return NULL ;
    if ((strcmp(nodo->titulo , str)==0)||(strcmp(nodo->ISBN, str)==0)){
        return nodo;
    }
    return busca_livro(nodo->prox, str);
}

// Busca autor por nome recebido por parametro.
Autor *busca_autor (Autor *nodo, char nome[100]){
    if (nodo == NULL) return NULL ;
    if (strcmp(nodo->nome , nome)==0) return nodo;
    return busca_autor(nodo->prox , nome);
}

Editora *busca_editora (Editora *nodo, char nome[100]){
    if (nodo == NULL) return NULL ;
    if (strcmp(nodo->nome , nome)==0) return nodo;
    return busca_editora(nodo->prox , nome);
}

// Insere Livro em lista de Livros.
Livro *insere_livro(Livro **inicio, char titulo[200]){
    Livro *ptaux=NULL, *ptaux2=NULL, *ptant=NULL;

    if((*inicio == NULL) || (strcmp((*inicio)->titulo, titulo) >= 0)){
        ptaux = (Livro *)malloc(sizeof(Livro));
        strcpy(ptaux->titulo, titulo); 
        //ptaux->val = val;
        ptaux->lista_autor = NULL;
        ptaux->prox = *inicio;
        *inicio = ptaux;
        return ptaux;
    }
    ptaux2 = *inicio;
    ptant = ptaux2;
    while ((ptaux2->prox != NULL) && (strcmp(ptaux2->titulo, titulo) < 0)){
        ptant = ptaux2;
        ptaux2=ptaux2->prox;
    }
    if(ptaux2->prox == NULL && (strcmp(ptaux2->titulo, titulo) < 0)){
        ptaux = (Livro *)malloc(sizeof(Livro));
        strcpy(ptaux->titulo, titulo); 
        //ptaux->val = val;
        ptaux->lista_autor = NULL;
        ptaux->prox = NULL;
        ptaux2->prox = ptaux;
        return ptaux;
    }
    else{
        ptaux = (Livro *)malloc(sizeof(Livro));
        strcpy(ptaux->titulo, titulo); 
        //ptaux->val = val;
        ptaux->lista_autor = NULL;
        ptaux->prox = ptant->prox;
        ptant->prox = ptaux;
        return ptaux;
    }
}

// Insere Autor em lista de autores.
Autor *insere_autor(Autor **autor_inicio, char autor[100]){
    Autor *aux=NULL,  *aux2=NULL;

    aux = (Autor *)malloc(sizeof(Autor));
    strcpy(aux->nome, autor);
    aux->lista_livros_autor = NULL;
    aux->prox = NULL;

    if(*autor_inicio == NULL){
        *autor_inicio = aux;
    }
    else{
        aux2 = *autor_inicio;
        while (aux2->prox != NULL){
            aux2=aux2->prox;
        }
        aux2->prox = aux;
    }
    return aux;
}

// Insere Editora em lista de editoras.
Editora *insere_editora(Editora **editora_inicio, char nome[100]){
    Editora *aux=NULL,  *aux2=NULL, *busca=NULL;

    aux = (Editora *)malloc(sizeof(Editora));
    strcpy(aux->nome, nome);
    aux->lista_livros_editora = NULL;
    aux->prox = NULL;

    if(*editora_inicio == NULL){
        *editora_inicio = aux;
    }
    else{
        aux2 = *editora_inicio;
        while (aux2->prox != NULL){
            aux2=aux2->prox;
        }
        aux2->prox = aux;
    }
    return aux;
}

// // Insere autor em lista de autores do filme.
void insere_autor_do_livro(Autor *autor, Livro *livro){
    ListaAutores *aux2=NULL, *aux=NULL;

    aux = (ListaAutores *)malloc(sizeof(ListaAutores));
    aux->autor = autor;
    aux->prox = NULL;

    if (livro->lista_autor == NULL){
        livro->lista_autor = aux;
    }
    else{
        aux2 = livro->lista_autor;
        while (aux2->prox != NULL){
            aux2=aux2->prox;
        }
        aux2->prox = aux;
    }
}

// // Insere livro em lista de livros do autor.
void insere_livro_do_Autor(Livro *livro, Autor *autor){
    LivrosAutor *aux2=NULL, *aux=NULL;

    aux = (LivrosAutor *)malloc(sizeof(LivrosAutor));
    aux->livro = livro;
    aux->prox = NULL;

    if (autor->lista_livros_autor == NULL){
        autor->lista_livros_autor = aux;
    }
    else{
        aux2 = autor->lista_livros_autor;
        while (aux2->prox != NULL){
            aux2=aux2->prox;
        }
        aux2->prox = aux;
    }
}

void insere_livro_do_Editora(Livro *livro, Editora *editora){
    LivrosEditora *aux2=NULL, *aux=NULL;

    aux = (LivrosEditora *)malloc(sizeof(LivrosEditora));
    aux->livro = livro;
    aux->prox = NULL;

    if (editora->lista_livros_editora == NULL){
        editora->lista_livros_editora = aux;
    }
    else{
        aux2 = editora->lista_livros_editora;
        while (aux2->prox != NULL){
            aux2=aux2->prox;
        }
        aux2->prox = aux;
    }
}

// // Remove editora de lista de editoras
void remove_editora(Editora **inicio, char nome[100]){    
    Editora *aux=NULL;
    if (*inicio == NULL) return;
    if (strcmp((*inicio)->nome, nome) != 0)
    {
        remove_editora(&((*inicio)->prox), nome);
        return;
    }
    aux = *inicio;
    (*inicio) = (*inicio)->prox;
    free(aux);
}

// // Remove autor de lista de autores
void remove_autor(Autor **inicio, char nome[100]){    
    Autor *aux=NULL;
    if (*inicio == NULL) return;
    if (strcmp((*inicio)->nome, nome) != 0)
    {
        remove_autor(&((*inicio)->prox), nome);
        return;
    }
    aux = *inicio;
    (*inicio) = (*inicio)->prox;
    free(aux);
}

// escreve livros - dados e autores do livro
void escreve_conteudo(Livro *livro_inicio){
    ListaAutores *aux;

    if(livro_inicio == NULL){
        printf("Não possui livros cadastrados.\n");
    }
    else{
        printf("Livros.\n");
    }

    while(livro_inicio != NULL){
        printf("Titulo:%s\nISBN: %s\nAno: %d\nNumero páginas: %d\nNumero Exemplares: %d\nNome Editora:%s\n", livro_inicio->titulo, livro_inicio->ISBN, livro_inicio->ano, livro_inicio->pag, livro_inicio->n_exemp, livro_inicio->l_editora->nome);
        aux = livro_inicio->lista_autor;
        while (aux != NULL){
            printf("Autor:%s\n", aux->autor->nome);
            aux = aux->prox;
        }
        livro_inicio = livro_inicio->prox;
        printf("\n+---------------------------------------------------------------------+\n");
    }
}


// //escreve lista autores.
void consulta_autores(Autor *autor_inicio){
    if(autor_inicio == NULL){
        printf("Não possui autores cadastrados.\n");
    }
    else{
        printf("Autores.\n");
    }

    while(autor_inicio != NULL){
        printf("\tNome:%s\n", autor_inicio->nome);
        autor_inicio = autor_inicio->prox;
    }
}

// escreve lista editoras.
void consulta_editores(Editora *editora_inicio){
    if(editora_inicio == NULL){
        printf("Não possui editoras cadastradas.\n");
    }
    else{
        printf("Editoras.\n");
    }
    while(editora_inicio != NULL){
        printf("\tNome:%s\n", editora_inicio->nome);
        editora_inicio = editora_inicio->prox;
    }
}
 
// void remove_livro_editora(LivrosEditora **inicio, char nome_livro[200]){
//     LivrosEditora  *aux=NULL, *ant=NULL;

//     if (*inicio == NULL) return;
//     if (strcmp((*inicio)->livro->titulo, nome_livro) != 0)
//     {
//         remove_livro_editora(&((*inicio)->prox), nome_livro);
//         return;
//     }
//     aux = *inicio;
//     (*inicio) = (*inicio)->prox;
//     free(aux);
// }

// void remove_livro_autor(LivrosAutor **inicio, char nome_livro[200]){
//     LivrosAutor  *aux=NULL, *ant=NULL;

//     if (*inicio == NULL) return;
//     if (strcmp((*inicio)->livro->titulo, nome_livro) != 0)
//     {
//         remove_livro_autor(&((*inicio)->prox), nome_livro);
//         return;
//     }
//     aux = *inicio;
//     (*inicio) = (*inicio)->prox;
//     free(aux);
// }

void cria_base_dados(Livro **livro_inicio, Autor **autor_inicio, Editora **editora_inicio){
    int i;
    int ano[5] = {1999, 2002, 2005, 2015, 2003};
    int exemp[5] = {19, 2, 20, 25, 3};
    int pag[5] = {999, 202, 25, 215, 363};
    Livro *livro_aux;
    Editora *busca_edit;
    Autor *busca_a;
    char aux[100], aux2[100], aux3[100];
    char isbn[5][15] = {
        "9788587589",
        "9788588798",
        "9788781458",
        "9785877198",
        "9785154598",
    };
    char titulo[5][100] = {
        "Cidades de papel",
        "E o vento levou",
        "Serena",
        "Quem e voce alasca?",
        "Agape",
    };
    char editora[5][100] = {
        "Editora A",
        "Editora B",
        "Editora C",
        "Paulus",
        "Editora FG",
    };
    char autor[5][100] = {
        "John Greem",
        "Rasch Ron",
        "Richard Simonetti",
        "John Greem",
        "Augustu Cury",
    };

    for(i=0; i<5; i++){
        strcpy(aux, titulo[i]);
        transforma_em_maiusculo(aux);
        livro_aux = insere_livro((&(*livro_inicio)), aux);
        livro_aux->ano = ano[i];
        livro_aux->pag = pag[i];
        livro_aux->n_exemp = exemp[i];
        strcpy(livro_aux->ISBN, isbn[i]);
        strcpy(aux2, editora[i]);
        transforma_em_maiusculo(aux2);
        busca_edit = busca_editora(*editora_inicio, aux2);
        if(busca_edit==NULL){
            // cria editora
            busca_edit = insere_editora((&(*editora_inicio)), aux2);
        }
        livro_aux->l_editora = busca_edit;
        insere_livro_do_Editora(livro_aux, busca_edit);
        strcpy(aux3, autor[i]);
        transforma_em_maiusculo(aux3);
        busca_a = busca_autor(*autor_inicio, aux3);
        if(busca_a==NULL){
            // cria autor
            busca_a = insere_autor((&(*autor_inicio)), aux3);
        }
        //add autor na lista
        insere_autor_do_livro(busca_a, livro_aux);
        insere_livro_do_Autor(livro_aux, busca_a);
    }
}

void ordena_lista(Autor **autor){
    Autor *aux=NULL, *inicio=*autor, *ant=NULL;

    if(inicio == NULL)return;
    ant = inicio;
    while(inicio != NULL){
        while(ant != inicio && (strcmp(ant->nome, inicio->nome) < 0)){
            aux = ant;
            aux->prox = inicio->prox;
            inicio->prox = aux;
        }
        ant = inicio;
        inicio = inicio->prox;
    }
}

void remove_autores_filme(ListaAutores **inicio){
    if(*inicio==NULL) return;
    remove_autores_filme(&(*inicio)->prox);
    free(*inicio);
    *inicio=NULL;
}

void exclui_livro_autor(LivrosAutor **inicio, Livro *livro){   
    LivrosAutor *aux;    
    if (*inicio==NULL) return;
    if ((*inicio)->livro != livro)
    {
        exclui_livro_autor(&((*inicio)->prox),livro);
        return;
    }
    aux = *inicio;
    (*inicio)=(*inicio)->prox;
    free(aux);    
}

void exclui_livro_editora(LivrosEditora **inicio, Livro *livro){   
    LivrosEditora *aux;    
    if (*inicio==NULL) return;
    if ((*inicio)->livro != livro)
    {
        exclui_livro_editora(&((*inicio)->prox),livro);
        return;
    }
    aux = *inicio;
    (*inicio)=(*inicio)->prox;
    free(aux);    
}

void remove_livro(Livro **inicio, char nome[100]){    
    Livro *aux;
    if (*inicio == NULL) return;
    if (strcmp((*inicio)->titulo, nome) != 0)
    {
        remove_livro(&((*inicio)->prox), nome);
        return;
    }
    aux = *inicio;
    (*inicio) = (*inicio)->prox;
    free(aux);    
}

void remocao_de_livro(Livro *livro, Livro **livro_inicio, Autor **autor_inicio, Editora **editora_inicio){
    Livro *livro_aux=NULL;
    Autor *autor=NULL, *aux_autor=NULL;

    // exclui_livro_editora(&(livro)->l_editora, livro);
    while (livro->lista_autor != NULL){
        aux_autor = livro->lista_autor->autor;
        exclui_livro_autor(&(aux_autor)->lista_livros_autor, livro);
        livro->lista_autor = livro->lista_autor->prox;
    }                 
    remove_autores_filme(&(livro)->lista_autor);
    remove_livro(&(*livro_inicio), livro->titulo);
    printf("Filme removido com sucesso!\n");
}

int main(){
    Livro *livro_inicio=NULL, *livro_aux=NULL, *busca_l=NULL;
    Autor *autor_inicio=NULL, *autor_aux=NULL, *busca_a=NULL;
    Editora *editora_inicio=NULL, *busca_edit=NULL;
    int op=0, j=0, ano1, ano2, i, autores=0;
    char nome1[200], nome2[100], isbn[20], nome_editora[100], nome_autor[100];
    int n=1, ano, n_pag, n_exemp;

    system("clear");
    
    while(op<15){
        printf("Digite a opção desejada!\n");
        printf("\t1 - Inserir Livro.\n");
        printf("\t2 - Insere autor.\n");
        printf("\t3 - Insere Editora.\n");
        printf("\t4 - Remoção de Autor.\n");
        printf("\t5 - Remoção de Editora.\n");
        printf("\t6 - Remove exemplares.\n");
        printf("\t7 - Consulta Livro.\n");
        printf("\t8 - Consulta Autores.\n");
        printf("\t9 - Consulta Editoras.\n");
        printf("\t10 - Consulta Livros.\n");
        printf("\t11 - Consulta Livro do autor.\n");
        printf("\t12 - Consulta Livro da editora.\n");
        printf("\t13 - Remoção do livro.\n");
        printf("\t14 - Criar base teste.\n");
        printf("\tDigite 16 para sair:\n");
        scanf("%d", &op);

        // Inserir Livro
        if(op==1){
            system("clear");
            while(n>0){
                setbuf (stdin,NULL);
                printf("Digite o titulo do livro:\n");
                fgets(nome1, 100, stdin);
                tirar_enter(nome1);
                transforma_em_maiusculo(nome1);
                busca_l = busca_livro(livro_inicio, nome1);
                if(busca_l==NULL){
                    livro_aux = insere_livro(&livro_inicio,  nome1);
                    printf("Digite o ISBN do livro:\n");
                    setbuf (stdin,NULL);
                    fgets(isbn, 20, stdin);
                    tirar_enter(isbn);
                    printf("Digite o ano do livro:\n");
                    scanf("%d", &ano);
                    printf("Digite o numero de páginas do livro:\n");
                    scanf("%d", &n_pag);
                    printf("Digite o número de exemplares do livro:\n");
                    scanf("%d", &n_exemp);
                    strcpy(livro_aux->ISBN, isbn);
                    livro_aux->ano = ano;
                    livro_aux->pag = n_pag;
                    livro_aux->n_exemp = n_exemp;
                    setbuf (stdin,NULL);
                    printf("Digite o nome da editora do livro:\n");
                    fgets(nome_editora, 100, stdin);
                    tirar_enter(nome_editora);
                    transforma_em_maiusculo(nome_editora);
                    busca_edit = busca_editora(editora_inicio, nome_editora);
                    if(busca_edit==NULL){
                        // cria editora
                        busca_edit = insere_editora(&editora_inicio, nome_editora);
                    }
                    livro_aux->l_editora = busca_edit;
                    insere_livro_do_Editora(livro_aux, busca_edit);
                    // inserir autores
                    printf("Digite 1 para inserir autores do livro, digite 0 se não possui autores:\n");
                    scanf("%d", &autores);
                    while(autores != 0){
                        printf("Digite o nome do autor do livro:\n");
                        setbuf (stdin,NULL);
                        fgets(nome_autor, 100, stdin);
                        tirar_enter(nome_autor);
                        transforma_em_maiusculo(nome_autor);
                        busca_a = busca_autor(autor_inicio, nome_autor);
                        if(busca_a==NULL){
                            // cria autor
                            busca_a = insere_autor(&autor_inicio, nome_autor);
                        }
                        //add autor na lista
                        insere_autor_do_livro(busca_a, livro_aux);
                        insere_livro_do_Autor(livro_aux, busca_a);

                        printf("Digite 1 para inserir autores do livro, digite 0 se não possui autores:\n");
                        scanf("%d", &autores);
                    }
                }
                else{
                    busca_l->n_exemp++;
                    printf("Livro já cadastrado. Adicionado exemplar do livro.\n");
                }

                printf("Digite 1 para inserir mais livros e 0 para parar:\n");
                scanf("%d", &n);
            }
        }
        // Insere autor
        else if(op==2){
            system("clear");
            printf("Digite o nome do autor:\n");
            setbuf (stdin,NULL);
            fgets(nome_autor, 100, stdin);
            tirar_enter(nome_autor);
            transforma_em_maiusculo(nome_autor);
            busca_a = busca_autor(autor_inicio, nome_autor);
            if(busca_a==NULL){
                insere_autor(&autor_inicio, nome_autor);
                printf("cadastrado com sucesso.\n");
            }
            else{
                printf("Autor já cadastrado.\n");
            }
        }
        // Insere Editora
        else if(op==3){
            system("clear");
            printf("Digite o nome da editora:\n");
            setbuf (stdin,NULL);
            fgets(nome_editora, 100, stdin);
            tirar_enter(nome_editora);
            transforma_em_maiusculo(nome_editora);
            busca_edit = busca_editora(editora_inicio, nome_editora);
            if(busca_edit==NULL){
                insere_editora(&editora_inicio, nome_editora);
                printf("Cadastrado com sucesso.\n");
            }
            else{
                printf("Editora já cadastrado.\n");
            }
        }
        // Remoção de Autor
        else if(op==4){
            system("clear");
            printf("Digite o nome do autor\n");
            setbuf (stdin,NULL);
            fgets(nome_autor, 100, stdin);
            tirar_enter(nome_autor);
            transforma_em_maiusculo(nome_autor);
            busca_a = busca_autor(autor_inicio, nome_autor);
            if(busca_a==NULL){
                printf("Autor não encontrado.\n");
            }
            else{
                if(busca_a->lista_livros_autor == NULL){
                    remove_autor(&autor_inicio, nome_autor);
                    printf("Autor removido.\n");
                }
                else{
                    printf("Autor possui livros não pode ser excluido.\n");
                }
            }
        }
        // Remoção de Editora.
        else if(op==5){
            system("clear");
            printf("Digite o nome da editora.\n");
            setbuf (stdin,NULL);
            fgets(nome_editora, 100, stdin);
            tirar_enter(nome_editora);
            transforma_em_maiusculo(nome_editora);
            busca_edit = busca_editora(editora_inicio, nome_editora);
            if(busca_edit==NULL){
                printf("Editora não encontrado.\n");
            }
            else{
                if(busca_edit->lista_livros_editora == NULL){
                    remove_autor(&autor_inicio, nome_autor);
                    printf("Editora removido.\n");
                }
                else{
                    printf("Editora possui livros não pode ser excluido.\n");
                }
            }
        }
        // Remove exemplares
        else if(op==6){
            system("clear");
            Editora *edit;
            LivrosEditora *livroedit;
            ListaAutores *autorl;
            LivrosAutor *livroaut;

            printf("Digite o titulo do Livro.\n");
            setbuf (stdin,NULL);
            fgets(nome1, 100, stdin);
            tirar_enter(nome1);
            transforma_em_maiusculo(nome1);
            busca_l = busca_livro(livro_inicio, nome1);
            if (busca_l!=NULL){
                if(busca_l->n_exemp==1){
                    remocao_de_livro(busca_l, &livro_inicio, &autor_inicio, &editora_inicio);
                }
                else{
                    busca_l->n_exemp--;
                    printf("Exemplar removido.\n");
                }
            }
            else{
                printf("Livro não encontrado.\n");
            }
        }
        // Consulta livro por titulo ou ISBN
        else if(op==7){
            system("clear");
            ListaAutores *aux=NULL;
            printf("Digite o titulo do livro ou ISBN:\n");
            setbuf (stdin,NULL);
            fgets(nome2, 100, stdin);
            tirar_enter(nome2);
            transforma_em_maiusculo(nome2);
            busca_l = consulta_livro(livro_inicio, nome2);
            if(busca_l!=NULL){
                printf("Titulo: %s\nISBN: %s\nAno: %d\nNumero paginas: %d\nNumero exemplares: %d\n", busca_l->titulo, busca_l->ISBN, busca_l->ano, busca_l->pag, busca_l->n_exemp);
                aux = busca_l->lista_autor;
                while(aux!=NULL){
                    printf("Nome Autor:%s\n", aux->autor->nome);
                    aux = aux->prox;
                }
            }
        }
        // Consulta Autores - Lista Autores
        else if(op==8){
            system("clear");
            consulta_autores(autor_inicio);
        }
        // Consulta Editoras - Lista Editoras
        else if(op==9){
            system("clear");
            consulta_editores(editora_inicio);
        }
        // Lista Livros - Dados do livros e autores do livro
        else if(op==10){
            system("clear");
            escreve_conteudo(livro_inicio);
        }
        // Consulta Livro do autor - Lista todos os livros do autor.
        else if(op==11){
            system("clear");
            printf("Digite o nome do autor:\n");
            setbuf (stdin,NULL);
            fgets(nome2, 100, stdin);
            tirar_enter(nome2);
            transforma_em_maiusculo(nome2);
            busca_a = busca_autor(autor_inicio, nome2);
            if(busca_a!=NULL){
                LivrosAutor *livrosautor;
                livrosautor = busca_a->lista_livros_autor;
                while(livrosautor!=NULL){
                    printf("Titulo do livro: %s\n", livrosautor->livro->titulo);
                    livrosautor = livrosautor->prox;
                }
            }
            else{
                printf("Autor não encontrado.\n");
            }
        }
        // Consulta Livro da Editora - Lista todos os livros da editora.
        else if(op==12){
            system("clear");
            printf("Digite o nome da editora:\n");
            setbuf (stdin,NULL);
            fgets(nome2, 100, stdin);
            tirar_enter(nome2);
            transforma_em_maiusculo(nome2);
            busca_edit = busca_editora(editora_inicio, nome2);
            if(busca_edit!=NULL){
                LivrosEditora *livroseditora;
                livroseditora = busca_edit->lista_livros_editora;
                while(livroseditora!=NULL){
                    printf("Titulo do livro: %s\n", livroseditora->livro->titulo);
                    livroseditora = livroseditora->prox;
                }
            }
            else{
                printf("Editora não encontrada.\n");
            }
        }
        // Remoção do livro - Remove nodo do livro e as ligações do livro com autores e editoras.
        else if(op==13){
            system("clear");
            Editora *edit;
            LivrosEditora *livroedit;
            ListaAutores *autorl;
            LivrosAutor *livroaut;


            printf("Digite o titulo do livro:\n");
            setbuf (stdin,NULL);
            fgets(nome2, 100, stdin);
            tirar_enter(nome2);
            transforma_em_maiusculo(nome2);
            busca_l = busca_livro(livro_inicio, nome2);
            if(busca_l!= NULL){
                remocao_de_livro(busca_l, &livro_inicio, &autor_inicio, &editora_inicio);
            }
        }
        else if(op==14){
            cria_base_dados(&livro_inicio, &autor_inicio, &editora_inicio);
        }
        else if(op==15){
            // tamanho = conta_tamanho(autor_inicio);
            // ordena_lista(&autor_inicio, tamanho);
        }
    }
}