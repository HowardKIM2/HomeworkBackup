#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main(void){
	int status;
	pid_t pid;
	char* argv[] = {"./newpgm","newpgm","one","two",NULL};
	char* env[] = {"name = OS_Hacker","age = 20",NULL};
	if((pid = fork()) > 0){
		wait(&status);
		printf("prompt >\n");
	}
	else if(pid == 0){
		execve("./newpgm",argv,env);
	}
	return 0;

}
