#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>
#include <string.h>
#include "cadastrarProduto.h"
#include "listarFornecedoresP.h"
#include "menu.h"

typedef struct {
    char nome_produto[50];
    float valor_compra;
    float valor_venda;
    float valor_lucro;
    int perc_lucro;
    int id_fornecedor;  // Adicionado o campo id_fornecedor
} Produto;

void cadastrarProduto() {
    setlocale(LC_ALL, "Portuguese");
    Produto produto;
    printf("-----------------------------------------------\n");
    printf("             CADASTRO DE PRODUTO               \n");
    printf("-----------------------------------------------\n");

    printf("Nome do produto: ");
    fgets(produto.nome_produto, sizeof(produto.nome_produto), stdin);
    produto.nome_produto[strcspn(produto.nome_produto, "\n")] = '\0';

    printf("Valor de compra: ");
    scanf("%f", &produto.valor_compra);

    printf("Valor de venda: ");
    scanf("%f", &produto.valor_venda);

    produto.valor_lucro = produto.valor_venda - produto.valor_compra;
    produto.perc_lucro = ((produto.valor_venda - produto.valor_compra) / produto.valor_compra) * 100;

    printf("Escolha uma opção:\n");
    printf("1 - Listar fornecedores e voltar ao cadastro\n");
    printf("2 - Informar ID do fornecedor\n");
    int opcao = 0;
    scanf("%d", &opcao);
    getchar(); // Limpa o caractere de nova linha ('\n') do buffer

    switch (opcao) {
    case 1:
        listarFornecedoresP();
        printf("ID do fornecedor: ");
        scanf("%d", &produto.id_fornecedor);
        break;
    case 2:
        printf("ID do fornecedor: ");
        scanf("%d", &produto.id_fornecedor);
        break;
    default:
        printf("Opção incorreta\n");
        return;
    }

    MYSQL conexao;
    mysql_init(&conexao);
    if (mysql_real_connect(&conexao, "127.0.0.1", "root", "", "frutaria", 0, NULL, 0)) {
        printf("Conectado com sucesso ao banco de dados!\n");
        printf("-----------------------------------------------\n");

        char query[1000];
        sprintf(query, "INSERT INTO `produto`(`nome_produto`, `valor_compra`, `valor_venda`, `valor_lucro`, `perc_lucro`, `id_fornecedor`) VALUES ('%s','%f','%f','%f','%d','%d');", produto.nome_produto, produto.valor_compra, produto.valor_venda, produto.valor_lucro, produto.perc_lucro, produto.id_fornecedor);
        mysql_query(&conexao, query);
        printf("\nProduto cadastrado com sucesso!\n");
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
        cadastrarProduto();
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
