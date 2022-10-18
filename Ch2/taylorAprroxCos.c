#include <stdio.h>
#include <math.h>
#define PI 3.141592


//for this case the datatype should be long long int.
//plain int will give the wrongly compute the taylor series.

long long int factorial(int n){
	if(n==0){
		return 1;
	}else if(n==1){
		return 1;
	}else{
		return n*factorial(n-1);
	}
}

double mycos(double x){
	double sum=0.0;
	for(int i=0;i<=10;++i){
		int n = 2*i;
		sum+= (pow(-1.0,i)*pow(x,n))/(factorial(n));
	}
	return sum;
}

int main(){

	printf("x\t\tmycos(x)\tcos(x)\n");
	for (int i=0;i<5;++i){
		printf("%lf\t%lf\t%lf\n",(i*PI)/2,mycos((i*PI)/2),cos((i*PI)/2));
	}
	return 0;
}

