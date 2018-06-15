#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

Produto le_produto(Usuario *usuario){
    Produto pro;
    printf("Nome do produto: ");
    getchar();
    fgets(pro.nome,sizeof(pro.nome),stdin);
    printf("Preco da unidade: ");
    scanf("%f",&pro.preco);
    printf("Quantidade para estoque inicial: ");
    scanf("%d",&pro.quantidade);
    printf("Categoria: (1)Limpeza (2)Bebidas (3)Alimentos : ");
    scanf("%d",&pro.categoria);
    printf("Data de validade (dd mm aaaa): ");
    scanf("%d %d %d",&pro.valido_ate.dia,&pro.valido_ate.mes,&pro.valido_ate.ano);
    pro.data_cadastrado.dia=0;
    pro.data_cadastrado.mes=0;
    pro.data_cadastrado.ano=0;
    pro.cadastrado_por = *usuario;
    pro.nome[strlen(pro.nome)-1] = 0;
    return pro;
}

Produto* insere_produto(Produto *produtos, int *n_produtos, Produto novo_produto, int *id){
    if(*n_produtos==0){
        produtos =(Produto*) malloc(sizeof(Produto));
    }else{
        produtos =(Produto*) realloc(produtos,(*n_produtos+1)*sizeof(Produto));
    }
    if(produtos==0)return 0;

    produtos[*n_produtos]=novo_produto;
    produtos[*n_produtos].id=*id;
    (*id)++;
    (*n_produtos)++;

    return produtos;
}

Produto* remove_produto(Produto *produtos, int *n_produtos, int id){
    int achou=0;
    
    for(int i=0;i<*n_produtos-1;i++){
       if(produtos[i].id==id){
           achou = 1;
           produtos[i]=produtos[*n_produtos-1];
           produtos = (Produto*) realloc(produtos,(*n_produtos-1)*sizeof(Produto));
           break;
       } 
    }
    (*n_produtos)--;
    
    if(produtos==0){
        return 0;
    }
    
    return produtos;
}

void lista_produtos(Produto *produtos, int *n_produtos){
    for(int i=0;i<*n_produtos;i++){
        printf("-- ID=%d Nome:%s  Quantidade:%d  Preco:%.2f ",produtos[i].id,produtos[i].nome,produtos[i].quantidade,produtos[i].preco);
        printf(" valido_ate:%d/%d/%d cadastrado_por:%s\n\n",produtos[i].valido_ate.dia,produtos[i].valido_ate.mes,produtos[i].valido_ate.ano,produtos[i].cadastrado_por.nome);

    }
}

int movimenta_estoque(Produto *produtos, int *n_produtos, int id,int quantidade,char operacao){
    
    for(int i=0;i<*n_produtos;i++){
       if(produtos[i].id==id){
           if(operacao=='+'){
               produtos[i].quantidade+=quantidade;
           }else if(operacao=='-'){
               if(produtos[i].quantidade-quantidade<0){
                   produtos[i].quantidade=0;
               }else{
                   produtos[i].quantidade-=quantidade;
               }
           }
           return 1;
           break;
       } 
    }
    return 0;
}

int produtos_para_arquivo(Produto *produtos, int *n_produtos){
    FILE *arquivo_produtos = fopen("produtos.txt","w");
    if (arquivo_produtos == 0) {
      printf("Erro: nao foi possivel abrir arquivo!\n");
      return 0;
   }

   for (int i = 0; i <*n_produtos; i++){
      fprintf(arquivo_produtos, "%d %s %d %.2f %d %d %d %s\n", produtos[i].id,produtos[i].nome,produtos[i].quantidade,produtos[i].preco,produtos[i].valido_ate.dia,produtos[i].valido_ate.mes,produtos[i].valido_ate.ano,produtos[i].cadastrado_por.nome);
   }

   fclose(arquivo_produtos);
   return 1;
}

Produto* arquivo_para_vetor(Produto *produtos, int *n_produtos,int *id){
    FILE *arquivo_produtos = fopen("produtos.txt","r");
    if (arquivo_produtos == 0) {
      printf("Erro: nao foi possivel abrir arquivo!\n");
      return 0;
   }
   
   Produto produto;
    while (fscanf(arquivo_produtos, "%d ", &produto.id) == 1) {
      //fgets(produto.nome, sizeof(produto.nome), arquivo_produtos);
      //produto.nome[strlen(produto.nome)-1] = 0;
      fscanf(arquivo_produtos, "%s %d %.2f %d %d %d %s\n", &produto.nome,&produto.quantidade,&produto.preco,&produto.valido_ate.dia,&produto.valido_ate.mes,&produto.valido_ate.ano,&produto.cadastrado_por.nome);
      //insere_produto(produtos,n_produtos,produto,id);
      printf("%s\n",produto.nome);
      printf("%d",produto.id);
   }

    fclose(arquivo_produtos);
    return produtos;
}