#include <stdio.h>

int main(){
	double a[20]={0.228952, 0.568418, 0.820277, 0.117099, 0.755212,
		      0.509299, 0.572073, 0.224526, 0.852861, 0.0612133,
		      0.175636, 0.568243, 0.0100543, 0.702012, 0.0345108,
	              0.146549, 0.189951, 0.144139, 0.261263, 0.474034};
	double sum1=0;
	double sum2=0;
	for (int i=0;i<20;++i){
		sum1+=a[i];
		sum2+=*(a+i);
	}
	double avg1= sum1/20.0;
	double avg2= sum2/20.0;
	printf("The average of the array using the index notation is =%lf\n",avg1);
	printf("The average of the array using pointer notation is =%lf\n",avg2);
	return 0;
}
