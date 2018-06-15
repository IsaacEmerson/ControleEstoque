#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

Usuario* cria_usuario(Usuario *usuario,int *quant_user){

    usuario = (Usuario*) malloc(2 * sizeof(Usuario));

    strcpy(usuario[0].nome,"Isaac Emerson");
    usuario[0].senha = 123;
    usuario[0].cargo = 1;//admin
    
    strcpy(usuario[1].nome,"Valdisklei");
    usuario[1].senha = 123456;
    usuario[1].cargo = 2;//gerente

    *quant_user=2;

    return usuario;
}

int logar(Usuario *usuario,int *quant_user,int *id_user){
    int senha;
    printf("Senha(123456): ");
    scanf("%d",&senha);
    for(int i=0;i<*quant_user;i++){
        if(usuario[i].senha==senha){
            *id_user=i;
            return 1;
        }
    }
    return 0;
}