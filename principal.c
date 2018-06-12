#include <stdio.h>
#include <stdlib.h>
///#include "usuario.h"
#include "menu.h"
///#include "produto.h"

typedef struct{
    int id;
    Data data;
    Usuario feita_por;
    Produto produto;
    char operacao;
    int quantidade;
}Movimentacao;

int main(){
    Usuario *usuario = 0;
    Produto *produtos = 0;
    Movimentacao *movimentacoes = 0;
    int n_produtos=0,id_del,n_old;
    int id_pro=1;

    movimentacoes = (Movimentacao*) malloc(sizeof(Movimentacao));

    usuario = cria_usuario(usuario);
    
    while(!logar(usuario)){
        printf("Senha incorreta !\n");
    }
    
    while(1){
        switch(menu_principal(usuario)){
            case 0:
                return 0;
            break;
            case 1:
                printf("\n\nCadastrar produtos\n\n");
                Produto pro = le_produto(usuario);
                produtos = insere_produto(produtos,&n_produtos,pro,&id_pro);
                if(produtos!=0){
                    printf("\n\nProduto %s Cadastrado com SUCESSO\n\n",pro.nome);
                    continue;
                }else{
                    printf("\n\nFALHA AO CADASTRAR\n\n");
                    continue;
                }
            break;
            case 3:
                if(n_produtos>0){
                    lista_produtos(produtos,&n_produtos);
                }
                continue;
            break;
            case 4:
                n_old = n_produtos;
                printf("Informe o id que deseja deletar: ");
                scanf("%d",&id_del);
                if(id_del!=0){
                    produtos = remove_produto(produtos, &n_produtos, id_del);
                    if(n_old>n_produtos){
                        printf("\n\nPRODUTO REMOVIDO COM SUCESSO\n\n");
                        continue;
                    }else{
                        printf("\n\nFALHA AO REMOVER\n\n");
                        continue;
                    }
                }
                continue;
            break;
            default:
                printf("Opcao invalida\n");
                continue;
            break;
        }
    }
    
    return 0;
}