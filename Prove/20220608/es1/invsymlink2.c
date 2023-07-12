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
	struct dirent* fd;
	DIR* dir = opendir(argv[1]);
	if (dir) {
		while(fd = readdir(dir) != NULL) {
			struct stat status;
                        if (fd->d_type == DT_LNK) {
			    strcpy(symname,fd->d_name);
			    getcwd(symlinkpath,PATH_MAX);
			    strcat(symlinkpath,"/");
			    strcat(symlinkpath,symname);
		            realpath(symlinkpath,filepath);

			    strcpy(filedir,filepath);
 			    strcpy(filename,basename(filepath));
			    strcpy(filedir,dirname(filedir));
			    strcpy(newsympath,filedir);
			    strcat(newsympath,"/");
	        	    strcat(newfilepath,"/");
			    strcat(newfilepath,filename);

			    printf("Moved symlink from %s\n to\n %s\n ",symlinkpath,newsympath);
			    printf("Moved file pointed by symlink from %s\n to \n %s\n",filepath,newfilepath);

			    rename(symlinkpath,newsympath);
			    rename(filepath,newfilepath);
		}
	}
		closedir(dir);
	}
        return 0;
}









