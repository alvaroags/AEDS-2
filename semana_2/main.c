#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void insere(TipoApontador *raiz, float nota, int matricula, char *nome){
    if(*raiz == NULL){
        *raiz = (TipoApontador)malloc(sizeof(tipoAluno));
        (*raiz)->matricula = matricula;
        (*raiz)->nota = nota;
        strcpy((*raiz)->nome, nome);
        (*raiz)->dir = NULL;
        (*raiz)->esq = NULL;
    } else{
        if(nota < (*raiz)->nota)
            insere(&(*raiz)->esq, nota, matricula, nome);
        else
            insere(&(*raiz)->dir, nota, matricula, nome);
    }
}



void imprimeOrdem(TipoApontador *raiz){    // 1° filho a esqueda  // 2° pai // 3° filho a direita
    if(*raiz){
        imprimeOrdem(&(*raiz)->esq);
        printf("---------------\n");
        printf("matricula: %d\n", (*raiz)->matricula);
        printf("aluno: %s\n", (*raiz)->nome);
        printf("nota: %.2f\n", (*raiz)->nota);
        printf("---------------\n");
        imprimeOrdem(&(*raiz)->dir);
    }
}

void menorNota(TipoApontador *raiz){
    if(*raiz){
        if((*raiz)->esq == NULL)
            printf("\nmenor nota: %.2f", (*raiz)->nota);
         else
            menorNota(&(*raiz)->esq);
    }
}

void maiorNota(TipoApontador *raiz){
    if(*raiz){
        if((*raiz)->dir == NULL)
            printf("\nmaior nota: %.2f\n", (*raiz)->nota);
        else
            maiorNota(&(*raiz)->dir);
    }
}

void numeroAlunos(TipoApontador *raiz, int *cont){
    if(*raiz){
        (*cont)++;
        numeroAlunos(&(*raiz)->esq, cont);
        numeroAlunos(&(*raiz)->dir, cont);
    }
}

void qtAlunosMedia(TipoApontador *raiz, int *cont){
    if(*raiz){
        if((*raiz)->nota >= 7.00)
            (*cont)++;
        qtAlunosMedia(&(*raiz)->esq, cont);
        qtAlunosMedia(&(*raiz)->dir, cont);
    }
}

int main(){
    TipoApontador raiz = NULL;
    int contAlunos = 0, contAlunosMedia = 0;
    insere(&raiz, 7.00, 123, "joao");
    insere(&raiz, 8.00, 124, "maria");
    insere(&raiz, 9.00, 125, "pedro");
    insere(&raiz, 10.00, 126, "jose");
    insere(&raiz, 6.00, 127, "marcos");
    insere(&raiz, 5.00, 128, "marcelo");
    insere(&raiz, 4.00, 129, "mariana");
    insere(&raiz, 3.00, 130, "marcela");
    insere(&raiz, 2.00, 131, "adriana");
    insere(&raiz, 1.00, 132, "juliana");
    insere(&raiz, 0.00, 133, "carlos");
    imprimeOrdem(&raiz);
    menorNota(&raiz);
    maiorNota(&raiz);
    numeroAlunos(&raiz, &contAlunos);
    printf("\nNumero de alunos: %d", contAlunos);
    qtAlunosMedia(&raiz, &contAlunosMedia);
    printf("\nNumero de alunos com media maior ou igual que 7: %d\n\n", contAlunosMedia);
    return 0;
}