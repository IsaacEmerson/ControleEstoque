typedef struct{
    char nome[102];
    int senha;
    int cargo;
}Usuario;

int logar(Usuario* usuario,int *quant_user,int *id_user);

Usuario* cria_usuario(Usuario* usuario,int *quant_user);