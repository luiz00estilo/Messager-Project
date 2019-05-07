#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdio.h>

/*Notas:
- O manuseamento de memória da mensagem é manual, então não se esqueça de alocar antes de usar (msginit() e loginit()), 
e desalocar quando terminar (msgend() e logend())
- O texto da mensagem (message.text) sempre termina com um caractere null ('\0')
*/

/*As definições a seguir definem o tamanho de "message.sender" e "message.date", respectivamente.
Estas podem ser modificadas à sua necesidade*/

#define MSG_SENDER_LEN 20
#define MSG_DATE_LEN 6


typedef struct{
    //Guarda os caracteres da mensagem
    char* text;
    //Guarda a capacidade total da variável "text"
    int len;
    //Guarda o nome de quem enviou a mensagem
    //--FALTA DEFINIR O TAMANHO, INICIALIZAÇÃO E DESTRUIÇÃO--
    char sender[MSG_SENDER_LEN];
    /*Guarda a uma data no formato aaaa/mm/dd/hh/mm/ss*/
    int date[MSG_DATE_LEN];
} message;

/*Aloca a mensagem "msg", com capacidade "length" (em caracteres)*/
void msginit(message* msg, int length);

/*Desaloca a mensagem "msg"*/
void msgend(message* msg);

/*Limpa todos os dados da mensagem*/
void msgclear(message* msg);

/*Retorna a quantidade de caracteres válidos em "msg*/
int msglen(message* msg);

/*Guarda o texto em "text" em "msg->text"*/
void msgsetstr(message* msg, char* text);

/*Guarda a data em "date" em "msg->date"*/
void msgsetdate(message* msg, int* date);

/*Guarda o ip em "sender" em "msg->sender"*/
void msgsetsender(message* msg, char* sender);

/*Copia o texto de "original" para "copy"*/
void msgcpy(message* copy, message* original);

/*Muda a capacidade de "msg" para "lengtg"*/
void msgres(message* msg, int length);

/*Concatena "cat" no final de "msg"*/
void msgcat(message* msg, message* cat);

/*Concatena a string "cat" no final de "msg"*/
void msgcats(message* msg, const char* cat);

/*Concatena o caractere "c" no final de "msg"*/
void msgcatc(message* msg, char c);

/*Lê a entrada do usuário, até encontrar um '\n'*/
void msgin(message* msg);

/*Lê a entrada do usuário, até encontrar o caractere "c"*/
void msginc(message* msg, char c);
/*- Se o caractere "c" não for encontrado, a função irá parar quando encontrar um '\n'
- '\0' não pode ser usado em "c"*/

/*Compara todos os caracteres de "msg0" aos de "msg1", se todos forem iguais retorna 1, caso contrário, retorna 0*/
int msgcomp(message* msg0, message* msg1);
/*COMPARANDO APENAS OS TEXTOS, IGNORANDO "msg.date" E "msg.sender"*/



typedef struct{
    /*Guarda todas a mensgens do "mlog"*/
    message* msgs;
    /*Guarda a quantidade de mensagens em "msgarr"*/
    int len;

} messagelog;


/*Aloca um array de mensagens no "log" com "loglen" de capacidade (em mensagens), cada mensagem tendo "msglen" de capacidade (em caracteres)*/
void loginit(messagelog* log, int loglen, int msglen);

/*Desaloca "log"*/
void logend(messagelog* log);

/*Limpa todas as mensagens em "log"*/
void logclear(messagelog* log);

/*Retorna a quantidades de mensagens em "log"*/
int loglen(messagelog* log);
/*
*As mensagens em uso são definidas por mensagens que possuem algo escrito
*A função irá parar na primeiram mensagem vazia que encontrar
*/

/*Copies the data from "original" to "copy"*/
void logcpy(messagelog* copy, messagelog* original);

/*Guarda os dados de "log" no arquivo "file"
NÃO GUARDA "log.date" POR ENQUANTO, VALORES NÃO CHAR*/   
void logfwrite(messagelog* log, FILE* file);
/*- Requer que "fopen()" seja chamado antes do uso de "file"*/

/*Lê os dados guardados por "logfwrite()" no arquivo "file" e os guarda em "log"*/
void logfread(messagelog* log, FILE* file);
/*- Requer que "fopen()" seja chamado antes do uso de "file"*/

#endif