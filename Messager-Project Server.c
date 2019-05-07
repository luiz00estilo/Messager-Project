#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "message.h"
#include "server.h"

int main(){

	while (1){
		int i, j, k;
		int date[6] = {1,2,3,4,5,6};
		messagelog log0, log1;
		FILE* ftest;


		while (1){
			loginit(&log0, 100, 100);
			loginit(&log1, 100, 100);


			/*msgsetstr(&log0.msgs[0], "This is the first line");
			msgsetsender(&log0.msgs[0], "201.461.823");
			msgsetdate(&log0.msgs[0], date);

			msgsetstr(&log0.msgs[1], "Then the second one");
			msgsetsender(&log0.msgs[1], "202.472.382");
			msgsetdate(&log0.msgs[1], date);

			msgsetstr(&log0.msgs[2], "This is the third");
			msgsetsender(&log0.msgs[2], "201.461.823");
			msgsetdate(&log0.msgs[2], date);

			msgsetstr(&log0.msgs[3], "And this is the last one");
			msgsetsender(&log0.msgs[3], "202.472.382");
			msgsetdate(&log0.msgs[3], date);*/


    	    ftest = fopen("test file", "r+");
			//fseek(ftest, 0, SEEK_END);
        	logfread(&log0, ftest);

        	fclose(ftest);

			printf("%s\n", log0.msgs[0].sender);
			for (i = 0; i < MSG_DATE_LEN; i++){
				printf("%i/", log0.msgs[0].date[i]);
			}
			printf("\n");
			printf("%s\n", log0.msgs[0].text);

			printf("%s\n", log0.msgs[1].sender);
			for (i = 0; i < MSG_DATE_LEN; i++){
				printf("%i/", log0.msgs[1].date[i]);
			}
			printf("\n");
			printf("%s\n", log0.msgs[1].text);

			printf("%s\n", log0.msgs[2].sender);
			for (i = 0; i < MSG_DATE_LEN; i++){
				printf("%i/", log0.msgs[2].date[i]);
			}
			printf("\n");
			printf("%s\n", log0.msgs[2].text);

			printf("%s\n", log0.msgs[3].sender);
			for (i = 0; i < MSG_DATE_LEN; i++){
				printf("%i/", log0.msgs[3].date[i]);
			}
			printf("\n");
			printf("%s\n", log0.msgs[3].text);

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