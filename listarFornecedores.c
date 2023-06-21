#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>
#include "listarFornecedores.h"
#include <locale.h>


typedef struct {
    int id;
    char nome[50];
    char site[100];
    char telefone[20];
    char uf[3];
} Fornecedor;

void listarFornecedores() {
    setlocale(LC_ALL, "Portuguese");
    MYSQL conexao;
    mysql_init(&conexao);

    if (!mysql_real_connect(&conexao, "127.0.0.1", "root", "", "frutaria", 0, NULL, 0)) {
        printf("Erro ao conectar ao banco de dados: %s\n", mysql_error(&conexao));
        return 1;
    }

    if (mysql_query(&conexao, "SELECT id_fornecedor, nome_fornecedor, site, telefone, uf FROM fornecedor")) {
        printf("Erro na consulta SQL: %s\n", mysql_error(&conexao));
        return 1;
    }

    MYSQL_RES *resultado = mysql_use_result(&conexao);
    MYSQL_ROW linha;

    while ((linha = mysql_fetch_row(resultado)) != NULL) {
        Fornecedor fornecedor;
        fornecedor.id = atoi(linha[0]);
        strncpy(fornecedor.nome, linha[1], sizeof(fornecedor.nome));
        strncpy(fornecedor.site, linha[2], sizeof(fornecedor.site));
        strncpy(fornecedor.telefone, linha[3], sizeof(fornecedor.telefone));
        strncpy(fornecedor.uf, linha[4], sizeof(fornecedor.uf));

        printf("ID: %d\n", fornecedor.id);
        printf("Nome: %s\n", fornecedor.nome);
        printf("Site: %s\n", fornecedor.site);
        printf("Telefone: %s\n", fornecedor.telefone);
        printf("UF: %s\n", fornecedor.uf);
        printf("\n");
    }

    mysql_free_result(resultado);
    mysql_close(&conexao);

    printf("\n");
    printf("1 - Retornar ao Menu principal\n");
    int escolha = 0;

    scanf("%d", &escolha);
    getchar();
    switch (escolha)
    {
    case 1:
        system("cls");
        menu();
        break;
    default:
        printf("Opção incorreta\n");
        break;
    }
}

