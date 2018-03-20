#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int game(int com,int player);
int main(void){
	srand(time(NULL));
	int com, player,chk;
	while(1){
		printf("가위 바위 보!! (1:가위, 2:바위, 3:보, 그 외 종료) : ");
		scanf("%d",&player);
		com = rand()%3 + 1;
		chk = game(com,player);
		if(chk == 1)
			break;
	}
	printf("게임 종료!\n");
	return 0;
}
int game(int com,int player){
	
	int res = player - com;
	int chk = 0;
	if(res == 1 || res == -2)
		printf("You win\n");
	else if(res == 0)
		printf("Draw\n");
	else if(res == -1|| res == 2)
		printf("You lose\n");
	switch(com){
		case 1:
			printf("com : 가위\n");
			break;
		case 2:
			printf("com : 바위\n");
			break;
		case 3:
			printf("com : 보\n");
			break;
		default:
			chk = 1;
			break;
	}
	return ckk;
}
