#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void insereArvoreTST(TipoApontador *tst,char *palavra){
    if(*tst == NULL){
        *tst = (TipoApontador)malloc(sizeof(tst));
        (*tst)->fimPalavra = 0;
        (*tst)->letra = palavra[0];
        (*tst)->dir = NULL;
        (*tst)->esq = NULL;
        (*tst)->meio = NULL;
    } else{
        if(palavra[0] < (*tst)->letra)
            insereArvoreTST(&(*tst)->esq, palavra);
        else if(palavra[0] > (*tst)->letra)
            insereArvoreTST(&(*tst)->dir, palavra);
        else{
            if(palavra[1] == '\0')
                (*tst)->fimPalavra = 1;
            else
                insereArvoreTST(&(*tst)->meio, palavra+1);
        }
    }
}

int main(){
    TipoApontador tst = NULL;
    char palavra[20];
    while(1){
        printf("digite uma palavra: ");
        scanf("%s", palavra);
        insereArvoreTST(&tst, palavra);
    }
}
