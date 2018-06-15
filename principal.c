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
    int n_produtos=0,id_produto,n_old,quant=0;
    int id_pro=1,quant_user=0,id_user;

    movimentacoes = (Movimentacao*) malloc(sizeof(Movimentacao));

    usuario = cria_usuario(usuario,&quant_user);
    
    while(!logar(usuario,&quant_user,&id_user)){
        printf("Senha incorreta !\n");
    }

    produtos = arquivo_para_vetor(produtos,&n_produtos,&id_pro);

    while(1){
        switch(menu_principal(usuario[id_user])){
            case 0:
                return 0;
            break;
            case 1:
                printf("\n\nCadastrar produtos\n\n");
                Produto pro = le_produto(usuario);
                produtos = insere_produto(produtos,&n_produtos,pro,&id_pro);
                if(produtos!=0){
                    printf("\n\nProduto %s Cadastrado com SUCESSO\n\n",pro.nome);
                    produtos_para_arquivo(produtos, &n_produtos);
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
                printf("Informe o id do produto que deseja deletar: ");
                scanf("%d",&id_produto);
                if(id_produto!=0){
                    produtos = remove_produto(produtos, &n_produtos, id_produto);
                    if(n_old>n_produtos){
                        printf("\n\nPRODUTO REMOVIDO COM SUCESSO\n\n");
                        produtos_para_arquivo(produtos, &n_produtos);
                        continue;
                    }else{
                        printf("\n\nFALHA AO REMOVER\n\n");
                        continue;
                    }
                }
                continue;
            break;
            case 5:
                printf("Informe o id do produto que deseja DECREMENTAR do estoque: ");
                scanf("%d",&id_produto);
                printf("Quantidade a ser REMOVIDA: ");
                scanf("%d",&quant);
                if(movimenta_estoque(produtos,&n_produtos,id_produto,quant,'-')){
                    printf("Operacao de DECREMENTO realizada com sucesso --%d !\n",quant);
                    produtos_para_arquivo(produtos, &n_produtos);
                    continue;
                }else{
                    printf("Operacao de DECREMENTO FALHA, tente novamente \n");
                    continue;
                }
            break;
            case 6:
                printf("Informe o id do produto que deseja INCREMENTAR no estoque: ");
                scanf("%d",&id_produto);
                printf("Quantidade a ser ADICIONADA: ");
                scanf("%d",&quant);
                if(movimenta_estoque(produtos,&n_produtos,id_produto,quant,'+')){
                    printf("Operacao de incremento realizada com sucesso ++%d !\n",quant);
                    produtos_para_arquivo(produtos, &n_produtos);
                    continue;
                }else{
                    printf("Operacao de incremento FALHA, tente novamente \n");
                    continue;
                }
            break;
            default:
                printf("Opcao invalida\n");
                continue;
            break;
        }
    }
    return 0;
}