#include<stdio.h>
void Cadastrar()

{
	//colocar a função de cadastrar	
}
void Remover()
{
	//colocar a função de remover
}
void Cad()
{
	int escolha=1;
	
	printf("Deseja Cadastrar ou Remover Amigo\n");
    printf("1 Cadastrar\n");
    printf("2 Remover\n");
    printf("3 Voltar ao menu principal\n\n");
    
	scanf("%i", &escolha);
    system("cls || clear");
    do{
	switch(escolha)
      {
            case 1:
                Cadastrar();
                printf("Funcao Cadastrar amigo:\n");
                //insirir a função de cadastrar amigo
                break;

            case 2:
                Remover();
                printf("Funcao remover amigo\n");
                //inserir a função de remover amigo
                break;

            case 3:
            	main();
               	break;
           
		    default:
              printf("POR FAVOR, DIGITE UMA OPCAO VALIDA\n");
              Cad();
      }
  }
  while(escolha);
  
}


void List()
{
    printf("LISTA DE AMIGOS\n");
    //função de listar amigos abrindo o arquivo
    main();
}

void Client()
{
    printf("Abrindo o client!\n");
    //abrir o client.c
    main();
}

void server()
{
    printf("Abrindo o Programa Servidor!\n");
    //abrir o server.c
    main();
}

void credito()
{
	printf("_______________________________________________________________\n\n");
	printf("    #                             #####                         \n");
	printf("    #          ##    #####       #     #  #    #    ##    ##### \n");
	printf("    #         #  #   #    #      #        #    #   #  #     #   \n");
	printf("    #        #    #  #####       #        ######  #    #    #   \n");
	printf("    #        ######  #    #      #        #    #  ######    #   \n");
	printf("    #        #    #  #    #      #     #  #    #  #    #    #   \n");
	printf("    #######  #    #  #####        #####   #    #  #    #    #   \n");
    printf("_______________________________________________________________\n\n");
	printf("    Criado por: \n");
	printf("    LUIZ HENRIQUE OLIVEIRA MARTINS\n");
	printf("    MARCUS VINICIUS MARACAJA PIRES\n");
	printf("    RAFAEL SALDANHA PICHELLI\n");
	printf("    MIQUEIAS LUIS MARTINS DE OLIVEIRA\n");
	printf("    \n\nProfessor: \n");
	printf("    Dr. Tiago Maritan Ugulino de Araujo\n\n\n");
	main();
}

void sair()
{
    printf("Obrigado por usar o LAB CHAT\n");
}


int main()
{
    int continuar=1;
	    printf("_______________________________________________________________\n\n");
		printf("    #                             #####                         \n");
		printf("    #          ##    #####       #     #  #    #    ##    ##### \n");
		printf("    #         #  #   #    #      #        #    #   #  #     #   \n");
		printf("    #        #    #  #####       #        ######  #    #    #   \n");
		printf("    #        ######  #    #      #        #    #  ######    #   \n");
		printf("    #        #    #  #    #      #     #  #    #  #    #    #   \n");
		printf("    #######  #    #  #####        #####   #    #  #    #    #   \n");
        printf("_______________________________________________________________\n\n");
    do{
       	printf("1. Cadastrar ou remover Amigo\n");
        printf("2. Lista de Amigos\n");
        printf("3. Conversar com amigo\n");
        printf("4. Nao fazer nada, apenas aguardar que alguem comverse com voce\n");
        printf("5. Criadores\n");
        printf("0. Sair\n");

        scanf("%i", &continuar);
        system("cls || clear");

        switch(continuar)
        {
            case 1:
                Cad();
                break;

            case 2:
                List();
                break;

            case 3:
                Client();
                break;

            case 4:
                server();
                break;
			
			case 5:
				credito();
				break;
				
			case 0:
                sair();
                break;

            default:
                printf("POR FAVOR, DIGITE UMA OPCAO VALIDA\n");
                main();
        }
	}while(continuar);
}
