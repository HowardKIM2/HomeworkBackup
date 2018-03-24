/*
	file name : hw.c
	description :
	this is made for Homework
	
	execute example : ./a.out a.txt (-a)
	-a is optional.
	required file : a.txt
	apple
	banana
	peach
	mango
	watermelon
	cherry
	strawberry

	result file : b.txt .c.txt

	contact:
	e-mail : mihaelkel@naver.com
	phone  : 82 -10-9132-6404(kr)
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

void read_txt_to_ascii_raw(int argc,char** argv,int* fd);
void set_raw_str_to_ascii(char* str,int fd);
void read_txt_to_ascii_col(int argc,char** argv,int* fd);
void set_col_str_to_ascii(char* str,int fd);
void exec_ls_a(void);
int main(int argc,char** argv){
	int fd;
	read_txt_to_ascii_raw(argc,argv,&fd);
	read_txt_to_ascii_col(argc,argv,&fd);
	exec_ls_a();
	close(fd);
}
void read_txt_to_ascii_raw(int argc,char** argv,int* fd){
	int new_fd;
	char buf[1024] = {'\0',};
	int ret;
	//a.txt b.txt open
	*fd = open(argv[1], O_RDONLY, 0644);
	new_fd = open("b.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while(ret = read(*fd, buf, sizeof(buf))){
		set_raw_str_to_ascii(buf,new_fd);
	}
	close(new_fd);

}
void set_raw_str_to_ascii(char* str,int fd){
	char buf[1024]={'\0',};
	char res[1024]={'\0',};
	int i = 0;
	int ascii[1024] = {0,};
	int asc_idk = 0;
	
	while(str[i++]){
		if(str[i] != '\n')
			ascii[asc_idk] += str[i];
		else
			asc_idk++;
	}
	for(i=0;i<asc_idk;i++){
		if(((i+1)%10 == 1)&&(i+1 != 11))
			sprintf(buf,"%dst raw's ascii sum : %d\n",i+1,ascii[i]);
		else if(((i+1)%10 == 2)&&(i+1 != 12))
			sprintf(buf,"%dnd raw's ascii sum : %d\n",i+1,ascii[i]);
		else if(((i+1)%10 == 3)&&(i+1 != 13))
			sprintf(buf,"%drd raw's ascii sum : %d\n",i+1,ascii[i]);
		else
			sprintf(buf,"%dth raw's ascii sum : %d\n",i+1,ascii[i]);
		strcat(res,buf);
	}
	write(fd, res, strlen(res));
}
void read_txt_to_ascii_col(int argc,char** argv,int* fd){
	int new_fd;
	char buf[1024] = {'\0',};
	int ret;
	//a.txt .c.txt open
	*fd = open(argv[1], O_RDONLY, 0644);
	new_fd = open(".c.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while(ret = read(*fd, buf, sizeof(buf))){
		set_col_str_to_ascii(buf,new_fd);
	}
	close(new_fd);

}
void set_col_str_to_ascii(char* str,int fd){
	char buf[1024]={'\0',};
	char res[1024]={'\0',};
	int i = 0;
	int ascii[1024] = {0,};
	int col_idk = 0;
	int max_col;
	while(str[i++]){
		if(str[i] != '\n')
			ascii[col_idk++] += str[i];
		else{
			if(max_col < col_idk)
				max_col = col_idk;
			col_idk = 0;
		}
	}
	strcat(res,"ascii sum(column side) : \n");
	for(i=0;i<max_col;i++){
		if(((i+1)%10 == 1)&&(i+1 != 11))
			sprintf(buf,"%dst     ",i+1);
		else if(((i+1)%10 == 2)&&(i+1 != 12))
			sprintf(buf,"%dnd     ",i+1);
		else if(((i+1)%10 == 3)&&(i+1 != 13))
			sprintf(buf,"%drd     ",i+1);
		else
			sprintf(buf,"%dth     ",i+1);
		strcat(res,buf);
	}
	strcat(res,"\n");
	for(i=0;i<max_col;i++){
		sprintf(buf,"%-8d",ascii[i]);
		strcat(res,buf);
	}
	write(fd, res, strlen(res));
}
void exec_ls_a(void){
	DIR* dp;
	int i = 0;
	struct dirent* p;
	dp = opendir(".");
	while(p = readdir(dp)){
		printf("%-16s ",p->d_name);
		if((i+1)%5 == 0)
			printf("\n");
		i++;
	}
	printf("\n");
	closedir(dp);

}
