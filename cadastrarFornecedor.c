#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>
#include <string.h>
#include "cadastrarFornecedor.h"
#include <locale.h>

typedef struct {
    char nome_fornecedor[100];
    char site[150];
    int telefone;
    char uf[3];
} Fornecedor;

void cadastrarFornecedor() {
    setlocale(LC_ALL, "Portuguese");
    Fornecedor fornecedor;

    printf("-----------------------------------------------\n");
    printf("             CADASTRO DE FORNECEDOR            \n");
    printf("-----------------------------------------------\n");

    printf("Nome do fornecedor: ");
    fgets(fornecedor.nome_fornecedor, sizeof(fornecedor.nome_fornecedor), stdin);
    fornecedor.nome_fornecedor[strcspn(fornecedor.nome_fornecedor, "\n")] = '\0';

    printf("Site do fornecedor: ");
    fgets(fornecedor.site, sizeof(fornecedor.site), stdin);
    fornecedor.site[strcspn(fornecedor.site, "\n")] = '\0';

    printf("Telefone do fornecedor: ");
    scanf("%d", &fornecedor.telefone);
    getchar(); // Limpa o caractere de nova linha ('\n') do buffer

    printf("UF do fornecedor: ");
    fgets(fornecedor.uf, sizeof(fornecedor.uf), stdin);
    fornecedor.uf[strcspn(fornecedor.uf, "\n")] = '\0';

    MYSQL conexao;
    mysql_init(&conexao);
    if (mysql_real_connect(&conexao, "127.0.0.1", "root", "", "frutaria", 0, NULL, 0)) {
        printf("Conectado com sucesso ao banco de dados!\n");
        printf("-----------------------------------------------\n");

        char query[1000];
        sprintf(query, "INSERT INTO `fornecedor`(`nome_fornecedor`, `site`, `telefone`, `uf`) VALUES ('%s','%s','%d','%s');", fornecedor.nome_fornecedor, fornecedor.site, fornecedor.telefone, fornecedor.uf);
        mysql_query(&conexao, query);
        printf("\nFornecedor cadastrado com sucesso!\n");
        Sleep(1000);

        mysql_close(&conexao);
    }
    else {
        printf("Falha de conexao\n");
        printf("Erro %d: %s\n", mysql_errno(&conexao), mysql_error(&conexao));
    }
    printf("\n");
    printf("-----------------------------------------------\n");
    printf("1 - Cadastrar outro produto\n");
    printf("2 - Retornar ao Menu principal\n");
    int escolha = 0;

    scanf("%d", &escolha);
    getchar();
    switch (escolha) {
    case 1:
        system("cls");
        cadastrarFornecedor();
        break;
    case 2:
        system("cls");
        menu();
        break;
    default:
        printf("Opção incorreta\n");
        break;
    }
}

