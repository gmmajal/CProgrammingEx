#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.141592

int main(){
	double x,y,z;
	int count=0;
	int n;
	printf("Enter the number of iterations= ");
	scanf("%d",&n);
	srand(time(NULL));
	for(int i=0;i<n;++i){
		x=1.0*rand()/RAND_MAX;
		y=1.0*rand()/RAND_MAX;
		z=1.0*rand()/RAND_MAX;
		if ((x*x)+(y*y)+(z*z)<1.0){
			count+=1;
		}
	}
	
	//unit sphere is contained within a cube with sides 2, thus 
	//the ratio: hit/No. of tries, needs to be multiplied by 2^3
	//in order to approximate the volume of unit cube.
	
	printf("The exact volume is: %lf\n",(4.0*PI)/(3.0));
	printf("The approximated value is: %lf\n", 8*(double)count/n);
	
	return 0;
}
