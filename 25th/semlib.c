#include "sem.h"

int CreateSEM(key_t semkey){
	int status = 0,semid;
	//IPC : inter process communication.
	if((semid = semget(semkey, 1, SEMPERM|IPC_CREAT|IPC_EXCL)) == -1){
		if(errno == EEXIST){
			printf("db1 : %d\n",semid);
			semid = semget(semkey, 1, 0);
			printf("db1-1 : %d\n",semid);
		}
	}
	else{
		printf("db2 : %d\n",semid);
		status = semctl(semid, 0, SETVAL, 2);
	}
	if(semid == -1 || status == -1)
		return -1;
	return semid;

}
int p(int semid){
	struct sembuf p_buf = {0, -1, SEM_UNDO};// SEM_UNDO initialyze sem, when process exits.
	if(semop(semid, &p_buf, 1) == -1) // semaphore value +1
		return -1;
	return 0;
}

int v(int semid){
	struct sembuf p_buf = {0, 1, SEM_UNDO};// 0, 1, SEM_UNDO : sub
	if(semop(semid, &p_buf, 1)== -1)
		return -1;
	return 0;
}
