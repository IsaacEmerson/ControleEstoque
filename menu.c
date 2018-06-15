#include <stdio.h>
#include "menu.h"
//teste
int menu_principal(Usuario usuario){
    int opcao;
    printf("############ BEM VINDO %s\n",usuario.nome);
    printf("   0 - Sair do Sistema\n");
    printf("PRODUTO----------------------------------------\n");
    printf("   1 - Cadastrar Novo Produto\n");
    printf("   2 - Editar Informacoes de Produtos\n");
    printf("   3 - Listar Produtos\n");
    printf("   4 - Deletar Produtos\n");
    printf("   5 - Remover do estoque\n");
    printf("   6 - Adicionar ao estoque\n");
    printf("RELATORIO---------------------------------------\n");
    if(usuario.cargo==1){printf("   7 - Ver Relatorios\n");}else{printf("   7 - DESTINADO AO ADMIN\n");}
    printf("USUARIO-----------------------------------------\n");
    printf("   8 - Minhas informacoes\n");
    if(usuario.cargo==1){printf("   9 - Cadastrar usuarios\n");}else{printf("   9 - DESTINADO AO ADMIN\n");}
    fflush(stdin);
    scanf("%d",&opcao);
    return opcao;
}