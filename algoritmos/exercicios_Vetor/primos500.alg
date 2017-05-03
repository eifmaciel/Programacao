algoritmo "primos vetor"
// Função :calcula os 500 primeiros numeros primos
// Autor : Eliane
// Data : 10/6/2014
// Seção de Declarações
var
n, i,p,j:inteiro
v :vetor[1..500]de inteiro
primo:logico
inicio
  n<-2
  p<-1
  enquanto p<501 faca
      primo<-verdadeiro
      i<-1
      enquanto (i<p) e (primo)e (i<(n/2)) faca
          se (n% v[i]=0)entao
             primo<-falso
          fimse
          i<-i+1
      fimenquanto
      se primo entao
         v[p]<-n
         p<-p+1
      fimse
      n<-n+1
  fimenquanto
  
  para j de 1 ate 500 passo 1 faca
       escreval("v[",j,"]=",v[j])
  fimpara
  
fimalgoritmo
