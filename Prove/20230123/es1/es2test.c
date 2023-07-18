#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

int main (int argc, char * argv[]) {

        int fd;

        char buffer[1024];

	int pid = getpid();

	sprintf(buffer,"%d",pid);
        strcat(buffer," ");
	strcat(buffer,"10");
	printf(buffer);
        fd = open("/tmp/ff",O_WRONLY);

	write(fd,buffer,strlen(buffer)+1);

	sigset_t* s; 
	sigaddset(s,10);
	int *signal; 
        close(fd);
        sigwait(s,signal);
}
