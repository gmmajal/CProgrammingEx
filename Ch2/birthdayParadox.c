#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 25
#include <time.h>

int main(){
	int a[N];
	int count=0;
	int s=0;
	int numSim;
	printf("Please enter the number of simulations:");
	scanf("%d",&numSim);
	srand(time(NULL));
	for (int i=0;i<N;++i){
		a[i]=(rand()%364)+1;
		printf("a[%d]=%d\n",i,a[i]);
	}
	while(s<numSim){
		for (int k=0;k<N-1;++k){
			for (int j=k+1;j<N;++j){
				if(a[k]==a[j]){
					count+=1;
					goto ExitLoop;
				}	
			}
		}
		ExitLoop:;
		for (int ii=0;ii<N;++ii){
			a[ii]=(rand()%364)+1;
		}
		s+=1;
	}

	printf("The estimated probability is=%lf\n",(double)count/numSim);		
	return 0;
}
