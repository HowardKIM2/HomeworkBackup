#include "shm.h"

int main(void){
	int mid;
	SHM_t* p;
	mid = CreateSHM(0x888);

	p = GetPtrSHM(mid);

	getchar();

	printf("name : [%s], score : [%d]\n",p->name,p->score);

	FreePtrSHM(p);

	return 0;
}
