#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

char symlinkpath[PATH_MAX];
char filepath[PATH_MAX];

void deleteSYMLINKS(char symlink[],int firstcall) {
	char buffer[PATH_MAX];
	if(readlink(symlink,buffer,PATH_MAX) == -1) {
		printf("- %s è un file \n",symlink);
		if(firstcall)
		realpath(symlink,filepath);
		printf("%s\n",filepath);
		return;
	}
	deleteSYMLINKS(buffer);

	
	return;
}



int main (int argc, char* argv[]) {
	
	if(argc != 2) {
		printf("Invalid Arguments");
		return 0;
	}

	DIR* dir = opendir(argv[1]);

	if(!dir) {
		printf("Directory non valida");
		return 0;
	}

	printf("Directory esiste : %s\n",dir);

	struct dirent* fd;

	while((fd = readdir(dir)) != NULL) {
		if(fd->d_type == DT_LNK) {
			char symlink[PATH_MAX];
			strcpy(symlink,fd->d_name);
			realpath(argv[1],symlinkpath);
			strcat(symlinkpath,"/");
			strcat(symlinkpath,symlink);
			printf("%s\n",symlinkpath);
			printf("%s\n",symlink);
			printf("- Questo è un link simbolico\n");
			deleteSYMLINKS(symlink,0);
			link(filepath,symlinkpath);
		}

	}



	closedir(dir);


}
