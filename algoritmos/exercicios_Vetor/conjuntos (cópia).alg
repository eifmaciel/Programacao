algoritmo "ordena��o"
// Fun��o :Fazer ordena��o de vetor, crescente , decrescente.
// Autor :Eliane
// Data : 23/6/2014
// Se��o de Declara��es 
var
   v:vetor[1..10]de inteiro
   j,i,n,aux:inteiro
inicio
        escreval("Digite o vetor: ")
        para i de 1 ate 10 faca
            leia(v[i])
        fimpara
        para i de 1 ate 10 faca
            escreva(v[i])
        fimpara
        escreval("...")
        
        para i de 1 ate 9 faca
             para j de i+1 ate 10 faca
                 se (v[i]>v[j])entao
                    aux<-v[i]
                    v[i]<-v[j]
                    v[j]<-aux
                 fimse
             fimpara
        fimpara
        escreval("Resultado ordena��o crescente ")
        para i de 1 ate 10 faca
            escreva(v[i])
        fimpara
        
        


        
        
        

fimalgoritmo
