#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Bibliotecas usadas para criar a conexão usando sockets 
	e enviar dados pela rede*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "client.h"



/* Variáveis globais usadas na conexão, envio e recebimento de dados*/
static int sockfd, newFD;
	
/**
	Função que cria uma conexão com o servidor. 
	Ele faz o pedido de conexão ao servidor e espera a resposta. 
	IMPORTANTE: O servidor precisa estar rodando esperando o pedido de conexão para que a mesma seja realizada 
	
	Parametros: uma string contendo o endereço IP do servidor. 
	Retorno: 1 se a conexão foi realizada com sucesso e -1 caso contrário.
 */
int conecta(char *ipServidor){
	struct sockaddr_in server;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if ( sockfd ==-1){
		printf("Socket não pode ser criado\n");
	}

	server.sin_addr.s_addr = inet_addr(ipServidor);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORTA);
 
    //Connect to remote server
    if (connect(sockfd, (struct sockaddr *)&server,sizeof(server)) < 0){
        printf("Erro de conexão\n");
        return -1;
    }
     
    printf("Conectado\n");
    return 1;
}

int enviaMensagem(char *msg, int tamMsg){
	// Envia mensagem
	return send(sockfd, msg, tamMsg, 0);
}

int recebeMensagem(char *msg, int tamMsg){
	// Envia mensagem
	return recv(sockfd, msg, tamMsg, 0);
}
