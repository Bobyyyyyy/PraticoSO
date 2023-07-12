#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/timerfd.h>
#include <time.h>
#include <unistd.h>
#include <inttypes.h>





static void printtime(void) {

}









int main (int argv, char* argc[]) {
        u_int64_t exp, tot_exp, max_exp;
        ssize_t s;
        printf("%s\n", argc[1]);
        char * token = strtok(argc[1],",");
        char  * arguments[3];
        int i = 0;
        while (token != NULL) {
                arguments[i] = token;
                printf(" %s\n",arguments[i]);
                token = strtok(NULL,",");
                i++;
        }

        max_exp = atoi(arguments[0]);
        struct itimerspec newtime;
        newtime.it_interval.tv_sec = atof(arguments[1]);
        newtime.it_interval.tv_nsec = 0;
        newtime.it_value.tv_sec = atof(arguments[1]);
        newtime.it_value.tv_nsec = 0;

        int fd = timerfd_create(CLOCK_REALTIME,0);

        timerfd_settime(fd,0,&newtime,NULL);





        return 0;

}
