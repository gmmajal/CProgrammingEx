#include <stdio.h>
#include <math.h>

typedef struct{
	double Real;
	double Im;
}Complex;

Complex ComplexMultiply(Complex z1, Complex z2){
	Complex z;
	z.Real=z1.Real*z2.Real - (z1.Im*z2.Im);
	z.Im=(z1.Real*z2.Im) + (z1.Im*z2.Real);
	return z;
}

Complex ComplexDiv(Complex z1, Complex z2){
	double den = pow(z2.Real,2)+pow(z2.Im,2);
	Complex z2conj;
	z2conj.Real = z2.Real;
	z2conj.Im = -z2.Im;
	Complex num = ComplexMultiply(z1,z2conj);
	Complex z;
       	z.Real = num.Real/den;
	z.Im = num.Im/den;
	return z;
}

int main(){
	Complex z1, z2, z;
	z1.Real =2.12 ;
	z1.Im = 1.21;
	z2.Real = -2.8;
	z2.Im = 7.8;
	z = ComplexDiv(z1,z2);
	printf("The division of z1/z2 = %lf + (%lf)i\n",z.Real, z.Im);
	return 0;
}
