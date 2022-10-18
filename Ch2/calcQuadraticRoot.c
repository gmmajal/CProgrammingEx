#include <stdio.h>
#include <math.h>
#include <complex.h>

int main(){
	double a,b,c;
	double x1,x2, discriminant;
	printf("Please enter the coefficents (a,b,c)  of the quadratic equation ax^2+bx+c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	discriminant= (b*b)-(4*a*c);
	
	if (discriminant<0){
		printf("There is no real root\n");
		double complex c1 = (-b + csqrt(discriminant))/(2*a);
		double complex c2 = (-b - csqrt(discriminant))/(2*a);
		double c1Real = creal(c1);
		double c1Img = cimag(c1);
	       	double c2Real = creal(c2);
		double c2Img = cimag(c2);	
		printf("The roots of the equation are %lf + (%lf)i and %lf + (%lf)i\n", c1Real, c1Img, c2Real, c2Img);
	}else{
		x1 = (-b+sqrt(discriminant))/(2.0*a);
		x2 = (-b-sqrt(discriminant))/(2.0*a);
		printf("The roots of the equation are x1: %lf and x2:%lf\n",x1,x2);
	}
	return 0;
}

	

