#include <stdio.h>
#include "menu.h"
//teste
int menu_principal(Usuario* usuario){
    int opcao;
    printf("############ BEM VINDO %s\n",usuario->nome);
    printf("   0 - Sair do Sistema\n");
    printf("Produto----------------------------------------\n");
    printf("   1 - Cadastrar Novo Produto\n");
    printf("   2 - Editar Informacoes de Produtos\n");
    printf("   3 - Listar Produtos\n");
    printf("   4 - Deletar Produtos\n");
    printf("   5 - Remover do estoque\n");
    printf("   6 - Adicionar ao estoque\n");
    printf("Relatorio---------------------------------------\n");
    printf("   7 - Ver Relatorios\n");
    printf("Usuario-----------------------------------------\n");
    printf("   8 - Minhas informacoes\n");
    fflush(stdin);
    scanf("%d",&opcao);
    return opcao;
}