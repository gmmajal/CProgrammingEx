#include <stdio.h>
#include <math.h>
#define EPS 1e-10
#define N 100

double f(double x){
	return exp(x)-(3.0*x);
}

int main(){
	double x1;double x2;double x3;
	do{
		printf("The range under consideration is [x1,x2]\n");
		printf("Please enter value for x1=");
		scanf("%lf",&x1);
		printf("Please enter value for x2=");
		scanf("%lf",&x2);
	}while(f(x1)*f(x2)>0);
	
	for(int i=0;i<N;++i){
		x3=0.5*(x1+x2);
		if(f(x1)*f(x3)<0){
			x2=x3;
		}else{
			x1=x3;
		}
		if( f(x3)==0.0 ||fabs(x1-x2)<EPS)
			break;
	}
	printf("The root of the equation is x=%lf\n",x3);
	return 0;
}


