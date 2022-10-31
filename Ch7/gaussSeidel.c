#include <stdio.h>
#include <math.h>

/*
 * The system of equations being solved using the 
 * Gauss Seidel method is
 * 27x + exp(x) * cos(y) - 0.12z = 3,
 * -0.2x**2 + 37y + 3xz = 6,
 *  x**2 - 0.2y * sin(x) + 29z = -4.
 *
 */


int main(){
	double x,y,z;
	x=1.0;y=1.0;z=1.0;
	int n;
	printf("Enter number of iterations:");
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		x = (3.0 + 0.12*z -exp(x)*cos(y))/27.0;
		y = (6.0+0.2*pow(x,2)-3.0*x*z)/37.0;
		z = (-4.0-pow(x,2)+0.2*y*sin(x))/29.0;	
	}
	printf("After %d iterations the value of x is:%lf\n",n,x);
	printf("After %d iterations the value of y is:%lf\n",n,y);
	printf("After %d iterations the value of z is:%lf\n",n,z);
	return 0;
}
