#include <stdio.h>
#include <math.h>

double f(double x){
	return x*log(x);
}

double Simpson(double a,double b,int n){
	double h = (b-a)/(2.0*n);
	double even_sum = 0.0;
	double odd_sum = 0.0;
	for(int i=1;i<2*n;i=i+2){
		odd_sum +=f(a+i*h);
	}
	for(int i=2;i<2*n;i=i+2){
		even_sum +=f(a+i*h);
	}
	double eps = 1e-16;//way to get around singularity
	double end_point_sum = f(a+eps)+f(b);
	return h/3.0 * (end_point_sum + 4.0 * odd_sum + 2.0 * even_sum);
}

int main(){
	double a=0.0;
	double b=1.0;
	int n;
	printf("Please enter number(must be even) number of partitions:");
	scanf("%d",&n);
	double simp_quad = Simpson(a,b,n);
	printf("The exact solution is -0.25\n");
	printf("The numerical solution is %lf\n",simp_quad);
	return 0;
}
