#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>


int main() {
    MYSQL conexao;
    mysql_init(&conexao);
    // Aqui tenho um servidor mysql rodando no IP: 127.0.0.1 com usuário "root" sem senha "". ele conecta ao database "banco"
    if ( mysql_real_connect(&conexao, "127.0.0.1", "root", "", "meubanco", 0, NULL, 0) )
    {
       printf("\nConexao ao banco realizada com sucesso!\n");
       mysql_query(&conexao,"INSERT INTO PESSOA(nome, sexo) values('Matheus Miranda', 'M');");
        mysql_close(&conexao);
    }
    else
    {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
    }

    return(0);
}
