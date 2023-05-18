#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>

#define MAX_USERS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct
{
    int id;
    char nome[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char sexo[MAX_NAME_LENGTH];
    char endereco[MAX_ADDRESS_LENGTH];
    double altura;
    int vacina;
} Usuario;

Usuario usuarios[MAX_USERS];
int totalUsuarios = 0;

int gerarId()
{
    return rand();
}

void cadastrarUsuario()
{
    if (totalUsuarios >= MAX_USERS)
    {
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

    usuario.id = gerarId();

    usuarios[totalUsuarios++] = usuario;

    printf("Usuário cadastrado com sucesso.\n");
}
void editarUsuario()
{
    int id;
    printf("Digite o ID do usuário a ser editado: ");
    scanf("%d", &id);

    int i;
    for (i = 0; i < totalUsuarios; i++)
    {
        if (usuarios[i].id == id)
        {
            Usuario usuario = usuarios[i];

            printf("Digite o novo nome completo: ");
            fgets(usuario.nome, MAX_NAME_LENGTH, stdin);
            usuario.nome[strcspn(usuario.nome, "\n")] = '\0';

            printf("Digite o novo email: ");
            fgets(usuario.email, MAX_EMAIL_LENGTH, stdin);
            usuario.email[strcspn(usuario.email, "\n")] = '\0';

            printf("Digite o novo sexo (Feminino, Masculino ou Indiferente): ");
            fgets(usuario.sexo, MAX_NAME_LENGTH, stdin);
            usuario.sexo[strcspn(usuario.sexo, "\n")] = '\0';

            printf("Digite o novo endereço: ");
            fgets(usuario.endereco, MAX_ADDRESS_LENGTH, stdin);
            usuario.endereco[strcspn(usuario.endereco, "\n")] = '\0';

            printf("Digite a nova altura (entre 1 e 2 metros): ");
            scanf("%lf", &usuario.altura);
            getchar();

            printf("Recebeu a vacina? (1 - Sim, 0 - Não): ");
            scanf("%d", &usuario.vacina);

            usuarios[i] = usuario;
            printf("Usuário editado com sucesso.\n");
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}
  return 0;
}
