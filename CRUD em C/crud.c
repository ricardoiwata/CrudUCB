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
void excluirUsuario()
{
    int id;
    printf("Digite o ID do usuário a ser excluído: ");
    scanf("%d", &id);
    int i;
    for (i = 0; i < totalUsuarios; i++)
    {
        if (usuarios[i].id == id)
        {
            int j;
            for (j = i; j < totalUsuarios - 1; j++)
            {
                usuarios[j] = usuarios[j + 1];
            }

            totalUsuarios--;

            printf("Usuário excluído com sucesso.\n");
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}
void buscarUsuarioPorEmail()
{
    char email[MAX_EMAIL_LENGTH];
    printf("Digite o email do usuário a ser buscado: ");
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    email[strcspn(email, "\n")] = '\0';
    int i;
    for (i = 0; i < totalUsuarios; i++)
    {
        if (strcmp(usuarios[i].email, email) == 0)
        {
            printf("Usuário encontrado:\n");
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereço: %s\n", usuarios[i].endereco);
            printf("Altura: %.2f\n", usuarios[i].altura);
            printf("Vacina: %s\n", usuarios[i].vacina ? "Sim" : "Não");
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}
void imprimirUsuarios()
{
    int i;
    for (i = 0; i < totalUsuarios; i++)
    {
        printf("ID: %d\n", usuarios[i].id);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Email: %s\n", usuarios[i].email);
        printf("Sexo: %s\n", usuarios[i].sexo);
        printf("Endereço: %s\n", usuarios[i].endereco);
        printf("Altura: %.2f\n", usuarios[i].altura);
        printf("Vacina: %s\n\n", usuarios[i].vacina ? "Sim" : "Não");
    }
}
void fazerBackup()
{
    FILE *arquivo = fopen("backup.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao criar o arquivo de backup.\n");
        return;
    }
    int i;
    for (i = 0; i < totalUsuarios; i++)
    {
        fprintf(arquivo, "%d\n", usuarios[i].id);
        fprintf(arquivo, "%s\n", usuarios[i].nome);
        fprintf(arquivo, "%s\n", usuarios[i].email);
        fprintf(arquivo, "%s\n", usuarios[i].sexo);
        fprintf(arquivo, "%s\n", usuarios[i].endereco);
        fprintf(arquivo, "%.2f\n", usuarios[i].altura);
        fprintf(arquivo, "%d\n", usuarios[i].vacina);
    }

    fclose(arquivo);

    printf("Backup realizado com sucesso.\n");
}
void fazerRestauracao()
{
    FILE *arquivo = fopen("backup.txt", "r");
    if (arquivo == NULL)
    {
        printf("Arquivo de backup não encontrado.\n");
        return;
    }
    totalUsuarios = 0;
    Usuario usuario;

    while (fscanf(arquivo, "%d", &usuario.id) == 1)
    {
        fscanf(arquivo, "%s", usuario.nome);
        fscanf(arquivo, "%s", usuario.email);
        fscanf(arquivo, "%s", usuario.sexo);
        fscanf(arquivo, "%s", usuario.endereco);
        fscanf(arquivo, "%lf", &usuario.altura);
        fscanf(arquivo, "%d", &usuario.vacina);
        usuarios[totalUsuarios++] = usuario;
    }

    fclose(arquivo);

    printf("Restauração dos dados concluída.\n");
}
int main()
{
    srand(time(NULL));
    char opcao;
    do
    {
        printf("Selecione uma opção:\n");
        printf("1. Cadastrar usuário\n");
        printf("2. Editar usuário\n");
        printf("3. Excluir usuário\n");
        printf("4. Buscar usuário pelo email\n");
        printf("5. Imprimir todos os usuários cadastrados\n");
        printf("6. Fazer backup dos usuários cadastrados\n");
        printf("7. Fazer restauração dos dados\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        getchar();

        switch (opcao)
        {
        case '1':
            cadastrarUsuario();
            break;
        case '2':
            editarUsuario();
            break;
        case '3':
            excluirUsuario();
            break;
        case '4':
            buscarUsuarioPorEmail();
            break;
        case '5':
            imprimirUsuarios();
            break;
        case '6':
            fazerBackup();
            break;
        case '7':
            fazerRestauracao();
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

  
  return 0;
}

