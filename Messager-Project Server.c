#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "message.h"
#include "server.h"

int main(){

 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>  //ATENÇÃO: PRECISA ACHAR A BIBLIOTECA EQUIVALENTE NO LINUX
int a,b,L,L2;

void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
int main(){
    /*//menu*/
    
    int opcao;
    
    do{
    	inicio:
        opcao=0;
        L=10;L2=2;b=2;
        system("cls");
        system("color 0f");
        printf("    #                             #####                         \n    #          ##    #####       #     #  #    #    ##    ##### \n    #         #  #   #    #      #        #    #   #  #     #   \n    #        #    #  #####       #        ######  #    #    #   \n    #        ######  #    #      #        #    #  ######    #   \n    #        #    #  #    #      #     #  #    #  #    #    #   \n    #######  #    #  #####        #####   #    #  #    #    #\n\n");
        printf("****************************************************************");
		printf("\n\n      1 - Cadartrar Amigos \n      2 - Lista de Amigos \n      3 - Conectar com amigo \n      4 - SAIR\n");
		printf("\n*****************************************************************\n");
        printf("Criado por: \nLUIZ HENRIQUE OLIVEIRA MARTINS\nMARCUS VINICIUS MARACAJA PIRES\nRAFAEL SALDANHA PICHELLI\nMIQUEIAS LUIS MARTINS DE OLIVEIRA\n\n\nProfessor: \nDr. Tiago Maritan Ugulino de Araujo\n");
		do{
            gotoxy(1,L);
            printf("-->");
            gotoxy(10,6);
            if(kbhit){a=getch();}
            if(a == 80 && b < 5){L2=L;L++;b++;}/*seta p/baixo*/
            if(a == 72 && b > 2){L2=L;L--;b--;}/*seta p/cima */
            if(L!=L2){gotoxy(1,L2);printf("   ");L2=L;}
            if(a == 13){opcao=b-1;}
        }while(opcao == 0);
        switch (opcao){
            case 1:
                system("cls");
                printf("\n    Cadastro de amigos\n");
                Sleep(2000);
                break;
            case 2:
                system("cls");
                printf("\n    Lista de Amigos\n");
                Sleep(2000);
                break;
            case 3:
                system("cls");
                printf("\n    Conectar com amigo\n");
                Sleep(2000);
                break;
            case 4:
                system("cls");
                printf("voce pediu para sair, prencione qualquer tecla para continuar\n");
                break;
            default:
                printf("voce deve escolher uma opcao valida\n");
                printf("Precione qualquer tecla para voltar ao menu\n");
                system("pause");
                goto inicio;
        }
    }while(opcao!=4);
    return 0;
} 


		while (1){
			loginit(&log0, 6, 10);
			loginit(&log1, 10, 100);

			msgset(&log0.msgs[0], "This is the first line", "201.461.823", date);
			msgset(&log0.msgs[1], "Then the second one", "202.472.382", date);
			msgset(&log0.msgs[2], "This is the third", "203.524.639", date);
			msgset(&log0.msgs[3], "And this is the last one", "204.576.012", date);

    	    ftest = fopen("test file", "w+");
			//fseek(ftest, 0, SEEK_END);
        	logfwrite(&log0, ftest);
			/*for (i = 0; i < 5; i++){
				for (j = 0; j < 4; j++){
					fwrite(log0.msgs[j].text, sizeof(char), msglen(&log0.msgs[j]), ftest);
					fwrite("\n", sizeof(char), 1, ftest);
				}
        	}*/
        	//fseek(ftest, msglen(&msg), SEEK_SET);

        	fclose(ftest);

        	scanf("%i", &i);

			logend(&log0);
			logend(&log1);
		}
	}

    int ret;
	int tamMsg;
	char msgEnv[TAM_MAX];
	char msgRec[TAM_MAX];

	/* Espera o cliente pedir para se conectar e se conecta */
	ret	= conecta();
	while (ret != -1){
		
		/* Lê uma mensagem do usuário e envia pela rede*/
		printf("Digite a mensagem para enviar: ");
		fgets(msgEnv, TAM_MAX, stdin);
		tamMsg = strlen(msgEnv); 
		
		ret = enviaMensagem(msgEnv, tamMsg);
		printf("Enviou uma mensagem com %d bytes\n", ret);


		/* Recebe uma mensagem pela rede */
		ret = recebeMensagem(msgRec, TAM_MAX);
		printf("Msg recebida: %s \n", msgRec);
	}

	return 0;
}