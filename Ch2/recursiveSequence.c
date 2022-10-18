#include <stdio.h>

int a_n(int n){
	if (n==0){
		return 2;
	}else if(n==1){
		return -1;
	}else{
		return -2*a_n(n-1) + 3*a_n(n-2);
	}
}

int main(){
	printf("The recursive sequence is a_n+2=-2a_n+1+3a_n\n");
	int a17= a_n(17);
	printf("a_17=%d\n",a17);
	return 0;
}

