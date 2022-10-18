#include <stdio.h>

int fact(int n){
	if(n==0){
		return 1;
	}else if(n==1){
		return 1;
	}else{
		return n*fact(n-1);
	}
}

int main(){
	printf("Calculating the factorial of integers\n");
	printf("The factorial of 4 is %d\n",fact(4));
	double sum=0.0;
	for(int i=0;i<12;++i){
		sum+=(double) 1/fact(i);
	}
	printf("The sum of the 1/i! series %lf\n",sum);
	return 0;
}
