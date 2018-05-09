#include <stdio.h>
#include <math.h>
#define dt 		0.000001
#define dtheta	0.000001
#define w	dtheta/dt
#define r	2
#define pi	3.14159
//각도에 따른 원 위의 x,y 좌표
#define posX(rad)	r*cos(rad)
#define posY(rad)	r*sin(rad)
//현재 각도에서 x성분 속도 구하기(x성분 위치 미분)
double v_x(double theta){
	return (posX(theta + dtheta) - posX(theta))/dt;
}
//현재 각도에서 y성분 속도 구하기(y성분 위치 미분)
double v_y(double theta){
	return (posY(theta + dtheta) - posY(theta))/dt;
}
//현재 각도에서 선속력(sqrt x^2+y^2)
double v(double theta){
	return sqrt(pow(v_x(theta),2)+pow(v_y(theta),2));
}
//현재 각도에서 x성분 가속도 구하기(x성분 속도 미분)
double a_x(double theta){
	return (v_x(theta + dtheta) - v_x(theta))/dt;
}
//현재 각도에서 y성분 가속도 구하기(y성분 속도 미분)
double a_y(double theta){
	return (v_y(theta + dtheta) - v_y(theta))/dt;
}
//현재 각도에서 가속도의 크기
double a(double theta){
	return sqrt(pow(a_x(theta),2)+pow(a_y(theta),2));
}

int main(void){
	double rad = 0;

#if	1
	//속도 출력
	while(rad<=2*pi)
	{
		printf ("%.3lf radian\tv_x(%.3lf) : %lfm/s\tv_y(%.3lf) : %lfm/s\tv(%.3lf) : %lfm/s\n",
			rad,rad,v_x(rad),rad,v_y(rad),rad,v(rad));
		rad += dtheta;
	}
#endif
	

#if	0
	//가속도 출력
	while(rad<=2*pi)
	{
		printf ("%.3lf radian\ta_x(%.3lf) : %lfm/s^2\ta_y(%.3lf) : %lfm/s^2\ta(%.3lf) : %lfm/s^2\n",
			rad,rad,a_x(rad),rad,a_y(rad),rad,a(rad));
		rad += dtheta;
	}
#endif
}
