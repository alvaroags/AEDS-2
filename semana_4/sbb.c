#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sbb.h"

void EE(TipoApontador *Ap){
    TipoApontador Ap1, Ap2;
    Ap1 = (*Ap)->esq;
    (*Ap)->esq = Ap1->dir;
    Ap1->dir = *Ap;
    Ap1->BitE = Vertical;
    (*Ap)->BitE = Vertical;
    *Ap = Ap1;
}

void DD(TipoApontador *Ap){
    TipoApontador Ap1, Ap2;
    Ap1 = (*Ap)->dir;
    (*Ap)->dir = Ap1->esq;
    Ap1->esq = *Ap;
    Ap1->BitD = Vertical;
    (*Ap)->BitD = Vertical;
    *Ap = Ap1;
}

void ED(TipoApontador *Ap){
    TipoApontador Ap1, Ap2;
    Ap1 = (*Ap)->esq;
    Ap2 = Ap1->dir;
    Ap1->BitD = Vertical;
    (*Ap)->BitE = Vertical;
    Ap1->dir = Ap2->esq;
    Ap2->esq = Ap1;
    (*Ap)->esq = Ap2->dir;
    Ap2->dir = *Ap;
    *Ap = Ap2;
}

void DE(TipoApontador *Ap){
    TipoApontador Ap1, Ap2;
    Ap1 = (*Ap)->dir;
    Ap2 = Ap1->esq;
    Ap1->BitE = Vertical;
    (*Ap)->BitD = Vertical;
    Ap1->esq = Ap2->dir;
    Ap2->dir = Ap1;
    (*Ap)->dir = Ap2->esq;
    Ap2->esq = *Ap;
    *Ap = Ap2;
}

void insereSBB(int reg, TipoApontador *Ap, TipoInclinacao *IAp, short *fim){
    if(*Ap == NULL){
        *Ap = (TipoApontador)malloc(sizeof(TNo));
        *IAp = Horizontal;
        (*Ap)->chave = reg;
        (*Ap)->esq = NULL;
        (*Ap)->dir = NULL;
        (*Ap)->BitD = Vertical;
        (*Ap)->BitE = Vertical;
        *fim = 0;
        return;
    }
    if(reg < (*Ap)->chave) {
        insereSBB(reg, &(*Ap)->esq, &(*Ap)->BitE, fim);
        if(*fim) return;
        if((*Ap)->BitE != Horizontal){
            *fim = 1;
            return;
        }
        if((*Ap)->esq->BitE == Horizontal){
            EE(Ap);
            *IAp = Horizontal;
            return;
        }
        if((*Ap)->esq->BitD == Horizontal){
            ED(Ap);
            *IAp = Horizontal;
            return;
        }
    }
    insereSBB(reg, &(*Ap)->dir, &(*Ap)->BitD, fim);
    if(*fim) return;
    if((*Ap)->BitD != Horizontal){
        *fim = 1;
        return;
    }
    if((*Ap)->dir->BitD == Horizontal){
        DD(Ap);
        *IAp = Horizontal;
        return;
    }
    if((*Ap)->dir->BitE == Horizontal){
        DE(Ap);
        *IAp = Horizontal;
    }

}

int altura_h(TipoApontador raiz){
    if(raiz == NULL)
        return -1;
    else{
        int he = altura_h(raiz->esq);
        int hd = altura_h(raiz->dir);
        if(he < hd)
            return hd + 1;
        else
            return he + 1;
    }
}

int altura_k(TipoApontador raiz){
    int he, hd;
    if(raiz == NULL)
        return -1;
    else{
        int he = altura_h(raiz->esq);
        int hd = altura_h(raiz->dir);
        if(he < hd){
            if(raiz->BitE == Vertical)
                return he + 1;
            else
                return he;
        }
        else{
            if(raiz->BitD == Vertical)
                return hd + 1;
            else
                return hd;
        }
    }
}


int main(){
    TipoApontador Dicionario = NULL;
    TipoInclinacao IAp;
    short fim;
    int valor;
    int i = 0;
    while (i < 11)
    {
        printf("digite uma palavra: ");
        scanf("%d", &valor);
        insereSBB(valor, &Dicionario, &IAp, &fim);
        i++;
    }
    printf("altura: %d\n", altura_k(Dicionario));
}