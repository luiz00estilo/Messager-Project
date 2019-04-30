#include <stdio.h>
#include "message.h"

int main(){
    int i;
    message msg[2];
    msginit(&msg[0], 10);
    msginit(&msg[1], 10);
    while (1){
    msgin(&msg[0]);
    msgin(&msg[1]);

    printf("%s\n%s\n%i\n\n", msg[0].text, msg[1].text, msgcomp(&msg[0], &msg[1]));
    }
    scanf("%i", &i);
    
    msgend(&msg[0]);
    msgend(&msg[1]);
    return 0;
}