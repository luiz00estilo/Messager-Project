#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "message.h"
#include "server.h"

int main(){

	while (1){
		int i, j, k;
		int date[6] = {1,2,3,4,5,6};
		messagelog log0 ,log1;
		FILE* ftest;

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