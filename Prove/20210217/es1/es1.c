#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>



int deleteSYMLINKS(char symlink[],int first_call) {
	char buffer[PATH_MAX];
	if(readlink(symlink,buffer,PATH_MAX) == -1) {
		printf("- %s è un file \n",symlink);
		return 0;
	}

	if(first_call) {
		if(deleteSYMLINKS(buffer,0)) {
			printf("- %s è un link simbolico allora elimino %s \n",buffer,symlink);
	   		unlink(symlink);
		}
	}
	return 1;
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
			printf("%s\n",symlink);
			printf("- Questo è un link simbolico\n");
			deleteSYMLINKS(symlink,1);
		}

	}



	closedir(dir);


}
