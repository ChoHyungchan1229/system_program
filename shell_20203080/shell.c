#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    int status;
    pid_t pid;
    pid = fork();
    if (pid == 0){
        //argv[] = {"ls", "-al", "/tmp", NULL};
        printf("processing...\n");
        execvp(argv[1], &argv[1]);
        fprintf(stderr, "%s\n", strerror(errno));
        exit(0);       
    }
    else if (pid > 0){
        pid_t waitP;
        waitP = wait(&status);
        if(WIFSIGNALED(status)){
            fprintf(stderr, "%s\n", strerror(errno));
            exit(0);
        }
    }
    else {
        fprintf(stderr, "fork error:%s\n", strerror(errno));
        exit(0);
    }
    printf("completed.\n");
    return 0;
}
