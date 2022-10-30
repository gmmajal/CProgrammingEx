#include <stdio.h>
#include <math.h>

/*
 * The function to be integrated is
 * 2.0*sqrt(-x**2 + 4*x -3).
 * The upper and lower limit of the integral
 * are 3 and 1, respectively. The quadrature
 * methods used are the Rectangle method and 
 * the Simpson's method.
 *
 * */

double f(double x){
	return 2.0*sqrt(-pow(x,2)+4*x-3);
}

double Simpson(double a,double b,int n){
	double h = (b-a)/(2.0*n);
	double s_even = 0.0;
	double s_odd = 0.0;
	for(int i=1; i<2*n;i=i+2){
		s_odd+=f(a + i*h);
	}
	for (int i=2;i< 2*n;i=i+2){
		s_even+=f(a + i*h);
	}
	double endpoint_sum = f(a) + f(b);
	return (h/3.0)*( endpoint_sum + (4.0*s_odd) + (2.0*s_even) );
}

double Rectangle(double a,double b,int n){
	double h = (b-a)/(double)n;
	double sum=0.0;
	for(int i=0;i<n;++i){
		sum+=f(a+ i*h);
	}
	return h*sum;
}

int main(){
	double pi = 4.0*atan(1.0);
	double a = 1;
	double b = 3;
	int n;
	printf("Please enter the number (must be even) of partitions:");
	scanf("%d",&n);
	double simp_quad = Simpson(a,b,n);
	double rec_quad = Rectangle(a,b,n);
	printf("The exact result is %lf\n",pi);
	printf("The result from Simpson quadrature is %lf\n",simp_quad);
	printf("The result from Rectangle quadrature is %lf\n", rec_quad);
	return 0;
}
