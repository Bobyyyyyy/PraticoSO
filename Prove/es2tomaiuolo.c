#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int epoch;

int read_directories(const char* path1, const char* path2) {
    DIR* d1 = NULL;
    DIR* d2 = NULL;
    if ((d1 = opendir(path1)) == NULL) {
        printf("Can't open %s\n", path1);
	return 0;
    }

    if ((d2 = opendir(path2)) == NULL) {
		mkdir(path2,0777);
	}


    struct dirent* entry = NULL;
    while ((entry = readdir(d1)) != NULL) {
	char full_name2[256] = { 0 };
        char full_name[256] = { 0 };
        snprintf(full_name, 100, "%s/%s", path1, entry->d_name);
	printf("%s\n",full_name);
	snprintf(full_name2,100, "%s/%s", path2, entry->d_name);
	printf("%s\n",full_name2);

	if(entry -> d_type == DT_REG) {

		struct stat buffer;
		if(stat(full_name,&buffer) == -1) {
			printf("stat error");
			return 0;
		}

		int lastmod = (int)buffer.st_mtime;

		if(lastmod < epoch) {
			if(link(full_name,full_name2) == -1) {
				printf("hardlink create failed");
				return 0;
			}
			printf("%d e' minore di %d allora creo link\n",lastmod,epoch);
		}

		else {
			printf("%d e' maggiore di %d allora copio\n",lastmod,epoch);
			FILE* fp2;
			FILE* fp1;
			fp2 = fopen(full_name2,"w");
			fp1 = fopen(full_name,"r");
			char c = fgetc(fp1);

			while(c != EOF) {
				fputc(c,fp2);
				c = fgetc(fp1);
			}

			fclose(fp1);
			fclose(fp2);
		}

	}
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                return read_directories(full_name,full_name2);
            }
        }
}
}




int main (int argc, char* argv[]) {

	if(argc != 4) {
		printf("arg error");
		return 0;
	}

	epoch = atoi(argv[1]);
	printf("%d\n",epoch);
	char* dir1 = argv[2];
	char* dir2 = argv[3];
	read_directories(dir1,dir2);
}
