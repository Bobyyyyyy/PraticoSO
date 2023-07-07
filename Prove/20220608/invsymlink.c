#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <libgen.h>
#include <limits.h>
#include <stdlib.h>
#include <dirent.h>

int main (int argc, char* argv[]) {
	char * path[PATH_MAX];
	struct stat status;
	lstat(argv[1],&status);
	mode_t mode = status.st_mode;
	if(S_ISLNK(mode)) {<
		realpath(argv[1],*path);
		DIR *directory = opendir(dirname(*path));
		struct dirent *dir;
		dir = readdir(directory);
	}
	printf("%ud",mode);
        return 0;
}









