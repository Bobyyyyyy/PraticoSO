#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/timerfd.h>
#include <time.h>
#include <unistd.h>
#include <inttypes.h>



int main (int argv, char* argc[]) {
        printf("%s\n", argc[1]);
        char * token = strtok(argc[1],",");
        char* arguments[3];
        int i = 0;
        while (token != NULL) {
                arguments[i] = token;
                printf("%s\n",arguments[i]);
                token = strtok(NULL,",");
                i++;
        }
        return 0;

}
