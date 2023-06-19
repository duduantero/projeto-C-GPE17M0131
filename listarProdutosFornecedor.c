#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>
#include <locale.h>
#include "listarProdutosFornecedor.h"


typedef struct {
    int id;
    char nome[50];
    float valor_compra;
    float valor_lucro;
    float perc_lucro;
    int id_fornecedor;
} Produto;

void listarProdutosFornecedor(){
    setlocale(LC_ALL,"Portuguese");
    int idFornecedor;
    printf("Escolha uma opção:\n");
    printf("1 - Listar fornecedores e voltar ao cadastro\n");
    printf("2 - Informar ID do fornecedor\n");
    int opcao = 0;
    scanf("%d", &opcao);
    getchar(); // Limpa o caractere de nova linha ('\n') do buffer

    switch (opcao) {
    case 1:
        listarFornecedoresP();
        break;
    case 2:
        printf("ID do fornecedor: ");
        break;
    default:
        printf("Opção incorreta\n");
        return;
    }
    printf("Digite o ID do fornecedor: ");
    scanf("%d", &idFornecedor);
    getchar();

    MYSQL conexao;
    mysql_init(&conexao);

    if (!mysql_real_connect(&conexao, "127.0.0.1", "root", "", "frutaria", 0, NULL, 0)) {
        printf("Erro ao conectar ao banco de dados: %s\n", mysql_error(&conexao));
        return;
    }

char query[200];
sprintf(query, "SELECT id_produto, nome_produto, valor_compra, valor_lucro, perc_lucro FROM Produto WHERE id_fornecedor = %d", idFornecedor);

if (mysql_query(&conexao, query)) {
    printf("Erro na consulta SQL: %s\n", mysql_error(&conexao));
    return;
}

MYSQL_RES *resultado = mysql_use_result(&conexao);
MYSQL_ROW linha;

while ((linha = mysql_fetch_row(resultado)) != NULL) {
    Produto produto;
    produto.id = atoi(linha[0]);
    strncpy(produto.nome, linha[1], sizeof(produto.nome));
    produto.valor_compra = atof(linha[2]);
    produto.valor_lucro = atof(linha[3]);
    produto.perc_lucro = atof(linha[4]);

    printf("ID do Produto: %d\n", produto.id);
    printf("Nome do Produto: %s\n", produto.nome);
    printf("Valor de Compra: %.2f\n", produto.valor_compra);
    printf("Valor de Lucro: %.2f\n", produto.valor_lucro);
    printf("Percentual de Lucro: %.2f %%\n", produto.perc_lucro);
    printf("\n");
}


     mysql_free_result(resultado);
    mysql_close(&conexao);
    printf("\n");
    printf("1 - Retornar ao Menu principal\n");
    printf("2 - Listar Produtos de outro Fornecedor \n");
    int escolha = 0;
    scanf("%d", &escolha);
    getchar();
    switch (escolha) {
    case 1:
        system("cls");
        menu();
        break;
    case 2:
        system("cls");
        listarProdutosFornecedor();
        break;
    default:
        printf("Opção incorreta\n");
        break;
    }
}
