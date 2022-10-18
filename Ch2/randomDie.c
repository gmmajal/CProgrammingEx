#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#include <math.h>

int main(){
	int a[N];
	double sum=0;
	double avg, std;

	srand(time(NULL));

	for (int i=0; i<N;++i){
		a[i]=(rand()%6)+1;
	}
	for (int i=0;i<N;++i){
		sum+=a[i];
	}
	avg=sum/(double)N;
	sum=0;
	for (int i=0;i<N;++i){
		sum+=pow(a[i]-avg,2.0);	
	}
	std=sqrt(sum/(N-1.0));

	printf("The average obtained for throwing a die %d times is %lf\n",N,avg);
	printf("The standard deviation obtained for throwing a die %d times is %lf\n",N,std);
	return 0;
}
