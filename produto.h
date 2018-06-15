#include "usuario.h"

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct{
    int id;
    char nome[102];
    float preco;
    int quantidade;
    int categoria;
    Usuario cadastrado_por;
    Data data_cadastrado;
    Data valido_ate;
}Produto;

Produto le_produto(Usuario *usuario);
Produto* insere_produto(Produto *produtos, int *n_produtos, Produto novo_produto,int *id);
Produto* remove_produto(Produto *produtos, int *n_produtos, int id);
void lista_produtos(Produto *produtos, int *n_produtos);
int movimenta_estoque(Produto *produtos, int *n_produtos, int id,int quantidade,char operacao);
int produtos_para_arquivo(Produto *produtos, int *n_produtos);
Produto* arquivo_para_vetor(Produto *produtos, int *n_produtos,int *id_pro);