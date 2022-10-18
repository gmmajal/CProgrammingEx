#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.141592


int main(){
	double x,y;
	int i, count =0;
	int n;
	printf("Enter the number of iterations=");
	scanf("%d",&n);
	srand(time(NULL));
	for(int i=0;i<n;++i){
		x=1.0*rand()/RAND_MAX;
		y=1.0*rand()/RAND_MAX;
		if ((x*x)+(y*y)<1){
			count +=1;
		}
	}
	printf("Exact result=%lf\n",PI/4);
	printf("Monte Carlo approximation=%lf\n",1.0*(double)count/n);	
	return 0;
}
