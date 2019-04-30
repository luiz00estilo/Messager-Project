#include <stdio.h>
#include "message.h"
#include "server.h"

int main(){

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
    
    return 0;
}