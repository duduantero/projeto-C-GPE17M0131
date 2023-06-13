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

    scanf("%d",&escolha);

    switch(escolha)
    {
    case 1:
        system("cls");
        printf();
        break;
    case 2:
        system("cls");
        printf();
        break;

    }

}
