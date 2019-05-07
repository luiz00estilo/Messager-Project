#ifndef SERVER_H
#define SERVER_H

/* Constante que define o tamanho máximo da mensagem enviada ou recebida*/
#define TAM_MAX 100
/* Constante que define a porta utilizada para conexão */
#define PORTA 12345

int conecta();

int enviaMensagem(char *msg, int tamMsg);

int recebeMensagem(char *msg, int tamMsg);

#endif