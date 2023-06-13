#include <stdio.h>
#include <winsock2.h>
#include <mysql.h>
#include <string.h>
#include <windows.h>
#define texto "%[^\n]s"

void menu(MYSQL conexao);
void update(MYSQL conexao);
int busca_id(MYSQL conexao, int id, char query[1024]);
int checa_estoque(MYSQL conexao, int id, char query[1024]);

void main()
{
    MYSQL conexao;
    mysql_init(&conexao);
    if(mysql_real_connect(&conexao, "127.0.0.1", "root", "", "carcessionaria", 0, NULL, 0))
    menu(conexao);
    else
    {
        printf("Falha na conexao com o Banco de Dados\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
    }

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
