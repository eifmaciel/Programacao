algoritmo "ordena��o"
// Fun��o :Fazer ordena��o de vetor, crescente , decrescente, buscas: sequencial,bin�ria.
// Autor :Eliane
// Data : 23/6/2014
// Se��o de Declara��es
var
v:vetor[1..50]de inteiro
j,i,n,aux,opcao,m, dado:inteiro
achou, ordenado:logico
inic, fim, meio, posi:inteiro

inicio
    escreval("Digite o tamanho do vetor:")
    leia(n)
    escreval("Digite o vetor: ")
    para i de 1 ate n faca
        leia(v[i])
    fimpara
    para i de 1 ate n faca
        escreva(v[i])
    fimpara
    ordenado<-Falso
    repita
        escreval("")
        escreval("1 -Ordenar em ordem crescente")
        escreval("2 -Ordenar em ordem decrescente")
        escreval("3 -Fazer busca sequencial")
        escreval("4 -Fazer Binaria")
        escreval("0-Sair")
        leia(opcao)

        se (opcao=1)entao
            para i de 1 ate n faca
                para j de i+1 ate n faca
                    se (v[i]>v[j])entao
                        aux<-v[i]
                        v[i]<-v[j]
                        v[j]<-aux
                    fimse
                fimpara
            fimpara
            escreval("Resultado ordena��o crescente.")
            para i de 1 ate n faca
                escreva(v[i])
            fimpara
            escreval("")
            ordenado<-Verdadeiro
        fimse
        
        se (opcao=2)entao
            para i de 1 ate n faca
                para j de i+1 ate n faca
                    se (v[i]<v[j])entao
                        aux<-v[i]
                        v[i]<-v[j]
                        v[j]<-aux
                    fimse
                fimpara
            fimpara
            escreval("Resultado ordena��o crescente.")
            para i de 1 ate n faca
                escreva(v[i])
            fimpara
            escreval("")
            ordenado<-Verdadeiro
        fimse
        
        se (opcao=3)entao
            escreval("Digite o numero a ser procurado:")
            leia(dado)
            i<-1
            posi<-0
            enquanto (i<=n) e (posi=0) faca
                se (dado=v[i])entao
                    posi<-i
                senao
                    i<-i+1
                fimse
            fimenquanto
            se (posi<>0) entao
                escreval("O dado ",dado," se encontra na posi��o:",i)
            senao
                escreval("O dado",dado," n�o se encontra no vetor.")
            fimse
        fimse
        
        se (opcao=4)e ordenado entao
            escreval("Digite o numero a ser procurado:")
            leia(dado)
            inic<-0
            fim <-n
            meio<-0
            achou <- falso
            enquanto (inic<=fim ) e (achou=Falso) faca
                meio<-(inic+fim)\2
                se (dado=v[meio]) entao
                    achou<-verdadeiro
                senao
                    se (dado<v[meio])entao
                        fim<-meio-1
                    senao
                        inic<-meio+1
                    fimse
                fimse
            fimenquanto
            se achou entao
                escreval("O dado esta na posi��o :",meio)
            senao
                escreval("O dado n�o esta na tabela.")
            fimse
        fimse
        se (opcao=4) e (ordenado=Falso) entao
            escreval("� necessario ordenar o vetor.")
        fimse
        
    ate(opcao=0)ou (opcao>4)

fimalgoritmo
