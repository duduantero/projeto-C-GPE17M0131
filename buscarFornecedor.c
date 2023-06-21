#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "menu.h"
#include "buscarFornecedor.h"

typedef struct {
    int id_fornecedor;
    char nome_fornecedor[50];
    char site[50];
    char telefone[20];
    char uf[3];
} Fornecedor;

void buscarFornecedor() {
    int idFornecedor;

    printf("Digite o ID do fornecedor: ");
    scanf("%d", &idFornecedor);

    MYSQL conexao;
    mysql_init(&conexao);

    if (!mysql_real_connect(&conexao, "127.0.0.1", "root", "", "frutaria", 0, NULL, 0)) {
        printf("Erro ao conectar ao banco de dados: %s\n", mysql_error(&conexao));
        return;
    }

    char query[200];
    sprintf(query, "SELECT * FROM Fornecedor WHERE id_fornecedor = %d", idFornecedor);

    if (mysql_query(&conexao, query)) {
        printf("Erro na consulta SQL: %s\n", mysql_error(&conexao));
        mysql_close(&conexao);
        return;
    }

    MYSQL_RES *resultado = mysql_store_result(&conexao);
    MYSQL_ROW linha;

    if ((linha = mysql_fetch_row(resultado)) != NULL) {
        Fornecedor fornecedor;
        fornecedor.id_fornecedor = atoi(linha[0]);
        strncpy(fornecedor.nome_fornecedor, linha[1], sizeof(fornecedor.nome_fornecedor));
        strncpy(fornecedor.site, linha[2], sizeof(fornecedor.site));
        strncpy(fornecedor.telefone, linha[3], sizeof(fornecedor.telefone));
        strncpy(fornecedor.uf, linha[4], sizeof(fornecedor.uf));

        printf("ID do Fornecedor: %d\n", fornecedor.id_fornecedor);
        printf("Nome do Fornecedor: %s\n", fornecedor.nome_fornecedor);
        printf("Site do Fornecedor: %s\n", fornecedor.site);
        printf("Telefone do Fornecedor: %s\n", fornecedor.telefone);
        printf("UF do Fornecedor: %s\n", fornecedor.uf);
    } else {
        printf("Fornecedor não encontrado.\n");
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




















