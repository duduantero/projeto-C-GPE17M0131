#include <stdio.h>
#include <locale.h>
#include "menu.h"
#include "cadastrarFornecedor.h"
#include "cadastrarProduto.h"
#include "listarFornecedores.h"
#include "listarProdutos.h"
#include "listarProdutosEstado.h"
#include "estadoMaisCaro.h"


void menu() {
    setlocale(LC_ALL, "Portuguese");
    int escolha;

    printf("\n");
    printf("-----------------------------------------------\n");
    printf("                 MENU DE OPÇÕES                \n");
    printf("-----------------------------------------------\n");
    printf("\n");

    printf("1 - Cadastrar fornecedor\n");
    printf("2 - Cadastrar produto\n");
    printf("3 - Listar fornecedores\n");
    printf("4 - Listar produtos\n");
    printf("5 - Listar produtos por Estado\n");
    printf("6 - Listar produtos por Fornecedor\n");
    printf("7 - Apresentar o(s) estado(s) onde está registrado o produto mais caro \n");
    scanf("%d", &escolha);
    getchar();
    switch (escolha) {
        case 1:
            system("cls");
            cadastrarFornecedor();
            break;
        case 2:
            system("cls");
            cadastrarProduto();
            break;
        case 3:
            system("cls");
            listarFornecedores();
            break;
        case 4:
            system("cls");
            listarProdutos();
            break;
        case 5:
            system("cls");
            listarProdutosEstado();
            break;
        case 6:
            system("cls");
            listarProdutosFornecedor();
            break;
        case 7:
            system("cls");
            estadoMaisCaro();
            break;
        default:
            printf("Opção incorreta\n");
            break;
    }
}
