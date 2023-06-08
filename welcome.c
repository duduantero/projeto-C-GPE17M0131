#include <locale.h>
#include "menu.c"

void welcome(){
    setlocale(LC_ALL, "Portuguese");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("-----------------------------------------------\n");
    printf("         BEM VINDO AO SACOLÃO DO FULANDO       \n");
    printf("-----------------------------------------------\n");
    Sleep(1000);
    system("cls");
    menu();
}
