typedef struct{
    char nome[102];
    int senha;
}Usuario;

int logar(Usuario* usuario);

Usuario* cria_usuario(Usuario* usuario);