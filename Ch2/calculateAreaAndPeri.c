#include <stdio.h>
#include <math.h>
#define PI 3.141592

void circle(double r, double* area, double* perimeter){
	*area = PI*pow(r,2);
	*perimeter= 2.0*PI*r;
}

int main(){
	double r, perimeter, area;
	printf("Enter radius= ");
	scanf("%lf",&r);
	circle(r, &area, &perimeter);
	printf("r=%lf area=%lf peri=%lf\n",r,area, perimeter);
	return 0;
}

