#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h>  // biblioteca de alocação de espaço em memória
#include <locale.h>  //biblioteca de alocação de texto por região
#include  <string.h>  //biblioteca responsável por cuidar das string

int registro() //função reponsável por cadastrar os usuários no sistema
{
   char arquivo[40];  //inicio criação de variáveis/string
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];	//final da criação de variáveis/string
   
   printf("DIGITE O CPF A SER CADASTRADO:  ");  //coletando informação do usuário
   scanf("%s", cpf);  //%s refere-se a string
   
   strcpy(arquivo, cpf);  //responsável por criar os valores das string
   
   FILE *file;  //cria o arquivo
   file = fopen(arquivo, "w");  //cria o arquivo e o "w" significa escrever
   fprintf(file,cpf);  //salvo o arquivo da variável
   fclose(file);  //fecha o arquivo
   
   file = fopen(arquivo, "a");  // "a" significa atualizar
   fprintf(file, ",");
   fclose(file);  //fecha o arquivo
   
   printf("DIGITE O NOME A SER CADASTRADO: ");  //coletando informação do usuário
   scanf("%s", nome);  //%s refere-se a string
   
   file = fopen(arquivo, "a");  // "a" significa atualizar
   fprintf(file, nome);  //salvo o arquivo da variável
   fclose(file);  //fecha o arquivo
   
   file = fopen(arquivo, "a");  // "a" significa atualizar
   fprintf(file, ",");
   fclose(file);  //fecha o arquivo
   
   printf("DIGITE O SOBRENOME A SER CADASTRADO: ");  //coletando informação do usuário
   scanf("%s", sobrenome);  //%s refere-se a string
   
   file = fopen(arquivo,"a");  // "a" significa atualizar
   fprintf(file,sobrenome);  //salvo o arquivo da variáve
   fclose(file);  //fecha o arquivo
   
   file = fopen(arquivo, "a");  // "a" significa atualizar
   fprintf(file, ",");
   fclose(file);  //fecha o arquivo
   
   printf("DIGITE O CARGO A SER CADASTRADO: ");  //coletando informação do usuário
   scanf("%s",cargo);  //%s refere-se a string
   
   file = fopen(arquivo,"a");  // "a" significa atualizar
   fprintf(file,cargo);  //salvo o arquivo da variáve
   fclose(file);  //fecha o arquivo
   
   system("pause");  //fim da função
   
   
}
int consulta()  //função reponsável por consultar os usuários no sistema
{

   setlocale (LC_ALL, "portuguese"); //definindo a linguagem
	    	
   char cpf[40];
   char conteudo[200];
   
   
   printf("DIGITE O CPF A SER CONSULTADO: ");  //coletando informação do usuário
   scanf("%s", cpf);  //%s refere-se a string
   
   FILE *file;  //cria o arquivo
   file = fopen(cpf,"r");  // "r" significa ler
   
   if(file == NULL)  // "if" significa se
   {
   	printf("NÃO FOI POSSIVEL ABRIR O ARQUIVO, NÃO LOCALIZADO!. \n");
   }

	while(fgets(conteudo, 200, file) != NULL)  // "while" significa enquento
	{
		printf("\n ESSAS SÃO AS INFORMAÇÕES DO USUÁRIO: ");  //coletando informação do usuário
		printf("%s" , conteudo);  //%s refere-se a string
		printf("\n\n");  // "\n\n" significa pular linha
	}
	
	system("pause");
}

int deletar()  //função reponsável por deletar os usuários no sistema
{
    char cpf[40];
	
	printf("DIGITE O CPF DO USUÁRIO A SER DELETADO: ");  //coletando informação do usuário
	scanf("%s", cpf);  //%s refere-se a string
	
	remove(cpf);  //comando
	
	FILE *file;  //cria o arquivo
	file = fopen(cpf, "r");  // "r" significa ler
	
	if(file == NULL);  // "if" significa se
	{
		printf("O USUÁRIO NÃO SE ENCONTRA NO SISTEMA!. \n");
		system("pause");	
	}
	
		
}

int main ()
{
	int opcao=0;  //definindo variáveis
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	  system("cls");
	
    	setlocale (LC_ALL, "portuguese"); //definindo a linguagem
	
	  printf ("### CARTÓRIO DA EBAC ###\n\n"); //inicio do menu
	  printf ("ESCOLHA A OPÇÃO DESEJADA NO MENU:\n\n" );
	  printf (" \t1 - REGISTRAR NOMES\n " );
	  printf ("  \t2 - CONSULTAR NOMES\n " );
	  printf ("   \t3 - DELETAR NOMES\n\n " ); 
	  printf ("   \t4 - SAIR DO SISTEMA\n\n " );
	  printf ("OPÇÃO: ");  //fim do menu
	
	  scanf("%d" , &opcao); //armazenando a escolha do usuário
	
	  system("cls");  //responável por limpar a tela
	  
	  switch(opcao)  //inicio da seleção do menu
	  {
	  	case 1 :
        registro();  //chamada de funções
	  	break;  //final da função
	  	
	  	case 2 :
        consulta();  //chamada de funções
        break;  //final da função
        
        case 3 :
        deletar();  //chamada de funções
	    break;  //final da função
	    
	    case 4 :
        printf("OBRIGADO POR UTILIZAR O SISTEMA!\n");
        return 0;
        break;
	    
	    default:
	    printf("ESSA OPÇÃO NÃO ESTA DISPONÍVEL\n");
	    system ("pause");	
	    break;  //final da função
	    
	  }
	
    }
   
}


