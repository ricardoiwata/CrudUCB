#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct {
    int id;
    char nome[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char sexo[MAX_NAME_LENGTH];
    char endereco[MAX_ADDRESS_LENGTH];
    double altura;
    int vacina;
} Usuario;

typedef struct {
    Usuario* usuarios;
    int totalUsuarios;
    int capacidade;
} BancoUsuarios;

BancoUsuarios* criarBancoUsuarios(int capacidade) {
    BancoUsuarios* banco = (BancoUsuarios*)malloc(sizeof(BancoUsuarios));
    banco->usuarios = (Usuario*)malloc(capacidade * sizeof(Usuario));
    banco->totalUsuarios = 0;
    banco->capacidade = capacidade;
    return banco;
}

void destruirBancoUsuarios(BancoUsuarios* banco) {
    free(banco->usuarios);
    free(banco);
}

void cadastrarUsuario(BancoUsuarios* banco) {
    if (banco->totalUsuarios >= banco->capacidade) {
        printf("Limite máximo de usuários atingido.\n");
        return;
    }

    Usuario usuario;

    printf("Digite o nome completo: ");
    fgets(usuario.nome, MAX_NAME_LENGTH, stdin);
    usuario.nome[strcspn(usuario.nome, "\n")] = '\0';

    printf("Digite o email: ");
    fgets(usuario.email, MAX_EMAIL_LENGTH, stdin);
    usuario.email[strcspn(usuario.email, "\n")] = '\0';

    printf("Digite o sexo (Feminino, Masculino ou Indiferente): ");
    fgets(usuario.sexo, MAX_NAME_LENGTH, stdin);
    usuario.sexo[strcspn(usuario.sexo, "\n")] = '\0';

    printf("Digite o endereço: ");
    fgets(usuario.endereco, MAX_ADDRESS_LENGTH, stdin);
    usuario.endereco[strcspn(usuario.endereco, "\n")] = '\0';

    printf("Digite a altura (entre 1 e 2 metros): ");
    scanf("%lf", &usuario.altura);
    getchar(); // Consumir o segundo caractere '\n'

    printf("Recebeu a vacina? (1 - Sim, 0 - Não): ");
    scanf("%d", &usuario.vacina);

    usuario.id = banco->totalUsuarios + 1;

    banco->usuarios[banco->totalUsuarios++] = usuario;

    printf("Usuário cadastrado com sucesso.\n");
}

void editarUsuario(BancoUsuarios* banco) {
    int id;
    printf("Digite o ID do usuário a ser editado: ");
    scanf("%d", &id);

    int i;
    for (i = 0; i < banco->totalUsuarios; i++) {
        if (banco->usuarios[i].id == id) {
            Usuario* usuario = &(banco->usuarios[i]);

            printf("Digite o novo nome completo: ");
            fgets(usuario->nome, MAX_NAME_LENGTH, stdin);
            usuario->nome[strcspn(usuario->nome, "\n")] = '\0';

            printf("Digite o novo email: ");
            fgets(usuario->email, MAX_EMAIL_LENGTH, stdin);
            usuario->email[strcspn(usuario->email, "\n")] = '\0';

            printf("Digite o novo sexo (Feminino, Masculino ou Indiferente): ");
            fgets(usuario->sexo, MAX_NAME_LENGTH, stdin);
            usuario->sexo[strcspn(usuario->sexo, "\n")] = '\0';

            printf("Digite o novo endereço: ");
            fgets(usuario->endereco, MAX_ADDRESS_LENGTH, stdin);
            usuario->endereco[strcspn(usuario->endereco, "\n")] = '\0';

            printf("Digite a nova altura (entre 1 e 2 metros): ");
            scanf("%lf", &usuario->altura);
            getchar();

            printf("Recebeu a vacina? (1 - Sim, 0 - Não): ");
            scanf("%d", &usuario->vacina);

            printf("Usuário editado com sucesso.\n");
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}

void excluirUsuario(BancoUsuarios* banco) {
    int id;
    printf("Digite o ID do usuário a ser excluído: ");
    scanf("%d", &id);

    int i;
    for (i = 0; i < banco->totalUsuarios; i++) {
        if (banco->usuarios[i].id == id) {
            int j;
            for (j = i; j < banco->totalUsuarios - 1; j++) {
                banco->usuarios[j] = banco->usuarios[j + 1];
            }

            banco->totalUsuarios--;

            printf("Usuário excluído com sucesso.\n");
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}

void imprimirUsuarios(BancoUsuarios* banco) {
    int i;
    for (i = 0; i < banco->totalUsuarios; i++) {
        Usuario usuario = banco->usuarios[i];
        printf("ID: %d\n", usuario.id);
        printf("Nome: %s\n", usuario.nome);
        printf("Email: %s\n", usuario.email);
        printf("Sexo: %s\n", usuario.sexo);
        printf("Endereço: %s\n", usuario.endereco);
        printf("Altura: %.2f\n", usuario.altura);
        printf("Vacina: %s\n\n", usuario.vacina ? "Sim" : "Não");
    }
}

int main() {
    BancoUsuarios* banco = criarBancoUsuarios(1000);

    char opcao;
    do {
        printf("Selecione uma opção:\n");
        printf("1. Cadastrar usuário\n");
        printf("2. Editar usuário\n");
        printf("3. Excluir usuário\n");
        printf("4. Listar todos os usuários cadastrados\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf(" %c", &opcao);
        getchar();

        switch (opcao) {
            case '1':
                cadastrarUsuario(banco);
                break;
            case '2':
                editarUsuario(banco);
                break;
            case '3':
                excluirUsuario(banco);
                break;
            case '4':
                imprimirUsuarios(banco);
                break;
            case '0':
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != '0');

    destruirBancoUsuarios(banco);

    return 0;
}
