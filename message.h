#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdlib.h>
#include <stdio.h>

/*Notas:
- O manuseamento de memória da mensagem é manual, então não se esqueça de alocar antes de usar, 
e desalocar quando terminar*/

typedef struct{
    //Guarda os caracteres da mensagem
    char* text;
    //Guarda a capacidade total da variável "text"
    int len;
    //Guarda o nome de quem enviou a mensagem
    //FALTA DEFINIR O TAMANHO, INICIALIZAÇÃO E DESTRUIÇÃO
    char* sender;
} message;

/*Aloca a mensagem "msg", com capacidade "length" (em caracteres)*/
void msginit(message* msg, int length);

/*Desaloca a mensagem "msg"*/
void msgend(message* msg);

/*Limpa todos os caracteres válidos da mensagem*/
void msgclear(message* msg);

/*Retorna a quantidade de caracteres válidos em "msg*/
int msglen(message* msg);

/*Guarda a string escrita em "original" para "copy"*/
void msgset(message* copy, const char* original);

/*Copia o texto de "original" para "copy"*/
void msgcpy(message* copy, message* original);

/*Muda a capacidade de "msg" para "lengtg"*/
void msgres(message *msg, int length);

/*Concatena "cat" no final de "msg"*/
void msgcat(message* msg, message* cat);

/*Concatena a string "cat" no final de "msg"*/
void msgcats(message* msg, const char* cat);

/*Concatena o caractere "c" no final de "msg"*/
void msgcatc(message* msg, char c);

/*Lê a entrada do usuário, até encontrar um '\n'*/
void msgin(message* msg);

/*Lê a entrada do usuário, até encontrar o caractere "c"
- Se o caractere "c" não for encontrado, a função irá parar quando encontrar um '\n'
- '\0' não pode ser usado em "c"*/
void msginc(message* msg, char c);

/*Compara todos os caracteres de "msg0" aos de "msg1", se todos forem iguais retorna 1, caso contrário, retorna 0*/
int msgcomp(message* msg0, message* msg1);

#endif