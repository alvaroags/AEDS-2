#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

Tno* insere(Tno *raiz, int valor){
    if(raiz == NULL){
        Tno *aux = malloc(sizeof(Tno));
        aux->valor = valor;
        aux->esq = NULL;
        aux->dir = NULL;
        return aux;
    } else{
        if(valor < raiz->valor)
            raiz->esq = insere(raiz->esq, valor);
        else
            raiz->dir = insere(raiz->dir, valor);
        return raiz;
    }
}

void insere_v2(Tno **raiz, int valor){
    Tno *aux = *raiz;
    while(aux){
        if(valor < aux->valor)
            raiz = &aux->esq;
        else
            raiz = &aux->dir;
        aux = *raiz;
    }
    aux = malloc(sizeof(Tno));
    aux->valor = valor;
    aux->esq = NULL;
    aux->dir = NULL;
    *raiz = aux;
}

void insere_v3(Tno **raiz, int valor){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(Tno));
        (*raiz)->valor = valor;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    } else{
        if(valor < (*raiz)->valor)
            insere_v3(&((*raiz)->esq), valor);
        else
            insere_v3(&((*raiz)->dir), valor);
    }
}


void imprimeOrdem(Tno *raiz){    // 1° filho a esqueda  // 2° pai // 3° filho a direita
    if(raiz){
        imprimeOrdem(raiz->esq);
        printf("%d", raiz->valor);
        imprimeOrdem(raiz->dir);
    }
}

void imprimePreOrdem(Tno *raiz){  // 1° pai  // 2° filho a esqueda // 3° filho a direita
    if(raiz){
        printf("%d", raiz->valor);
        imprimePreOrdem(raiz->esq);
        imprimePreOrdem(raiz->dir);
    }
}

void imprimePosOrdem(Tno *raiz){  // 1° filho a direita // 2° filho a direita // 3° pai 
    if(raiz){
        imprimePosOrdem(raiz->esq);
        imprimePosOrdem(raiz->dir);
        printf("%d", raiz->valor);
    }
}

int alturaArvore(TipoApontador raiz){
    if(raiz == NULL)
        return -1;
    else{
        int alturaEsq = alturaArvore(raiz->esq);
        int alturaDir = alturaArvore(raiz->dir);
        if(alturaEsq > alturaDir)
            return alturaEsq + 1;
        else
            return alturaDir + 1;
    }
}

int pesquisaArvore(TipoApontador raiz, int valor){
    if(raiz == NULL)
        return -1;
    else{
        if(raiz->valor == valor)
            return valor;
        else{
            if(valor < raiz->valor)
                return pesquisaArvore(raiz->esq, valor);
            else
                return pesquisaArvore(raiz->dir, valor);
        }
    }
}

void antecessor(TipoApontador raiz, TipoApontador *ant){
    TipoApontador aux;
    if((*ant)->dir != NULL){
        antecessor(raiz, &(*ant)->dir);
        return;
    }else{
        raiz->valor = (*ant)->valor;
        aux = *ant;
        *ant = (*ant)->esq;
        free(aux);
    }
}

int removeArvore(TipoApontador *raiz, int valor){
    TipoApontador aux;
    if(*raiz == NULL)
        return -1;
    else{
        if(valor < (*raiz)->valor)
            return removeArvore(&(*raiz)->esq, valor);
        else{
            if(valor > (*raiz)->valor)
                return removeArvore(&(*raiz)->dir, valor);
            else{
                aux = *raiz;
                if((*raiz)->dir == NULL){
                    *raiz = (*raiz)->esq;
                    free(aux);
                }else{
                    if((*raiz)->esq == NULL){
                        *raiz = (*raiz)->dir;
                        free(aux);
                    }else{
                        antecessor(*raiz, &(*raiz)->esq);
                    }
                }
                return 1;
            }
        }
    }
}

int main(){
    int i, valor;
    Tno *raiz = NULL;
    
    for(i=0;i<4;i++){
        scanf("%d", &valor);
        insere_v3(&raiz, valor);
    }
    imprimePosOrdem(raiz);
    printf("\n");
    // printf("\n%d", alturaArvore(raiz));
    // printf("\n%d", pesquisaArvore(raiz, 30));
    scanf("%d", &valor);
    removeArvore(&raiz, valor);	
    imprimePosOrdem(raiz);
    
    return 0;
}