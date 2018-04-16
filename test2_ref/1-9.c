#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
void create_files(char* file);
int main(void){
	system("mkdir test");
	printf("test directory created!\n");
	chdir("test");
	system("mkdir go exam");
	printf("go, exam directory created!\n");
	chdir("exam");

	
	create_files("aa");
	sleep(1);
	create_files("bb");
	sleep(1);
	create_files("cc");
	sleep(1);
	create_files("dd");
	sleep(1);
	create_files("ee");

	system("mv aa bb dd ee ../go");
	printf("aa,bb,dd,ee moved to go\n");
}
void create_files(char* file){
	int fd;
	srand(time(NULL));
	int nn, nr = rand() % 5 + 2; 
	char buf[32];
	fd = open(file,O_WRONLY|O_CREAT|O_TRUNC,0644);
	int i, j;
	for(j=0;j<nr;j++){
		nn = rand()%20 + 10;
		usleep(10);
		for(i=0;i<nn;i++){
			buf[0] = rand()%26 + 65; 
			write(fd,buf,1);
		}
		buf[0] = '\n';
		write(fd,buf,1);
	}
	printf("%s file created\n",file);
	close(fd);
}
