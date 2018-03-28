#include "shm.h"

int main(void){
	int mid;
	SHM_t* p;
	mid = OpenSHM(0x888);

	p = GetPtrSHM(mid);

	getchar();
	strcpy(p->name,"Who.");
	p->score = 93;

	FreePtrSHM(p);

	return 0;
}
