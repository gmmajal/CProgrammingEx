#include <stdio.h>
#include <math.h>
#define EPS 1e-10
#define N 100

double f(double x){
	return x*sin(x)-exp(x)+(x*sin(pow(x,2)));
}

double fprime(double x){
	return sin(x)+(x*cos(x))-exp(x)+(sin(x*x) +  2*x*x*cos(x*x) );
}

int main(){
	double x1;double x2;
	do{
		printf("The function lies between the range [-2,2]\n");
		printf("Please enter your initial guess =");
		scanf("%lf",&x1);
	}while(fprime(x1)==0.0);
	for(int i=0;i<N;++i){
		x2 = x1 - f(x1)/fprime(x1);
		if(fabs(x1-x2)<EPS){
			break;
		}else{
			x1 = x2;
		}
	}
	printf("The root of the equation is = %lf\n",x1);
	return 0;
}
