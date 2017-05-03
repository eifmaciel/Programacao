algoritmo "numero piramidal"

var
   con,a,b,i,j,contp,soma,c:inteiro
   
inicio
con<-0
a<-2
b<-3
i<-3
enquanto con<>100 faca
    soma<-0
    i<-i+1
    contp<-0
    para j de 1 ate i passo 1 faca
        se (i%j=0) entao
            contp<-contp+1
        fimse
    fimpara
    se contp=2 entao
        con<-con+1
        c<-i
        soma<-a+b+c
        escreval("Soma dos primos: ",a,"+",b,"+",c,"=",soma)
        a<-b
        b<-c
    fimse
fimenquanto
fimalgoritmo
