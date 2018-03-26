/*
	file name : ls.c
	description :
	this file is for making ls instructor with 3 options, -a, -l, -R

	contact :
	e-mail : mihaelkel@naver.com
	phone : -82 10-9132-6404(kr)
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
int read_ls_opt(int argc,char** argv,char* ins);
void ls_start(int flag,char* dname);
void adj_l_opt(struct dirent* p);
int main(int argc,char** argv){
	char* ins = "alR";
	int flag;
	char* s_dir;

	//search otehr directory 
	//ex)ls ../.. -alR
	if(argv[1][0] != '-')
		s_dir = argv[1];
	else
		s_dir = ".";
	
	//set flag
	flag = read_ls_opt(argc,argv,ins);
	
	//ls start path in c_dir, with flag option.
	ls_start(flag,s_dir);
	
	
	return 0;
}
int read_ls_opt(int argc,char** argv,char* ins){
	int flag = 0b00000000;
	int cmd;
	while((cmd = getopt(argc, argv, ins)) > 0){
		switch(cmd){
			case 'a':
				flag |= 0b00000001;
				printf("%c added\n",ins[0]);
				break;
			case 'l':
				flag |= 0b00000010;
				printf("%c added\n",ins[1]);				
				break;
			case 'R':
				flag |= 0b00000100;
				printf("%c added\n",ins[2]);
				break;
		}
	}
	return flag;
}
void ls_start(int flag,char* dname){
	DIR *dp;
	int i = 0;
	struct dirent* p;
	struct stat buf;
	//current directory open
	chdir(dname);
	dp = opendir(".");
	//-R option check, print directory name 
	if(flag & 0b00000100)
		printf("\n%s :\n",dname);
	while(p = readdir(dp)){
		//-a option check.
		if(!(flag & 0b00000001)){			 
			if(p->d_name[0] == '.')
				continue;
		}

		//-l option chkeck.
		if(flag & 0b00000010){
			adj_l_opt(p);
		}
		printf("%-16s ",p->d_name);

		//displaying 5 files, go to next line.(when -l is not added)
		//displaying 1 file , in 1 line.(when -l is addedd)
		if(!(flag & 0b00000010)){
			if((i + 1) % 5 == 0)
				printf("\n");
			i++;
		}
		else
			printf("\n");
	}
	printf("\n");
	//-R option adjust.
	if(flag & 0b00000100){
		rewinddir(dp);
		while(p = readdir(dp)){
			stat(p->d_name,&buf);
			if(S_ISDIR(buf.st_mode))
				if(strcmp(p->d_name,".") && strcmp(p->d_name,".."))
					ls_start(flag,p->d_name);
		}
	}
	//close the working directory
	chdir("..");
	closedir(dp);
}
void adj_l_opt(struct dirent* p){
	struct stat buf;
	struct passwd* pw;
	struct group* gr;
	struct tm* tm;
	char ch;

	//permission has(nrwxrwxrwx)
	char perm[11] = "----------";
	char rwx[4] = "rwx";
	char sst[4] = "sst";
	int i;
	stat(p->d_name, &buf);

	//check the current file's type
	if(S_ISDIR(buf.st_mode))
		perm[0] = 'd';
	if(S_ISREG(buf.st_mode))
		perm[0] = '-';
	if(S_ISFIFO(buf.st_mode))
		perm[0] = 'p';
	if(S_ISSOCK(buf.st_mode))
		perm[0] = 's';
	if(S_ISCHR(buf.st_mode))
		perm[0] = 'c';
	if(S_ISBLK(buf.st_mode))
		perm[0] = 'b';
	
	//rwx setting
	for(i=0;i<9;i++)
		if((buf.st_mode >> (8-i))&1)
			perm[i+1] = rwx[i%3];
	
	//sst setting
	for(i=0;i<3;i++)
		if((buf.st_mode >> (11-i))&1)
			if(perm[(i+1)*3] == '-')
				perm[(i+1)*3] = sst[i]^0x20;
			else
				perm[(i+1)*3] = sst[i];

	//print : -rwxrwxrwx 1 username groupname size YYYY-MM-DD HH:MM
	//ex    : -rw-r--r-- 1 howard   howard    4096 2018-03-24 22:10
	printf("%s ",perm);
	printf("%-6lu ",buf.st_nlink);
	pw = getpwuid(buf.st_uid);
	printf("%-10s ",pw->pw_name);
	gr = getgrgid(buf.st_gid);
	printf("%-10s ",gr->gr_name);
	printf("%-6ld ",buf.st_size);
	tm = localtime(&buf.st_mtime);
	printf("%d-%02d-%02d %02d:%02d ",
			tm->tm_year + 1900, tm->tm_mon +1,tm->tm_mday, tm->tm_hour,tm->tm_min);

}
