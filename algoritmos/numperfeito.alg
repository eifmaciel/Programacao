algoritmo "numeros perfeitos"

var
num,i,d, p:inteiro
inicio
    enquanto p<=9 faca
        i<-0
        d<-0
        escreva("Digite um numero:")
        leia(num)
        para i de 1 ate num passo 1 faca
            se (num%i=0) e (i<num)entao
                d<-d+i
            fimse
        fimpara
        se (d=num)entao
            p<-p+1
            escreval("É um numeroperfeito: ",num)
        fimse

    fimenquanto
    
            

fimalgoritmo
