#include "message.h"


void msginit(message* msg, int length){
    int i;

    //Allocating memory for the string
    msg->text = (char*) malloc(length * sizeof(char));

    //Setting the length
    msg->len = length;

    //Setting all characters to null
    for (i = 0; i < msg->len; i++) {
        msg->text[i] = '\0';
    }

    return;
}

void msgend(message* msg){
    free(msg->text);
    msg->len = 0;
}

void msgclear(message* msg) {
    int i;

    //Setting all the valid characters to null
    for (i = 0; msg->text[i] != '\0'; i++) {
        msg->text[i] = '\0';
    }
    return;
}

int msglen(message* msg){
    int i;
    for (i = 0; msg->text[i] != '\0'; i++);
    return i;
}

void msgset(message* copy, const char* original) {
    int i;
    msgclear(copy);

    //Copies all the characters, leaving only the last '\0'
    for (i = 0; i < (copy->len - 1) && original[i] != '\0'; i++){
        copy->text[i] = original[i];
    }
    return;
}

void msgcpy(message* copy, message* original) {
    int i;

    msgclear(copy);

    //Copies all characters, leaving only the last '\0'
    for (i = 0; i < (copy->len- 1) && original->text[i] != '\0'; i++) {
        copy->text[i] = original->text[i];
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