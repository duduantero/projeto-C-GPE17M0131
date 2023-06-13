#include <locale.h>


void menu()
{
    setlocale(LC_ALL, "Portuguese");
    int escolha;

    printf("\n");
    printf("-----------------------------------------------\n");
    printf("                 MENU DE OPÇÕES                \n");
    printf("-----------------------------------------------\n");
    printf("\n");

    printf("1 - Cadastrar produto");

    scanf("%d",&escolha);

    switch(escolha)
    {
    case 1:
        system("cls");
        testeCadastro();
        break;
    default:
        system("cls");
        printf();
        break;

    }

}
