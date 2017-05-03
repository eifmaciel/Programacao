algoritmo "cartões natalinos"
var
   en,s,preciso,posso,sobra:inteiro
   r,tot, vs, ve,qntposso:real

inicio
      escreva("Digite a quantidade de selos que você possui:")
      leia(s)
      escreva("Digite a quantidade de envelopes que você possui:")
      leia(en)
      escreva("Digite o valor em reais que você possui:")
      leia(r)
      vs<-0.5
      ve<-0.12
      se en>s entao
         preciso<- en-s
         posso<- r\ vs
         se posso>=preciso entao
            tot=(vs*preciso)
            r<-r-tot
            s<-s+preciso
         senao
              se posso<preciso entao
                 tot<-(vs*posso)
                 r<-r-tot
                 s<-s+posso
              fimse
         fimse
      senao
           se s>en entao
              preciso<-s-en
              posso<-r\ve
              se posso>=preciso entao
                 tot<-(ve*preciso)
                 r<-r-tot
                 s<-s+preciso
              senao
                   se posso<preciso entao
                      tot<-(ve*posso)
                      r<-r-tot
                      s<-s+posso
                   fimse
              fimse
      fimse
      qntposso<-r\(vs+ve)                                 0
      se qntposso>0 entao
         s<-s+qntposso
         en<-en+qntposso
         r<-qntposso*(vs+ve)
      fimse
      se s<en entao
         result<-en-s
         escreva ("Numero de cartas que posso mandar: ",s,"Numero de envelopes que sobraram: ",result)
      senao
           se s<en entao
              result<-s-en
              escreva ("Numero de cartas que posso mandar: ",en,"Numero de selos que sobraram: ",result)
      fimse
      


fimalgoritmo
