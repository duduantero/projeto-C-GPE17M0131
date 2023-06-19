#include <locale.h>
#include "welcome.h"
#include "cadastrarFornecedor.h"
#include "cadastrarProduto.h"
#include "menu.h"

void welcome(){
    setlocale(LC_ALL, "Portuguese");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("-----------------------------------------------\n");
    printf("         BEM VINDO A FRUTARIA       \n");
    printf("-----------------------------------------------\n");
    Sleep(750);
    system("cls");
    menu();
}
