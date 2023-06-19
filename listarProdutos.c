#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>
#include "listarProdutos.h"

typedef struct {
    int id;
    char nome[50];
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percLucro;
    int idFornecedor;
} Produto;

void listarProdutos() {
    MYSQL conexao;
    mysql_init(&conexao);

    if (!mysql_real_connect(&conexao, "127.0.0.1", "root", "", "frutaria", 0, NULL, 0)) {
        printf("Erro ao conectar ao banco de dados: %s\n", mysql_error(&conexao));
        return;
    }

    if (mysql_query(&conexao, "SELECT id_produto, nome_produto, valor_compra, valor_venda, valor_lucro, perc_lucro, id_fornecedor FROM produto")) {
        printf("Erro na consulta SQL: %s\n", mysql_error(&conexao));
        return;
    }

    MYSQL_RES *resultado = mysql_use_result(&conexao);
    MYSQL_ROW linha;

    while ((linha = mysql_fetch_row(resultado)) != NULL) {
        Produto produto;
        produto.id = atoi(linha[0]);
        strncpy(produto.nome, linha[1], sizeof(produto.nome));
        produto.valorCompra = atof(linha[2]);
        produto.valorVenda = atof(linha[3]);
        produto.valorLucro = atof(linha[4]);
        produto.percLucro = atof(linha[5]);
        produto.idFornecedor = atoi(linha[6]);

        printf("ID do Produto: %d\n", produto.id);
        printf("Nome do Produto: %s\n", produto.nome);
        printf("Valor de Compra: %.2f\n", produto.valorCompra);
        printf("Valor de Venda: %.2f\n", produto.valorVenda);
        printf("Valor de Lucro: %.2f\n", produto.valorLucro);
        printf("Percentual de Lucro: %.2f%%\n", produto.percLucro);
        printf("ID do Fornecedor: %d\n", produto.idFornecedor);
        printf("\n");
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
