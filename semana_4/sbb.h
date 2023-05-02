typedef enum{
    Horizontal, Vertical
} TipoInclinacao;

typedef struct SBB *TipoApontador;
typedef struct SBB{
    int chave;
    TipoApontador esq, dir;
    TipoInclinacao BitE, BitD;
} TNo;