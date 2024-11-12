/* compilar com o seguinte comando: gcc main.c -lmysqlclient -o main */

#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void main(void)
{
    MYSQL conexao;
      int res;
      MYSQL_RES *resp;
   	  MYSQL_ROW linhas;
      MYSQL_FIELD *campos;
      int conta;

    mysql_init(&conexao);
     if ( mysql_real_connect(&conexao, "wagnerweinert.com.br", "tads23_lucas", "tads23_lucas", "tads23_lucas", 3306, NULL, 0) )
      {
        printf("conectado com sucesso!\n");
      }


}