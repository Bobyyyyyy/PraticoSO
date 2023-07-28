#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
/* FUNZIONA SOLO SE EXEC È NELLA STESSA DIRECTORY DEL PROGRAMMA */

#define BUFFL sizeof(struct inotify_event) + NAME_MAX + 1

int main(int argc, char* argv[]) {

	if(argc != 2) {
		printf("CmdLine error");
		return 0;
	}

	int fd = inotify_init();
	int watchd = inotify_add_watch(fd,argv[1],IN_CREATE);

	struct inotify_event buff[BUFFL];
	read(fd,buff,BUFFL);

	/* Separare il comando dagli argomenti  */
	char cmd[PATH_MAX];
	char * args[PATH_MAX];
	char filename[PATH_MAX];
	strcpy(filename,buff[0].name);
	char * token = strtok(filename," ");
	strcpy(cmd,token);
	args[0] = token;
	int i = 1;
	while(token != NULL) {
		token = strtok(NULL," ");
		if(token != NULL) {
		   args[i] = token;
		   printf("%s\n",args[i]);
		   i++;
		}

	};

	/* Esecuzione e eliminazione file  */
	char filepath[PATH_MAX] = "./exec/";
	char name[PATH_MAX];
	
	strcat(filepath,buff[0].name);




	/* Non so perchè non mi considera la directory in cui è il file quindi la remove non va */
	remove(filepath);
	execvp(cmd,args);
}
