
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <libgen.h>
#include <limits.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main (int argc, char* argv[]) {
	char symlinkdir[PATH_MAX];
	char symlinkpath[PATH_MAX];
	char filedir[PATH_MAX];
	char filepath[PATH_MAX];
	char symname[PATH_MAX];
	char filename[PATH_MAX];

	char newfilepath[PATH_MAX];
	char newsympath[PATH_MAX];


	struct stat status;

	if (lstat(argv[1],&status) == 0 ) {
	}
	mode_t mode = status.st_mode;
	if(S_ISLNK(mode)) {
		strcpy(symlinkpath,argv[1]);
		realpath(argv[1],filepath);
		strcpy(filedir,filepath);
		strcpy(filename,basename(filepath));
		strcpy(filedir,dirname(filedir));
		strcpy(newsympath,filedir);
		strcat(newsympath,"/");

		strcpy(symname,basename(argv[1]));
		strcpy(newfilepath,dirname(argv[1]));
	        strcat(newfilepath,"/");
		strcat(newfilepath,filename);
		strcat(newsympath,symname);

		printf("Moved symlink from %s\n to\n %s\n ",symlinkpath,newsympath);
		printf("Moved file pointed by symlink from %s\n to \n %s\n",filepath,newfilepath);

		rename(symlinkpath,newsympath);
		rename(filepath,newfilepath);
	}
        return 0;
}









