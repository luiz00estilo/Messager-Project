#include "message.h"

#include <stdlib.h>

void msginit(message* msg, int length){
    int i;

    //Allocating the variables
    msg->text = (char*) malloc(length * sizeof(char));

    //Setting the length
    msg->len = length;

    //Setting all data to null
    for (i = 0; i < msg->len; i++) {
        msg->text[i] = '\0';
    }
    for (i = 0; i < MSG_SENDER_LEN; i++) {
        msg->sender[i] = '\0';
    }
    for (i = 0; i < MSG_DATE_LEN; i++){
        msg->date[i] = 0;
    }

    return;
}

void msgend(message* msg){
    int i = 0;

    /*Deallocating the string*/
    free(msg->text);

}

void msgclear(message* msg) {
    int i;

    //Clearing "msg->text"
    for (i = 0; msg->text[i] != '\0'; i++) {
        msg->text[i] = '\0';
    }

    //Clearing "msg->sender"
    for (i = 0; i < MSG_SENDER_LEN; i++){
        msg->sender[i] = '\0';
    }

    //Clearing "msg->date"
    for (i = 0; i < MSG_DATE_LEN; i++){
        msg->date[i] = 0;
    }

    return;
}

int msglen(message* msg){
    int i;
    for (i = 0; msg->text[i] != '\0'; i++);
    return i;
}

void msgsetstr(message* msg, char* text) {
    int i;
    
    //Clearing "msg->text"
    for (i = 0; msg->text[i] != '\0'; i++) {
        msg->text[i] = '\0';
    }

    //Copying from "text" to "msg->text"
    for (i = 0; i < (msg->len - 1) && text[i] != '\0'; i++){
        msg->text[i] = text[i];
    }

    return;
}

void msgsetdate(message* msg, int* date){
    int i;

    //Clearing "msg->date"
    for (i = 0; i < MSG_DATE_LEN; i++){
        msg->date[i] = 0;
    }

    //Copying from "date" to "msg->date"
    for (i = 0; i < MSG_DATE_LEN; i++){
        msg->date[i] = date[i];
    }
}

void msgsetsender(message* msg, char* sender){
    int i;

    //Clearing "msg->sender"
    for (i = 0; i < MSG_SENDER_LEN; i++){
        msg->sender[i] = '\0';
    }

    //Copying from "sender" to "msg->sender"
    for (i = 0; i < (MSG_SENDER_LEN - 1) && sender[i] != '\0'; i++){
        msg->sender[i] = sender[i];
    }

}

void msgcpy(message* copy, message* original) {
    int i;

    msgclear(copy);

    //Copies all characters, leaving only the last '\0'
    for (i = 0; i < (copy->len- 1) && original->text[i] != '\0'; i++) {
        copy->text[i] = original->text[i];
    }

    for (i = 0; i < MSG_DATE_LEN; i++){
        copy->date[i] = original->date[i];
    }

    for (i = 0; i < MSG_SENDER_LEN; i++){
        copy->sender[i] = original->sender[i];
    }
    
    return;
}

void msgres(message *msg, int length) {
    message dummy;
    msginit(&dummy, msg->len);

    msgcpy(&dummy, msg);

    msgend(msg);
    msginit(msg, length);

    msgcpy(msg, &dummy);

    msgend(&dummy);
    return;
}

void msgcat(message* msg, message* cat) {
    int i, j;
    //Finds the end of "msg"
    i = msglen(msg);

    //Copies all the characters to the end of "msg", leaving only the last '\0'
    for (j = 0; i < (msg->len - 1) && cat->text[j] != '\0'; i++ ,j++){
        msg->text[i] = cat->text[j];
    }
    return;
}

void msgcats(message* msg, const char* cat) {
    int i, j;
    //Finds the end of "msg"
    i = msglen(msg);

    //Copies all the characters to the end of "msg", leaving only the last '\0'
    for (j = 0; i < (msg->len - 1) && cat[j] != '\0'; i++ ,j++){
        msg->text[i] = cat[j];
    }
    return;
}

void msgcatc(message* msg, char c) {
    int i, j;
    //Finds the end of "msg"
    i = msglen(msg);

    //Copies all the characters to the end of "msg", leaving only the last '\0'
    if (i < (msg->len - 1)){
        msg->text[i] = c;
    }
    return;
}

void msgin(message* msg) {
    int i;
    char ctemp = '\0';

    msgclear(msg);
    //Copies all the characters, leaving only the last '\0' or an '\n' is found
    for (i = 0; i < (msg->len - 1) && ctemp != '\n'; i++){
        scanf("%c", &ctemp);
        msg->text[i] = ctemp;
    }
    //Deletes the '\n' at the end, if it exists
    if (msg->text[i - 1] == '\n'){
        msg->text[i - 1] = '\0';
    }
    /*If the "else" loop is activated, the "for" loop didn't consume all typed characters, so ,
    to avoid buffer overflow, it will consume the rest of teh characters*/
    else {
        for (i = 0; ctemp != '\n'; i++){
            scanf("%c", &ctemp);
        }
    }

    return;
}

void msginc(message* msg, char c) {
    if (c == '\0') return;

    int i;
    char ctemp = '\0';

    msgclear(msg);
    //Copies all the characters, leaving only the last '\0', or an "c" or '\n' is found
    for (i = 0; i < (msg->len - 1) && (ctemp != c && ctemp != '\n'); i++){
        scanf("%c", &ctemp);
        msg->text[i] = ctemp;
    }

    //Deletes the "c" at the end, if it exists
    if (msg->text[i - 1] == c || msg->text[i - 1] == '\n'){
        msg->text[i - 1] = '\0';
    }
    else {
        /*If the "else" loop is activated, the "for" loop didn't consume all typed characters, so,
        to avoid buffer overflow, it will consume the rest of teh characters*/
        for (i = 0; ctemp != c; i++){
            scanf("%c", &ctemp);
        }
    }

    return;
}

int msgcomp(message* msg0, message* msg1){
    if (msglen(msg0) != msglen(msg1)){
        return 0;
    }
    else {
        int i;
        int len = msglen(msg0);
        for (i = 0; i < len; i++){
            if(msg0->text[i] != msg1->text[i]){
                return 0;
            }
        }
        return 1;
    }
}


//--------------------------------------


void loginit(messagelog* log, int loglen, int msglen){
    int i;

    /*Allocating the log*/
    log->msgs = (message*) malloc(loglen * sizeof(message));
    
    /*Allocating the messages*/
    for (i = 0; i < loglen; i++){
        msginit(&log->msgs[i], msglen);
    }
    
    /*Setting the length*/
    log->len = loglen;

    return;
}

void logend(messagelog* log){
    int i;

    /*Deallocating the messages*/
    for (i = 0; i < log->len; i++){
        msgend(&log->msgs[i]);
    }

    /*Deallocating the log*/
    free(log->msgs);
    return;
}

void logclear(messagelog* log){
    int i;
    for (i = 0; i < log->len; i++){
        msgclear(&log->msgs[i]);
    }
    return;
}

int loglen(messagelog* log){
    int i;
    for (i = 0; i < log->len; i++){
        if (msglen(&log->msgs[i]) == 0) break;
    }
    return i;
}

void logcpy(messagelog* copy, messagelog* original){
    int i;
    int oriLen = loglen(original);

    logclear(copy);

    for (i = 0; i < copy->len && i < oriLen; i++){
        msgcpy(&copy->msgs[i], &original->msgs[i]);
    }
}

//Not declared in "message.h"
int msgsenderlen(message* msg){
    int i;
    for (i = 0; msg->sender[i] != '\0'; i++);
    return i;
}
//---------------------------

void logfwrite(messagelog* log, FILE* file){
    int i;
    int llen = loglen(log);
    int eol = -1;

    for (i = 0; i < llen; i++){
        //Writing ip
        fwrite(log->msgs[i].sender, sizeof(char), msgsenderlen(&log->msgs[i]), file);
        fwrite("\n", sizeof(char), 1, file);

        //Writing date (the date ends in (int)-1 instead of a '\n')
        fwrite(log->msgs[i].date, sizeof(int), MSG_DATE_LEN, file);
        fwrite(&eol, sizeof(int), 1, file);

        //Writing text
        fwrite(log->msgs[i].text, sizeof(char), msglen(&log->msgs[i]), file);
        fwrite("\n", sizeof(char), 1, file);
    }
    return;
}

void logfread(messagelog* log, FILE* file){
    int i, j;
    char dummyC;
    int dummyI;

    logclear(log);

    //For all msgs
    for (i = 0; i < log->len && !feof(file); i++){
        //printf("%i\n", i);
        //Copy ip to "log->msg[i].sender"
        for (j = 0; fread(&dummyC, sizeof(char), 1, file) == 1
        && dummyC != '\n'
        && j < MSG_SENDER_LEN; j++){
            log->msgs[i].sender[j] = dummyC;
        }

        //Copy date to "log->msg[i].date"
        for (j = 0; fread(&dummyI, sizeof(int), 1, file) == 1
        && dummyI != -1
        && j < MSG_DATE_LEN; j++){
            log->msgs[i].date[j] = dummyI;
        }

        //Copy ip to "log->msg[i].sender"
        for (j = 0; fread(&dummyC, sizeof(char), 1, file) == 1
        && dummyC != '\n'
        && j < log->msgs[i].len; j++){
            log->msgs[i].text[j] = dummyC;
        }

    }
    return;
}