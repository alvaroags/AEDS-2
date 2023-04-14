typedef struct Aluno *TipoApontador;

typedef struct Aluno 
{
    char nome[50];
    int matricula;
    float nota;
    TipoApontador esq, dir;
} tipoAluno;