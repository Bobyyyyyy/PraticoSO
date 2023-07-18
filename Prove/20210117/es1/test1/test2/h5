// 17.20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <libgen.h>

ino_t finode;
char filename[PATH_MAX];

void rreaddir(DIR * dir, char prevdir[]) {
	struct dirent* entry;
	while((entry = readdir(dir)) != NULL) {
			char relpath[PATH_MAX];
			strcpy(relpath,prevdir);
			strcat(relpath,entry->d_name);
			char fullpath[PATH_MAX];
			realpath(relpath,fullpath);
			struct stat buffer;
			if(entry->d_type == DT_REG) {
				if(strcmp(entry->d_name,filename) != 0) {
					if((stat(fullpath,&buffer)) != -1) {
						if(buffer.st_ino == finode) {
							printf("Link %s\n", relpath);
						}
					}
					else {
						printf("stat error");
					}
				}
			}

			if(entry->d_type == DT_LNK) {
                                if(stat(fullpath,&buffer) != -1) {
                                        if(buffer.st_ino == finode) {
                                                printf("symink %s\n", relpath);
                                        }
                                }
                        }

      		      	if ((entry->d_type == DT_DIR) && (strcmp(entry->d_name,".") != 0) && (strcmp(entry->d_name,"..") != 0) ) {
				char* dirn = basename(fullpath);
				char savedir[PATH_MAX];
				strcpy(savedir,prevdir);
				strcat(savedir,dirn);
				strcat(savedir,"/");
				printf("%s\n",savedir);
                                DIR *d = opendir(relpath);
				printf("nome directory: %s\n" ,dirn);
                                rreaddir(d,savedir);
                        }
	}

	closedir(dir);
}




int main (int argv, char * argc[]) {

	if (argv != 3) {
		printf("Arg error");
		return 0;
	}


	char * file = argc[1];
	char * dir = argc[2];

	DIR* d;

	if((d = opendir(dir)) == NULL ) {
		printf("dir error");
		return 0;
	}

	struct stat buffer;
	if(stat(file,&buffer) == -1) {
		printf("file do not exists");
		return 0;
	}

	finode = buffer.st_ino;
	strcpy(filename, basename(argc[1]));
	printf("%s\n",filename);
	printf("%d\n",finode);
	rreaddir(d,"");
}
