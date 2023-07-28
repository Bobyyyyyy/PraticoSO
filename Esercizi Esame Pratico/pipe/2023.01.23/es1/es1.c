#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
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
			if(strcmp(buffer,"FINE\n") == 0) {
				break;
			}
			else {
				printf("%s\n",buffer);
			}
		}
	}

	close(fd);
	remove(argv[1]);

	return 0;

}
