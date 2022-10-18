#include <stdio.h>

int main(){
	float temp_c,temp_f;
	printf("Enter temperature value in Celsius= ");
	scanf("%f",&temp_c);
	temp_f= 32.0 + (float)(9.0*temp_c)/5.0;
	printf("It is %f degree in Fahrenheit\n",temp_f);
	return 0;
}

