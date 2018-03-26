#include <unistd.h>

int main(void){
	execlp("ps","ps","-e","-f",NULL);
	return 0;
}
