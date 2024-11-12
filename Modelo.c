/* 
 * File:   main.c
 * Author: Prof. Wagner Rodrigo Weinert
 *
 * Created on 04 de novembro de 2021
 * Banco de Dados programac
 * create table carro(placa varchar(7) not null, modelo varchar(45) not null, primary key(placa));
 * INSTRUÇÕES PARA Kubuntu ou Debian
  * instalar cliente mysql: apt-get install libmysqlclient-dev 
 * compilar com o seguinte comando: gcc main.c -lmysqlclient -o main
 */

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
      int conta; //Contador comum

      mysql_init(&conexao);
     if ( mysql_real_connect(&conexao, "wagnerweinert.com.br", "tads23_lucas", "tads23_lucas", "tads23_lucas", 3306, NULL, 0) )
      {
           printf("conectado com sucesso!\n");

  		   
  		   //inserção na tabela
  		   res=mysql_query(&conexao,"insert into agenda(nome) values('Teste');");
           if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
           else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

           
           //seleção na tabela
		   if (mysql_query(&conexao,"select * from agenda;"))
                  printf("Erro: %s\n",mysql_error(&conexao));
           else
      			{
         			resp = mysql_store_result(&conexao);//recebe a consulta
        			if (resp) //se houver consulta
        			{
           				//passa os dados dos campos para a variável campos
           				//escreve na tela os nomes dos campos dando
           				//um tab somente
           				campos = mysql_fetch_fields(resp);
           				for (conta=0;conta<mysql_num_fields(resp);conta++) 
           				{
              				printf("%s",(campos[conta]).name);
              				if (mysql_num_fields(resp)>1)
                  				printf("\t");
              			}
                    	printf("\n");  
		            	//enquanto retornar registros, conta até o
        		    	//número de colunas que a tabela tem e escreve na
              			//tela com um tab, depois pula a linha e tenta
              			//pegar outro registros
              			while ((linhas=mysql_fetch_row(resp)) != NULL)
              			{
                 			for (conta=0;conta<mysql_num_fields(resp);conta++)
                    			printf("%s\t",linhas[conta]);
                 			printf("\n");
              			}
                	}
          			mysql_free_result(resp);//limpa a variável do resultado: resp
        		}

        	//Alterando um valor
			res=mysql_query(&conexao,"update carro set modelo='Pampa' where placa like 'AWX1313'");
            if (!res) printf("Registros alterados %d\n", mysql_affected_rows(&conexao));
            else printf("Erro na alteração %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));        		


        	//Excluindo um valor	
        	res=mysql_query(&conexao,"delete from carro where placa like 'AWX1313'");
            if (!res) printf("Registros excluídos %d\n", mysql_affected_rows(&conexao));
            else printf("Erro na exclusão %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));        		

        	mysql_close(&conexao);
       }
       else
       {
            printf("Falha de conexao\n");
            printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
       }

}
