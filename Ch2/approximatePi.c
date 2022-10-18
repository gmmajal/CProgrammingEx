#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(){
	int n=100;//n=10,20,50,100
	double sum=0.0;
	printf("The value of pi/4=%lf\n",M_PI_4);
	for (int i=0;i<n;++i){
		sum+= (pow(-1,i+2))/((2.0*i)+1.0);
		printf("At i=%d the value of series is %lf\n",i,sum);
	}
	return 0;
}
