algoritmo "conjuntos"
// Fun��o :Fazer uni�o, intersec��o, e diferen�a com vetor
// Autor :Eliane
// Data : 10/6/2014
// Se��o de Declara��es 
var
   v:vetor[1..10]de inteiro
   w:vetor[1..10]de inteiro
   r:vetor[1..20]de inteiro
   opcao,n,a,b,k,j,i,p:inteiro
   achou:logico
inicio
    a<-1
    repita
        p<-0
        escreval("Digite o elemento v[",a,"]: ")
        leia(n)
        para i de 1 ate 10 faca
            se (n=v[i])entao
               p<-p+1
            fimse
        fimpara
        se (p=0) e (n>0)entao
           v[a]<-n
           a<-a+1
        fimse
    ate (n<0) ou (a=11)

    b<-1
    repita
        p<-0
        escreval("Digite o elemento w[",b,"]:")
        leia(n)
        para i de 1 ate 10 faca
             se (n=w[i])entao
                p<-p+1
             fimse
        fimpara
        se (p=0)e (n>0)entao
           w[b]<-n
           b<-b+1
        fimse
    ate (n<0) ou (b=11)
    
    repita
        escreval("Digite a opcao desejada:")
        escreval("1- uni�o")
        escreval("2- interse��o")
        escreval("3- subtra��o V-W")
        escreval("4- subtra��o W -V")
        escreval("0- Sair")
        leia(opcao)
    
        se (opcao=1) entao
           para i de 1 ate (a-1) faca
                r[i]<-v[i]
           fimpara
           i<-0
           k<-a
           enquanto (i<(b-1))faca
                j<-0
                i<-i+1
                achou<-falso
                enquanto (j<k)e (achou=falso) faca
                    j<-j+1
                    se (w[i]=r[j])entao
                       achou<-verdadeiro
                    fimse
                fimenquanto
                se (achou=falso) entao
                   r[k]<-w[i]
                   k<-k+1
                fimse
           fimenquanto
           escreval("A uni�o dos conjuntos �:")
           escreva("r= [")
           para p de 1 ate k-1 passo 1 faca
                escreva(r[p],",")
           fimpara
           escreval("]")
        fimse

        se (opcao=2) entao
           i<-0
           k<-0
           enquanto (i<(a-1)) faca
               j<-0
               i<-i+1
               achou<-falso
               enquanto (j<(a-1))e (achou=falso) faca
                   j<-j+1
                   se (v[i]=w[j])entao
                       achou<-verdadeiro
                       k<-k+1
                       r[k]<-v[i]
                   fimse
               fimenquanto
           fimenquanto
           i<-0
           escreva("A intersec��o dos conjuntos �:r= [")
           para i de 1 ate k passo 1 faca
               escreva(r[i],",")
           fimpara
           escreval("]")
        fimse

        se (opcao=3) entao
            i<-0
            k<-0
            enquanto (i<(a-1)) faca
                j<-0
                i<-i+1
                achou<-falso
                enquanto (j<(a-1))e (achou=falso) faca
                    j<-j+1
                    se (v[i]=w[j])entao
                        achou<-verdadeiro
                    fimse
                fimenquanto
                se (achou=falso) entao
                    k<-k+1
                    r[k]<-v[i]
                fimse
            fimenquanto
            i<-0
            escreva("A subtra��o do conjunto V-W �: r= [")
            para i de 1 ate k passo 1 faca
                escreva(r[i],",")
            fimpara
            escreval("]")
        fimse


        se (opcao=4) entao
            i<-0
            k<-0
            enquanto (i<(b-1)) faca
                j<-0
                i<-i+1
                achou<-falso
                enquanto (j<(b-1))e (achou=falso) faca
                    j<-j+1
                    se (w[i]=v[j])entao
                        achou<-verdadeiro
                    fimse
                fimenquanto
                se (achou=falso) entao
                    k<-k+1
                    r[k]<-w[i]
                fimse
            fimenquanto
            i<-0
            escreva("A subtra��o do conjunto W -V �: r= [")
            para i de 1 ate k passo 1 faca
                escreva(r[i],",")
            fimpara
            escreval("]")
        fimse
    ate (opcao=0)


fimalgoritmo
