#include <stdio.h>  // biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  //biblioteca de aloca��o de texto por regi�o
#include  <string.h>  //biblioteca respons�vel por cuidar das string

int registro() //fun��o repons�vel por cadastrar os usu�rios no sistema
{
   char arquivo[40];  //inicio cria��o de vari�veis/string
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];	//final da cria��o de vari�veis/string
   
   printf("DIGITE O CPF A SER CADASTRADO:  ");  //coletando informa��o do usu�rio
   scanf("%s", cpf);  //%s refere-se a string
   
   strcpy(arquivo, cpf);  //respons�vel por criar os valores das string
   
   FILE *file;  //cria o arquivo
   file = fopen(arquivo, "w");  //cria o arquivo e o "w" significa escrever
   fprintf(file,cpf);  //salvo o arquivo da vari�vel
   fclose(file);  //fecha o arquivo
   
   file = fopen(arquivo, "a");  // "a" significa atualizar
   fprintf(file, ",");
   fclose(file);  //fecha o arquivo
   
   printf("DIGITE O NOME A SER CADASTRADO: ");  //coletando informa��o do usu�rio
   scanf("%s", nome);  //%s refere-se a string
   
   file = fopen(arquivo, "a");  // "a" significa atualizar
   fprintf(file, nome);  //salvo o arquivo da vari�vel
   fclose(file);  //fecha o arquivo
   
   file = fopen(arquivo, "a");  // "a" significa atualizar
   fprintf(file, ",");
   fclose(file);  //fecha o arquivo
   
   printf("DIGITE O SOBRENOME A SER CADASTRADO: ");  //coletando informa��o do usu�rio
   scanf("%s", sobrenome);  //%s refere-se a string
   
   file = fopen(arquivo,"a");  // "a" significa atualizar
   fprintf(file,sobrenome);  //salvo o arquivo da vari�ve
   fclose(file);  //fecha o arquivo
   
   file = fopen(arquivo, "a");  // "a" significa atualizar
   fprintf(file, ",");
   fclose(file);  //fecha o arquivo
   
   printf("DIGITE O CARGO A SER CADASTRADO: ");  //coletando informa��o do usu�rio
   scanf("%s",cargo);  //%s refere-se a string
   
   file = fopen(arquivo,"a");  // "a" significa atualizar
   fprintf(file,cargo);  //salvo o arquivo da vari�ve
   fclose(file);  //fecha o arquivo
   
   system("pause");  //fim da fun��o
   
   
}
int consulta()  //fun��o repons�vel por consultar os usu�rios no sistema
{

   setlocale (LC_ALL, "portuguese"); //definindo a linguagem
	    	
   char cpf[40];
   char conteudo[200];
   
   
   printf("DIGITE O CPF A SER CONSULTADO: ");  //coletando informa��o do usu�rio
   scanf("%s", cpf);  //%s refere-se a string
   
   FILE *file;  //cria o arquivo
   file = fopen(cpf,"r");  // "r" significa ler
   
   if(file == NULL)  // "if" significa se
   {
   	printf("N�O FOI POSSIVEL ABRIR O ARQUIVO, N�O LOCALIZADO!. \n");
   }

	while(fgets(conteudo, 200, file) != NULL)  // "while" significa enquento
	{
		printf("\n ESSAS S�O AS INFORMA��ES DO USU�RIO: ");  //coletando informa��o do usu�rio
		printf("%s" , conteudo);  //%s refere-se a string
		printf("\n\n");  // "\n\n" significa pular linha
	}
	
	system("pause");
}

int deletar()  //fun��o repons�vel por deletar os usu�rios no sistema
{
    char cpf[40];
	
	printf("DIGITE O CPF DO USU�RIO A SER DELETADO: ");  //coletando informa��o do usu�rio
	scanf("%s", cpf);  //%s refere-se a string
	
	remove(cpf);  //comando
	
	FILE *file;  //cria o arquivo
	file = fopen(cpf, "r");  // "r" significa ler
	
	if(file == NULL);  // "if" significa se
	{
		printf("O USU�RIO N�O SE ENCONTRA NO SISTEMA!. \n");
		system("pause");	
	}
	
		
}

int main ()
{
	int opcao=0;  //definindo vari�veis
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	  system("cls");
	
    	setlocale (LC_ALL, "portuguese"); //definindo a linguagem
	
	  printf ("### CART�RIO DA EBAC ###\n\n"); //inicio do menu
	  printf ("ESCOLHA A OP��O DESEJADA NO MENU:\n\n" );
	  printf (" \t1 - REGISTRAR NOMES\n " );
	  printf ("  \t2 - CONSULTAR NOMES\n " );
	  printf ("   \t3 - DELETAR NOMES\n\n " ); 
	  printf ("   \t4 - SAIR DO SISTEMA\n\n " );
	  printf ("OP��O: ");  //fim do menu
	
	  scanf("%d" , &opcao); //armazenando a escolha do usu�rio
	
	  system("cls");  //respon�vel por limpar a tela
	  
	  switch(opcao)  //inicio da sele��o do menu
	  {
	  	case 1 :
        registro();  //chamada de fun��es
	  	break;  //final da fun��o
	  	
	  	case 2 :
        consulta();  //chamada de fun��es
        break;  //final da fun��o
        
        case 3 :
        deletar();  //chamada de fun��es
	    break;  //final da fun��o
	    
	    case 4 :
        printf("OBRIGADO POR UTILIZAR O SISTEMA!\n");
        return 0;
        break;
	    
	    default:
	    printf("ESSA OP��O N�O ESTA DISPON�VEL\n");
	    system ("pause");	
	    break;  //final da fun��o
	    
	  }
	
    }
   
}


