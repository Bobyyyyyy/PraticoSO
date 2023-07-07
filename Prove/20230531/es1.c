#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int procNumber = 0;

void listFiles(const char* dirname, const char* command) {
    	DIR* dir = opendir(dirname);
    	if (dir == NULL) {
        	return;
    	}

    	struct dirent* entity;
    	entity = readdir(dir);
    	while (entity != NULL) {
		char path[100] = {0};
		strcat(path,dirname);
		strcat(path,"/");
		strcat(path,entity->d_name);
	        if (entity->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0) {
            		listFiles(path,command);
        	}
		else if (strcmp(entity->d_name,"cmdline")==0) {
			char cmdlinecontent[100];
			FILE *fptr;
			fptr = fopen(path,"r");
			fgets(cmdlinecontent, strlen(command), fptr);
			printf("%s\n",cmdlinecontent);
			if (strcmp(cmdlinecontent,command) == 0) {
				procNumber++;
			}
			fclose(fptr);
		}
        		entity = readdir(dir);
    	}
    	closedir(dir);
	}


int main (int argv, char* argc[]) {
	if (argv == 1) {
		printf("invalid arguments");
		return 0;
	}
	char* cmd = argc[1];
	char* args= argc[2];

	char fullcmd[100] = {0};
	strcat(fullcmd,cmd);
	strcat(fullcmd," ");
	strcat(fullcmd,args);
	printf("%s\n",fullcmd);
	listFiles("/proc", fullcmd);
	printf("%d",procNumber);
	return 0;

}
