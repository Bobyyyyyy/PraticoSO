#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

int main (int argc, char * argv[]) {

	if(argc != 2) {
		printf("Argument Error");
		return 0;
	}

	int fd;

	mkfifo(argv[1],0666);

	char buffer[1024];
	fd = open(argv[1],O_RDONLY);

	while(1) {
		memset(buffer,0,1024);
		if(read(fd,buffer,1024)>0) {
			char pid[20];
			char signal[20];

			char* token = strtok(buffer, " ");
			strcpy(pid,token);
			token = strtok(NULL, " ");
			strcpy(signal,token);

			pid_t PID = atoi(pid);
			int SIGNAL = atoi(signal);

			kill(PID,SIGNAL);

			
			break;

		}
	}

	close(fd);
	remove(argv[1]);

	return 0;

}
