//quero que faça o arquivo main.h como um arquivo que contenha a estrutura de uma arvore TST
//e que tenha as funções de inserção 

typedef struct ArvoreTST *TipoApontador;

typedef struct ArvoreTST{
    char letra;
    TipoApontador esq, dir, meio;
    int fimPalavra;
} TST;