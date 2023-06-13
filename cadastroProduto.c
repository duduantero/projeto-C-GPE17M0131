#include <stdio.h>
#include <string.h>

typedef struct {
    char nome_produto[50];
    float valor_compra;
    float valor_venda;
    float valor_lucro;
    int perc_lucro;
} Produto;

Produto SetProduto(char nome_produto[], float valor_compra, float valor_venda) {
    Produto alface;
    strcpy(alface.nome_produto, nome_produto);
    alface.valor_compra = valor_compra;
    alface.valor_venda = valor_venda;
    alface.valor_lucro = valor_venda - valor_compra;
    alface.perc_lucro = ((valor_venda - valor_compra) / valor_compra) * 100;

    return alface;
}



int main() {
    Produto alface = SetProduto("Alface", 5.0, 7.0);
    imprimirProduto(alface);

    return 0;
}
