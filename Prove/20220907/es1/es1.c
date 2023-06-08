#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <wait.h>
#include <time.h>
int main(int argv, char* argc[]) {
        char* argList[argv];
	clock_t start,end;
	argList[0] = argc[1];
        int i = 1;
        for (int j = 2; j<=argv;j++) {
                if (j == argv) {
                        argList[i] = NULL;
                }

                argList[i] = argc[j];
                i++;
        }


        while(1) {
		start = clock();
		if(fork() == 0) { 
                	if(execvp(argc[1],argList) == -1) {
                        	printf("ciao");
                        	break;
			}
			else {
				exit(1);
			}
                }
		else {
			wait(NULL);
		}
		end = clock();
		if( (((double)end - start) / CLOCKS_PER_SEC) < 1) {
			break;
		} 
	}

        return 0;
}
