#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
void make_rand_dir(void);
int main(void){
	printf("create random directories\n");
	int i;
	for(i=0;i<3;i++)
		make_rand_dir();
	return 0;
}
void make_rand_dir(void){
	srand(time(NULL));
	int nl = rand()%10 + 5;
	char* name = (char*)malloc(sizeof(char)*nl);
	int i;
	for(i=0;i<nl;i++)
		name[i] = 97 + rand()%26;
	mkdir(name,0644);
	printf("%s dir created!\n",name);
	sleep(1);
}
