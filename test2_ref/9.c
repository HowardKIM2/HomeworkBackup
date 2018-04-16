#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
typedef struct __queue{
	char* file;
	struct __queue* link;
}queue;

queue* get_queue_node(void);
void ins_queue(queue** head, char* file);
void read_files_queue(queue** head,char* argv);
void print_files_queue(queue* head);
void read_file_content(char* file);
void err_handler(char* msg);
int main(int argc, char** argv){
	queue* head = NULL;
	read_files_queue(&head,argv[0]);
	
	print_files_queue(head);
}
queue* get_queue_node(void){
	queue* tmp;
	tmp = (queue*)malloc(sizeof(queue)*1);
	tmp->link = NULL;
	return tmp;
}
void ins_queue(queue** head, char* file){
	queue** tmp = head;
	while(*tmp)
		tmp = &(*tmp)->link;
	*tmp = get_queue_node();
	(*tmp)->file = file;
}
void read_files_queue(queue** head,char* argv){
	DIR* dp;
	struct dirent* p;
	dp = opendir(".");
	struct stat buf;
	while(p = readdir(dp)){
		stat(p->d_name,&buf);
		//except directory, current file
		if(!S_ISDIR(buf.st_mode)&&(strncmp(p->d_name,argv+2,strlen(p->d_name))))
			ins_queue(head,p->d_name);
	}
}
void print_files_queue(queue* head){
	queue* tmp = head;
	while(tmp){
		printf("file : %s\n",tmp->file);
		read_file_content(tmp->file);
		tmp = tmp->link;
	}
}
void read_file_content(char* file){
	int fd, ret;
	char buf[1024];
	if((fd = open(file,O_RDONLY,0644)) < 0)
		err_handler("Open error");

	while((ret = read(fd,buf,1024)) >0)
		write(1,buf,ret);
	close(fd);
}
void err_handler(char* msg){
	fputs(msg,stderr);
	fputc('\n',stderr);
	exit(-1);
}
