#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "message.h"
#include "client.h"

int main(){
	int ret;
	int tamMsg;
	char msgEnv[TAM_MAX];
	char msgRec[TAM_MAX];

	/* Pede para se conectar no servidor */
	ret	= conecta("127.0.0.1");
	while (ret != -1){
		
		/* Recebe uma mensagem do servidor pela rede */
		ret = recebeMensagem(msgRec, TAM_MAX);
		printf("Msg recebida: %s \n", msgRec);
	
		/* Lê uma mensagem do usuário e envia pela rede para o servidor*/
		printf("Digite a mensagem para enviar: ");
		fgets(msgEnv, TAM_MAX, stdin);
		tamMsg = strlen(msgEnv); 
		
		ret = enviaMensagem(msgEnv, tamMsg);
		printf("Enviou uma mensagem com %d bytes\n", ret);

	}

	return 0;
}