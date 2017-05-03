#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
  int numero;
  struct nodo *pEsquerda;
  struct nodo *pDireita;  
}TNodo;

int altura ( struct nodo * raiz ){
    if ( raiz == NULL ) return -1;
    int altesq = altura ( raiz -> fesq );
    int altdir = altura ( raiz -> fdir );
    if ( altesq > altdir ) return altesq +1;
    else return altdir +1;
    }
    int fb ( struct nodo * raiz )
    {
    if ( raiz == NULL ) return 0;
    return altura ( raiz - > fdir ) - altura ( raiz -> fesq );
}

void insere ( struct nodo ** raiz , int valor ){
    if (* raiz == NULL ){
        * raiz =( struct nodo *) malloc ( sizeof ( struct nodo ));
        (* raiz )- > fesq = NULL ;
        (* raiz )- > fdir = NULL ;
        (* raiz )- > num = valor ;
        return ;
    }
    if ( valor < (* raiz ) -> num ){
        insere (&(* raiz )- > fesq , valor );
    }
    else{
        insere (&(* raiz )-> fdir , valor );
    }
}

void balance (struct nodo ** raiz, int valor){
    if (* raiz == NULL ) return ;
    int fbraiz = fb (* raiz );
    int fbesq = fb ((* raiz )- > fesq );
    int fbdir = fb ((* raiz )- > fdir );
    printf (" fb (% d )=% d fbesq =% d fbdir =%d\n" ,(* raiz ) -> num , fbraiz , fbesq , fbdir );
    if (fbraiz ==2 && fbesq == -1){
        rot_dir (&(* raiz )-> fesq ); rot_esq ( raiz ); return ;}
    if (fbraiz ==2 && fbesq ==1){
        rot_esq ( raiz ); return ;}
    if (fbraiz == -2 && fbesq == -1){
        rot_dir ( raiz ); return ;}
    if (fbraiz == -2 && fbesq ==1){
        rot_esq (&(* raiz )-> fesq ); rot_dir ( raiz ); return ;}
    if (fbraiz ==2 && fbdir == -1){
        rot_dir (&(* raiz )-> fdir ); rot_esq ( raiz ); return ;}
    if (fbraiz ==2 && fbdir ==1){
        rot_esq ( raiz ); return ;}
    if (fbraiz == -2 && fbdir == -1){
        rot_dir ( raiz ); return ;}
    if (fbraiz == -2 && fbdir ==1){
        rot_esq (&(* raiz )-> fdir ); rot_dir ( raiz ); return ;}
    if (valor >(* raiz )- > num ){
        balance (&(* raiz )-> fdir , valor );
    }
    else balance (&(* raiz )- > fesq , valor );
}
