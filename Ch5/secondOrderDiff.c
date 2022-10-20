#include<stdio.h>
#define N 11

/*10  values are used for altitude and time
 *
 *The second order stencil used for t=0 is 
 *f'(x)= (4f(x+h)-f(x+2h)-3f(x))/2h
 *
 *The second order stencil used for t in [20,180] is
 *f'(x)= (f(x+h)-f(x-h))/2h
 *
 *The second order stencil used for t=200 is
 *f'(x)= (3f(x)-4f(x-h)+f(x-2h))/2h
 *
 */ 

int main(int argc, char* argv[]){
	double altitude[N]={370, 9170,23835,45624,62065,87368,97355,103422,127892,149626,160095};
	double central[N];
	double h=20;
	central[0]=((4.0*altitude[1])-altitude[2]-(3.0*altitude[0]))/(2.0*h);
	for (int i=1;i<N-1;++i){
		central[i] = (altitude[i+1]-altitude[i-1])/(2.0*h);
	}
	central[10] = ((3.0*altitude[10]) - (4.0*altitude[9]) + altitude[8])/(2.0*h);
	printf(" x               Central\n---------------------\n");
	for(int i=0;i<N;++i){
		printf("%lf\t%lf\n",i*h, central[i]);
	}
	return 0;
}
