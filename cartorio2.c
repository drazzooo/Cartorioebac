#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rio no sistema
{
	//in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings

	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf);  //%s refere-se a strings
	
	strcpy(arquivo , cpf); //respons�vel por copiar os valores das strings
	
	FILE *file;
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" signifida escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
   char cpf[40];
   char conteudo[200];
   
   printf("Digite o cpf a ser consultado: ");
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf, "r");
   
   if(file == NULL)
   {
   	printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");
   }
   
   while(fgets(conteudo, 200, file) != NULL)
   {
   	printf("\nEssas s�o as informa��es do usu�rio: ");
   	printf("%s", conteudo);
   	printf("\n\n");
   }
   
   system("pause");
   
   
   	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);	
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O Usu�rio n�o se encontra no sistema! \n");
    	system("pause");
	}
	
	
	
	
}

int main()
{
	int opcao=0; //definindo vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL, "PORTUGUESE"); //Definindo linguagem
		
		printf("Cart�rio EBAC\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("Op��o: "); //Fim do menu
		
		scanf("%d", &opcao); //Amazenando a escolha do usu�rio
		
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
				registro(); //chamada de fun��es
				break;
				
			case 2:
				consulta();
				break;
				
			case 3:
			    deletar();
			    break;
			
			default:
			    printf("Voc� escolheu uma op��o que n�o existe\n");
			    system("pause");
			    break;	
		}   //fim da sele��o
	}
	
	
}
