#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include <locale.h>

typedef struct {
    int id;
    char nome[100];
    char site[100];
    char telefone[20];
    char uf[3];
} Fornecedor;

void informarFornecedor(int id_fornecedor) {
    MYSQL conexao;
    mysql_init(&conexao);

    if (!mysql_real_connect(&conexao, "127.0.0.1", "root", "", "frutaria", 0, NULL, 0)) {
        printf("Erro ao conectar ao banco de dados: %s\n", mysql_error(&conexao));
        return;
    }

    char query[200];
    sprintf(query, "SELECT * FROM Fornecedor WHERE id_fornecedor = %d", id_fornecedor);

    if (mysql_query(&conexao, query)) {
        printf("Erro na consulta SQL: %s\n", mysql_error(&conexao));
        mysql_close(&conexao);
        return;
    }

    MYSQL_RES *resultado = mysql_store_result(&conexao);
    MYSQL_ROW linha;

    if ((linha = mysql_fetch_row(resultado)) != NULL) {
        Fornecedor fornecedor;
        fornecedor.id = atoi(linha[0]);
        strncpy(fornecedor.nome, linha[1], sizeof(fornecedor.nome));
        strncpy(fornecedor.site, linha[2], sizeof(fornecedor.site));
        strncpy(fornecedor.telefone, linha[3], sizeof(fornecedor.telefone));
        strncpy(fornecedor.uf, linha[4], sizeof(fornecedor.uf));

        printf("ID do Fornecedor: %d\n", fornecedor.id);
        printf("Nome do Fornecedor: %s\n", fornecedor.nome);
        printf("Site do Fornecedor: %s\n", fornecedor.site);
        printf("Telefone do Fornecedor: %s\n", fornecedor.telefone);
        printf("UF do Fornecedor: %s\n", fornecedor.uf);
    } else {
        printf("Nenhum fornecedor encontrado com o ID: %d\n", id_fornecedor);
    }

    mysql_free_result(resultado);
    mysql_close(&conexao);
}

