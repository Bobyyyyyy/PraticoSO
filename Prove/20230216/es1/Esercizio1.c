x#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

 int main (int argc, char*argv[]) {
//	if (argc != 3) {
//	return -1;
//	}

	FILE *file1 = fopen(argv[1],"r");
	FILE *file2 = fopen(argv[2],"w");
	char f;

	if(file1 == NULL || file2 == NULL) {
		printf("non funziona un cazzo");
		return 0;
 	}

	fseek(file1,0,SEEK_END);
	int size = ftell(file1);

	if(fork() == 0) {
		fseek(file1,0,SEEK_SET);
		do {
			fputc(fgetc(file1),file2);
		}while(ftell(file1) != (size/2));
	}

	else {
		if (fork()==0) {
			int curChar;
			fseek(file1, (size/2) , SEEK_SET);
			fseek(file2, (size/2) , SEEK_SET);
			while (1) {
				curChar = fgetc(file1);
				if( curChar == EOF) { 
					break;
				}
				fputc(curChar,file2);
			         }
		}
	    }

	fclose(file1);
	fclose(file2);
	return 0;
}
