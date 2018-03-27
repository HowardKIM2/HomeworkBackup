#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

//it dosen't work because "goto" only works in the same function.
//goto doesn't have an ability that release the "stack"
void goto_func(void){
	goto err;
}
int main(void){
	int ret;
	char buf[1024];
	if((ret = read(0,buf,sizeof(buf))) > 0)
		goto_func();

	return 0;
err:
	perror("read()");
	exit(-1);
}


