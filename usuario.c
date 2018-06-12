#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

Usuario* cria_usuario(Usuario *usuario){
    usuario = (Usuario*) malloc(sizeof(Usuario));
    strcpy(usuario->nome,"Isaac Emerson");
    usuario->senha = 123;
    return usuario;
}

int logar(Usuario *usuario){
    int senha;
    printf("Senha(123): ");
    scanf("%d",&senha);
    if(usuario->senha==senha){
        return 1;
    }else{
        return 0;
    }
}