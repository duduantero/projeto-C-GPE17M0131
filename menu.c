#include <stdio.h>
#include <locale.h>
#include "menu.h"
#include "cadastrarFornecedor.h"
#include "cadastrarProduto.h"
#include "listarFornecedores.h"
#include "listarProdutos.h"
#include "listarProdutosEstado.h"
#include "estadoMaisCaro.h"
#include "fornecedorMaisBarato.h"
#include "listarProdutosCresc.h"
#include "listarProdutosLucro.h"
#include "buscarFornecedor.h"


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
    printf("8 - Apresentar o(s) fornecedor(s) onde está registrado o produto mais barato \n");
    printf("9 - Listar todos os produtos em ordem crescente de valor \n");
    printf("10 - Listar todos os produtos em ordem crescente de maior valor do lucro\n");
    printf("11 - Buscar fornecedor\n");


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
        case 8:
            system("cls");
            fornecedorMaisBarato();
            break;
        case 9:
            system("cls");
            listarProdutosCresc();
            break;
        case 10:
            system("cls");
            listarProdutosLucro();
            break;
        case 11:
            system("cls");
            buscarFornecedor();
            break;
        default:
            printf("Opção incorreta\n");
            menu();
            break;
    }
}
