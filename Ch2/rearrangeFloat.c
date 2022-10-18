#include <stdio.h>

void reorder(float* pa, float* pb){
	float tmp;
	if (*pb<*pa){
		tmp=*pa;
		*pa=*pb;
		*pb=tmp;
	}
}

int main(){
	float a=15, b=-6;
	reorder(&a,&b);
	printf("%f %f\n",a,b);
	return 0;
}

