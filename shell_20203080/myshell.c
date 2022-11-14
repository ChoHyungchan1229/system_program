#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<readline/readline.h>


int main()
{
    pid_t pid;
    int status;
	char* cmd_arr[10];
    char* cmdline;
    char* opt;

    while(1) {
        cmdline = readline("$ ");

		opt = strtok(cmdline," \n" );

		if(!strcmp(opt, "quit"))
            break;

		int i = 0;
		while (opt != NULL){
			cmd_arr[i]=malloc(sizeof(char)*20);
			strcpy(cmd_arr[i], opt);
			i++;
			opt = strtok(NULL, " \n");
		}
		cmd_arr[i] = NULL;
		pid = fork();
		if (pid == 0){//child
			execvp(cmd_arr[0], &cmd_arr[0]);
			fprintf(stderr, "%s\n", strerror(errno));
			exit(0);
		}
		else if (pid > 0){//parent
			pid_t waitP;
			waitP = wait(&status);
			if(WIFSIGNALED(status)){
				fprintf(stderr, "%s\n", strerror(errno));
				exit(0);
			}
		}
		else {
			fprintf(stderr,"fork error : %s\n", strerror(errno));
			exit(0);
		}
	} 



    return 0;
}

