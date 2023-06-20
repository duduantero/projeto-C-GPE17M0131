#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "estadoMaisCaro.h"
#include "menu.h"
#include "informarFornecedor.h"


typedef struct {
    int id;
    char nome[50];
    float valor_compra;
    float valor_lucro;
    float perc_lucro;
    int id_fornecedor;
} Produto;

void estadoMaisCaro() {
    MYSQL conexao;
    mysql_init(&conexao);

    if (!mysql_real_connect(&conexao, "127.0.0.1", "root", "", "frutaria", 0, NULL, 0)) {
        printf("Erro ao conectar ao banco de dados: %s\n", mysql_error(&conexao));
        return;
    }

    char query[200];
    sprintf(query, "SELECT * FROM Produto ORDER BY valor_compra DESC LIMIT 1");

    if (mysql_query(&conexao, query)) {
        printf("Erro na consulta SQL: %s\n", mysql_error(&conexao));
        mysql_close(&conexao);
        return;
    }

    MYSQL_RES *resultado = mysql_store_result(&conexao);
    MYSQL_ROW linha;

    if ((linha = mysql_fetch_row(resultado)) != NULL) {
        Produto produto;
        produto.id = atoi(linha[0]);
        strncpy(produto.nome, linha[1], sizeof(produto.nome));
        produto.valor_compra = atof(linha[2]);
        produto.valor_lucro = atof(linha[3]);
        produto.perc_lucro = atof(linha[4]);
        produto.id_fornecedor = atoi(linha[6]);

        printf("ID do Produto: %d\n", produto.id);
        printf("Nome do Produto: %s\n", produto.nome);
        printf("Valor de Compra: %.2f\n", produto.valor_compra);
        printf("Valor de Lucro: %.2f\n", produto.valor_lucro);
        printf("Percentual de Lucro: %.2f\n", produto.perc_lucro);
        printf("ID do Fornecedor: %d\n", produto.id_fornecedor);
        printf("-----------------------------------------------\n");
        informarFornecedor(produto.id_fornecedor);
    } else {
        printf("Nenhum produto encontrado.\n");
    }

    mysql_free_result(resultado);
    mysql_close(&conexao);

         printf("\n");
    printf("1 - Retornar ao Menu principal\n");
    int escolha = 0;

    scanf("%d", &escolha);
    getchar();
    switch (escolha) {
    case 1:
        system("cls");
        menu();
        break;
    default:
        printf("Opção incorreta\n");
        break;
    }


}





