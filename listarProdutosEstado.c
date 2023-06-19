#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>
#include "listarProdutosEstado.h"

typedef struct {
    int id;
    char nome[50];
    float valor_compra;
    float valor_lucro;
    float perc_lucro;
    int id_fornecedor;
} Produto;

void listarProdutosEstado() {
    char uf[3];
    printf("Digite a UF desejada: ");
    scanf("%s", uf);
    getchar();

    MYSQL conexao;
    mysql_init(&conexao);

    if (!mysql_real_connect(&conexao, "127.0.0.1", "root", "", "frutaria", 0, NULL, 0)) {
        printf("Erro ao conectar ao banco de dados: %s\n", mysql_error(&conexao));
        return;
    }

    char query[200];
    sprintf(query, "SELECT Produto.nome_produto, Produto.valor_compra, Produto.valor_lucro FROM Produto JOIN Fornecedor ON Produto.id_fornecedor = Fornecedor.id_fornecedor WHERE Fornecedor.uf = '%s'", uf);

    if (mysql_query(&conexao, query)) {
        printf("Erro na consulta SQL: %s\n", mysql_error(&conexao));
        return;
    }

    MYSQL_RES *resultado = mysql_use_result(&conexao);
    MYSQL_ROW linha;

    while ((linha = mysql_fetch_row(resultado)) != NULL) {
        Produto produto;
        strncpy(produto.nome, linha[0], sizeof(produto.nome));
        produto.valor_compra = atof(linha[1]);
        produto.valor_lucro = atof(linha[2]);

        printf("Nome do Produto: %s\n", produto.nome);
        printf("Valor de Compra: %.2f\n", produto.valor_compra);
        printf("Valor de Lucro: %.2f\n", produto.valor_lucro);
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
